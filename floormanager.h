/*
 *  floormanager.h
 *  tower
 *
 *  Created by Geordie Millar on 10/06/09.
 *  Copyright 2009 __MyCompanyName__. All rights reserved.
 *
 */

#import "floor.h"
#include <vector>
using namespace std;
#import "buildingobject.h"

class floormanager {
public:
	vector<flr*> floors;
	floormanager();
	void build_floor(int thefloor,int leftbound,int rightbound);
	void changeFloorLeft(int thefloor, int newleft);
	void changeFloorRight(int thefloor, int newright);
	void addBuilding(int thefloor, buildingobject *bo);
};