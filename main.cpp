#import <stdio.h>
#import <stdlib.h>
#import <string.h>
#import <math.h>
#import <time.h>
#import <unistd.h>
#import <SDL_ttf/SDL_ttf.h>

#import "sdl.h"
#import "sdl_opengl.h"

#import "gametime.hpp"
#import "globals.h"
#import "bgdraw.h"
#import "floormanager.h"
#import "fgdraw.h"
#import "menudraw.h"

#import "office.h"

#define timebase 50


static unsigned int screen_width = 960;
static unsigned int screen_height = 720;
static unsigned int mode = 0;

SDL_Surface *screen;
SDL_TimerID timer1, timer2;

void addtimers(unsigned int timer1_time, unsigned int timer2_time);
void removetimers();
static Uint32 game_event_push(Uint32 interval, void* param);

int main(int argc, char *argv[])
{
	srandom(time(0) * getpid());
	int done;
		
	SDL_Event event;
	if ( SDL_Init(SDL_INIT_EVERYTHING) < 0 ) {
		fprintf(stderr, "Couldn't initialize SDL: %s\n",
			SDL_GetError());
		exit(1);
	}	
	SDL_GL_SetAttribute( SDL_GL_DOUBLEBUFFER, 1 ); 
	screen=SDL_SetVideoMode(screen_width,screen_height, 16, SDL_OPENGL | SDL_RESIZABLE);
		if (screen == NULL) {
		fprintf(stderr, "Couldn't set 800x600x%i video mode: %s\n",
						16, SDL_GetError());
		SDL_Quit();
		exit(2);
	}

	glEnable( GL_TEXTURE_2D );
	glViewport( 0, 0, screen_width, screen_height );
	glMatrixMode( GL_PROJECTION );
	glLoadIdentity();
	glOrtho(0.0f, screen_width, 0.0f, screen_height, -1.0f, 1.0f);
	glMatrixMode( GL_MODELVIEW );
	glLoadIdentity();
	
	glDisable(GL_DEPTH_TEST);
	glEnable(GL_BLEND);							// Enable Blending
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);		
	
	SDL_GL_SwapBuffers();
			
	addtimers(500,84000);

	unsigned int mousex;
	unsigned int mousey;

	
	TTF_Init(); 
	
	TTF_Font* font = TTF_OpenFont("tower.app/Contents/Resources/" "Vera.ttf", 12);  // FIXME: make this global
	if (font == NULL){
		printf("Unable to load font, exiting!\n");
		exit(1);
	}
	
	
	Globals *g = new Globals();
	g->screen_width = screen_width;
	g->screen_height = screen_height;
	
	g->font = font;
	
	textureManager *tm = new textureManager();
	g->tm = tm;
	GameTime *gt = new GameTime();
	g->gt = gt;
	
	tm->loadAll();
	
	g->bgim = tm->textures["buildingsbg"];
	
	bgdraw *bg = new bgdraw(g);
	floormanager *fm = new floormanager();
	fgdraw *fg = new fgdraw(g,fm);
	menudraw *mg = new menudraw(g);
	
	//////////////////////////////////////////////////////
	
	fm->build_floor(0,10,40);
	fm->build_floor(1,12,38);
	fm->build_floor(2,14,36);
	fm->changeFloorLeft(1, 11);
		
	office *of = new office(11,1,tm,gt);
	fm->addBuilding(1, of);
	of->occupied = true;
	office *of2 = new office(20,1,tm,gt);
	fm->addBuilding(1, of2);
	
	//////////////////////////////////////////////////////
	
	done = 0;
	while ( !done ) {

		/* Check for events */
		while ( SDL_PollEvent(&event) ) {
			switch (event.type) {
				case SDL_MOUSEMOTION:
					mousex = event.motion.x;
					mousey = event.motion.y;
					break;
				case SDL_USEREVENT:
					if(event.type==SDL_USEREVENT) {
						glClear( GL_COLOR_BUFFER_BIT );
						
						bg->drawBG();
						fg->drawFG();
						mg->drawMenu();
						
						SDL_GL_SwapBuffers();
						Uint32 time = 50;
						timer1 = SDL_AddTimer(time, game_event_push, NULL);
					}
					break;
				case (SDL_USEREVENT+1):
					if(event.type==(SDL_USEREVENT+1)) {
//						timer2 = SDL_AddTimer(84000, rent_event_push, 0);
					}
					break;
				case SDL_MOUSEBUTTONDOWN:
			//			toolLayerClicked(event.button.x,event.button.y);
					break;
				case SDL_MOUSEBUTTONUP:
						//toolLayerUnClicked(event.button.x,event.button.y);
					break;
				case SDL_VIDEORESIZE:
					screen_width = event.resize.w;
					screen_height = event.resize.h;
					
					/*screen=SDL_SetVideoMode(screen_width,screen_height, 16, SDL_OPENGL | SDL_RESIZABLE);
					if (screen == NULL) {
						fprintf(stderr,"Unable to grab surface after resize event: %s\n",SDL_GetError());
						exit(1);
					}*/
						

					glOrtho(0.0f, 1000, 1000, 0.0f, -1.0f, 1.0f);
					glViewport( 0, 0, screen_width, screen_height );
					glLoadIdentity();
					break;
				case SDL_KEYDOWN:
					switch(event.key.keysym.sym){
						case SDLK_q:
							removetimers();
							SDL_Quit();
							break;
						case SDLK_UP:
							g->y -= 10;
							glViewport( 0+g->x, 0+g->y, screen_width, screen_height );
							glLoadIdentity();
							break;
						case SDLK_DOWN:
							g->y += 10;
							glViewport( 0+g->x, 0+g->y, screen_width, screen_height );
							glLoadIdentity();
							break;
						case SDLK_LEFT:
							g->x += 10;
							glViewport( 0+g->x, 0+g->y, screen_width, screen_height );
							glLoadIdentity();

							break;
						case SDLK_RIGHT:
							g->x -= 10;
							glViewport( 0+g->x, 0+g->y, screen_width, screen_height );
							glLoadIdentity();

							break;
						default:
							break;
					}
					break;
				case SDL_QUIT:
					puts("Quitting");
					removetimers();
					done = 1;
					break;
				default:
					break;
			}
		}
	}
	
	/* Clean up the SDL library */
	puts("reached SDL_QUIT");
	SDL_Quit();
	return(0);
}


static Uint32 game_event_push(Uint32 interval, void* param)
{
	SDL_Event event;
	event.type = SDL_USEREVENT;
	//event.user.data1 = 1;
	SDL_PushEvent(&event);
	return 0; //0 means stop timer
}

int rent_event_push(int a) {
	SDL_Event event;
	event.type = (SDL_USEREVENT + 1);
	//event.user.data1 = 1;
	SDL_PushEvent(&event);
	return 0; /* 0 means stop timer */
}

int office_redraw_event_push(int a) {
	SDL_Event event;
	event.type = (SDL_USEREVENT + 2);
	//event.user.data1 = 1;
	SDL_PushEvent(&event);
	return 0; /* 0 means stop timer */
}

/*int screenshot(int newsockfd) {
	char image[32768];
	bzero(image,32768);
	SDL_SaveBMP(screen, "/tmp/tower_image.bmp");
	FILE *fp;
	fp = fopen("/tmp/tower_image.bmp","rb");
	while (fread(image,8192,4,fp) > 0) {
		write(newsockfd,image,32768);
	}
	close(newsockfd);
	close(fp);
}*/


void removetimers() {
	SDL_RemoveTimer(timer1);
	SDL_RemoveTimer(timer2);
}

void addtimers(unsigned int timer1_time, unsigned int timer2_time) {
	//timer2 = SDL_AddTimer(timer2_time, rent_event_push, 0); // 84000
	timer1 = SDL_AddTimer(timebase, game_event_push, 0);
}