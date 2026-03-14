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
        //Getter functions
        std::string get_flight_delay();
        int get_day_of_week();
        std::string get_airline();
        bool get_cancelled();
        bool get_diverted();
        std::string get_departure_airport();
        std::string get_departure_city_name();
        std::string get_departure_time_label();
        float get_departure_delay();
};