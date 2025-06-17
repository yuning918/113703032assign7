#ifndef OBSTACLE_H
#define OBSTACLE_H

#include "gameObject.h"
#include "unit.h"
#include "RPSGameObject.h"

class obstacle : public RPSGameObject{
	public:
		obstacle(Position pos, int i);
};
#endif
