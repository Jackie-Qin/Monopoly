#ifndef __GAME_MANAGER_HPP__
#define __GAME_MANAGER_HPP__

class Card;
class LocationGroup;
class Location;
class Role;

#include <string>
#include <vector>
#include <map>
#include "rlIterator.hpp"

#include "monopoly/dice.hpp"
#include "monopoly/location.hpp"

enum GroupColor: std::size_t;

class Role;
class RoleGroup;
class Location;
class LocationGroup;
class Player;
class Phase;
class cardGroup;

class GameManager {
private:
    LocationGroup* locationGroup;
    std::vector<Location*> locations;
    RLIterator <LocationGroup, Location>* locationItor;
    RLIterator <RoleGroup, Role>* roleItor;
    std::map<Role*,RLIterator<LocationGroup,Location>> PlayerLocationMap;
    RoleGroup* roleGroup;
    Dice* dice;
    Phase* phase;
    cardGroup* cardgroup;
    Role* bank;
    int playernum;
    int round=0;
public:
    GameManager();
    void init();
    void setplayer(int playernum);
    void run();
    void movePlayer(Role* player, int steps);
    void transferMoney(Role* giver, Role* receiver, int amount);
    virtual std::size_t rollDice();
    /* need to be implemented */
    virtual void goJail(Role* player);
    virtual void payForRent(Location* property,Role* payer, Role* receiver, GroupColor color);
    virtual Card* drawCard();
    virtual void buildHouse();
    virtual void buildHotel();
    /* yes = true, no = false */
    virtual bool askForBail(Role* player);

    //TODO price should be various to different colors

    virtual bool askForBuy(Role* player);
    virtual bool askForBuild(Role* player);
    virtual bool endGame();
    virtual RLIterator<LocationGroup, Location>* getPlayerPosition(Role* player);
    std::string getLocationName(int index); //this functin is juct for test
    RLIterator <RoleGroup, Role>* getRoleItor();//this functin is juct for test
    std::map<Role*,RLIterator<LocationGroup,Location>> getRoleLocationMap();//this functin is juct for test
    Location* getLocation(int index);
    ~GameManager();
};

#endif // __GAME_MANAGER_HPP__