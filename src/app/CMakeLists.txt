add_library(app-lib
   app.cpp)

target_link_libraries(app-lib console-lib)
target_include_directories(app-lib PUBLIC ${CMAKE_SOURCE_DIR}/src)