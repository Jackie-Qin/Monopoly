#ifndef __CARD_TEST_HPP__
#define __CARD_TEST_HPP__

#include <gtest/gtest.h>
#include <string>
#include "monopoly/role.hpp"
#include "monopoly/location.hpp"
#include "monopoly/Card.hpp"

TEST(CardTest, RewardTest){
    Player* p = new Player(500);
    GameManager* g = new GameManager();
    rewardCard* reward = new rewardCard();
    reward->run(g, p);
    EXPECT_EQ(p->getMoney(), 700);
}

TEST(CardTest, PunishmentTest){
    Player* p = new Player(500);
    GameManager* g = new GameManager();
    punishmentCard* punish = new punishmentCard();
    punish->run(g, p);
    EXPECT_EQ(p->getMoney(), 300);
}



#endif