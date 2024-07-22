#pragma once

#include "sparepart.hpp"

class available_sparepart : public sparepart
{
    int m_quant;
    std::string m_loc;
    static constexpr const char* curr_loc = "Burgas";

public:
    double get_total_price() const;
    int get_delivery_time() const;
    void output() const;

    available_sparepart() = delete;
    available_sparepart(std::string id, std::string name, vehicle vehicle, double price,
        sparepart::condition cond, int replacement_time, double replacement_wage,
         std::string instructions, int quantity, std::string location);
};
