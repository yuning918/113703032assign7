// TODO implementation
#include <iostream>
#include <string>
#include <vector>
#include "gameObjectFactory.h"
#include "iconFactory.h"
#include "gameObject.h"
#include "player.h"
#include "obstacle.h"

using namespace std;

GameObject* gameObjectFactory::createPlayer(Position pos) {
    return new player(pos);
}

GameObject* gameObjectFactory::createObstacle(Position pos, int i) {
    return new obstacle(pos, i);
}
