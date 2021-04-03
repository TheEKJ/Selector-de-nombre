add_library(console-lib 
event_queue.cpp
error.cpp
win/keys.cpp
win/char_buffer.cpp
win/win_console.cpp
win/event_queue.cpp
console.cpp)

target_include_directories(console-lib PRIVATE .)