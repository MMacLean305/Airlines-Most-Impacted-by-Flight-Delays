
#pragma once

#include "flight.h"
#include <vector>
#include <algorithm>

using namespace std;

//Pseudocode from Discussion 6 & 7 Slides
void heapify(vector<Flight>& data, int size, int parent, int& swaps){

    int left = 2*parent + 1;
    int right = 2*parent + 2;

    int max = parent;

    if (left < size && data.at(left).total_delay() > data.at(max).total_delay()){
        max = left;
    }

    if (right < size && data.at(right).total_delay() > data.at(max).total_delay()){
        max = right;
    }

    if (max != parent){
        swap(data.at(parent), data.at(max));
        swaps++;
        heapify(data, size, max, swaps);
    }

}


//https://www.geeksforgeeks.org/dsa/heap-sort/
void heapSort(vector<Flight>& data, int& swaps, int size){

    int index = size/2 - 1;

    for (int i = index; i>=0; i--){
        heapify(data, size, i, swaps);
    }

    for (int i = size - 1; i > 0; i--){
        swap(data.at(0), data.at(i));
        swaps++;
        heapify(data, i, 0, swaps);
    }


}




