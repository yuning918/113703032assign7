#include "obstacle.h"
#include "gameObject.h"
#include "unit.h"
#include "icon.h"
#include "iconFactory.h"
#include "RPSGameObject.h"

obstacle::obstacle(Position pos, int i) {
	_pos = pos;
	switch (i){
		case 0: 
			_icon = iconFactory::createTop();
			_type = TOP;
			break;
		case 1:
 			_icon = iconFactory::createLeft();
			_type = LEFT;
			break;
	}
}

