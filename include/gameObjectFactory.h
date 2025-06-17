// TODO 
// Finish the declaration of GameObjectFactory that
// 1. offers some methods to create a GameObject.
// 2. encapsulates the constructor from the caller. 
#ifndef GAME_OBJECT_FACTORY_H
#define GAME_OBJECT_FACTORY_H

#include "gameObject.h"
#include "icon.h"
#include "unit.h"

class gameObjectFactory {
public:
    static GameObject* createPlayer(Position pos);
    static GameObject* createObstacle(Position pos, int i);
};

#endif
