/*
 *  time.hpp
 *  tower2
 *
 *  Created by Geordie Millar on 1/12/07.
 *  Copyright 2007 __MyCompanyName__. All rights reserved.
 *
 */

#import "sdl.h"

class GameTime {
	public:
	Uint32 offset;
	Uint32 offsetFromFile;
	
	GameTime();
	void zeroCounterAndSetOffsetFromFile(Uint32 theOffset);
	Uint32 weeks();
	unsigned int days();
	char* day(unsigned int thisday);
	Uint32 ticks();
	Uint32 hours();
	int dayticks();
	float frachours();
	Uint32 minutes();

};