/*
 *  office.h
 *  tower
 *
 *  Created by Geordie Millar on 14/06/09.
 *  Copyright 2009 __MyCompanyName__. All rights reserved.
 *
 */

#import "buildingobject.h"
#import "textureManager.h"
#import "gametime.hpp"

class office : public buildingobject {
public:
	office(int position, int floor, textureManager *tm, GameTime *gt);
	
	int calcMaintainance();
	int calcIncome();
	int incomeType();
	int numOccupants();
};