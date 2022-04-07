#include "monopoly/Card.hpp"
#include "monopoly/gameManager.hpp"

void cardGroup::addCard(Card* c){
    cardPool.push_back(c);
}

Card* cardGroup::getCard(int index){
    return cardPool[index];
}

void rewardCard::run(GameManager* g, Role* p){
    g->transferMoney(nullptr, p, 200);
}

std::string rewardCard::getName() {
    return "RewardCard";
}

void punishmentCard::run(GameManager* g, Role* p){
    g->transferMoney(nullptr, p, -200);
}

std::string punishmentCard::getName() {
    return "PunishmentCard";
}
