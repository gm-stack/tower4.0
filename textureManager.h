/*
 *  textureManager.h
 *  tower
 *
 *  Created by Geordie Millar on 9/06/09.
 *  Copyright 2009 __MyCompanyName__. All rights reserved.
 *
 */

#import "zImage.h"
#import <string>
#import <map>
using namespace std;

class textureManager {
public:
	textureManager();
	void loadAll();
	map<string,zImage*> textures;
};