/*
 *  zImage.cpp
 *  tower
 *
 *  Created by Geordie Millar on 9/06/09.
 *  Copyright 2009 __MyCompanyName__. All rights reserved.
 *
 */

#include "zImage.h"

zImage::zImage(char* filename) {
	SDL_Surface *temp;
	temp = SDL_LoadBMP(filename);
	printf("load bitmap: %s\n", filename);
	if (temp == NULL) {
		printf("Unable to load bitmap %s : %s\n", filename, SDL_GetError());
		exit(0);
		return;
	}
	
	printf("image is %ix%i\n", temp->w, temp->h);
	
	int w=1; while (w < temp->w) { w=w*2; }
	int h=1; while (h < temp->h) { h=h*2; }
	printf("power of 2 %ix%i\n",w,h);
	
	surface = SDL_CreateRGBSurface(SDL_SWSURFACE,w,h,32,0xFF000000, 0x00FF0000, 0x0000FF00, 0x000000FF);
	SDL_SetAlpha (surface, SDL_SRCALPHA, 255);
	
	tcx = ((float)temp->w/(float)surface->w);
	tcy = ((float)temp->h/(float)surface->h);
	sizex = temp->w;
	sizey = temp->h;
	
	printf("tcx=%f tcy=%f sizex=%i sizey=%i\n",tcx,tcy,sizex,sizey);
	
	SDL_BlitSurface(temp, NULL, surface, NULL);
	
	int x = 0;
	int y = 0;
	int pitch = surface->pitch;
	Uint32 *bufp;
	Uint32 alphaColor;
	alphaColor = SDL_MapRGB(surface->format,255,0,255);
	
	while(y<surface->h){
		while(x<surface->w) { 
			bufp = (Uint32 *)surface->pixels + y*pitch/4 + x; 
			if (*bufp == alphaColor) {
				*bufp = SDL_MapRGBA(surface->format,0,0,0,0);
			}
			x++;
		}
		x=0;
		y++;
	}
	
	glGenTextures( 1, &glu );
	glBindTexture( GL_TEXTURE_2D, glu );
	
	glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST );
	glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST );
	
	// Edit the texture object's image data using the information SDL_Surface gives us
	glTexImage2D( GL_TEXTURE_2D, 0, GL_RGBA, surface->w, surface->h, 0, GL_RGBA, GL_UNSIGNED_INT_8_8_8_8, surface->pixels );
	
	SDL_FreeSurface(temp);
}

void zImage::draw(int x, int y) {
	
	glBindTexture( GL_TEXTURE_2D, glu );
	glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP );
	glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP );
	
	glBegin( GL_QUADS );
	
	//Top-left vertex (corner)
	glColor4f( 1.0f, 1.0f, 1.0f, 1.0f); 
	glTexCoord2f( 0, 0 );
	glVertex3f( x, y + sizey, 0 );
	
	//Top-right vertex (corner)
	glTexCoord2f( tcx, 0 );
	glVertex3f( x + sizex, y + sizey, 0 );
	
	//Bottom-right vertex (corner)
	glTexCoord2f( tcx, tcy );
	glVertex3f( x + sizex, y, 0 );
	
	//Bottom-left vertex (corner)
	glTexCoord2f( 0, tcy );
	glVertex3f(x, y, 0 );

	glEnd();
}	
	
