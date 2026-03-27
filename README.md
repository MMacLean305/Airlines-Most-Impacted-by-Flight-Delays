# Airlines-Most-Impacted-by-Flight-Delays

**Airline Delay Analyzer
Created by: Matthew MacLean and Ashwin Guda**


**Usage Guide:**

-Clone Repository into IDE of choice, preferrably CLion.

-Make sure at least 8mb are allocated to the stack (The CMake should do this already, but the Windows default of 1mb will cause overflow issues)

-If a IDE is used, ensure the "Run in external console" run configuration is enabled

If you'd like to run this code on the full 6 million rows, the data set can be sourced from here https://www.kaggle.com/datasets/bordanova/2023-us-civil-flights-delay-meteo-and-aircraft?resource=download&select=US_flights_2023.csv. 

Utilize the US_flights_2023.csv

**Command Guide:**

        /h : List functions
        /compare_sort : Reprints the sort algorithm comparison information
        /numdelays_airline (airline) : Prints the number of delayed flights from a given airline
        /numdelays_airport (departure airport)  (arrival airport) : Prints the number of delayed flights from a departure airport to arrival airport 
        /numdelays_day (day of week) : Shows the number of delayed flights for a given day of week
        /bw_dates : Prints the 5 dates with most/least delays
        /bw_days : Prints the 5 days with most/least delays
        /bw_airlines : Prints the 5 airlines with most/least delays
        /show10 : Prints the first 10 datapoints of each sorted list
        /show50 : Prints the first 50 datapoints of each sorted list
        /show100 : Prints the first 100 datapoints of each sorted list
        /show500 : Prints the first 500 datapoints of each sorted list
        /show# (number) : Prints the number of datapoints of each sorted list
