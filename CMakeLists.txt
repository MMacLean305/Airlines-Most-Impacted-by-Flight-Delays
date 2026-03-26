cmake_minimum_required(VERSION 3.22)
project(Airlines)

add_executable(Airlines
    src/main.cpp
    src/fileio.cpp
    src/flight.cpp
    src/quicksort.h
    src/heapsort.h
)

configure_file(US_Flights_2023.csv US_Flights_2023.csv COPYONLY)
