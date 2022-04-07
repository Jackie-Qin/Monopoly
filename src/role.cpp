#include "monopoly/role.hpp"

void RoleGroup::addUser(Role* r){
    rolePool.push_back(r);
}

Role* RoleGroup::get(std::size_t index){
    return this->rolePool.at(index);
}

RLIterator<RoleGroup, Role> *RoleGroup::createIterator() {
    return new RLIterator<RoleGroup, Role>(this);
}

std::size_t RoleGroup::size() {
    return this->rolePool.size();
}


Player::Player(int amount){
    money = amount;
    inJail = false;
}

void Player::getInJail(){
    inJail  = true;
}

void Player::getOutJail(){
    inJail = false;
}

void Player::setName(std::string s){
    this->name = s;
}

std::string Player::getName(){
    return this->name;
}

std::string Player::showMoney(){
    return std::to_string(this->money);
}

int Player::getMoney(){
    return this->money;
}

/* amount can be a positive or negative number */
void Player::addMoney(int amount){
    this->money += amount;
}

void Player::addProperty(LocationGroup* l){
    this->property.insert(l);
}

void Player::deleteProperty(LocationGroup* l){
    this->property.erase(l);
}

void Player::setPhase(Phase *p) {
    this->phase = p;
}

Phase* Player::getPhase() {
    return this->phase;
}

std::string Bank::showMoney(){
    return std::to_string(this->money);
}

int Bank::getMoney(){
    return this->money;
}

/* amount can be a positive or negative number */
void Bank::addMoney(int amount){
    this->money += amount;
}

void Bank::addProperty(LocationGroup* l){
    this->property.insert(l);
}

void Bank::deleteProperty(LocationGroup* l){
    this->property.erase(l);
}

void Bank::addHotel(int a){
    this->hotel += a;
}

void Bank::setPhase(Phase *p) {
    this->phase = p;
}

Phase* Bank::getPhase() {
    return this->phase;
}

void Bank::addHouse(int a) {
    this->house += a;
}
