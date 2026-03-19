#pragma once
#include <iostream>
#include "flight.h"
#include "fileio.h"
#include "quicksort.h"
#include "heapsort.h"
#include <vector>
#include <sstream>
using namespace std;

/*
To do list:
-CMake
-quicksort
-heapsort
-finish console functions
-debug
*/






int main(){
    //File io
    vector<Flight> unsorted_flights = scrape_data("US_flights_2023.csv");



    //Call the heap sort and quick sort

    double heap_execution = 0.0; //temp value
    int heap_num_swaps = 0; //temp value
    double quick_execution = 0.0; //temp value
    int quick_num_swaps = 0; //temp value

    vector<Flight> heapSortedData = heapSort(unsorted_flights, heap_num_swaps);
    vector<Flight> quickSortedData = quickSort(unsorted_flights, quick_num_swaps);


    //Print out info on sort time and num of swaps

    cout << "Heap Sort:" << endl;
    cout << '\t' << "Execution time: " << heap_execution << endl;
    cout << '\t' << "Number of swaps: " << heap_num_swaps << endl;

    cout << "Quick Sort:" << endl;
    cout << '\t' << "Execution time: " << quick_execution << endl;
    cout << '\t' << "Number of swaps: " << quick_num_swaps << endl;


    //Console loop
    string raw_command;
    while(true){
        string command = "";
        int num_args = 0;
        
        cout << "Please enter a command (/h for help):" << endl;
        getline(cin, raw_command);

        istringstream strstream(raw_command);


        string command = "";
        strstream >> command;
        vector<std::string> arguments;
        string argument;

        while (strstream >> argument) {
            arguments.push_back(argument);
        }


        if(command == "/h"){
            cout << "|HELP| List of functions " << endl;
            cout << '\t' << "/h : List functions" << endl;
            cout << '\t' << "/compare_sort : Reprints the sort alogrithm comparison information" << endl;
            cout << '\t' << "/numdelays_airline (airline) : Prints the number of delayed flights from a given airline" <<endl;
            cout << '\t' << "/numdelays_airport (arrival airport) (arrival airport) : Prints the number of delayed flights from a departure airport to arrival airport" << endl;
            cout << '\t' << "/numdelays_day (day of week) : Shows the number of delayed flights for a given day of week" << endl;
            cout << '\t' << "/bw_dates : Prints the 5 dates with most/least delays" << endl;
            cout << '\t' << "/bw_days : Prints the 5 days with most/least delays" << endl;
            cout << '\t' << "/bw_airlines : Prints the 5 airlines with most/least delays" << endl;
            cout << '\t' << "/show10 : Prints the first 10 datapoints of each sorted list" <<endl;
            cout << '\t' << "/show50 : Prints the first 50 datapoints of each sorted list" <<endl;
            cout << '\t' << "/show100 : Prints the first 100 datapoints of each sorted list" <<endl;
            cout << '\t' << "/show500 : Prints the first 500 datapoints of each sorted list" <<endl;
            cout << '\t' << "/show# (number) : Prints the number of datapoints of each sorted list" << endl;
            cout << '\t' << "/quit : Quits" << endl;
            //ADD MORE COMMANDS HERE
        }
        else if(command == "/compare_sort"){
            cout << "Heap Sort:" << endl;
            cout << '\t' << "Execution time: " << heap_execution << endl;
            cout << '\t' << "Number of swaps: " << heap_num_swaps << endl;

            cout << "Quick Sort:" << endl;
            cout << '\t' << "Execution time: " << quick_execution << endl;
            cout << '\t' << "Number of swaps: " << quick_num_swaps << endl;
        }
        else if(command == "/numdelays_airline"){
            //finish command
        }
        else if(command == "/numdelays_airport"){
            //finish command
        }
        else if(command == "/numdelays_day"){
            //finish command
        }
        else if(command == "/bw_dates"){
            //finish command
        }
        else if(command == "/bw_days"){
            //finish command
        }
        else if(command == "/bw_airlines"){
            //finish command
        }
        else if(command == "/show10"){
            cout << "Quick sort: " << endl;
            cout << endl;
            for(int i = 0; i < 10; i++){
                quickSortedData[i].print_data_clean();
            }
            cout << endl;
            cout << "Heap sort: " << endl;
            cout << endl;
            for(int i = 0; i < 10; i++){
                heapSortedData[i].print_data_clean();
            }
            cout << endl;
        }
        else if(command == "/show50"){
            cout << "Quick sort: " << endl;
            cout << endl;
            for(int i = 0; i < 50; i++){
                quickSortedData[i].print_data_clean();
            }
            cout << endl;
            cout << "Heap sort: " << endl;
            cout << endl;
            for(int i = 0; i < 50; i++){
                heapSortedData[i].print_data_clean();
            }
            cout << endl;
        }
        else if(command == "/show100"){
            cout << "Quick sort: " << endl;
            cout << endl;
            for(int i = 0; i < 100; i++){
                quickSortedData[i].print_data_clean();
            }
            cout << endl;
            cout << "Heap sort: " << endl;
            cout << endl;
            for(int i = 0; i < 100; i++){
                heapSortedData[i].print_data_clean();
            }
            cout << endl;
        }
        else if(command == "/show500"){
            cout << "Quick sort: " << endl;
            cout << endl;
            for(int i = 0; i < 500; i++){
                quickSortedData[i].print_data_clean();
            }
            cout << endl;
            cout << "Heap sort: " << endl;
            cout << endl;
            for(int i = 0; i < 500; i++){
                heapSortedData[i].print_data_clean();
            }
            cout << endl;
        }
        else if(command == "/show#"){
            //Exception handler
            if(arguments.empty()){
                cout << "|ERROR| No number specified" << endl;
                continue;
            }
            if(!stoi(arguments[0])){
                cout << "|ERROR| No number specified" << endl;
                    continue;
            }
            int num_to_print = stoi(arguments[0]);

            cout << "Quick sort: " << endl;
            cout << endl;
            for(int i = 0; i < num_to_print; i++){
                quickSortedData[i].print_data_clean();
            }
            cout << endl;
            cout << "Heap sort: " << endl;
            cout << endl;
            for(int i = 0; i < num_to_print; i++){
                heapSortedData[i].print_data_clean();
            }
            cout << endl;
        }
        else if(command == "/quit"){
            break;
        }
        else{
            cout << "Command not recognized" << endl;
        }
    }
    return 0;
}