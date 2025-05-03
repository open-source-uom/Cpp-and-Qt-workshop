add_library(ast ast.cpp)
add_library(calc::ast ALIAS ast)

add_executable(ast_test ast.t.cpp)
target_link_libraries(ast_test calc::ast)

add_test(AstTest_1 ast_test)
add_test(AstTest_2 ast_test)
add_test(AstTest_3 ast_test)