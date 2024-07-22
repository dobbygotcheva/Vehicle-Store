#pragma once

#include "vehicle.hpp"

#include <string>

class sparepart
{
public:
    enum class condition : uint8_t { NEW, REFURB };

protected:
    std::string m_id;
    std::string m_name;
    vehicle m_veh;
    double m_price;
    condition m_cond;
    int m_repltime;
    double m_replwage;
    std::string m_instr;

public:
    int get_warranty() const; // 1 int = day
    double get_total_price() const;
    const std::string& name() const { return m_name; }
    void output() const;

    sparepart() = delete;
    sparepart(std::string id, std::string name, vehicle vehicle, double price,
        sparepart::condition cond, int replacement_time, double replacement_wage, std::string instructions);
};

