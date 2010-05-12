/*
 *  globals.h
 *  tower
 *
 *  Created by Geordie Millar on 9/06/09.
 *  Copyright 2009 __MyCompanyName__. All rights reserved.
 *
 */

#import "gametime.hpp"
#import "zImage.h"
#import "TextureManager.h"
#import <SDL_ttf/SDL_ttf.h>

class Globals {
public:
Globals();
	GameTime *gt;
	textureManager *tm;
	int screen_width;
	int screen_height;
	int x;
	int y;
	TTF_Font *font;
	
	zImage *bgim;
};