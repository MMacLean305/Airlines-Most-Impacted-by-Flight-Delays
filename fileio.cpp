#include "fileio.h"
#include <fstream>
using namespace std;

vector<Flight> scrape_data(const std::string& filename){
    ifstream file(filename);
    vector<Flight> flights {};
    string line;
    getline(file, line);
    while(getline(file, line)){
        
    }
}