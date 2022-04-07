#include "monopoly/dice.hpp"

#include <cstdlib>

Dice::Dice(std::size_t sided)
    :sided(sided) {}

std::size_t Dice::roll() {
    int temp = std::rand() % this->sided + 1;
    std::cout << "Dice number is " << temp << "." << std::endl;
    return temp;
}