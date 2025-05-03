add_subdirectory(ast)
add_subdirectory(parser)

include_directories(ast)
include_directories(parser)

add_executable(calculator main.cpp)
target_link_libraries(
    calculator    # The executable
    calc::ast     # The Libraries
    calc::parser
)