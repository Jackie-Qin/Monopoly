#ifndef __LOCATION_TEST_HPP__
#define __LOCATION_TEST_HPP__

#include <gtest/gtest.h>
#include <string>

#include "monopoly/location.hpp"
#include "monopoly/role.hpp"

TEST(BeginningTest, GetNameTest) {
    std::string name("Beginning");
    Location* beginning = new Beginning();
    EXPECT_STREQ(beginning->getName().c_str(), name.c_str());
}

/*
 * Beginning always has a owner
 */
TEST(BeginningTest, IsOwnedTest) {
    Location* beginning = new Beginning();
    EXPECT_TRUE(beginning->isOwned());
}

TEST(BeginningTest, TriggerTest){
   Location* beginning = new Beginning();
   Role* player = new Player(200);
   GameManager* gameManager = new GameManager();

   int currentMoney = player->getMoney();
   beginning->trigger(player, gameManager);

   EXPECT_EQ(BEGINNING_REWARD, player->getMoney() - currentMoney);
}

#endif // __LOCATION_TEST_HPP__