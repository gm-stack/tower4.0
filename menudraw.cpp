/*
 *  menudraw.cpp
 *  tower
 *
 *  Created by Geordie Millar on 14/06/09.
 *  Copyright 2009 __MyCompanyName__. All rights reserved.
 *
 */

#include "menudraw.h"

#define shm(a) (g->screen_height - a)

menudraw::menudraw(Globals *g) {
	this->g = g;
	zTowerText = new zTextImage(g->font,"zTower 1.2 alpha");
	int i;
	for (i=0;i<7;i++) {
		weekdays.push_back(new zTextImage(g->font,g->gt->day(i)));
	}
	char buffer[10];
	for (i=0;i<1000;i++) { // FIXME: more?
		sprintf(buffer, "%i", i);
		numbers.push_back(new zTextImage(g->font,buffer));
	}
	colon = new zTextImage(g->font,":");
}

void menudraw::drawMenu(){
	
	glColor4f(0.0f, 0.0f, 0.0f, 0.8f);
	glDisable(GL_TEXTURE_2D);
	glRectangle(0, g->screen_height, 800, shm(80));
	glEnable(GL_TEXTURE_2D);
		
	zTowerText->draw(12, shm((8 + zTowerText->sizey)));
	
	
	int whichday = g->gt->days();
	weekdays[whichday]->draw(12, shm((24 + weekdays[whichday]->sizey)));
	
	int whichweek = g->gt->weeks();
	numbers[whichweek]->draw(12+weekdays[whichday]->realsizex, shm((24 + weekdays[whichday]->sizey)));
	
	int whichhour = g->gt->hours();
	numbers[whichhour]->draw(12, shm((24 + 2 * weekdays[whichday]->sizey)));
	colon->draw(12 + numbers[whichhour]->realsizex, shm((24 + 2 * weekdays[whichday]->sizey)));
	
	int whichminute = g->gt->minutes();
	numbers[whichminute]->draw(12 + numbers[whichhour]->realsizex + colon->realsizex, shm((24 + 2 * weekdays[whichday]->sizey)));

	
/*	
	
	if ((money_gl == 0) || (prevmoney != money_amount)) {
		if (money_amount != prevmoney) {
			prevmoney = money_amount;
			printf("creating because changed\n");
			glDeleteTextures(1, &money_gl);
		}
		printf("creating money_gl\n");
		SDL_Color foregroundColor = { 255, 255, 255 };
		SDL_Surface *money_s;
		SDL_Surface *money_gl_s;
		
		char moneytext[64];
		sprintf(moneytext, "$%i", money_amount);
		money_s = TTF_RenderText_Blended(font, moneytext, foregroundColor); 
		
		money_gl_width = nextpoweroftwo(money_s->w);
		money_gl_height = nextpoweroftwo(money_s->h);
		money_gl_s = SDL_CreateRGBSurface(0, money_gl_width, money_gl_height, 32, 0x00ff0000, 0x0000ff00, 0x000000ff, 0xff000000); 
		SDL_BlitSurface(money_s, 0, money_gl_s, 0);
		
		int x = 0;
		int y = 0;
		int pitch = money_gl_s->pitch;
		Uint32 *bufp;				
		while(y<money_gl_s->h){
			while(x<money_gl_s->w) { 
				bufp = (Uint32 *)money_gl_s->pixels + y*pitch/4 + x; 
				*bufp = *bufp | ((*bufp & 0x00FF0000) << 8);
				x++;
			}
			x=0;
			y++;
		}
		
		glGenTextures(1, &money_gl);
		glBindTexture(GL_TEXTURE_2D, money_gl);
		glTexImage2D(GL_TEXTURE_2D, 0, 4, money_gl_width, money_gl_height, 0, GL_RGBA, GL_UNSIGNED_INT_8_8_8_8_REV, money_gl_s->pixels );
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		SDL_FreeSurface(money_s);
		SDL_FreeSurface(money_gl_s);
	}
	
	glBindTexture(GL_TEXTURE_2D, money_gl);
	glColor3f(1.0f, 1.0f, 1.0f);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f); glVertex2f(600, 8);
	glTexCoord2f(1.0f, 0.0f); glVertex2f(600 + money_gl_width, 8);
	glTexCoord2f(1.0f, 1.0f); glVertex2f(600 + money_gl_width, money_gl_height + 8);
	glTexCoord2f(0.0f, 1.0f); glVertex2f(600, money_gl_height + 8);
	glEnd();
	glBindTexture( GL_TEXTURE_2D, 0 );
	
	if (menu_unselected_gl == NULL) {	
		printf("creating menu un/selected\n");
		SDL_Surface *menu_unselected;
		SDL_Surface *menu_selected;
		
		
		menu_unselected = loadImageToPowerOfTwoSurface(NULL ,system_filepath "images/unselected.bmp");
		menu_unselected_cw = calctc_x();
		menu_unselected_ch = calctc_y();
		menu_unselected_rw = size_x();
		menu_unselected_rh = size_y();
		
		menu_selected = loadImageToPowerOfTwoSurface(NULL ,system_filepath "images/selected.bmp");
		menu_selected_cw = calctc_x();
		menu_selected_ch = calctc_y();
		menu_selected_rw = size_x();
		menu_selected_rh = size_y();
		
		
		glGenTextures( 1, &menu_unselected_gl );
		glBindTexture( GL_TEXTURE_2D, menu_unselected_gl );
		glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST );
		glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST );
		glTexImage2D( GL_TEXTURE_2D, 0, GL_RGBA, menu_unselected->w, menu_unselected->h, 0, GL_RGBA, GL_UNSIGNED_INT_8_8_8_8, menu_unselected->pixels );
		SDL_FreeSurface(menu_unselected);
		
		glGenTextures( 1, &menu_selected_gl );
		glBindTexture( GL_TEXTURE_2D, menu_selected_gl );
		glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST );
		glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST );
		glTexImage2D( GL_TEXTURE_2D, 0, GL_RGBA, menu_selected->w, menu_selected->h, 0, GL_RGBA, GL_UNSIGNED_INT_8_8_8_8, menu_selected->pixels );
		SDL_FreeSurface(menu_selected);
		
    }
	
	glBindTexture( GL_TEXTURE_2D, menu_unselected_gl );
	glBegin( GL_QUADS );
	// Top-left vertex (corner)
	glColor4f( 1.0f, 1.0f, 1.0f, 1.0f); 
	glTexCoord2f( 0, 0 );
	glVertex3f( 240, 8, 0 );
	
	//Bottom-left vertex (corner)
	glTexCoord2f( menu_unselected_cw, 0 );
	glVertex3f(240 + menu_unselected_rw, 8, 0 );
	
	//Bottom-right vertex (corner)
	glTexCoord2f( menu_unselected_cw, menu_unselected_ch );
	glVertex3f( 240 + menu_unselected_rw, 8 + menu_unselected_rh, 0 );
	
	//Top-right vertex (corner)
	glTexCoord2f( 0, menu_unselected_ch );
	glVertex3f( 240, 8 + menu_unselected_rh, 0 );
	glEnd();
	
	if (mode) {
		glBindTexture( GL_TEXTURE_2D, menu_selected_gl ); // FIXME - this is not quite right
		glBegin( GL_QUADS );
		// Top-left vertex (corner)
		glColor4f( 1.0f, 1.0f, 1.0f, 1.0f); 
		glTexCoord2f( ((menu_unselected_cw / 11) * (mode - 1)), 0 );
		glVertex3f( 240 + (mode-1) *16, 8, 0 );
		
		//Bottom-left vertex (corner)
		glTexCoord2f( ((menu_unselected_cw / 11) * mode), 0 );
		glVertex3f(240 + (mode) *16, 8, 0 );
		
		//Bottom-right vertex (corner)
		glTexCoord2f( ((menu_unselected_cw / 11) * mode), menu_unselected_ch );
		glVertex3f( 240 + (mode) *16, 24, 0 );
		
		//Top-right vertex (corner)
		glTexCoord2f( ((menu_unselected_cw / 11) * (mode - 1)), menu_unselected_ch );
		glVertex3f(240 + (mode-1) *16, 24, 0 );
		glEnd();
		
		
		if (toolnamegl[0] == 0) {
			unsigned int thisname;
			printf("creating toolnames\n");
			glGenTextures(8, &toolnamegl);
			char text[64];
			SDL_Color foregroundColor = { 255, 255, 255 };
			SDL_Surface *textSurface;
			SDL_Surface *textSurface_gl;
			thisname = 0;
			while (thisname < 8) {
				sprintf(text, "%s", toolname(thisname));
				textSurface = TTF_RenderText_Blended(font, text, foregroundColor);
				toolname_width[thisname] = nextpoweroftwo(textSurface->w);
				toolname_height[thisname] = nextpoweroftwo(textSurface->h);
				textSurface_gl = SDL_CreateRGBSurface(0, toolname_width[thisname], toolname_height[thisname], 32, 0x00ff0000, 0x0000ff00, 0x000000ff, 0xff000000); 
				SDL_BlitSurface(textSurface, 0, textSurface_gl, 0);
				
				int x = 0;
				int y = 0;
				int pitch = textSurface_gl->pitch;
				Uint32 *bufp;				
				while(y< textSurface_gl->h){
					while(x< textSurface_gl->w) { 
						bufp = (Uint32 *) textSurface_gl->pixels + y*pitch/4 + x; 
						*bufp = *bufp | ((*bufp & 0x00FF0000) << 8);
						x++;
					}
					x=0;
					y++;
				}
				
				glBindTexture(GL_TEXTURE_2D, toolnamegl[thisname]);
				glTexImage2D(GL_TEXTURE_2D, 0, 4, toolname_width[thisname], toolname_height[thisname], 0, GL_RGBA, GL_UNSIGNED_INT_8_8_8_8_REV, textSurface_gl->pixels );
				glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
				glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
				SDL_FreeSurface(textSurface);
				SDL_FreeSurface(textSurface_gl);
				thisname++;
			}
		}
		
		glBindTexture(GL_TEXTURE_2D, toolnamegl[mode]);
		glColor3f(1.0f, 1.0f, 1.0f);
		glBegin(GL_QUADS);
		glTexCoord2f(0.0f, 0.0f); glVertex2f(240, 26);
		glTexCoord2f(1.0f, 0.0f); glVertex2f(240 + toolname_width[mode], 26);
		glTexCoord2f(1.0f, 1.0f); glVertex2f(240 + toolname_width[mode], toolname_height[mode] + 26);
		glTexCoord2f(0.0f, 1.0f); glVertex2f(240, toolname_height[mode] + 26);
		glEnd();
		glBindTexture( GL_TEXTURE_2D, 0 );
	}
	
	msgage = SDL_GetTicks() - msgticks;
	if (msgage < 3250) {
		glBindTexture(GL_TEXTURE_2D, newmsg_gl);
		if (msgage < 100) {
			glColor4f(1.0f, 1.0f, 1.0f, ((float)msgage / 100.0f));
		} else if (msgage > 3000) {
			glColor4f(1.0f, 1.0f, 1.0f, 1.0f - ((float)(msgage - 3000) / 250.0f));
		} else {
			glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
		}
		glBegin(GL_QUADS);
		glTexCoord2f(0.0f, 0.0f); glVertex2f(240, 42);
		glTexCoord2f(1.0f, 0.0f); glVertex2f(240 + newmsg_gl_width, 42);
		glTexCoord2f(1.0f, 1.0f); glVertex2f(240 + newmsg_gl_width, newmsg_gl_height + 42);
		glTexCoord2f(0.0f, 1.0f); glVertex2f(240, newmsg_gl_height + 42);
		glEnd();
		glBindTexture( GL_TEXTURE_2D, 0 );
	}
	
	
	if (weekdays[0] == 0) {
		unsigned int thisday;
		printf("creating weekdays\n");
		glGenTextures(7, &weekdays);
		char text[16];
		SDL_Color foregroundColor = { 255, 255, 255 };
		SDL_Surface *textSurface;
		SDL_Surface *textSurface_gl;
		thisday = 0;
		while (thisday < 8) {
			sprintf(text, "%s", day(thisday));
			textSurface = TTF_RenderText_Blended(font, text, foregroundColor);
			weekdays_real_width[thisday] = textSurface->w;
			weekdays_width[thisday] = nextpoweroftwo(textSurface->w);
			weekdays_height[thisday] = nextpoweroftwo(textSurface->h);
			textSurface_gl = SDL_CreateRGBSurface(0, weekdays_width[thisday], weekdays_height[thisday], 32, 0x00ff0000, 0x0000ff00, 0x000000ff, 0xff000000); 
			SDL_BlitSurface(textSurface, 0, textSurface_gl, 0);
			
			int x = 0;
			int y = 0;
			int pitch = textSurface_gl->pitch;
			Uint32 *bufp;				
			while(y< textSurface_gl->h){
				while(x< textSurface_gl->w) { 
					bufp = (Uint32 *) textSurface_gl->pixels + y*pitch/4 + x; 
					*bufp = *bufp | ((*bufp & 0x00FF0000) << 8);
					x++;
				}
				x=0;
				y++;
			}
			
			glBindTexture(GL_TEXTURE_2D, weekdays[thisday]);
			glTexImage2D(GL_TEXTURE_2D, 0, 4, weekdays_width[thisday], weekdays_height[thisday], 0, GL_RGBA, GL_UNSIGNED_INT_8_8_8_8_REV, textSurface_gl->pixels );
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
			SDL_FreeSurface(textSurface);
			SDL_FreeSurface(textSurface_gl);
			thisday++;
		}
	}
	
	if (digits[0] == 0) {
		unsigned int thisnum;
		printf("creating digits\n");
		glGenTextures(61, &digits);
		char text[16];
		SDL_Color foregroundColor = { 255, 255, 255 };
		SDL_Surface *textSurface;
		SDL_Surface *textSurface_gl;
		thisnum = 0;
		while (thisnum < 61) {
			sprintf(text, "%i", thisnum);
			textSurface = TTF_RenderText_Blended(font, text, foregroundColor);
			digits_realwidth[thisnum] = textSurface->w;
			digits_width[thisnum] = nextpoweroftwo(textSurface->w);
			digits_height[thisnum] = nextpoweroftwo(textSurface->h);
			textSurface_gl = SDL_CreateRGBSurface(0, digits_width[thisnum], digits_height[thisnum], 32, 0x00ff0000, 0x0000ff00, 0x000000ff, 0xff000000); 
			SDL_BlitSurface(textSurface, 0, textSurface_gl, 0);
			
			int x = 0;
			int y = 0;
			int pitch = textSurface_gl->pitch;
			Uint32 *bufp;				
			while(y< textSurface_gl->h){
				while(x< textSurface_gl->w) { 
					bufp = (Uint32 *) textSurface_gl->pixels + y*pitch/4 + x; 
					*bufp = *bufp | ((*bufp & 0x00FF0000) << 8);
					x++;
				}
				x=0;
				y++;
			}
			
			glBindTexture(GL_TEXTURE_2D, digits[thisnum]);
			glTexImage2D(GL_TEXTURE_2D, 0, 4, digits_width[thisnum], digits_height[thisnum], 0, GL_RGBA, GL_UNSIGNED_INT_8_8_8_8_REV, textSurface_gl->pixels );
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
			SDL_FreeSurface(textSurface);
			SDL_FreeSurface(textSurface_gl);
			thisnum++;
		}
		
		glGenTextures(1, &colon);
		sprintf(text, ":");
		textSurface = TTF_RenderText_Blended(font, text, foregroundColor);
		colon_realwidth = textSurface->w;
		colon_width = nextpoweroftwo(textSurface->w);
		colon_height = nextpoweroftwo(textSurface->h);
		textSurface_gl = SDL_CreateRGBSurface(0, colon_width, colon_height, 32, 0x00ff0000, 0x0000ff00, 0x000000ff, 0xff000000); 
		SDL_BlitSurface(textSurface, 0, textSurface_gl, 0);
		
		int x = 0;
		int y = 0;
		int pitch = textSurface_gl->pitch;
		Uint32 *bufp;				
		while(y< textSurface_gl->h){
			while(x< textSurface_gl->w) { 
				bufp = (Uint32 *) textSurface_gl->pixels + y*pitch/4 + x; 
				*bufp = *bufp | ((*bufp & 0x00FF0000) << 8);
				x++;
			}
			x=0;
			y++;
		}
		
		glBindTexture(GL_TEXTURE_2D, colon);
		glTexImage2D(GL_TEXTURE_2D, 0, 4, colon_width, colon_height, 0, GL_RGBA, GL_UNSIGNED_INT_8_8_8_8_REV, textSurface_gl->pixels );
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		SDL_FreeSurface(textSurface);
		SDL_FreeSurface(textSurface_gl);
		
		
		
		
	}
	
	int whichday = days();
	
	glBindTexture(GL_TEXTURE_2D, weekdays[whichday]);
	glColor3f(1.0f, 1.0f, 1.0f);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f); glVertex2f(12, 24);
	glTexCoord2f(1.0f, 0.0f); glVertex2f(12 + weekdays_width[whichday], 24);
	glTexCoord2f(1.0f, 1.0f); glVertex2f(12 + weekdays_width[whichday], weekdays_height[whichday] + 24);
	glTexCoord2f(0.0f, 1.0f); glVertex2f(12, weekdays_height[whichday] + 24);
	glEnd();
	
	int whichweek = weeks();
	
	glBindTexture(GL_TEXTURE_2D, digits[whichweek]);
	glColor3f(1.0f, 1.0f, 1.0f);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f); glVertex2f(weekdays_real_width[whichday] + 16, 24);
	glTexCoord2f(1.0f, 0.0f); glVertex2f(weekdays_real_width[whichday] + 16 + digits_width[whichweek], 24);
	glTexCoord2f(1.0f, 1.0f); glVertex2f(weekdays_real_width[whichday] + 16 + digits_width[whichweek], digits_height[whichweek] + 24);
	glTexCoord2f(0.0f, 1.0f); glVertex2f(weekdays_real_width[whichday] + 16, digits_height[whichweek] + 24);
	glEnd();
	
	
	int whichhour = hours();
	
	glBindTexture(GL_TEXTURE_2D, digits[whichhour]);
	glColor3f(1.0f, 1.0f, 1.0f);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f); glVertex2f(weekdays_real_width[whichday] + digits_width[whichweek] + 32, 24);
	glTexCoord2f(1.0f, 0.0f); glVertex2f(weekdays_real_width[whichday] + digits_width[whichweek] + 32 + digits_width[whichhour], 24);
	glTexCoord2f(1.0f, 1.0f); glVertex2f(weekdays_real_width[whichday] + digits_width[whichweek] + 32 + digits_width[whichhour], digits_height[whichhour] + 24);
	glTexCoord2f(0.0f, 1.0f); glVertex2f(weekdays_real_width[whichday]+ digits_width[whichweek] + 32, digits_height[whichhour] + 24);
	glEnd();
	
	glBindTexture(GL_TEXTURE_2D, colon);
	glColor3f(1.0f, 1.0f, 1.0f);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f); glVertex2f(weekdays_real_width[whichday] + digits_width[whichweek] + digits_width[whichhour] + 32, 24);
	glTexCoord2f(1.0f, 0.0f); glVertex2f(weekdays_real_width[whichday] + digits_width[whichweek] + digits_width[whichhour] + 32 + colon_width, 24);
	glTexCoord2f(1.0f, 1.0f); glVertex2f(weekdays_real_width[whichday] + digits_width[whichweek] + digits_width[whichhour] + 32 + colon_width, colon_height + 24);
	glTexCoord2f(0.0f, 1.0f); glVertex2f(weekdays_real_width[whichday]+ digits_width[whichweek] + digits_width[whichhour] + 32, colon_height + 24);
	glEnd();
	
	int whichminute = minutes();
	
	glBindTexture(GL_TEXTURE_2D, digits[whichminute]);
	glColor3f(1.0f, 1.0f, 1.0f);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f); glVertex2f(weekdays_real_width[whichday] + digits_width[whichweek] + digits_width[whichhour] + 32 + colon_width, 24);
	glTexCoord2f(1.0f, 0.0f); glVertex2f(weekdays_real_width[whichday] + digits_width[whichweek] + digits_width[whichhour] + 32 + colon_width + digits_width[whichminute], 24);
	glTexCoord2f(1.0f, 1.0f); glVertex2f(weekdays_real_width[whichday] + digits_width[whichweek] + digits_width[whichhour] + 32 + colon_width + digits_width[whichminute], digits_height[whichminute] + 24);
	glTexCoord2f(0.0f, 1.0f); glVertex2f(weekdays_real_width[whichday]+ digits_width[whichweek] + digits_width[whichhour] + 32 + colon_width, digits_height[whichminute] + 24);
	glEnd();
	
	
	
	
	
	
	
	
	if ((pop_gl == 0) || (prevpop != pop)) {
		if (prevpop != pop) {
			prevpop = pop;
			printf("creating pop because changed\n");
			glDeleteTextures(1, &pop_gl);
		}
		printf("creating pop_gl\n");
		SDL_Color foregroundColor = { 255, 255, 255 };
		SDL_Surface *pop_s;
		SDL_Surface *pop_gl_s;
		
		char poptext[64];
		sprintf(poptext, "%i people", pop);
		pop_s = TTF_RenderText_Blended(font, poptext, foregroundColor); 
		
		pop_gl_width = nextpoweroftwo(pop_s->w);
		pop_gl_height = nextpoweroftwo(pop_s->h);
		pop_gl_s = SDL_CreateRGBSurface(0, pop_gl_width, pop_gl_height, 32, 0x00ff0000, 0x0000ff00, 0x000000ff, 0xff000000); 
		SDL_BlitSurface(pop_s, 0, pop_gl_s, 0);
		
		int x = 0;
		int y = 0;
		int pitch = pop_gl_s->pitch;
		Uint32 *bufp;				
		while(y<pop_gl_s->h){
			while(x<pop_gl_s->w) { 
				bufp = (Uint32 *)pop_gl_s->pixels + y*pitch/4 + x; 
				*bufp = *bufp | ((*bufp & 0x00FF0000) << 8);
				x++;
			}
			x=0;
			y++;
		}
		
		glGenTextures(1, &pop_gl);
		glBindTexture(GL_TEXTURE_2D, pop_gl);
		glTexImage2D(GL_TEXTURE_2D, 0, 4, pop_gl_width, pop_gl_height, 0, GL_RGBA, GL_UNSIGNED_INT_8_8_8_8_REV, pop_gl_s->pixels );
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		SDL_FreeSurface(pop_s);
		SDL_FreeSurface(pop_gl_s);
	}
	
	glBindTexture(GL_TEXTURE_2D, pop_gl);
	glColor3f(1.0f, 1.0f, 1.0f);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f); glVertex2f(700, 8);
	glTexCoord2f(1.0f, 0.0f); glVertex2f(700 + pop_gl_width, 8);
	glTexCoord2f(1.0f, 1.0f); glVertex2f(700 + pop_gl_width, pop_gl_height + 8);
	glTexCoord2f(0.0f, 1.0f); glVertex2f(700, pop_gl_height + 8);
	glEnd();
	glBindTexture( GL_TEXTURE_2D, 0 );
	
	
	
	
	
	
	
	
	
	*/
}

void menudraw::glRectangle(int x1,int y1,int x2,int y2) {
	glBegin( GL_QUADS );
	glVertex3f( x1, y1, 0.0f );
	glVertex3f( x1, y2, 0 );
	glVertex3f( x2, y2, 0 );
	glVertex3f( x2, y1, 0 );
	glEnd();
}