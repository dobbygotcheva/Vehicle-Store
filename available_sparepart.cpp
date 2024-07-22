#include <iostream>

#include "available_sparepart.hpp"

double available_sparepart::get_total_price() const
{
    return m_quant * ((sparepart*)this)->get_total_price();
}

int available_sparepart::get_delivery_time() const
{
return (m_loc == curr_loc) ? 0 : 1; // 1 - random number.
}

void available_sparepart::output() const
{
    ((const sparepart*)this)->output();
    std::cout << " "
        << m_quant << " "
        << m_loc;
}

available_sparepart::available_sparepart(std::string id, std::string name, vehicle vehicle, double price,
        sparepart::condition cond, int replacement_time, double replacement_wage,
         std::string instructions, int quantity, std::string location) :
        sparepart(id, name, vehicle, price, cond, replacement_time, replacement_wage, instructions)
         , m_quant(quantity)
         , m_loc(std::move(location))
{
}

