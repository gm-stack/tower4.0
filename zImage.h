/*
 *  zImage.h
 *  tower
 *
 *  Created by Geordie Millar on 9/06/09.
 *  Copyright 2009 __MyCompanyName__. All rights reserved.
 *
 */

#import "SDL.h"
#import "SDL_opengl.h"

class zImage {
	public:
	zImage(char* filename);
	void draw(int x, int y);
	SDL_Surface *surface;
	GLuint glu;
	float tcx;
	float tcy;
	int sizex;
	int sizey;
};