#include "Main.h"

ALLEGRO_DISPLAY* display = NULL; 
ALLEGRO_FONT *font;

void InitAllegro(int W, int H)
{

	//initialize allegro
	if (!al_init())
	{
		printf("failed to initialize allegro!\n");
	}

	//initialize display screen
	display = al_create_display(W, H);
	if (!display)
	{
		printf("failed to create display!\n");
		exit(0);
	}
	else
	{
		printf("ok");
		al_clear_to_color(al_map_rgb(0, 0, 0));
	}

	//initialize keyboard
	if (!al_install_keyboard())
	{
		printf("failed to install keyboard!\n");
		exit(0);
	}

	//initialize image addon
	if (!al_init_image_addon())
	{
		printf("failed to initialize image addon!\n");
		exit(0);
	}

	//initialize mouse
	if (!al_install_mouse())
	{
		printf("failed to install mouse!\n");
		exit(0);
	}
	//initialize primitive shapes
	if (!al_init_primitives_addon())
	{
		printf("failed to initialize primitives!\n");
		exit(0);
	}
	//initialize font
	al_init_font_addon(); // initialize the font addon
	al_init_ttf_addon();// initialize the ttf (True Type Font) addon	 (get fonts here: http://www.1001freefonts.com/)
	font = al_load_ttf_font("Early GameBoy.ttf", 12, 0); //secodn variable is size
													//font = al_load_font("a4_font.tga", 0, 0); //size variable doesn't matter becasue the font is fixed-size 
	if (!font)
	{
		printf("failed to create font!\n");
		exit(0);
	}
}

void EndAllegro()
{
	al_destroy_display(display);
}

void main()
{
	///////////////////////////////////
	// INITIALIZE
	///////////////////////////////////
	//bool endGame = false;

	//initialize allegro
	int sw = 640;
	int sh = 480;
	InitAllegro(sw, sh);

	//create main object
	Game game;

	///////////////////////////////////
	// LOOP (includes update and draw)
	///////////////////////////////////

	game.Run();

	//clean up
	EndAllegro();
}    