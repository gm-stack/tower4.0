/*
 *  floormanager.cpp
 *  tower
 *
 *  Created by Geordie Millar on 10/06/09.
 *  Copyright 2009 __MyCompanyName__. All rights reserved.
 *
 */

#include "floormanager.h"

floormanager::floormanager() {
}

void floormanager::build_floor(int thefloor,int leftbound,int rightbound) {
	flr *flr2 = new flr(leftbound,rightbound);
	floors.push_back(flr2);
}

void floormanager::changeFloorLeft(int thefloor, int newleft) {
	floors[thefloor]->leftbound = newleft;
}

void floormanager::changeFloorRight(int thefloor, int newright) {
	floors[thefloor]->rightbound = newright;
}

void floormanager::addBuilding(int thefloor, buildingobject *bo) {
	floors[thefloor]->objects.push_back(bo);
}