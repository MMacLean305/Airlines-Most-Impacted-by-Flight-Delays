#include <iostream>
#include "flight.h"
using namespace std;

//Constructor
Flight(
    std::string flight_date,
    std::string day_of_week,
    std::string airline,
    std::string tail_number,
    std::string dep_airport,
    std::string dep_city,
    std::string dep_time,
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
int total_delay();
void print_all_data();