/*
 *  office.cpp
 *  tower
 *
 *  Created by Geordie Millar on 14/06/09.
 *  Copyright 2009 __MyCompanyName__. All rights reserved.
 *
 */

#include "office.h"

office::office(int position, int floor, textureManager *tm, GameTime *gt)
: buildingobject(position, 9, floor, 9, 17, gt)
{
	bool opendays[] = {false, true, true, true, true, true, false};	
	int i = 0;
	for(i=0;i<7;i++) {
		this->opendays[i] = opendays[i];
	}
	
	srandom(time(0) * getpid());
	i = ((rand() % 4) + 1);	
	switch (i) {
		case 1:
			emptytextures.push_back(tm->textures["office_1_wkdy_empty"]);
			idletextures.push_back(tm->textures["office_1_wkdy_unused"]);
			activetextures.push_back(tm->textures["office_1_wkdy_busy_1"]);
			activetextures.push_back(tm->textures["office_1_wkdy_busy_2"]);
			activetextures.push_back(tm->textures["office_1_wkdy_busy_3"]);
			activetextures.push_back(tm->textures["office_1_wkdy_busy_4"]);
			constructiontextures.push_back(tm->textures["office_1_wkdy_construction_1"]);
			constructiontextures.push_back(tm->textures["office_1_wkdy_construction_2"]);
			constructiontextures.push_back(tm->textures["office_1_wkdy_construction_3"]);
			constructiontextures.push_back(tm->textures["office_1_wkdy_construction_4"]);
			break;
		case 2:
			emptytextures.push_back(tm->textures["office_2_wkdy_empty"]);
			idletextures.push_back(tm->textures["office_2_wkdy_unused"]);
			activetextures.push_back(tm->textures["office_2_wkdy_busy_1"]);
			activetextures.push_back(tm->textures["office_2_wkdy_busy_2"]);
			activetextures.push_back(tm->textures["office_2_wkdy_busy_3"]);
			activetextures.push_back(tm->textures["office_2_wkdy_busy_4"]);
			constructiontextures.push_back(tm->textures["office_2_wkdy_construction_1"]);
			constructiontextures.push_back(tm->textures["office_2_wkdy_construction_2"]);
			constructiontextures.push_back(tm->textures["office_2_wkdy_construction_3"]);
			constructiontextures.push_back(tm->textures["office_2_wkdy_construction_4"]);
			break;
		case 3:
			emptytextures.push_back(tm->textures["office_3_wkdy_empty"]);
			idletextures.push_back(tm->textures["office_3_wkdy_unused"]);
			activetextures.push_back(tm->textures["office_3_wkdy_busy_1"]);
			activetextures.push_back(tm->textures["office_3_wkdy_busy_2"]);
			activetextures.push_back(tm->textures["office_3_wkdy_busy_3"]);
			activetextures.push_back(tm->textures["office_3_wkdy_busy_4"]);
			constructiontextures.push_back(tm->textures["office_3_wkdy_construction_1"]);
			constructiontextures.push_back(tm->textures["office_3_wkdy_construction_2"]);
			constructiontextures.push_back(tm->textures["office_3_wkdy_construction_3"]);
			constructiontextures.push_back(tm->textures["office_3_wkdy_construction_4"]);
			break;
		case 4:
			emptytextures.push_back(tm->textures["office_4_wkdy_empty"]);
			idletextures.push_back(tm->textures["office_4_wkdy_unused"]);
			activetextures.push_back(tm->textures["office_4_wkdy_busy_1"]);
			activetextures.push_back(tm->textures["office_4_wkdy_busy_2"]);
			activetextures.push_back(tm->textures["office_4_wkdy_busy_3"]);
			activetextures.push_back(tm->textures["office_4_wkdy_busy_4"]);
			constructiontextures.push_back(tm->textures["office_4_wkdy_construction_1"]);
			constructiontextures.push_back(tm->textures["office_4_wkdy_construction_2"]);
			constructiontextures.push_back(tm->textures["office_4_wkdy_construction_3"]);
			constructiontextures.push_back(tm->textures["office_4_wkdy_construction_4"]);
			break;
		default:
			printf("rand failed in allocation of office: %i\n", i);
			exit(0);
			break;
	}

}

int calcMaintainance();
int calcIncome();
int incomeType();
int numOccupants();