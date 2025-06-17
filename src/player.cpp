#include "player.h"
#include "gameObject.h"
#include "unit.h"
#include "iconFactory.h"
#include "RPSGameObject.h"

player::player(Position pos) {
	_icon = iconFactory::createPlayer();
    	_pos = pos;
	_type = PLAYER;
}

void player::update(int move){
    // Define player behavior
	if(move == 1){
		if (Jumping) {
		   jump();
         	   if (jumpCounter > 3) _pos.y()--; // jump up
            	   else _pos.y()++;                // fall down
                   jumpCounter--;
                   if (jumpCounter == 0) Jumping = false;
        	}
	}else if(move == 2){
		Squatting = true;
		_icon = iconFactory::createSquat();
	}else if(move == 3){
		if(Squatting){
			_icon = iconFactory::createPlayer();
			Squatting = false;
		}
		_pos.x()--;
	}else if(move == 4){
		if(Squatting){
			_icon = iconFactory::createPlayer();
			Squatting = false;
		}
		_pos.x()++;
	}
	_pos.x() = std::max(0, std::min(16, _pos.x()));
}

void player::onCollision(ICollider* other) {
    
}

void player::jump() {
	if(Squatting){
		_icon = iconFactory::createPlayer();
		Squatting = false;
	}
    	if (!Jumping) {
        	Jumping = true;
        	jumpCounter = 6;
    	}
}
