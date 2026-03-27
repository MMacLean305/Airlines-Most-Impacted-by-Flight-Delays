cmake_minimum_required(VERSION 3.22)
project(Airlines)

add_executable(Airlines
    src/main.cpp
    src/fileio.cpp
    src/flight.cpp
    src/quicksort.h
    src/heapsort.h
)

set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -Wl,--stack,8388608")
configure_file(US_Flights_2023.csv US_Flights_2023.csv COPYONLY)
