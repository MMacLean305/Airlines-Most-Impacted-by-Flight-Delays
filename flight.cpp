#include <iostream>
#include "flight.h"
using namespace std;

string Flight::get_flight_delay(){
    return this->flight_delay;
}
int Flight::get_day_of_week(){
    return this->day_of_week;
}
string Flight::get_airline(){
    return this->airline;
}
bool Flight::get_cancelled(){
    return this->cancelled;
}
bool Flight::get_diverted(){
    return this->diverted;
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
float Flight::get_departure_delay(){
    return departure_delay;
}
