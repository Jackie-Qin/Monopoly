#ifndef __MONOPOLY_ROLE_HPP__
#define __MONOPOLY_ROLE_HPP__
#include <vector>
#include <string>
#include <set>

#include "monopoly/location.hpp"
#include "monopoly/phase.hpp"
#include "monopoly/rlIterator.hpp"


class Phase;
class Role{
public:
    virtual std::string showMoney() = 0;
    virtual void addProperty(LocationGroup* l) = 0;
    virtual void deleteProperty(LocationGroup* l) = 0;
    virtual int getMoney() = 0;
    virtual void setName(std::string s) = 0;
    /* amount can be a positive or negative number */
    virtual void addMoney(int amount)=0;
    virtual void setPhase(Phase* p)=0;
    virtual Phase* getPhase()=0;
    virtual std::string getName()=0;
    virtual void addHouse(int a) = 0;
    virtual void addHotel(int a) = 0;
};


class RoleGroup : public Role{
private:
    std::vector<Role*> rolePool;
    std::string name;
public:
    std::string showMoney() override{ return ""; }
    void addProperty(LocationGroup* l) override{ }
    void deleteProperty(LocationGroup* l) override{ }
    int getMoney() override{ return 0; }
    /* amount can be a positive or negative number */
    virtual void setName(std::string s) override{} ;
    void addUser(Role* r);
    Role* get(std::size_t index);
    virtual std::string getName() override {};
    virtual RLIterator<RoleGroup, Role>* createIterator();
    virtual std::size_t size();
    virtual void addMoney(int amount) override {};
    virtual void setPhase(Phase* p) override {};
    virtual Phase* getPhase() override {};
    virtual void addHouse(int a)override {};
    virtual void addHotel(int a)override {};
};


class Player : public Role{
private:
    bool inJail;
    int money;
    std::string name;
    std::set<LocationGroup*> property;
    Phase* phase;
public:
    explicit Player(int amount);
    virtual void getInJail();
    virtual void getOutJail();

    void setName(std::string s) override;
    virtual std::string getName();

    virtual std::string showMoney() override;
    virtual int getMoney() override;
    /* amount can be a positive or negative number */
    virtual void addMoney(int amount) override ;

    virtual void setPhase(Phase* p);
    virtual Phase* getPhase();

    virtual void addProperty(LocationGroup* l) ;
    virtual void deleteProperty(LocationGroup* l) ;

    virtual void addHouse(int a) override {};
    virtual void addHotel(int a) override {};
};


class Bank : public Role{
private:
    int money;
    int hotel;
    int house;
    std::set<LocationGroup*> property;
    Phase* phase;
public:
    std::string showMoney() override;
    int getMoney() override;
    /* amount can be a positive or negative number */
    void addMoney(int amount) ;
    virtual std::string getName() override {};
    void setPhase(Phase* p);
    Phase* getPhase();
    virtual void setName(std::string s) override{} ;
    void addProperty(LocationGroup* l) override;
    void deleteProperty(LocationGroup* l) override;
    void addHouse(int a);
    void addHotel(int a);
};
#endif //MONOPOLY_ROLE_HPP