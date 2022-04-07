#ifndef __LOCATION_EVENT_HPP__
#define __LOCATION_EVENT_HPP__

#include "monopoly/gameManager.hpp"
#include "monopoly/role.hpp"

class LocationEvent {
public:
    virtual void happen(GameManager* gameManager, Role* player) = 0;
};

class EmptyEvent: public LocationEvent {

public:
    virtual void happen(GameManager* gameManager, Role* player) override;
};

class NoMansLand: public LocationEvent {
public:
    virtual void happen(GameManager* gameManager, Role* player) override;
};

class MansLand: public LocationEvent {
public:
    virtual void happen(GameManager* gameManager,Role* player) override;
};

class SpecialEvent: public LocationEvent {
public:
    virtual void happen(GameManager* gameManager, Role* player) override;
};

class BeginningEvent: public LocationEvent {
public:
    virtual void happen(GameManager* gameManager, Role* player) override;
};

class NoMansUnity: public LocationEvent {
public:
    virtual void happen(GameManager* gameManager, Role* player) override;
};

class MansUnity: public LocationEvent {
public:
    virtual void happen(GameManager* gameManager, Role* player) override;
};

class NoMansRailroad: public LocationEvent {
public:
    virtual void happen(GameManager* gameManager, Role* player) override;
};

class MansRailroad: public LocationEvent {
public:
    virtual void happen(GameManager* gameManager, Role* player) override;
};

#endif // __LOCATION_EVENT_HPP__