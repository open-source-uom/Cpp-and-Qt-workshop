include_directories(../ast)

add_library(parser parser.cpp)
add_library(calc::parser ALIAS parser)

