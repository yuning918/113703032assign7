// TODO implementation
#include "gameObject.h"

Position GameObject::getPosition() const {
    return _pos;
}

Icon GameObject::getIcon() const {
    return _icon;
}

void GameObject::setPosition(const Position& p){
	_pos = p;
}

void GameObject::update(int move){

}

bool GameObject::intersect(const GameObject* other) const {
    return (true);
}

