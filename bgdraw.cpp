/*
 *  bgdraw.cpp
 *  tower
 *
 *  Created by Geordie Millar on 9/06/09.
 *  Copyright 2009 __MyCompanyName__. All rights reserved.
 *
 */

#include "bgdraw.h"

bgdraw::bgdraw(Globals *g) {
	this->g = g;
}

void bgdraw::drawBG() {
	float hours = g->gt->frachours();
	
	if (hours < 4) { // night
		redscale = 18;
		greenscale = 18;
		bluescale = 18;
		
		redshift = 0;
		greenshift = 0;
		blueshift = 0;
		
	} else if (hours >= 4 && hours < 9) { // sunrise
		redscale = 17;
		greenscale = 18;
		bluescale = 18;
		
		redshift = ((hours - 4) / 5) * 136;
		greenshift = ((hours - 4) / 5) * 207;
		blueshift = ((hours - 4) / 5) * 222;
	} else if (hours >= 9 && hours <= 14) { // early morning
		bluescale = greenscale = redscale = (((hours - 9) / 5) * 50) + 18;
		
		redshift = 136;
		greenshift = 207;
		blueshift = 222;
	} else if (hours > 14 && hours <= 21) { // late afternoon
		bluescale = greenscale = redscale = (((7 - (hours - 14)) / 7) * 50) + 18;
		
		redshift = 136;
		greenshift = 207;
		blueshift = 222;
		
	} else if (hours > 21) { // night
		redscale = 18;
		greenscale = 18;
		bluescale = 18;
		
		redshift = ((3 - (hours - 21)) / 3) * 136;
		greenshift = ((3 - (hours - 21)) / 3) * 207;
		blueshift = ((3 - (hours - 21)) / 3) * 222;
	}
	
	red = (redshift + (200 / redscale));
	green = (greenshift + (200 / greenscale));
	blue = (blueshift + (200 / bluescale));
	
	SDL_Rect dest;
	
	glDisable(GL_TEXTURE_2D);
	
	glColor4f( (red/(float)255), (green/(float)255), (blue/(float)255), 1.0f ); 
	glRectangle(0, 0, g->screen_width, g->screen_height);
		
	glColor4f( 0.5f, 0.4f, 0.2985f, 1.0f ); 
	glRectangle(0, 0, g->screen_width, 8); 
	
	glEnable(GL_TEXTURE_2D);
	
	dest.x = 0;
	dest.w = g->bgim->sizex;
	dest.h = g->bgim->sizey;
	dest.y = 8;
	
	while (dest.x < g->screen_width) {
		g->bgim->draw(dest.x,dest.y);
		dest.x = dest.x + dest.w;
	}
	
	glBindTexture( GL_TEXTURE_2D, 0 );
}

void bgdraw::glRectangle(int x1,int y1,int x2,int y2) {
	glBegin( GL_QUADS );
	glVertex3f( x1, y1, 0.0f );
	glVertex3f( x1, y2, 0 );
	glVertex3f( x2, y2, 0 );
	glVertex3f( x2, y1, 0 );
	glEnd();
}
