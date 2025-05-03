add_library(hello_lib SHARED hello_world.cpp)
add_library(UniMacedonia::hello_lib ALIAS hello_lib)

set_target_properties(hello_lib PROPERTIES CXX_VISIBILITY_PRESET hidden)

generate_export_header(hello_lib)

target_include_directories(hello_lib PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
  $<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}>
  $<INSTALL_INTERFACE:include/UniMacedonia> 
)

SET(HELLO_LIB_PUB_HEADERS
    hello_world.h
    ${CMAKE_CURRENT_BINARY_DIR}/hello_lib_export.h
)

set_target_properties(hello_lib PROPERTIES
  PUBLIC_HEADER "${HELLO_LIB_PUB_HEADERS}"
)

install(TARGETS hello_lib
  EXPORT UniMacedoniaTargets
  LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR} 
  ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
  RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
  PUBLIC_HEADER DESTINATION "${CMAKE_INSTALL_INCLUDEDIR}/UniMacedonia")
