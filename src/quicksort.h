#pragma once

#include <vector>

using namespace std;

void quickSort(vector<Flight>& data, int& swaps){

    

}

int partition (vector<Flight>& data, int& low, int& high, int& swaps){

    int pivot = data.at(low).total_delay();
    int up = low;
    int down = high;

    while (up < down){
        for (int i = up; i < high; i++){
            if (data.at(i).total_delay() > pivot){
                up++;
                break;
            }
        }

        for (int i = down; i > low; i--){
            if(data.at(i).total_delay() < pivot){
                down--;
                break;
            }
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