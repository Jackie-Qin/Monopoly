#include "monopoly/locationEvent.hpp"
#include "monopoly/gameManager.hpp"
#include "monopoly/role.hpp"
#include "monopoly/location.hpp"
#include "monopoly/Card.hpp"

void EmptyEvent::happen(GameManager* gameManager, Role* player) {

}

void NoMansLand::happen(GameManager* gameManager, Role* player) {
    bool response = gameManager->askForBuy(player);

    /* decided to buy */
    if (response) {
        auto it = gameManager->getPlayerPosition(player);
        Property* property = (Property*) it->get();
        property->setOwner(player);
        LocationEvent* event = new MansLand();
        property->setEvent(event);
        
    }
}

void MansLand::happen(GameManager* gameManager, Role* player) {
    auto it = gameManager->getPlayerPosition(player);
    Property* property = (Property*) it->get();
    /* is the owner */
    if (property->getOwner() == player) {
        if (property->getNumHouse() < 5) {
            bool response = gameManager->askForBuild(player);
            if (response) {
                property->buildHouse();
                gameManager->buildHouse();
                if (property->getNumHouse() == 5) {
                    gameManager->buildHotel();
                }
            }
            
        }
        
    } else { // isn't the owner
        gameManager->payForRent(property,player, property->getOwner(), property->getColor());
    }
}

void SpecialEvent::happen(GameManager* gameManager, Role* player) {
    auto card = gameManager->drawCard();
    card->run(gameManager, player);
}

void BeginningEvent::happen(GameManager* gameManager, Role* player) {
    gameManager->transferMoney(nullptr, player, BEGINNING_REWARD);
}

void NoMansUnity::happen(GameManager* gameManager, Role* player) {

    bool response = gameManager->askForBuy(player);

    /* decided to buy */
    if (response) {
        auto it = gameManager->getPlayerPosition(player);
        Unity* unity = (Unity*) it->get();
        unity->setOwner(player);
        unity->setEvent(new MansUnity());
    }
}

void MansUnity::happen(GameManager* gameManager, Role* player) {
    auto it = gameManager->getPlayerPosition(player);
    Unity* unity = (Unity*) it->get();
    /* is the owner */
    if (unity->getOwner() == player) {
        
    } else { // isn't the owner
        gameManager->transferMoney(player, unity->getOwner(), 200);
    }
}

void NoMansRailroad::happen(GameManager* gameManager, Role* player) {
    bool response = gameManager->askForBuy(player);

    /* decided to buy */
    if (response) {
        auto it = gameManager->getPlayerPosition(player);
        Railroad* railroad = (Railroad*) it->get();
        railroad->setOwner(player);
        railroad->setEvent(new MansRailroad());
    }

}

void MansRailroad::happen(GameManager* gameManager, Role* player) {
    auto it = gameManager->getPlayerPosition(player);
    Railroad* railroad = (Railroad*) it->get();

    /* is the owner */
    if (railroad->getOwner() == player) {
        
    } else { // isn't the owner
        gameManager->transferMoney(player, railroad->getOwner(), 200);
    } 
}