#ifndef ELEMENT_H
#define ELEMENT_H

#include <vector>
#include "unit.h"
#include "icon.h"
#include <iostream>
class GameObject{

public:

    Position getPosition() const;
    Icon getIcon() const;
	virtual void setPosition(const Position& p);
    virtual void update(int move);
	virtual bool intersect(const GameObject* other) const;
protected:

    Position _pos;
    Icon _icon;
};

#endif
