#include <iostream>

#include "absl/synchronization/notification.h"

#include "library/cc/engine.h"
#include "library/cc/engine_builder.h"
#include "library/common/http/header_utility.h"

std::shared_ptr<Envoy::Platform::Engine> createEngine() {
  Envoy::Platform::EngineBuilder engine_builder;
  engine_builder.setLogLevel(Envoy::Logger::Logger::trace);
  absl::Notification engine_running;
  engine_builder.setOnEngineRunning(
      [&engine_running] { engine_running.Notify(); });
  auto engine = engine_builder.build();
  // Wait until the Engine is ready.
  engine_running.WaitForNotification();
  return engine;
}

std::shared_ptr<Envoy::Platform::Stream>
newStream(Envoy::Platform::StreamPrototype& client,
          absl::Notification& request_finished) {
  Envoy::EnvoyStreamCallbacks callbacks;
  callbacks.on_complete_ = [&](envoy_stream_intel, envoy_final_stream_intel) {
    request_finished.Notify();
  };
  return client.start(std::move(callbacks));
}

void sendRequest(Envoy::Platform::Stream& stream) {
  auto headers = Envoy::Http::Utility::createRequestHeaderMapPtr();
  headers->setMethod("GET");
  headers->setScheme("https");
  headers->setHost("www.google.com:443");
  headers->setPath("/");
  stream.sendHeaders(std::move(headers), true);
}

int main() {
  auto engine = createEngine();
  auto client = engine->streamClient()->newStreamPrototype();

  absl::Notification request_finished;
  auto stream = newStream(*client, request_finished);
  sendRequest(*stream);
  // Wait for the request to finish.
  request_finished.WaitForNotification();

  engine->terminate();
  return 0;
}