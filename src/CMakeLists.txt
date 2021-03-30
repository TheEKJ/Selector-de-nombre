add_executable(SN 
main.cpp
exception.cpp
event_queue.cpp
win/keys.cpp
win/win_console.cpp
win/event_queue.cpp
console.cpp)

target_include_directories(SN PUBLIC .)