#ifndef PLAYER_H
#define PLAYER_H

#include "RPSGameObject.h"
#include "gameObject.h"
#include "unit.h"

class player : public RPSGameObject{
public:
	player(Position pos);
	void jump();
	void update(int move)override;
	void onCollision(ICollider* other) override;
private:
	bool Jumping = false;
    	int jumpCounter = 0;
    	bool Squatting = false;
};
#endif
