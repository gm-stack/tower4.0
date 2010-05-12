/*
 *  bgdraw.h
 *  tower
 *
 *  Created by Geordie Millar on 9/06/09.
 *  Copyright 2009 __MyCompanyName__. All rights reserved.
 *
 */

#import "globals.h"
#import "SDL.h"
#import "SDL_opengl.h"

class bgdraw {
public:
	bgdraw(Globals *g);
	void drawBG();
	void glRectangle(int x1,int y1,int x2,int y2);
	
	Globals *g;
	
	short int redscale,greenscale,bluescale;
	short int redshift,greenshift,blueshift;
	short int red, green, blue;
};