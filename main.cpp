#include <iostream>
#include <vector>
#include <memory>

#include "vehicle.hpp"
#include "available_sparepart.hpp"
#include "contracted_sparepart.hpp"

int main()
{
    std::vector<std::unique_ptr<vehicle>> vs;
    std::vector<std::unique_ptr<available_sparepart>> as;
    std::vector<std::unique_ptr<contracted_sparepart>> cs;

    vs.emplace_back(std::make_unique<vehicle>("Ford", "Explorer", 1996));
    vs.emplace_back(std::make_unique<vehicle>("Mercedes", "Benz", 2013));
    vs.emplace_back(std::make_unique<vehicle>("Toyota", "Yaris", 2016));

    as.emplace_back(std::make_unique<available_sparepart>("123", "Crank shaft", *vs[0], 1, sparepart::condition::NEW,
                                                          10, 20, "Be careful", 1, "Burgas"));
    as.emplace_back(std::make_unique<available_sparepart>("124", "Cam shaft", *vs[1], 2, sparepart::condition::REFURB,
                                                          30, 25, "Dual-overhead", 5, "Sofia"));
    as.emplace_back(std::make_unique<available_sparepart>("125", "Exhaust", *vs[2], 3, sparepart::condition::REFURB,
                                                          40, 80, "Weld catalyst in place", 1, "Burgas"));

    cs.emplace_back(std::make_unique<contracted_sparepart>("223", "Door hinge", *vs[1], 17, sparepart::condition::NEW,
                                                          5, 40, "Avoid sharp edges", "UltraMaxx", 50, 15));
    cs.emplace_back(std::make_unique<contracted_sparepart>("224", "Steering wheel", *vs[0], 8, sparepart::condition::REFURB,
                                                          17, 25, "Attach to housing", "MegaLo", 52, 18));
    cs.emplace_back(std::make_unique<contracted_sparepart>("225", "Turbo encabulator", *vs[2], 23, sparepart::condition::NEW,
                                                          18, 23, "Tighten to 5 ugga duggas", "NFS Underground Store", 24, 16));

    for(const auto& p : as)
    {
        std::cout << p->name() << " " << p->get_total_price() << '\n';
    }
    std::cout << '\n';
    for(const auto& p : cs)
    {
        std::cout << p->name() << " " << p->get_total_price() << '\n';
    }

    return 0;
}
