#include <iostream>

class Flight{
    private:
        std::string flight_delay;
        int day_of_week;
        std::string airline;
        std::string tail_number;
        bool cancelled;
        bool diverted;
        std::string departure_airport;
        std::string departure_city_name;
        std::string departure_time_label;
        float departure_delay;
    public:
        std::string get_flight_delay(){
            return this->flight_delay;
        }
        int get_day_of_week(){
            return this->day_of_week;
        }
        std::string get_airline(){
            return this->airline;
        }
        bool get_cancelled(){
            return this->cancelled;
        }
        bool get_diverted(){
            return this->diverted;
        }
        std::string get_departure_airport(){
            return this->departure_airport;
        }
        std::string get_departure_city_name(){
            return this->departure_city_name;
        }
        std::string get_departure_time_label(){
            return this->departure_time_label;
        }
        float get_departure_delay(){
            return departure_delay;
        }
    
};