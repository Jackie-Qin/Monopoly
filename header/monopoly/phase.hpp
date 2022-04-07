#ifndef __PHASE_HPP__
#define __PHASE_HPP__

#include "monopoly/gameManager.hpp"
#include "monopoly/role.hpp"

/**
 * Strategy Pattern
 */
class Phase {

public:
    virtual void execute(GameManager* gameManager, Role* player) = 0;
};

class NormalMainPhase: public Phase {
public:

    virtual void execute(GameManager* gameManager, Role* player);
};

class InJailMainPhase: public Phase {
public:

    virtual void execute(GameManager* gameManager, Role* player);
};

class BankrupcyMainPhase: public Phase {
public:

    virtual void execute(GameManager* gameManager, Role* player);
};

class TradePhase: public Phase {
public:

    virtual void execute(GameManager* gameManager, Role* player);
};

#endif // __PHASE_HPP__