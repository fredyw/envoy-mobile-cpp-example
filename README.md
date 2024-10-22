# envoy-mobile-cpp-example

An example of using [Envoy Mobile](https://github.com/envoyproxy/envoy/tree/main/mobile) in C++.

## Prerequisite
1. Install [Bazelisk](https://github.com/bazelbuild/bazelisk).
2. Install Clang and libc++.
3. Run `git submodule update --init` to clone the Envoy repo.
4. Run `envoy/bazel/setup_clang.sh` to configure Clang.

## How to run the example
```
bazelisk run //:envoy_cpp_example
```