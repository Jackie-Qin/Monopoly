#include <gtest/gtest.h>

#include <cstdlib>
#include <ctime>

#include "location_test.hpp"
#include "rlIterator_test.hpp"
#include "Card_test.hpp"
#include "role_test.hpp"
#include "dice_test.hpp"
#include "gameManager_test.hpp"

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  std::srand(std::time(nullptr));
  return RUN_ALL_TESTS();
}
