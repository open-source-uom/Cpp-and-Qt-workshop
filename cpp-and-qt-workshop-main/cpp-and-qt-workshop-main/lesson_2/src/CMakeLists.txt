add_library(redis_server 
    redis_server.cpp
    tcp_connection.cpp
)

target_link_libraries(redis_server
    Boost::system
    fmt::fmt
)

set_target_properties(redis_server PROPERTIES CXX_VISIBILITY_PRESET hidden)
generate_export_header(redis_server)

target_include_directories(redis_server PUBLIC
$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
$<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}>
$<INSTALL_INTERFACE:include/redis_server/> 
)  

add_executable(redis redis.m.cpp)
target_link_libraries(redis fmt::fmt redis_server)