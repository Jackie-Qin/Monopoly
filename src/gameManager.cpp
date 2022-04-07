#include "monopoly/role.hpp"
#include "monopoly/gameManager.hpp"
#include <string>
#include <map>
#include "monopoly/dice.hpp"
#include "monopoly/Card.hpp"
#include "monopoly/location.hpp"
#include <cmath>

/*initial LocationGroup prices*/
std::map<GroupColor, int> initail_map(){
    std::map<GroupColor, int> temp;
    temp[dark_blue]=400;
    temp[green]=300;
    temp[red]=220;
    temp[orange]=180;
    temp[yellow]=260;
    temp[pink]=140;
    temp[brown]=60;
    temp[light_blue]=100;
    return temp;
}
std::map<GroupColor ,int> LocationGroup::prices(initail_map());

GameManager::GameManager() {
    this->dice = new Dice(6);
}

void GameManager::init() {
    /*initial locationGroup*/
    locationGroup=new LocationGroup;
    locations.push_back(new Beginning);
    locations.push_back(new Property("OLD KENT STREET",brown));
    locations.push_back(new Special("COMMUNITY CHEST"));
    locations.push_back(new Property("WHITECHAPEL ROAD",brown));
    locations.push_back(new Special("INCOME TAX"));
    locations.push_back(new Railroad("KING CROSS STATION"));
    locations.push_back(new Property("THE ANGEL. ISLINGTON",light_blue));
    locations.push_back(new Special("CHANCE"));
    locations.push_back(new Property("EUSTON ROAD",light_blue));
    locations.push_back(new Property("PENTONVILLE ROAD",light_blue));
    locations.push_back(new Special("JUST VISITING"));
    locations.push_back(new Property("PULL MALL",pink));
    locations.push_back(new Unity("ELECTRIC COMPANY"));
    locations.push_back(new Property("WHITEHALL",pink));
    locations.push_back(new Property("NORTHUMRL'D AVENUE",pink));
    locations.push_back(new Railroad("MARYLEBONE STATION"));
    locations.push_back(new Property("BOW STREET",orange));
    locations.push_back(new Special("COMMUNITY CHEST"));
    locations.push_back(new Property("MARYLBBOROUGH STREET",orange));
    locations.push_back(new Property("VINE STREET",orange));
    locations.push_back(new Special("FREE PARKING"));
    locations.push_back(new Property("STRAND",red));
    locations.push_back(new Special("CHANCE"));
    locations.push_back(new Property("FLEET STREET",red));
    locations.push_back(new Property("TRAFALGAR SQUARE",red));
    locations.push_back(new Railroad("FENCHURCH ST. STATION"));
    locations.push_back(new Property("LEICESTER SQUARE",yellow));
    locations.push_back(new Property("COVENTRY STREET",red));
    locations.push_back(new Special("WARTER WORKS"));
    locations.push_back(new Property("PICCADILLY",yellow));
    locations.push_back(new Special("GO TO JAIL"));
    locations.push_back(new Property("REGENT STREET",green));
    locations.push_back(new Property("OXFORD STREET",green));
    locations.push_back(new Special("COMMUNITY CHEST"));
    locations.push_back(new Property("BOND STREET",green));
    locations.push_back(new Railroad("LIVERPOOL ST. STATION"));
    locations.push_back(new Special("CHANCE"));
    locations.push_back(new Property("PARK LANE",dark_blue));
    locations.push_back(new Special("SUPER TAX"));
    locations.push_back(new Property("MAYFAIR",dark_blue));
    locationGroup->addLocation(locations);
    locationItor=locationGroup->createIterator();
    /*initial CardGroup*/
    bank = new Bank;
    cardgroup=new cardGroup;
    auto* rewardcard=new rewardCard();
    cardgroup->addCard(rewardcard);
    auto* punishmentcard=new punishmentCard;
    cardgroup->addCard(punishmentcard);
    this->phase=new NormalMainPhase();
    roleGroup=new RoleGroup;
}

void GameManager::setplayer(int playernum) {
    this->playernum=playernum;
    for (int i = 0; i <playernum ; ++i) {
        auto* player=new Player(1500);
        player->setName("Player"+std::to_string(i+1));
        player->setPhase(new NormalMainPhase);
        roleGroup->addUser(player);
        RLIterator<LocationGroup, Location> rlIterator(locationGroup);
        PlayerLocationMap.insert({player,rlIterator});
    }
    roleGroup->addUser(bank);
    roleItor=roleGroup->createIterator();
}


void GameManager::movePlayer(Role* player, int steps) {
    RLIterator<LocationGroup, Location>* tempitor = getPlayerPosition(player);
    for (int i = 0; i < steps ; ++i) {
        tempitor->next();
        tempitor->get()->trigger(player,this);
    }
    std::cout<< tempitor->get()->getName()<<std::endl;
    tempitor->get()->landOn(player,this);
}

void GameManager::transferMoney(Role *giver, Role *receiver, int amount) {
    if (giver != nullptr)
        giver->addMoney(-amount);
    receiver->addMoney(amount);
}


std::string GameManager::getLocationName(int index) {
    return locations[index]->getName();
}


std::size_t GameManager::rollDice() {
    return this->dice->roll();
}

void GameManager::goJail(Role *player) {
    Phase* phase = new InJailMainPhase;
    player->setPhase(phase);
}

void GameManager::payForRent(Location* property,Role *payer, Role* receiver, GroupColor color) {
    int amount;
    amount=property->getNumHouse()*50+locationGroup->getPrice(color);
    transferMoney(payer,receiver,amount);
}

Card* GameManager::drawCard() {
    return cardgroup->getCard((int)rand()%2);
}

void GameManager::buildHouse() {
    bank->addHouse(-1);
}

void GameManager::buildHotel() {
    bank->addHotel(-1);
    bank->addHouse(5);
}

bool GameManager::askForBail(Role* player) {
    std::cout << "Do you want to bail?(Y/N)" << std::endl;
    char input;
    std::cin >> input;
    while(input != 'Y' && input != 'N'){
        std::cout << "Invalid Input. Please enter again." << std::endl;
        std::cin >> input;
    }
    if(input == 'Y'){
        std::cout << "$50 was paid." << std::endl;
        player->addMoney(-50);
        return true;
    } else {
        std::cout << "You are in Jail now." << std::endl;
        return false;
    }
}

bool GameManager::askForBuy(Role* player) {
    std::cout << "Do you want to buy at this location?(Y/N)" << std::endl;
    char input;
    std::cin >> input;
    while(input != 'Y' && input != 'N'){
        std::cout << "Invalid Input. Please enter again." << std::endl;
        std::cin >> input;
    }
    if(input == 'Y'){
        std::cout << "Payment completed." << std::endl;
        //TODO different location detection
        NoMansLand* res = new NoMansLand();
        res->happen(this, player);
        return true;
    } else {
        std::cout << "You didn't make the purchase." << std::endl;
        return false;
    }
}

bool GameManager::askForBuild(Role *player) {
    //TODO didn't check if it's owned
    std::cout << "Do you want to build?(Y/N)" << std::endl;
    char input;
    std::cin >> input;
    while(input != 'Y' && input != 'N'){
        std::cout << "Invalid Input. Please enter again." << std::endl;
        std::cin >> input;
    }
    if(input == 'Y'){
        std::cout << "Payment completed." << std::endl;
        MansLand* res = new MansLand();
        res->happen(this, player);
        return true;
    } else {
        std::cout << "You didn't build." << std::endl;
        return false;
    }
}

RLIterator<LocationGroup, Location>* GameManager::getPlayerPosition(Role* player) {
    return &PlayerLocationMap.at(player);
}

GameManager::~GameManager() {
    delete this->dice;
}

RLIterator<RoleGroup, Role> *GameManager::getRoleItor() {
    return this->roleItor;
}

std::map<Role *, RLIterator<LocationGroup, Location>> GameManager::getRoleLocationMap() {
    return this->PlayerLocationMap;
}

Location *GameManager::getLocation(int index) {
    return locations[index];
}

bool GameManager::endGame() {
    int Bankrupcynum=0;
    RLIterator<RoleGroup, Role> tempItor(roleGroup);
    for (int i = 0; i <playernum ; ++i) {
        if (tempItor.get()->getMoney()<0)
            Bankrupcynum++;
    }
    return (Bankrupcynum == playernum) || (round >= 100);
}

void GameManager::run() {
    while(!endGame()){
        std::cout << roleItor->get()->getName()+"'s ROUND"<< std::endl;
        roleItor->get()->getPhase()->execute(this,roleItor->get());
        roleItor->next();
        round++;
    }
}



