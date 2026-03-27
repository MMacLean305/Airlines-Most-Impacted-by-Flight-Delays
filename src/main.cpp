#include <iostream>
#include "flight.h"
#include "fileio.h"
#include "quicksort.h"
#include "heapsort.h"
#include <vector>
#include <sstream>
#include <unordered_map>
#include <algorithm>
using namespace std;

/*
To do list:
-quicksort
-debug
*/






int main(){

    
    //Loading screen
    // cout << "Loading flight data"
    

    

    //File io
    vector<Flight> unsorted_flights_quick = scrape_data("US_flights_2023.csv");

    vector<Flight> unsorted_flights_heap = scrape_data("US_flights_2023.csv");

    //https://ansi.tools/
    //cout << "\033[2K\r";

    //Call the heap sort and quick sort

    double heap_execution = 0.0; //temp value
    int heap_num_swaps = 0; //temp value
    double quick_execution = 0.0; //temp value
    int quick_num_swaps = 0; //temp value

    heapSort(unsorted_flights_heap, heap_num_swaps, unsorted_flights_heap.size());
    quickSort(unsorted_flights_quick, 0, unsorted_flights_quick.size() - 1, quick_num_swaps);

    vector<Flight> heapSortedData = unsorted_flights_heap;
    vector<Flight> quickSortedData = unsorted_flights_quick;

    //constant values
     int qcSize = quickSortedData.size();
     int hpSize = heapSortedData.size();

     //Day maping
     unordered_map<int, string> day_map = {
        {1, "Monday"},
        {2, "Tuesday"},
        {3, "Wednesday"},
        {4, "Thursday"},
        {5, "Friday"},
        {6, "Saturday"},
        {7, "Sunday"}
    };


    //Print out info on sort time and num of swaps

    cout << "Heap Sort:" << endl;
    cout << '\t' << "Execution time: " << heap_execution << endl;
    cout << '\t' << "Number of swaps: " << heap_num_swaps << endl;

    cout << "Quick Sort:" << endl;
    cout << '\t' << "Execution time: " << quick_execution << endl;
    cout << '\t' << "Number of swaps: " << quick_num_swaps << endl;

    vector<Flight> reversedQuickSort = quickSortedData;
    vector<Flight> reversedHeapSort = heapSortedData;

    reverse(reversedQuickSort.begin(),reversedQuickSort.end());
    reverse(reversedHeapSort.begin(), reversedHeapSort.end());


    //Console loop
    string raw_command;
    while(true){
        string command = "";
        int num_args = 0;
        
        cout << "Please enter a command (/h for help):" << endl;
        getline(cin, raw_command);

        istringstream strstream(raw_command);

        strstream >> command;
        vector<std::string> arguments;
        string argument;

        while (strstream >> argument) {
            arguments.push_back(argument);
        }


        if(command == "/h"){
            cout << "|HELP| List of functions " << endl;
            cout << '\t' << "/h : List functions" << endl;
            cout << '\t' << "/compare_sort : Reprints the sort algorithm comparison information" << endl;
            cout << '\t' << "/numdelays_airline (airline) : Prints the number of delayed flights from a given airline" <<endl;
            cout << '\t' << "/numdelays_airport (departure airport) (arrival airport) : Prints the number of delayed flights from a departure airport to arrival airport" << endl;
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
            cout << endl;
        }
        else if(command == "/numdelays_airline"){
            if(arguments.empty()){
            cout << "|ERROR| No airline specified" << endl;
            continue;
            }
            string airline = arguments[0];
            int total_num = 0;
            int num_delayed = 0;
            for(int i = 0; i < quickSortedData.size(); i++){
                if((quickSortedData[i].get_airline() == airline) && (quickSortedData[i].any_delay() == true)){
                    total_num += 1;
                    num_delayed += 1;
                }
                else if(quickSortedData[i].get_airline() == airline){
                    total_num += 1;
                }
            }
            float per_delayed =((float)num_delayed / (float)total_num) * 100;
            
            cout << airline << ": " << endl;
            cout << "Total number of flights: " << total_num << endl;
            cout << "Number of flights delayed: " << num_delayed << endl;
            cout << "Percentage delayed: " << per_delayed << "%" << endl;
            cout << endl;
        }
        else if(command == "/numdelays_airport"){

            if (arguments.size() < 2){
                cout << "|ERROR| Not enough arguments" << endl;
                continue;
            }

            string departure = arguments[0];
            string arrival = arguments[1];

            int count = 0;

            for (Flight flight : quickSortedData){
                if((flight.get_departure_airport() == departure) && (flight.get_arrival_airport() == arrival) && flight.any_delay()){
                    count++;
                }
            }
            cout << "Departure airport: " << departure <<  " to Arrival airport: " << arrival << endl;
            cout << "Number of delayed flights: " << count << endl;
            cout << endl;

        }
        else if(command == "/numdelays_day"){

            if (arguments.empty()){
                cout << "|ERROR| No day specified" << endl;
                continue;
            }

            int day = 0;
            
            if (arguments[0] == "Monday"){
                day = 1;
            }
            else if (arguments[0] == "Tuesday"){
                day = 2;
            }
            else if (arguments[0] == "Wednesday"){
                day = 3;
            }
            else if (arguments[0] == "Thursday"){
                day = 4;
            }
            else if (arguments[0] == "Friday"){
                day = 5;
            }
            else if (arguments[0] == "Saturday"){
                day = 6;
            }
            else if (arguments[0] == "Sunday"){
                day = 7;
            }
            else{
                cout << "|ERROR| Invalid day specified" << endl;
                cout << "Please enter Monday, Tuesday, etc" <<endl; 
                continue;
            }

            unordered_map<int, int> freq;

            for (Flight flight : quickSortedData){
                if(flight.total_delay() > 0){
                    freq[flight.get_day_of_week()]++;
                }
            }

            for (auto iter = freq.begin(); iter != freq.end(); iter++){
                if (iter->first == day){
                    cout << "Day: " << day_map[iter->first] << endl;
                    cout << "Number of delayed flights: " << iter->second << endl;
                    cout << endl;
                }
            }
            cout << endl;

        }
        //sorting map by value from https://www.geeksforgeeks.org/cpp/sorting-a-map-by-value-in-c-stl/
        else if(command == "/bw_dates"){
            unordered_map<string, int> freq;

            for (Flight flight : quickSortedData){
                if(flight.total_delay() > 0){
                    freq[flight.get_flight_date()]++;
                }
            }

            vector<pair<string, int>> sorted_freq(freq.begin(), freq.end());
            sort(sorted_freq.begin(), sorted_freq.end(), compareDelay<string>);

            cout << "----- Top 5 dates with most delays -----" << endl << endl;
            for(int i = 0; i < 5 && i < sorted_freq.size(); i++){
                cout << sorted_freq[i].first << ": " << sorted_freq[i].second << endl;
            }
            cout << endl;

            cout << "----- Top 5 dates with least delays -----" << endl << endl;
            for(int i = sorted_freq.size() - 1; i >= 0 && i >= (int)sorted_freq.size() - 5; i--){
                cout << sorted_freq[i].first << ": " << sorted_freq[i].second << endl;
            }
            cout << endl;
            cout << endl;

        }
               //sorting map by value from https://www.geeksforgeeks.org/cpp/sorting-a-map-by-value-in-c-stl/
        else if(command == "/bw_days"){
            unordered_map<int, int> freq;

            for (Flight flight : quickSortedData){
                if(flight.total_delay() > 0){
                    freq[flight.get_day_of_week()]++;
                }
            }

            vector<pair<int, int>> sorted_freq(freq.begin(), freq.end());
            sort(sorted_freq.begin(), sorted_freq.end(), compareDelay<int>);

            cout << "----- Top 5 days with most delays -----" << endl << endl;
            for(int i = 0; i < 5 && i < sorted_freq.size(); i++){
                cout << day_map[sorted_freq[i].first] << ": " << sorted_freq[i].second << endl;
            }

            cout << endl;

            cout << "----- Top 5 days with least delays -----" << endl << endl;
            for(int i = sorted_freq.size() - 1; i >= 0 && i >= (int)sorted_freq.size() - 5; i--){
                cout << day_map[sorted_freq[i].first] << ": " << sorted_freq[i].second << endl;
            }
            cout << endl;
            cout << endl;
            

        }
               //sorting map by value from https://www.geeksforgeeks.org/cpp/sorting-a-map-by-value-in-c-stl/
        else if(command == "/bw_airlines"){
            unordered_map<string, int> freq;

            for (Flight flight : quickSortedData){
                if(flight.total_delay() > 0){
                    freq[flight.get_airline()]++;
                }
            }

            vector<pair<string, int>> sorted_freq(freq.begin(), freq.end());
            sort(sorted_freq.begin(), sorted_freq.end(), compareDelay<string>);

            cout << "----- Top 5 airlines with most delays -----" << endl << endl;
            for(int i = 0; i < 5 && i < sorted_freq.size(); i++){
                cout << sorted_freq[i].first << ": " << sorted_freq[i].second << endl;
            }
            cout << endl;
            cout << "----- Top 5 airlines with least delays -----" << endl << endl;
            for(int i = sorted_freq.size() - 1; i >= 0 && i >= (int)sorted_freq.size() - 5; i--){
                cout << sorted_freq[i].first << ": " << sorted_freq[i].second << endl;
            }
            cout << endl;

            cout << endl;

        }
        else if(command == "/show10"){
            cout << "----- Quick sort -----" << endl;
            cout << endl;
            for(int i = 0; i < 10 && i < qcSize; i++){
                cout << "Flight " << i+1 << ": " << endl;
                reversedQuickSort[i].print_data_clean();
                cout << endl;
            }

            cout << endl;
            cout << "----- Heap sort -----" << endl;
            cout << endl;
            for(int i = 0; i < 10 && i < hpSize; i++){
                cout << "Flight " << i+1 << ": " << endl;
                reversedHeapSort[i].print_data_clean();
                cout << endl;
            }
            cout << endl;
        }
        else if(command == "/show50"){
            cout << "----- Quick sort -----" << endl;
            cout << endl;
            for(int i = 0; i < 50 && i < qcSize; i++){
                cout << "Flight " << i+1 << ": " << endl;
                reversedQuickSort[i].print_data_clean();
                cout << endl;
            }

            cout << endl;
            cout << "----- Heap sort -----" << endl;
            cout << endl;
            for(int i = 0; i < 50 && i < hpSize; i++){
                cout << "Flight " << i+1 << ": " << endl;
                reversedHeapSort[i].print_data_clean();
                cout << endl;
            }
            cout << endl;
        }
        else if(command == "/show100"){
            cout << "----- Quick sort -----" << endl;
            cout << endl;
            for(int i = 0; i < 100 && i < qcSize; i++){
                cout << "Flight " << i+1 << ": " << endl;
                reversedQuickSort[i].print_data_clean();
                cout << endl;
            }

            cout << endl;
            cout << "----- Heap sort -----" << endl;
            cout << endl;
            for(int i = 0; i < 100 && i < hpSize; i++){
                cout << "Flight " << i+1 << ": " << endl;
                reversedHeapSort[i].print_data_clean();
                cout << endl;
            }
            cout << endl;
        }
        else if(command == "/show500"){
            cout << "----- Quick sort -----" << endl;
            cout << endl;
            for(int i = 0; i < 500 && i < qcSize; i++){
                cout << "Flight " << i+1 << ": " << endl;
                reversedQuickSort[i].print_data_clean();
                cout << endl;
            }
            cout << endl;
            cout << "----- Heap sort -----" << endl;
            cout << endl;
            for(int i = 0; i < 500 && i < hpSize; i++){
                cout << "Flight " << i+1 << ": " << endl;
                reversedHeapSort[i].print_data_clean();
                cout << endl;
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
            if(num_to_print > qcSize){
                cout << "|ERROR| Number is larger than dataset" << endl;
                continue;
            }

            cout << "----- Quick sort -----" << endl;
            cout << endl;
            for(int i = 0; i < num_to_print; i++){
                reversedQuickSort[i].print_data_clean();
            }
            cout << endl;
            cout << "----- Heap sort -----" << endl;
            cout << endl;
            for(int i = 0; i < num_to_print; i++){
                reversedHeapSort[i].print_data_clean();
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