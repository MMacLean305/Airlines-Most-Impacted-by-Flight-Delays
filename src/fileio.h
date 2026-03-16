#pragma once
#include <iostream>
#include <vector>
#include "flight.h"
#include <string>

std::vector<Flight> scrape_data(const std::string& filename);
