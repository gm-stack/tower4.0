/*
 *  zTextImage.cpp
 *  tower
 *
 *  Created by Geordie Millar on 14/06/09.
 *  Copyright 2009 __MyCompanyName__. All rights reserved.
 *
 */

#include "zTextImage.h"

zTextImage::zTextImage(TTF_Font *font, char* text2) {
	
		SDL_Color foregroundColor = { 255, 255, 255 };
		SDL_Surface *text;
		SDL_Surface *text_gl;
		text = TTF_RenderText_Blended(font, text2, foregroundColor);
		
		realsizex = text->w;
		realsizey = text->h;
	
		int w=1; while (w < text->w) { w=w*2; }
		int h=1; while (h < text->h) { h=h*2; }
		
		text_gl = SDL_CreateRGBSurface(0, w, h, 32, 0x00ff0000, 0x0000ff00, 0x000000ff, 0xff000000); 
		SDL_BlitSurface(text, 0, text_gl, 0);
		
		int x = 0;
		int y = 0;
		int pitch = text_gl->pitch;
		Uint32 *bufp;				
		while(y<text_gl->h){
			while(x<text_gl->w) { 
				bufp = (Uint32 *)text_gl->pixels + y*pitch/4 + x; 
				*bufp = *bufp | ((*bufp & 0x00FF0000) << 8);
				x++;
			}
			x=0;
			y++;
		}
		
		glGenTextures(1, &glu);
		glBindTexture(GL_TEXTURE_2D, glu);
		glTexImage2D(GL_TEXTURE_2D, 0, 4, w, h, 0, GL_RGBA, GL_UNSIGNED_INT_8_8_8_8_REV, text_gl->pixels );
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		sizex = w;
		sizey = h;
		SDL_FreeSurface(text);
		SDL_FreeSurface(text_gl);
}

void zTextImage::draw(int x, int y) {
	
	glBindTexture( GL_TEXTURE_2D, glu );
	glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP );
	glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP );
	
	glBegin( GL_QUADS );
	
	//Top-left vertex (corner)
	glColor4f( 1.0f, 1.0f, 1.0f, 1.0f); 
	glTexCoord2f( 0, 0 );
	glVertex3f( x, y + sizey, 0 );
	
	//Top-right vertex (corner)
	glTexCoord2f( 1, 0 );
	glVertex3f( x + sizex, y + sizey, 0 );
	
	//Bottom-right vertex (corner)
	glTexCoord2f( 1, 1 );
	glVertex3f( x + sizex, y, 0 );
	
	//Bottom-left vertex (corner)
	glTexCoord2f( 0, 1 );
	glVertex3f(x, y, 0 );
	
	glEnd();
}	

