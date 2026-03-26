
#pragma once

#include "flight.h"
#include <vector>

using namespace std;

//Pseudocode from Discussion 6 & 7 Slides

void heapSort(vector<Flight>& data, int swaps, int size){


    int index = size/2 - 1;

    for (int i = index; i>=0; i--){
        heapify(data, size, i);
    }


}

void heapify(vector<Flight>& data, int size, int parent){

    int left = 2*parent + 1;
    int right = 2*parent + 2;

    int max = parent;

    if (right < size && data.at(right).total_delay() > data.at(max).total_delay()){
        max = right;
    }
    if (left < size && data.at(left).total_delay() > data.at(max).total_delay()){
        max = left;
    }

    if (max != parent){
        swap(data.at(parent), data.at(max));
        swaps++;
        heapify(data, size, max);
    }

}


