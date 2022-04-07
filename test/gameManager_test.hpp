
#ifndef __GAME_MANAGER_TEST_HPP__
#define __GAME_MANAGER_TEST_HPP__ 
#include <gtest/gtest.h>
#include "monopoly/gameManager.hpp"
#include <string>
#include<iomanip>
#include "cstdlib"
#include <cstring>

TEST(GameManagerTest,InitLocationNameZERO){
    GameManager *gameManager=new GameManager();
    gameManager->init();
    EXPECT_EQ(gameManager->getLocationName(0),"Beginning");
}

TEST(GameManagerTest,InitLocationNameTHREE){
    GameManager *gameManager=new GameManager();
    gameManager->init();
    EXPECT_EQ(gameManager->getLocationName(3),"WHITECHAPEL ROAD");
}


TEST(GameManagerTest, RollTest) {
    GameManager game_manager;
    for (std::size_t i = 0; i < 12; i++)
    {
        EXPECT_LE(game_manager.rollDice(), 6);
        EXPECT_GE(game_manager.rollDice(), 1);
    }
}
//TEST(GameManagerTest,MovePlayer){
//    GameManager *gameManager=new GameManager();
//    gameManager->init();
//    gameManager->setplayer(4);
//    gameManager->movePlayer(gameManager->getRoleItor()->get(),3);
//    EXPECT_EQ(gameManager->getRoleLocationMap().at(gameManager->getRoleItor()->get()).get()->getName(),"WHITECHAPEL ROAD");
//}
TEST(GameManagerTest,DrawCard){
    GameManager *gameManager=new GameManager();
    gameManager->init();
    Card* rewardcard = new rewardCard;
    Card* punishcard = new punishmentCard;
    Card* testcard=gameManager->drawCard();
    EXPECT_TRUE(std::strcmp(rewardcard->getName().c_str(),testcard->getName().c_str())||std::strcmp(punishcard->getName().c_str(),testcard->getName().c_str()));
}
TEST(GameManagerTest,PayForMoney){
    GameManager* gameManager=new GameManager;
    gameManager->init();
    gameManager->setplayer(2);
    Role *player1= gameManager->getRoleItor()->get();
    gameManager->getRoleItor()->next();
    Role* player2= gameManager->getRoleItor()->get();
    gameManager->payForRent(gameManager->getLocation(2),player1,player2,brown);
    EXPECT_EQ(player1->getMoney(),1440);
}

#endif //MONOPOLY_LIB_GAMEMANAGER_TEST_HPP
