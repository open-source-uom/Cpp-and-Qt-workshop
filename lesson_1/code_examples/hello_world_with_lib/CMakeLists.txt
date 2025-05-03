
cmake_minimum_required(VERSION 3.16 FATAL_ERROR)

project(CodeVis LANGUAGES CXX VERSION 1.0)

include(GNUInstallDirs)
include(CMakePackageConfigHelpers)
include(GenerateExportHeader)

add_subdirectory(src)

configure_package_config_file(
    UniMacedoniaConfig.cmake.in
    ${CMAKE_CURRENT_BINARY_DIR}/UniMacedoniaConfig.cmake
    INSTALL_DESTINATION lib/UniMacedonia/cmake
)

write_basic_package_version_file(
  ${CMAKE_CURRENT_BINARY_DIR}/UniMacedoniaConfigVersion.cmake
  VERSION 1.0
  COMPATIBILITY SameMajorVersion)

install(FILES 
    ${CMAKE_CURRENT_BINARY_DIR}/UniMacedoniaConfig.cmake
    ${CMAKE_CURRENT_BINARY_DIR}/UniMacedoniaConfigVersion.cmake
DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/UniMacedonia )

install(EXPORT UniMacedoniaTargets
        FILE UniMacedoniaTargets.cmake
        NAMESPACE UniMacedonia::
        DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/UniMacedonia
)
