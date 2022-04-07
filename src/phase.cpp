#include <map>

#include "monopoly/phase.hpp"
#include "monopoly/gameManager.hpp"
#include "monopoly/role.hpp"

/**
 * NormalMainPhase
 */

void NormalMainPhase::execute(GameManager* gameManager, Role* player) {
    std::size_t doubles = 0;
    std::size_t steps1, steps2, steps;
    do
    {
        steps1 = gameManager->rollDice();
        steps2 = gameManager->rollDice();
        steps = steps1 + steps2;
        if (steps1 == steps2) {doubles++;}
        if (doubles == 2) {
            gameManager->goJail(player);
            break;
        }
        gameManager->movePlayer(player, steps);

    } while (steps1 == steps2);
    
}    

/**
 * InJailMainPhase
 */

void InJailMainPhase::execute(GameManager* gameManager, Role* player) {
    static std::map<Role*, std::size_t> playerinJailMap;

    if (playerinJailMap[player] == 3) {
        playerinJailMap.erase(player);
    }

    auto it = playerinJailMap.find(player);
    if (it != playerinJailMap.end()){
        playerinJailMap[player]++;
    } else {
        playerinJailMap[player] = 1;
        bool response = gameManager->askForBail(player);
        if (response) { playerinJailMap.erase(player); }
    }
}

/**
 * BankrupcyMainPhase
 */

void BankrupcyMainPhase::execute(GameManager* gameManager, Role* player) {
    // pass
}

/**
 * TradePhase
 */

void TradePhase::execute(GameManager* gameManager, Role* player) {
    // TO-DO
}

