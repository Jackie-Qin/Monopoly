#ifndef __DICE_HPP__
#define __DICE_HPP__

#include <iostream>

class Dice {
private:
    std::size_t sided;
public:
    Dice(std::size_t sided);
    std::size_t roll();
};

#endif // __DICE_HPP__