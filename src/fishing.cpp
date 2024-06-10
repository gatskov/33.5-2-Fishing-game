#include "fishing.h"
#include <stdexcept>
#include <random>


int Fishing::random(int a, int b)
{
    std::random_device rd;
    std::mt19937 ran(rd());
    std::uniform_int_distribution<> gen_mt(a, b);
    return  gen_mt(ran);
}

Fishing::Fishing()
{
    constexpr auto size_pond = sizeof(_pond)/sizeof(_pond[0]);

    for(std::size_t i = 0; i < size_pond; ++i)
    {
        _pond[i] = Items::EMPTY;
    }

    _pond[random(0, size_pond - 1)] = Items::FISH;

    int count_pond = 0;

    while(count_pond != _size_boot)
    {
        const auto rand = random(0, size_pond - 1);
        if(Items::EMPTY == _pond[rand])
        {
            _pond[rand] = Items::BOOT;
            ++count_pond;
        }
    }

}

void Fishing::catchFish(std::size_t pond) const
{
    constexpr auto size_pond = sizeof(_pond)/sizeof(_pond[0]);
    if(pond >= size_pond)
        throw std::out_of_range("Error: fishing sector must be 0 to 8");

    if(_pond[pond] == Items::FISH)
        throw exception_fish("\t--Good job, you caught a fish");

    if(_pond[pond] == Items::BOOT)
        throw exception_boot("\t--Ha ha, you caught the boot");

    if(_pond[pond] == Items::EMPTY)
    {
        ++_col_fishing;
        throw std::runtime_error("\t--There are no fish here, try again");
    }


}