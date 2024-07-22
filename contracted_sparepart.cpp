#include <iostream>

#include "contracted_sparepart.hpp"

double contracted_sparepart::get_total_price() const
{
    return m_price + m_replwage + m_delprice;
}

int contracted_sparepart::get_delivery_time() const
{
    return m_deltime;
}

void contracted_sparepart::output() const
{
   ((const sparepart*)this)->output();
    std::cout << " "
        << m_vendor << " "
        << m_delprice << " "
        << m_deltime;
}

contracted_sparepart::contracted_sparepart(std::string id, std::string name, vehicle vehicle, double price,
        sparepart::condition cond, int replacement_time, double replacement_wage, std::string instructions,
        std::string vendor, double delivery_price, int delivery_time) :
            sparepart(id, name, vehicle, price, cond, replacement_time, replacement_wage, instructions)
            , m_vendor(std::move(vendor))
            , m_delprice(delivery_price)
            , m_deltime(delivery_time)
{
}
