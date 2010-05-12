/*
 *  buildingobject.h
 *  tower
 *
 *  Created by Geordie Millar on 13/06/09.
 *  Copyright 2009 __MyCompanyName__. All rights reserved.
 *
 */
#include <vector>
using namespace std;
#import "zImage.h"
#import "gametime.hpp"

class buildingobject {
public:
	int position;
	int width;
	int floor;
	
	int activestart;
	int activefinish;
	
	bool opendays[7];
	
	bool occupied;
	
	vector<zImage*> emptytextures;
	vector<zImage*> idletextures;
	vector<zImage*> activetextures;
	vector<zImage*> constructiontextures;
	
	int buildstarttime;
	int buildfinishtime;
	
	// useful methods:
	buildingobject(int position, int width, int floor, int activestart, int activefinish, GameTime *gt);
	bool willcollide(int left, int right);
	void draw();
	
	// non-useful methods (override these)
	int calcMaintainance();
	int calcIncome();
	int incomeType();
	int numOccupants();
	
	GameTime *gt;
	
};