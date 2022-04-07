//
// Created by KingTiger on 2020/12/10.
//
#include <iostream>
#include <string>
#include <cstdlib>
#include "monopoly/Card.hpp"
#include "monopoly/dice.hpp"
#include "monopoly/gameManager.hpp"
#include "monopoly/location.hpp"
#include "monopoly/locationEvent.hpp"
#include "monopoly/phase.hpp"
#include "monopoly/rlIterator.hpp"
#include "monopoly/role.hpp"



int main(){
    srand(time(0));
    GameManager* gameManager = new GameManager();
    gameManager->init();
    std::cout << "How many players do you have?" << std::endl;
    int numPeople;
    std::cin >> numPeople;
    while(numPeople < 2 || numPeople > 4){
        std::cout << "Invalid number of players. Please enter again." << std::endl;
        std::cin >> numPeople;
    }
    gameManager->setplayer(numPeople);
    gameManager->run();
    return 0;
}
