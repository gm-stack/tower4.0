/*
 *  menudraw.h
 *  tower
 *
 *  Created by Geordie Millar on 14/06/09.
 *  Copyright 2009 __MyCompanyName__. All rights reserved.
 *
 */

#import "globals.h"
#import <SDL_ttf/SDL_ttf.h>
#import "zTextImage.h"
#include <vector>
using namespace std;

class menudraw {
public:
	menudraw(Globals *g);
	Globals *g;
	void drawMenu();
	void glRectangle(int x1,int y1,int x2,int y2);

	zTextImage *zTowerText;
	vector<zTextImage*> weekdays;
	vector<zTextImage*> numbers;
	zTextImage *colon;
};