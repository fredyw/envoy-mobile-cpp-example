workspace(name = "envoy_mobile_cpp_example")

local_repository(
    name = "envoy",
    path = "envoy",
)

local_repository(
    name = "envoy_mobile",
    path = "envoy/mobile",
)

local_repository(
    name = "envoy_build_config",
    path = "envoy/mobile/envoy_build_config",
)

load("@envoy//bazel:api_binding.bzl", "envoy_api_binding")

envoy_api_binding()

load("@envoy//bazel:api_repositories.bzl", "envoy_api_dependencies")

envoy_api_dependencies()

load("@envoy//bazel:repositories.bzl", "envoy_dependencies")

envoy_dependencies()

load("@envoy//bazel:repositories_extra.bzl", "envoy_dependencies_extra")

envoy_dependencies_extra()

load("@envoy//bazel:python_dependencies.bzl", "envoy_python_dependencies")

envoy_python_dependencies()

load("@envoy//bazel:dependency_imports.bzl", "envoy_dependency_imports")

envoy_dependency_imports()