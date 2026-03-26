#pragma once
#include <iostream>
#include <utility>


class Flight{
    private:
        //Basic info
        std::string flight_date;
        int day_of_week;
        std::string airline;
        std::string tail_number;
        std::string departure_airport;
        std::string departure_city_name;
        std::string departure_time_label;
        std::string arrival_airport;
        std::string arrival_city_name;
        std::string distance_type;
        std::string flight_dur;

        //Aircraft info
        std::string manufacturer; 
        std::string model;
        int aircraft_age;
        
        //Delay info
        bool dep_delay_tag;
        std::string dep_delay_type;
        bool arr_delay_tag;
        std::string arr_delay_type;
        int dep_delay;
        int arr_delay;
        
        //Delay type
        bool delay_carrier;
        bool delay_weather;
        bool delay_nas;
        bool delay_security;
        bool delay_last_aircraft;

    public:
        //Constructor
        Flight(
            std::string flight_date,
            std::string day_of_week,
            std::string airline,
            std::string tail_number,
            std::string dep_airport,
            std::string dep_city,
            std::string dep_time,
            std::string dep_delay,
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
        );
        
        //Getter functions
        std::string get_flight_date();
        int get_day_of_week();
        std::string get_airline();
        std::string get_tail_number();
        std::string get_departure_airport();
        std::string get_departure_city_name();
        std::string get_departure_time_label();
        std::string get_arrival_airport();
        std::string get_arrival_city_name();
        std::string get_distance_type();
        std::string get_flight_dur();
        std::string get_manufacturer(); 
        std::string get_model();
        int get_aircraft_age();
        bool get_dep_delay_tag();
        std::string get_dep_delay_type();
        bool get_arr_delay_tag();
        std::string get_arr_delay_type();
        int get_dep_delay();
        int get_arr_delay();
        bool get_delay_carrier();
        bool get_delay_weather();
        bool get_delay_nas();
        bool get_delay_security();
        bool get_delay_last_aircraft();



        //Other functions
        int total_delay();
        void print_all_data();
        void print_data_clean();
        bool any_delay();


};

//comparison functions
//https://www.geeksforgeeks.org/cpp/sorting-a-map-by-value-in-c-stl/

template<typename T>
bool compareDelay(const std::pair<T, int>& a, const std::pair<T, int>& b){
    return a.second > b.second;
};