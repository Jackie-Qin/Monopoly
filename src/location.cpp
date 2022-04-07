#include "monopoly/location.hpp"
#include "monopoly/gameManager.hpp"
#include "monopoly/role.hpp"
#include "monopoly/rlIterator.hpp"
#include "monopoly/locationEvent.hpp"

/**
 * Beginning
 */


bool Beginning::isOwned() {
    return true;
}

std::string Beginning::getName() {
    return name;
}


int Beginning::getNumHouse() {
    return 0;
}

void Beginning::landOn(Role *player, GameManager *gameManager) {
    this->trigger(player, gameManager);
}

void Beginning::trigger(Role *player, GameManager *gameManager) {
    this->event->happen(gameManager, player);
}

Beginning::Beginning() {
    this->name = "Beginning";
    this->event = new BeginningEvent();
}

/**
 * Property
 */

Property::Property(std::string name, GroupColor color)
    :name(name), color(color) {
    this->event = new NoMansLand();
    this->house = 0;
    this->hotel = 0;
};

void Property::landOn(Role *player, GameManager *gameManager) {
    this->event->happen(gameManager, player);
}

bool Property::isOwned() {
    return false;
}

std::string Property::getName() {
    return name;
}

void Property::trigger(Role *player, GameManager *gameManager) {

}

int Property::getNumHouse() {
    return (this->hotel*5 + this->house);
}

GroupColor Property::getColor() {
    return this->color;
}

void Property::buildHouse() {
    this->house++;
    if (this->house == 5) {
        this->house = 0;
        this->hotel = 1;
    }
}

void Property::setOwner(Role *player) {
    this->owner = player;
}

Role* Property::getOwner() {
    return this->owner;
}

void Property::setEvent(LocationEvent* event) {
    delete this->event;
    this->event = event;
}

Property::~Property() {
    delete this->event;
}

/**
 * Special
 */

Special::Special(std::string name) {
    this->name = name;
    this->event = new SpecialEvent();
}

void Special::landOn(Role* player, GameManager* gameManager) {
    this->event->happen(gameManager, player);
}

bool Special::isOwned() {
    return true;
}

std::string Special::getName() {
    return this->name;
}

void Special::trigger(Role *player, GameManager* gameManager) {

}

int Special::getNumHouse() {
    return 0;
}

/**
 * Unity
 */

Unity::Unity(std::string name)
    :name(name) {
    this->event = new NoMansUnity();
}

void Unity::setOwner(Role *player) {
    this->owner = player;
}

Role* Unity::getOwner() {
    return this->owner;
}

void Unity::landOn(Role *player, GameManager* gameManager) {
    this->event->happen(gameManager, player);
}

bool Unity::isOwned() {
    return owner == nullptr? true : false;
}

std::string Unity::getName() {
    return this->name;
}

void Unity::trigger(Role *player, GameManager* gameManager) {
    
}

int Unity::getNumHouse() {
    return 0;
}

void Unity::setEvent(LocationEvent* event) {
    delete this->event;
    this->event = event;
}

Unity::~Unity() {
    delete this->event;
}

/**
 * Railroad
 */

Railroad::Railroad(std::string name)
    :name(name) {

    this->event = new NoMansRailroad();
}

void Railroad::setOwner(Role *player) {
    this->owner = player;
}

Role* Railroad::getOwner() {
    return this->owner;
}

void Railroad::landOn(Role *player, GameManager* gameManager) {
    // TO-TO
}

bool Railroad::isOwned() {
    return owner == nullptr? true : false;
}

std::string Railroad::getName() {
    return this->name;
}

void Railroad::trigger(Role *player, GameManager* gameManager) {
    // TO-DO
}

int Railroad::getNumHouse() {
    return 0;
}

void Railroad::setEvent(LocationEvent* event) {
    delete this->event;
    this->event = event;
}

Railroad::~Railroad() {
    delete this->event;
}

/**
 * LocationGroup
 */

void LocationGroup::landOn(Role *player, GameManager* gameManager) {
    // TO-DO
}

bool LocationGroup::isOwned() {
    return true;
}

std::string LocationGroup::getName() {
    return "LocationGroup";
}

void LocationGroup::trigger(Role *player, GameManager* gameManager) {
    // TO-DO
}

int LocationGroup::getNumHouse() {
    return 0;
}

void LocationGroup::addLocation(Location *location) {
    properties.push_back(location);
}

void LocationGroup::addLocation(std::vector<Location*> locations) {
    properties.insert(properties.begin(), locations.begin(), locations.end());
}

Location* LocationGroup::get(std::size_t index) {
    return this->properties.at(index);
}

std::size_t LocationGroup::size() {
    return this->properties.size();
}

RLIterator<LocationGroup, Location>* LocationGroup::createIterator() {
    return new RLIterator<LocationGroup, Location>(this);
}

int LocationGroup::getPrice(GroupColor color) {
    return prices.at(color);
}
