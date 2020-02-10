cmake_minimum_required (VERSION 3.1.3)

project (v2v)

set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")
set (CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -D_DEBUG")
set (CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -D_DEBUG")

find_package(Threads REQUIRED)
find_package(ZXing REQUIRED)

include_directories(
    ${ZXing_INCLUDE_DIRS}
)

add_executable (main
    src/main.cpp
    src/webcam.cpp
)

target_link_libraries(main
    ZXingCore
    ${CMAKE_THREAD_LIBS_INIT}
)
