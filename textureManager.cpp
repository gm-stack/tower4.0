/*
 *  textureManager.cpp
 *  tower
 *
 *  Created by Geordie Millar on 9/06/09.
 *  Copyright 2009 __MyCompanyName__. All rights reserved.
 *
 */

#include "textureManager.h"

#define system_filepath "tower.app/Contents/Resources/"

textureManager::textureManager() {
}

void textureManager::loadAll() {
	textures["buildingsbg"] = new zImage(system_filepath "images/buildingsbg.bmp");
	
	textures["bulletpoint"] = new zImage(system_filepath "images/bulletpoint.bmp");
	
	textures["elevator_above"] = new zImage(system_filepath "images/elevator_above.bmp");
	textures["elevator_back"] = new zImage(system_filepath "images/elevator_back.bmp");
	textures["elevator_bottom"] = new zImage(system_filepath "images/elevator_bottom.bmp");
	textures["elevator_top"] = new zImage(system_filepath "images/elevator_top.bmp");
	
	textures["empty"] = new zImage(system_filepath "images/empty.bmp");
	textures["skylobby"] = new zImage(system_filepath "images/skylobby.bmp");
	textures["skylobby_seat"] = new zImage(system_filepath "images/skylobby_seat.bmp");
	textures["lobby"] = new zImage(system_filepath "images/lobby.bmp");
	
	textures["firestairs"] = new zImage(system_filepath "images/firestairs.bmp");
	
	textures["office_1_wkdy_busy_1"] = new zImage(system_filepath "images/office_1_wkdy_busy_1.bmp");
	textures["office_1_wkdy_busy_2"] = new zImage(system_filepath "images/office_1_wkdy_busy_2.bmp");
	textures["office_1_wkdy_busy_3"] = new zImage(system_filepath "images/office_1_wkdy_busy_3.bmp");
	textures["office_1_wkdy_busy_4"] = new zImage(system_filepath "images/office_1_wkdy_busy_4.bmp");
	
	textures["office_1_wkdy_construction_1"] = new zImage(system_filepath "images/office_1_wkdy_construction_1.bmp");
	textures["office_1_wkdy_construction_2"] = new zImage(system_filepath "images/office_1_wkdy_construction_2.bmp");
	textures["office_1_wkdy_construction_3"] = new zImage(system_filepath "images/office_1_wkdy_construction_3.bmp");
	textures["office_1_wkdy_construction_4"] = new zImage(system_filepath "images/office_1_wkdy_construction_4.bmp");
	
	textures["office_1_wkdy_empty"] = new zImage(system_filepath "images/office_1_wkdy_empty.bmp");
	textures["office_1_wkdy_unused"] = new zImage(system_filepath "images/office_1_wkdy_unused.bmp");
	
	textures["office_2_wkdy_busy_1"] = new zImage(system_filepath "images/office_2_wkdy_busy_1.bmp");
	textures["office_2_wkdy_busy_2"] = new zImage(system_filepath "images/office_2_wkdy_busy_2.bmp");
	textures["office_2_wkdy_busy_3"] = new zImage(system_filepath "images/office_2_wkdy_busy_3.bmp");
	textures["office_2_wkdy_busy_4"] = new zImage(system_filepath "images/office_2_wkdy_busy_4.bmp");
	
	textures["office_2_wkdy_construction_1"] = new zImage(system_filepath "images/office_2_wkdy_construction_1.bmp");
	textures["office_2_wkdy_construction_2"] = new zImage(system_filepath "images/office_2_wkdy_construction_2.bmp");
	textures["office_2_wkdy_construction_3"] = new zImage(system_filepath "images/office_2_wkdy_construction_3.bmp");
	textures["office_2_wkdy_construction_4"] = new zImage(system_filepath "images/office_2_wkdy_construction_4.bmp");
	
	textures["office_2_wkdy_empty"] = new zImage(system_filepath "images/office_2_wkdy_empty.bmp");
	textures["office_2_wkdy_unused"] = new zImage(system_filepath "images/office_2_wkdy_unused.bmp");
	textures["office_3_wkdy_busy_1"] = new zImage(system_filepath "images/office_3_wkdy_busy_1.bmp");
	textures["office_3_wkdy_busy_2"] = new zImage(system_filepath "images/office_3_wkdy_busy_2.bmp");
	textures["office_3_wkdy_busy_3"] = new zImage(system_filepath "images/office_3_wkdy_busy_3.bmp");
	textures["office_3_wkdy_busy_4"] = new zImage(system_filepath "images/office_3_wkdy_busy_4.bmp");
	
	textures["office_3_wkdy_construction_1"] = new zImage(system_filepath "images/office_3_wkdy_construction_1.bmp");
	textures["office_3_wkdy_construction_2"] = new zImage(system_filepath "images/office_3_wkdy_construction_2.bmp");
	textures["office_3_wkdy_construction_3"] = new zImage(system_filepath "images/office_3_wkdy_construction_3.bmp");
	textures["office_3_wkdy_construction_4"] = new zImage(system_filepath "images/office_3_wkdy_construction_4.bmp");
	
	textures["office_3_wkdy_empty"] = new zImage(system_filepath "images/office_3_wkdy_empty.bmp");
	textures["office_3_wkdy_unused"] = new zImage(system_filepath "images/office_3_wkdy_unused.bmp");
	textures["office_4_wkdy_busy_1"] = new zImage(system_filepath "images/office_4_wkdy_busy_1.bmp");
	textures["office_4_wkdy_busy_2"] = new zImage(system_filepath "images/office_4_wkdy_busy_2.bmp");
	textures["office_4_wkdy_busy_3"] = new zImage(system_filepath "images/office_4_wkdy_busy_3.bmp");
	textures["office_4_wkdy_busy_4"] = new zImage(system_filepath "images/office_4_wkdy_busy_4.bmp");
	
	textures["office_4_wkdy_construction_1"] = new zImage(system_filepath "images/office_4_wkdy_construction_1.bmp");
	textures["office_4_wkdy_construction_2"] = new zImage(system_filepath "images/office_4_wkdy_construction_2.bmp");
	textures["office_4_wkdy_construction_3"] = new zImage(system_filepath "images/office_4_wkdy_construction_3.bmp");
	textures["office_4_wkdy_construction_4"] = new zImage(system_filepath "images/office_4_wkdy_construction_4.bmp");
	
	textures["office_4_wkdy_empty"] = new zImage(system_filepath "images/office_4_wkdy_empty.bmp");
	textures["office_4_wkdy_unused"] = new zImage(system_filepath "images/office_4_wkdy_unused.bmp");
	
	textures["restaurant_1_empty_1"] = new zImage(system_filepath "images/restaurant_1_empty_1.bmp");
	
	textures["selected"] = new zImage(system_filepath "images/selected.bmp");
	
	textures["titlebg"] = new zImage(system_filepath "images/titlebg.bmp");
	textures["unselected"] = new zImage(system_filepath "images/unselected.bmp");
	
	textures["x"] = new zImage(system_filepath "images/x.bmp");
	textures["x_cursor"] = new zImage(system_filepath "images/x_cursor.bmp");	
}