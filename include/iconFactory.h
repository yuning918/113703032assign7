// TODO 
// Finish the declaration of IconFactory that
// 1. offers some methods to create an Icon.
// 2. encapsulates the constructor from the caller. 
#ifndef ICON_FACTORY_H
#define ICON_FACTORY_H

#include <iostream>
#include <vector>
#include <string>
#include "icon.h"

class iconFactory{
public:
    static Icon createTop();
	static Icon createLeft();
	static Icon createPlayer();
	static Icon createSquat();
};

#endif
