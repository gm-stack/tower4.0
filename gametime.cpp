/*
 *  time.c
 *  tower
 *
 *  Created by Geordie Millar on 7/02/07.
 *  Copyright 2007 __MyCompanyName__. All rights reserved.
 *
 */

#import "gametime.hpp"
#import <math.h>


/*****************************************
 * There are multiple factors in play here. The first of them being the actual number of ticks.
 * The second being the number at which the file was saved
 * The third being the time now, when the time's loaded
 *****************************************/



GameTime::GameTime() {
	offset = 0;
	offsetFromFile = 0;
}

void GameTime::zeroCounterAndSetOffsetFromFile(Uint32 theOffset) { // you must zero the counter when the file is loaded, and set the offset to this
	offset = SDL_GetTicks(); // subtracted from future calls, this zeros it
	offsetFromFile = theOffset; // and this is the offset...
}

Uint32 GameTime::weeks() {
	Uint32 time;
	div_t weeks;
	time = (SDL_GetTicks() - offset) + offsetFromFile;
	weeks = div(time,84000);
	return weeks.quot;
}

unsigned int GameTime::days() {
	Uint32 time;
	time = (SDL_GetTicks() - offset) + offsetFromFile;
	div_t days, days2;
	days = div(time,12000);
	days2 = div(days.quot,7);
	return days2.rem;
}

char* GameTime::day(unsigned int thisday) {
	switch (thisday) {
	case 0:
		return("Sunday, week ");
		break;
	case 1:
		return("Monday, week ");
		break;
	case 2:
		return("Tuesday, week ");
		break;
	case 3:
		return("Wednesday, week ");
		break;
	case 4:
		return("Thursday, week ");
		break;
	case 5:
		return("Friday, week ");
		break;
	case 6:
		return("Saturday, week ");
		break;
	case 7:
		return("Sunday, week ");
		break;
	default:
		return("Unknown Day - WTF!?"); // this shouldn't happen...
		break;
	}
}

Uint32 GameTime::ticks() {
	return (SDL_GetTicks() - offset) + offsetFromFile;
}

Uint32 GameTime::hours() {
	Uint32 time;
	time = (SDL_GetTicks() - offset) + offsetFromFile;
	div_t hours, hours2;
	hours = div(time,500);
	hours2 = div(hours.quot,24);
	return hours2.rem;
}

int GameTime::dayticks() {
	Uint32 time;
	time = (SDL_GetTicks() - offset) + offsetFromFile;
	div_t days,	;
	days = div(time,12000);
	return days.rem;
}

float GameTime::frachours() {
	Uint32 time;
	time = SDL_GetTicks();
	//time = time - offset;
	//time = time + offsetFromFile;
	div_t hours;
	hours = div(time,12000);
	float frachr;
	frachr = hours.rem/(float)500;
	return frachr;
}


Uint32 GameTime::minutes() {
	Uint32 time;
	time = (SDL_GetTicks() - offset) + offsetFromFile;
	div_t minutes, minutes2;
	minutes = div(time,8);
	minutes2 = div(minutes.quot,60);
	return minutes2.rem;
}