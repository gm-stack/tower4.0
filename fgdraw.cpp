/*
 *  fgdraw.cpp
 *  tower
 *
 *  Created by Geordie Millar on 13/06/09.
 *  Copyright 2009 __MyCompanyName__. All rights reserved.
 *
 */

#include "fgdraw.h"

fgdraw::fgdraw(Globals *g, floormanager *fm) {
	this->g = g;
	this->fm = fm;
}

void fgdraw::drawFG() {
	vector<flr*> floors = fm->floors;
	int i;
	for (i=0 ; i < floors.size(); i++ ) {
		this->DrawTowerFloor(floors[i]->leftbound,floors[i]->rightbound,i);
		this->DrawFireStairs(floors[i]->leftbound,floors[i]->rightbound,i);
		this->DrawBuildingObjects(floors[i]->objects);
	}
}


void fgdraw::DrawTowerFloor(int xfrom, int xto, int floor) {
	SDL_Rect dest;
	map<string,zImage*> _textures = g->tm->textures;
	
	if (floor == 0){
		dest.w = _textures["lobby"]->sizex;
		dest.h = _textures["lobby"]->sizey;
		dest.y = (36*floor + 8);
		while (xfrom < xto) {
			dest.x = 8 * xfrom;
			_textures["lobby"]->draw(dest.x,dest.y);
			xfrom++;
		}
	} else if (floor % 15 == 0) {
		dest.w = _textures["skylobby"]->sizex;
		dest.h = _textures["skylobby"]->sizey;
		dest.y = (36*floor + 8);
		while (xfrom < xto) {
			dest.x = 8 * xfrom;
			// FIXME: draws the extra half-bit
			
			if ((xfrom / 4) % 2) {
				_textures["skylobby_seat"]->draw(dest.x,dest.y);
			} else {
				_textures["skylobby"]->draw(dest.x,dest.y);
			}			
			xfrom = xfrom + 2;
		}
	} else {
		dest.w = _textures["empty"]->sizex;
		dest.h = _textures["empty"]->sizey;
		dest.y = (36*floor + 8);
		while (xfrom < xto) {
			dest.x = 8 * xfrom;
			_textures["empty"]->draw(dest.x,dest.y);
			xfrom++;
		}
	}
}

void fgdraw::DrawFireStairs(int xfrom, int xto, int floor) {
	SDL_Rect dest;
	map<string,zImage*> _textures = g->tm->textures;
	
	dest.x = 8 * (xfrom - 3);
	dest.y = (36 * floor + 8);
	dest.w = _textures["firestairs"]->sizex; 
	dest.h = _textures["firestairs"]->sizey;
	
	_textures["firestairs"]->draw(dest.x,dest.y);
	dest.x = 8 * xto;
	_textures["firestairs"]->draw(dest.x,dest.y);
}

void fgdraw::DrawBuildingObjects(vector<buildingobject*> objs) {
	int i;
	for (i=0 ; i < objs.size(); i++ ) {
		objs[i]->draw();
	}
}

