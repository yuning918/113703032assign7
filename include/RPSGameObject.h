#ifndef RPS_H
#define RPS_H

#include "collider.h"
#include "gameObject.h"
#include "unit.h"

enum RPSType { TOP, LEFT, PLAYER };

class RPSGameObject : public GameObject, public ICollider {

public:
void updateAll(RPSGameObject* objects);
  void onCollision(ICollider *other) override;
  bool intersect(ICollider *other) override;

  RPSType getType() const;
  void setType(RPSType type);

protected:
  RPSType _type;
};
#endif

