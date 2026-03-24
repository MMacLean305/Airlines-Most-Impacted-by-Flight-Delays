#pragma once

#include <vector>
#include <algorithm>
#include "flight.h"

using namespace std;

//Pseudocode from Discussion 8 Slides

void quickSort(vector<Flight>& data,int low, int high, int& swaps){

    if (data.at(low).total_delay() < data.at(high).total_delay()){
        int pivot = partition(data, low, high, swaps);
        quickSort(data,low, pivot-1, swaps);
        quickSort(data, pivot+1, high, swaps);
    }

}

int partition (vector<Flight>& data, int low, int high, int& swaps){

    int pivot = data.at(low).total_delay();
    int up = low;
    int down = high;

    while (up < down){
        for (int i = up; i < high; i++){
            if (data.at(i).total_delay() > pivot){
                break;
            }
            up++;
        }

        for (int i = down; i > low; i--){
            if(data.at(i).total_delay() < pivot){
                break;
            }
            down--;
        }

        if (up < down){
            swap(data.at(up), data.at(down));
            swaps++;
        }
    }
    swap(data.at(low), data.at(down));
    swaps++;
    return down;
}