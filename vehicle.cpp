#include <algorithm>
#include <stdexcept>

#include <iostream>

#include "vehicle.hpp"

void vehicle::output() const
{
        std::cout << m_make << " " << m_model << " " << m_year;
}

vehicle::vehicle(std::string make, std::string model, int year) :
    m_make(std::move(make))
    ,m_model(std::move(model))
    ,m_year(year)
{
    if(year < 1950 || year > 2030)
    {
        throw std::invalid_argument("Invalid year");
    }
    if(makes.end() == std::find_if(makes.begin(), makes.end(),
        [&](const char* valid_make){ return m_make == valid_make; }))
    {
        throw std::invalid_argument("Invalid make");
    }
}
