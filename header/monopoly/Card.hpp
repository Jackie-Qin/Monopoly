#ifndef MONOPOLY_CARD_HPP
#define MONOPOLY_CARD_HPP
#include <string>
#include <set>
#include <vector>
#include "monopoly/gameManager.hpp"

class Card{
public:
    virtual void run(GameManager* g, Role* p) = 0;
    virtual std::string getName()=0;
};


class cardGroup : public Card{
private:
    std::vector<Card*> cardPool;
public:
    void run(GameManager* g, Role* p){ return; }
    void addCard(Card* c);
    Card* getCard(int index);
    virtual std::string getName() override {};
};


class rewardCard : public Card{
public:
    rewardCard(){};
    virtual std::string getName();
    void run(GameManager* g, Role* p);
};

class punishmentCard : public Card{
public:
    punishmentCard(){};
    virtual std::string getName();
    void run(GameManager* g, Role* p);
};

//class goJailCard : public Card{
//public:
//    goJailCard(){};
//    virtual void run(GameManager g, Role* p);
//};



#endif //MONOPOLY_CARD_HPP