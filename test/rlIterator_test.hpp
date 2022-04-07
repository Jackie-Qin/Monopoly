#ifndef __RLITERATOR_TEST_HPP__
#define __RLITERATOR_TEST_HPP__

#include <gtest/gtest.h>

#include "monopoly/rlIterator.hpp"
#include "monopoly/location.hpp"
#include "monopoly/role.hpp"


TEST(RLIteratorTest, LocationGroupTest) {
    Location* beginning = new Beginning();
    Location* property1 = new Property("property1", green);
    Location* property2 = new Property("property2", orange);

    LocationGroup locationGroup;
    locationGroup.addLocation(beginning);
    locationGroup.addLocation(property1);
    locationGroup.addLocation(property2);

    ASSERT_EQ(locationGroup.size(), 3);
    RLIterator<LocationGroup, Location> rlIterator(&locationGroup);
    ASSERT_TRUE(rlIterator.hasNext());

    EXPECT_EQ(rlIterator.get(), beginning);
    rlIterator.next();
    ASSERT_TRUE(rlIterator.hasNext());

    EXPECT_EQ(rlIterator.get(), property1);
    rlIterator.next();
    ASSERT_TRUE(rlIterator.hasNext());

    EXPECT_EQ(rlIterator.get(), property2);
    rlIterator.next();
    ASSERT_TRUE(rlIterator.hasNext());

}

TEST(RLIteratorTest, LocationGroupCreateIteratorTest) {
    Location* beginning = new Beginning();
    Location* property1 = new Property("property1", green);
    Location* property2 = new Property("property2", orange);

    LocationGroup locationGroup;
    locationGroup.addLocation(beginning);
    locationGroup.addLocation(property1);
    locationGroup.addLocation(property2);

    ASSERT_EQ(locationGroup.size(), 3);
    auto rlIterator = locationGroup.createIterator();
    ASSERT_TRUE(rlIterator->hasNext());

    EXPECT_EQ(rlIterator->get(), beginning);
    rlIterator->next();
    ASSERT_TRUE(rlIterator->hasNext());

    EXPECT_EQ(rlIterator->get(), property1);
    rlIterator->next();
    ASSERT_TRUE(rlIterator->hasNext());


    EXPECT_EQ(rlIterator->get(), property2);
    rlIterator->next();
    ASSERT_TRUE(rlIterator->hasNext());

}

TEST(RLIteratorTest, RoleGroupTest) {
    Role* player1 = new Player(200);
    Role* player2 = new Player(200);
    Role* player3 = new Player(200);

    RoleGroup roleGroup;
    roleGroup.addUser(player1);
    roleGroup.addUser(player2);
    roleGroup.addUser(player3);
    RLIterator<RoleGroup,Role> rlIterator(&roleGroup);
    ASSERT_TRUE(rlIterator.hasNext());

    EXPECT_EQ(rlIterator.get(), player1);
    rlIterator.next();
    ASSERT_TRUE(rlIterator.hasNext());

    EXPECT_EQ(rlIterator.get(), player2);
    rlIterator.next();
    ASSERT_TRUE(rlIterator.hasNext());

    EXPECT_EQ(rlIterator.get(), player3);
    rlIterator.next();
    ASSERT_TRUE(rlIterator.hasNext());

}

TEST(RLIteratorTest, RoleGroupCreateIteratorTest) {
    Role* player1 = new Player(200);
    Role* player2 = new Player(200);
    Role* player3 = new Player(200);

    RoleGroup roleGroup;
    roleGroup.addUser(player1);
    roleGroup.addUser(player2);
    roleGroup.addUser(player3);

    auto rlIterator = roleGroup.createIterator();
    ASSERT_TRUE(rlIterator->hasNext());

    EXPECT_EQ(rlIterator->get(), player1);
    rlIterator->next();
    ASSERT_TRUE(rlIterator->hasNext());

    EXPECT_EQ(rlIterator->get(),player2);
    rlIterator->next();
    ASSERT_TRUE(rlIterator->hasNext());


    EXPECT_EQ(rlIterator->get(), player3);
    rlIterator->next();
    ASSERT_TRUE(rlIterator->hasNext());

}


#endif // __RLITERATOR_TEST_HPP__