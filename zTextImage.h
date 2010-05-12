/*
 *  zTextImage.h
 *  tower
 *
 *  Created by Geordie Millar on 14/06/09.
 *  Copyright 2009 __MyCompanyName__. All rights reserved.
 *
 */

#import <SDL_ttf/SDL_ttf.h>
#import "SDL.h"
#import "SDL_opengl.h"

class zTextImage {
public:
	zTextImage::zTextImage(TTF_Font *font, char* text2);
	void draw(int x, int y);
	SDL_Surface *surface;
	GLuint glu;
	int sizex;
	int sizey;
	int realsizex;
	int realsizey;
};