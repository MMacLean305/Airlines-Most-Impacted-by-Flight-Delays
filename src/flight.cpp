#include <iostream>
#include "flight.h"
using namespace std;

//Constructor
Flight::Flight(
    string flight_date,
    string day_of_week,
    std::string airline,
    std::string tail_number,
    std::string dep_airport,
    std::string dep_city,
    std::string dep_time,
    string dep_delay,
    std::string dep_delay_tag,
    std::string dep_delay_type,
    std::string arr_airport,
    std::string arr_city,
    std::string arr_delay,
    std::string arr_delay_type,
    std::string flight_dur,
    std::string distance_type,
    std::string delay_carrier,
    std::string delay_weather,
    std::string delay_nas,
    std::string delay_security,
    std::string delay_last_aircraft,
    std::string manufacturer,
    std::string model,
    std::string aircraft_age
){
    this->flight_date = flight_date;
    this->day_of_week = stoi(day_of_week);
    this->airline = airline;
    this->tail_number = tail_number;
    this->departure_airport = dep_airport;
    this->departure_city_name = dep_city;
    this->departure_time_label = dep_time;
    this->arrival_airport = arr_airport;
    this->arrival_city_name = arr_city;
    this->flight_dur = flight_dur;
    this->distance_type = distance_type;
    this->manufacturer = manufacturer;
    this->model = model;
    this->aircraft_age = stoi(aircraft_age);
    
    if(dep_delay_tag[0] == '1'){
        this->dep_delay_tag = true;
    }else{
        this->dep_delay_tag = false;
    }

    this->dep_delay_type = dep_delay_type;
    this->arr_delay_type = arr_delay_type;
    this->dep_delay = stoi(dep_delay);
    this->arr_delay = stoi(arr_delay); 
    if(this->arr_delay != 0){
        this->arr_delay_tag = true;
    }
    else{
        this->arr_delay_tag = false;
    }

    if(delay_carrier[0] == '1'){
        this->delay_carrier = true;
    }
    else{
        this->delay_carrier = false;
    }
    if(delay_weather[0] == '1'){
        this->delay_weather = true;
    }
    else{
        this->delay_weather = false;
    }

    if(delay_nas[0] = '1'){
        this->delay_nas = true;
    }else{
        this->delay_nas = false;
    }

    if(delay_security[0] = '1'){
        this->delay_security = true;
    }else{
        this->delay_security = false;
    }

    if(delay_last_aircraft[0] = '1'){
        this->delay_last_aircraft = true;
    }else{
        this->delay_last_aircraft = false;
    }
}

//Getter functions
string Flight::get_flight_date(){
    return this->flight_date;
}
int Flight::get_day_of_week(){
    return this->day_of_week;
}
string Flight::get_airline(){
    return this->airline;
}
string Flight::get_tail_number(){
    return this->tail_number;
}
string Flight::get_departure_airport(){
    return this->departure_airport;
}
string Flight::get_departure_city_name(){
    return this->departure_city_name;
}
string Flight::get_departure_time_label(){
    return this->departure_time_label;
}
string Flight::get_arrival_airport(){
    return this->arrival_airport;
}
string Flight::get_arrival_city_name(){
    return this->arrival_city_name;
}
string Flight::get_distance_type(){
    return this->distance_type;
}
string Flight::get_flight_dur(){
    return this->flight_dur;
}
string Flight::get_manufacturer(){
    return this->manufacturer;
}
string Flight::get_model(){
    return this->model;
}
int Flight::get_aircraft_age(){
    return this->aircraft_age;
}
bool Flight::get_dep_delay_tag(){
    return this->dep_delay_tag;
}
string Flight::get_dep_delay_type(){
    return this->dep_delay_type;
}
bool Flight::get_arr_delay_tag(){
    return this->arr_delay_tag;
}
string Flight::get_arr_delay_type(){
    return this->arr_delay_type;
}
int Flight::get_dep_delay(){
    return this->dep_delay;
}
int Flight::get_arr_delay(){
    return this->arr_delay;
}
bool Flight::get_delay_carrier(){
    return this->delay_carrier;
}
bool Flight::get_delay_weather(){
    return this->delay_weather;
}
bool Flight::get_delay_nas(){
    return this->delay_nas;
}
bool Flight::get_delay_security(){
    return this->delay_security;
}
bool Flight::get_delay_last_aircraft(){
    return this->delay_last_aircraft;
}

//Other functions
int Flight::total_delay(){
    return std::max(0, dep_delay) + std::max(0, arr_delay);
}
void Flight::print_all_data(){
    cout << "Work in progress";
}
void Flight::print_data_clean(){
    cout << "Work in progress";
}