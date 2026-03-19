#pragma once
#include <iostream>
#include "flight.h"
#include "fileio.h"
#include "quicksort.h"
#include "heapsort.h"
#include <vector>
using namespace std;
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

        if(raw_command == "/h"){
            cout << "|HELP| List of functions" << endl;
            //ADD MORE COMMANDS HERE
        }
        else if(raw_command == "/quit"){
            break;
        }
        else{
            cout << "Command not recognized" << endl;
        }
    }
    return 0;
}