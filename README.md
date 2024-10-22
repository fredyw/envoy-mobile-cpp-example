# envoy-mobile-cpp-example

An example of using [Envoy Mobile](https://github.com/envoyproxy/envoy/tree/main/mobile) in C++.

## Prerequisite
1. Install Clang and libc++.
2. Run `git submodule update --init` to clone the Envoy repo.
3. Run `envoy/bazel/setup_clang.sh` to configure Clang.

## How to run the example
```
bazel run //:envoy_cpp_example
```