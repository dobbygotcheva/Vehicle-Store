#pragma once

#include <string>
#include <array>

class vehicle
{
    std::string m_make;
    std::string m_model;
    int m_year;
    static constexpr std::array<const char*, 3> makes = { "Ford", "Mercedes", "Toyota" };

public:
    void output() const;

    vehicle() = delete;
    vehicle(std::string make, std::string model, int year);
};
