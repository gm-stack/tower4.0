/*
 *  floor.h
 *  tower
 *
 *  Created by Geordie Millar on 10/06/09.
 *  Copyright 2009 __MyCompanyName__. All rights reserved.
 *
 */

#include <vector>
using namespace std;
#import "buildingobject.h"

class flr {
public:
	flr(int leftbound, int rightbound);
	int leftbound;
	int rightbound;
	vector<buildingobject*> objects;
};