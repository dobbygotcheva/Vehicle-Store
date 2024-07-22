#include <iostream>

#include "sparepart.hpp"

int sparepart::get_warranty() const
{
    return (m_cond == sparepart::condition::NEW)
            ?3*365
            :3*30;
}

double sparepart::get_total_price() const
{
    return m_price + m_repltime*m_replwage;
}

void sparepart::output() const
{
    std::cout
        << m_id << " "
        << m_name << " ";
    m_veh.output();
    std::cout << " "
        << m_price << " "
        << m_repltime << " "
        << m_replwage << " "
        << m_instr;
}

sparepart::sparepart(std::string id, std::string name, vehicle vehicle, double price,
        sparepart::condition cond, int replacement_time, double replacement_wage, std::string instructions) :
        m_id(std::move(id))
        ,m_name(std::move(name))
        ,m_veh(std::move(vehicle))
        ,m_price(price)
        ,m_cond(cond)
        ,m_repltime(replacement_time)
        ,m_replwage(replacement_wage)
        ,m_instr(std::move(instructions))
{
}
