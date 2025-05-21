cmake_minimum_required(VERSION 3.20)
project(reference_model_siso VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)
# set(CMAKE_CXX_EXTENSIONS OFF)

# Define library target
add_library(reference_model_siso STATIC src/reference_model_siso.cpp)

# Include directories
target_include_directories(reference_model_siso
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
)

include(GNUInstallDirs)
include(CMakePackageConfigHelpers)

# ---------- install the target ----------
install(TARGETS reference_model_siso
        EXPORT reference_model_sisoTargets
        ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR} #static libs
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR} #dynamic libs
        RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}) #executables and dlls

# ---------- install headers ----------
install(DIRECTORY include/ DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})

# ---------- generate + install Config files ----------
configure_package_config_file(
        ${CMAKE_CURRENT_SOURCE_DIR}/cmake/reference_model_sisoConfig.cmake.in
        ${CMAKE_CURRENT_BINARY_DIR}/reference_model_sisoConfig.cmake
        INSTALL_DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/reference_model_siso)

write_basic_package_version_file(
        ${CMAKE_CURRENT_BINARY_DIR}/reference_model_sisoConfigVersion.cmake
        VERSION ${PROJECT_VERSION}
        COMPATIBILITY SameMajorVersion)

install(FILES
        ${CMAKE_CURRENT_BINARY_DIR}/reference_model_sisoConfig.cmake
        ${CMAKE_CURRENT_BINARY_DIR}/reference_model_sisoConfigVersion.cmake
        DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/reference_model_siso)

# ---------- export the targets ----------
install(EXPORT reference_model_sisoTargets
        FILE reference_model_sisoTargets.cmake
        NAMESPACE reference_model_siso::
        DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/reference_model_siso)


# ---------- optional test executable ----------
if(CMAKE_PROJECT_NAME STREQUAL reference_filter_siso)
  add_executable(reference_model_siso_testing src/reference_model_siso.cpp)
  target_link_libraries(reference_model_siso_testing
                        PRIVATE reference_model_siso)
endif()
