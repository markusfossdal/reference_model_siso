cmake_minimum_required(VERSION 3.20)
project(reference_model_third_order_siso)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")

add_library(reference_model_third_order_siso STATIC
    src/reference_model_third_order_siso.cpp
)

target_include_directories(
    reference_model_third_order_siso PUBLIC
    "include"
)

if (CMAKE_PROJECT_NAME STREQUAL reference_filter_third_order_siso)
    add_executable(reference_model_third_order_siso_testing src/reference_model_third_order_siso.cpp)
    target_link_libraries(reference_model_third_order_siso_testing PRIVATE reference_model_third_order_siso)

endif()
