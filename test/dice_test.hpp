#ifndef __DICE_TEST_HPP__
#define __DICE_TEST_HPP__

#include <gtest/gtest.h>

#include "monopoly/dice.hpp"

TEST(DiceTest, Roll12SidedDice) {
    Dice D(12);
    for (std::size_t i = 0; i < 12; i++)
    {
        EXPECT_LE(D.roll(), 12);
        EXPECT_GE(D.roll(), 1);
    }
    
}

TEST(DiceTest, Roll6SidedDice) {
    Dice D(6);
    for (std::size_t i = 0; i < 12; i++)
    {
        EXPECT_LE(D.roll(), 6);
        EXPECT_GE(D.roll(), 1);
    }
    
}


#endif // __DICE_TEST_HPP__