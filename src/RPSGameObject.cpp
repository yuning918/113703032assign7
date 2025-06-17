#include <iostream>
#include "RPSGameObject.h"
#include "unit.h"
#include "iconFactory.h"
#include "player.h"
#include <unordered_set>

void RPSGameObject::updateAll(RPSGameObject* obj) {
    if(obj->getType() == TOP) obj->setPosition({getPosition().x(), getPosition().y()+1}); 
    if(obj->getType() == LEFT) obj->setPosition({getPosition().x()+1, getPosition().y()});
}

void RPSGameObject:: onCollision(ICollider *other){
	if (dynamic_cast<player*>(other)) return;
	else delete other;
}

bool RPSGameObject::intersect(ICollider *other){
	if(getType() == LEFT) return false;
	RPSGameObject* rpsOther = dynamic_cast<RPSGameObject*>(other);
    	if (!rpsOther) return false;
	if(getPosition().x() - rpsOther->getPosition().x() < 4 && 
	   getPosition().x() - rpsOther->getPosition().x() > -2){
		if(getPosition().y() - rpsOther->getPosition().y() < 4 && 
	   	   getPosition().y() - rpsOther->getPosition().y() > -2){
			return true;
		}
		return false;
	}else{
		return false;
	}
}

RPSType RPSGameObject::getType() const{
	return _type;
}

void RPSGameObject::setType(RPSType type){
	_type = type;
}
