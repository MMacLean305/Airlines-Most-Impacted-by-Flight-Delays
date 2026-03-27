#pragma once

#include <vector>
#include <algorithm>
#include "flight.h"

using namespace std;

//Pseudocode from Discussion 8 Slides

int partition (vector<Flight>& data, int low, int high, int& swaps){

     int mid = (low + high) / 2;
     swap(data.at(low), data.at(mid));
     swaps++;

     int pivot = data.at(low).total_delay();
     int up = low + 1;
     int down = high;


     while (true){
         while (up<=high && data.at(up).total_delay() < pivot) {
             up++;
         }

         while (down > low && data.at(down).total_delay() >= pivot) {
             down--;
         }

         if (up >= down) {
             break;
         }
         swap(data.at(up), data.at(down));
         swaps++;

     }
     swap(data.at(low), data.at(down));
     swaps++;
     return down;
}

void quickSort(vector<Flight>& data,int low, int high, int& swaps){

     if (low < high){
         int pivot = partition(data, low, high, swaps);
         if (pivot > low) {
             quickSort(data,low, pivot -1, swaps);
         }
         if (pivot < high) {
             quickSort(data, pivot + 1, high, swaps);
         }
     }

}