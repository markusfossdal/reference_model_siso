cmake_minimum_required(VERSION 3.20)
project(reference_model_siso)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")

# Define library target
add_library(reference_model_siso STATIC src/reference_model_siso.cpp)

# Include directories 
target_include_directories(reference_model_siso PUBLIC "include")

# Install the static library
# install(TARGETS reference_model_siso ARCHIVE DESTINATION lib)

# Install headers
# install(DIRECTORY include/ DESTINATION include)


if(CMAKE_PROJECT_NAME STREQUAL reference_filter_siso)
  add_executable(reference_model_siso_testing src/reference_model_siso.cpp)
  target_link_libraries(reference_model_siso_testing
                        PRIVATE reference_model_siso)

endif()
