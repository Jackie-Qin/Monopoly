#ifndef __LOCATION_HPP__
#define __LOCATION_HPP__

#include <string>
#include <map>
#include <vector>

class Role;
class GameManager;
class LocationEvent;

#include "monopoly/rlIterator.hpp"
#include "monopoly/locationEvent.hpp"

#define BEGINNING_REWARD 200

enum GroupColor : std::size_t {dark_blue, green, red, orange, yellow, pink, white, brown, light_blue };

class Location {
public:
    /* when a player finally stops on this location, asking the player if buy the property or paying for rent */
    virtual void landOn(Role* player, GameManager* gameManager) = 0;
    /* I think this method can be dropped off */
    virtual bool isOwned() = 0;
    /* get property, utility, railroad names */
    virtual std::string getName() = 0;
    /* when a player lands on or passes the Go space, tiggering this method */
    virtual void trigger(Role* player, GameManager* gameManager) = 0;
    /* return the number of house on this land */
    virtual int getNumHouse() = 0;
};

class Beginning: public Location {
private:
    std::string name;
    LocationEvent* event;
public:
    Beginning();

    virtual bool isOwned();
    virtual std::string getName();
    virtual void trigger(Role *player, GameManager *gameManager);

    virtual void landOn(Role *player, GameManager *gameManager);

    virtual int getNumHouse();
};

class Property: public Location {
private:
    std::string name;
    Role* owner;
    GroupColor color;
    int house;
    int hotel;
    Role* mortgage;
    LocationEvent* event;
public:
    Property(std::string name, GroupColor color);

    virtual void landOn(Role *player,GameManager *gameManager);

    virtual bool isOwned();

    virtual std::string getName();

    virtual void trigger(Role *player, GameManager *gameManager);

    virtual int getNumHouse();

    virtual void buildHouse();

    virtual GroupColor getColor();

    virtual void setOwner(Role* player);

    virtual Role* getOwner();

    virtual void setEvent(LocationEvent* event);

    ~Property();
};

class Special: public Location {
private:
    std::string name;
    LocationEvent* event;
public:
    Special(std::string name);

    virtual void landOn(Role* player, GameManager* gameManager);

    virtual bool isOwned();

    virtual std::string getName();

    virtual void trigger(Role *player, GameManager *gameManager);

    virtual int getNumHouse();
};

class Unity: public Location {
private:
    std::string name;
    Role* owner;
    Role* mortgage;
    LocationEvent* event;
public:
    Unity(std::string name);

    virtual void setOwner(Role* o);

    virtual Role* getOwner();

    virtual void landOn(Role *player,GameManager *gameManager) override;

    virtual bool isOwned() override;

    virtual std::string getName() override;

    virtual void trigger(Role *player, GameManager *gameManager) override;

    virtual int getNumHouse() override;

    virtual void setEvent(LocationEvent* event);

    ~Unity();
};

class Railroad: public Location {
private:
    std::string name;
    Role* owner;
    Role* mortgage;
    LocationEvent* event;

public:
    Railroad(std::string name);

    void setOwner(Role* owner);

    Role* getOwner();

    virtual void landOn(Role *player,GameManager *gameManager) override;

    virtual bool isOwned() override;

    virtual std::string getName() override;

    virtual void trigger(Role *player, GameManager *gameManager) override;

    virtual int getNumHouse() override;

    virtual void setEvent(LocationEvent* event);

    ~Railroad();
};

class LocationGroup: public Location {
protected:
    /* this member should be converted to static */
    static std::map<GroupColor, int> prices;
    std::vector<Location*> properties;
public:
    virtual void landOn(Role *player,GameManager *gameManager) override;

    virtual bool isOwned() override;

    virtual std::string getName() override;

    virtual void trigger(Role *player, GameManager *gameManager) override;

    virtual int getNumHouse() override;

    virtual void addLocation(Location* location);

    virtual void addLocation(std::vector<Location*> locations);

    virtual Location* get(std::size_t index);

    virtual std::size_t size();

    virtual int getPrice(GroupColor color);
    /**
     * Group like classes should be able to generate Iterator,
     * in case of worng usage of RLIterator
     * 
     * object should be delete manually after use
     */
    virtual RLIterator<LocationGroup, Location>* createIterator();
};
#endif // __LOCATION_HPP__