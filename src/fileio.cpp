#include "fileio.h"
#include <fstream>
#include <sstream>
using namespace std;

vector<Flight> scrape_data(const std::string& filename){
    ifstream file(filename);
    vector<Flight> flights {};
    string line;
    getline(file, line);
    while(getline(file, line)){
        stringstream raw(line);
        string flight_date;
        string day_of_week;
        string airline;
        string tail_number;
        string dep_airport;
        string dep_city;
        string dep_time;
        string dep_delay_tag;
        string dep_delay_type;
        string arr_airport;
        string arr_city;
        string arr_delay;
        string arr_delay_type;
        string flight_dur;
        string distance_type;
        string delay_carrier;
        string delay_weather;
        string delay_nas;
        string delay_security;
        string delay_last_aircraft;
        string manufacturer; 
        string model;
        string aircraft_age;

        getline(raw, flight_date, ',');
        getline(raw, day_of_week, ',');
        getline(raw, airline, ',');
        getline(raw, tail_number, ',');
        getline(raw, dep_airport, ',');
        getline(raw, dep_city, ',');
        getline(raw, dep_time, ',');
        getline(raw, dep_delay_tag, ',');
        getline(raw, dep_delay_type, ',');
        getline(raw, arr_airport, ',');
        getline(raw, arr_city, ',');
        getline(raw, arr_delay, ',');
        getline(raw, arr_delay_type, ',');
        getline(raw, flight_dur, ',');
        getline(raw, distance_type, ',');
        getline(raw, delay_carrier, ',');
        getline(raw, delay_weather, ',');
        getline(raw, delay_nas, ',');
        getline(raw, delay_security, ',');
        getline(raw, delay_last_aircraft, ',');
        getline(raw, manufacturer, ',');
        getline(raw, model, ',');
        getline(raw, aircraft_age, ',');

    }
}