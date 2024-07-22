#pragma once

#include "sparepart.hpp"

class contracted_sparepart : public sparepart
{
    std::string m_vendor;
    double m_delprice;
    int m_deltime; // 1 int = 1 day

public:
    double get_total_price() const;
    int get_delivery_time() const;
    void output() const;

    contracted_sparepart() = delete;
    contracted_sparepart(std::string id, std::string name, vehicle vehicle, double price,
        sparepart::condition cond, int replacement_time, double replacement_wage, std::string instructions,
        std::string vendor, double delivery_price, int delivery_time);
};
