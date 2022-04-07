#ifndef __R_L_ITERATOR_HPP__
#define __R_L_ITERATOR_HPP__

#include <iostream>

/**
 * an cycle iterator
 */
template <class GroupClass, class ElementClass>
class RLIterator {
private:
    std::size_t index;
    GroupClass* container;

public:
    RLIterator(GroupClass* t) {
        this->container = t;
        index = 0;
    }
    virtual bool hasNext() {
        return this->index < container->size();
    }
    virtual void next() {
        index++;
        index %= container->size();
    }
    virtual ElementClass* get() {
        return container->get(index);
    }

};

#endif // __R_L_ITERATOR_HPP__