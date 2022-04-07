#ifndef __ROLE_TEST_HPP__
#define __ROLE_TEST_HPP__

#include <gtest/gtest.h>
#include <string>
#include "monopoly/role.hpp"
#include "monopoly/location.hpp"
#include "monopoly/Card.hpp"
#include "monopoly/phase.hpp"


TEST(RoleTest, InformationTest){
    Player* p1 = new Player(500);
    p1->setName("test1");
    Player* p2 = new Player(1000);
    p2->setName("test2");
    GameManager* g = new GameManager();
    EXPECT_EQ(p1->getMoney(), 500);
    EXPECT_EQ(p2->getMoney(), 1000);
    EXPECT_EQ(p1->getName(), "test1");
    EXPECT_EQ(p2->getName(), "test2");
}

TEST(RoleTest, RoleGroupTest) {
    RoleGroup *r = new RoleGroup();
    Player *p1 = new Player(0);
    Player *p2 = new Player(0);
    r->addUser(p1);
    r->addUser(p2);
    EXPECT_EQ(r->get(0), p1);
    EXPECT_EQ(r->get(1), p2);
}
TEST(RoleTest, PhaseTest){
    Player* p = new Player(0);
    Phase* phase1 = new NormalMainPhase();
    p->setPhase(phase1);
    EXPECT_EQ(p->getPhase(), phase1);
    Phase* phase2 = new InJailMainPhase();
    p->setPhase(phase2);
    EXPECT_EQ(p->getPhase(), phase2);
}




#endif