/*
 *  buildingobject.cpp
 *  tower
 *
 *  Created by Geordie Millar on 13/06/09.
 *  Copyright 2009 __MyCompanyName__. All rights reserved.
 *
 */

#include "buildingobject.h"

buildingobject::buildingobject(int position, int width, int floor, int activestart, int activefinish, GameTime *gt) {
	this->position = position;
	this->width = width;
	this->floor = floor;
	this->activestart = activestart;
	this->activefinish = activefinish;
	occupied = false;
	this->gt = gt;
}


bool buildingobject::willcollide(int left, int right) {
	if ((left > position) && (left < (position + width))) return true;
	if ((right > position) && (right < (position + width))) return true;
	return false;
}

void buildingobject::draw() {
	if (!occupied) {
		emptytextures[0]->draw(position*8,(floor*36 + 8));
	} else {
		if (opendays[gt->days()]) {
			int hours = gt->frachours();
			if ((hours > activestart) && (hours < activefinish)) {
				activetextures[0]->draw(position*8,(floor*36 + 8));
			} else {
				idletextures[0]->draw(position*8,(floor*36 + 8));
			}
		} else {
			idletextures[0]->draw(position*8,(floor*36 + 8));
		}
	}
}


int buildingobject::calcMaintainance() {
	return 0;
}

int buildingobject::calcIncome() {
	return 0;
}

int buildingobject::incomeType() {
	return 0;
}

int buildingobject::numOccupants() {
	return 0;
}