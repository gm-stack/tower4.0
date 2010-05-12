/*
 *  fgdraw.h
 *  tower
 *
 *  Created by Geordie Millar on 13/06/09.
 *  Copyright 2009 __MyCompanyName__. All rights reserved.
 *
 */

#import "globals.h"
#import <string>
#import <map>
#import "floormanager.h"
#import "textureManager.h"
#import "zImage.h"

using namespace std;

class fgdraw {
public:
	fgdraw(Globals *g, floormanager *fm);
	void drawFG();
	void DrawTowerFloor(int xfrom, int xto, int floor);
	void DrawFireStairs(int xfrom, int xto, int floor);
	void DrawBuildingObjects(vector<buildingobject*> objs);	
	
	Globals *g;
	floormanager *fm;
};