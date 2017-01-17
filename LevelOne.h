#pragma once
class LevelOne
{
public:
	ALLEGRO_KEYBOARD_STATE key_state;
	ALLEGRO_MOUSE_STATE mouse_state;

	Render render;
	Physics physics;

	AnimatedObject player;
	ALLEGRO_BITMAP* pbmp;

	MinigameOne mg1;

	ALLEGRO_BITMAP* bg;

	GameObject begin;
	ALLEGRO_BITMAP* beginPic;
	int bgw;
	int bgh;
	int oldx, dx;
	

	bool end;
	bool nifflerCaptured;
	bool demiCaptured;
	bool pixieCaptured;
	bool pushedBack;
	bool menu;
	bool evanesco;
	int play;
	int score;
	int checkpoint;

	int mousex;
	int mousey;
	int selected;
	int health;

	AI elf;
	ALLEGRO_BITMAP* ebmp;
	AI snape;
	ALLEGRO_BITMAP* sbmp;

	GameObject caught;
	ALLEGRO_BITMAP* cbmp;
	ALLEGRO_BITMAP* cbmp1;
	ALLEGRO_BITMAP* cbmp2;
	ALLEGRO_BITMAP* cbmp3;

	AnimatedObject healthT;
	ALLEGRO_BITMAP* hbmp;
	ALLEGRO_BITMAP* hbmp2;
	ALLEGRO_BITMAP* hbmp3;
	ALLEGRO_BITMAP* hbmp4;
	ALLEGRO_BITMAP* hbmp5;

	LevelOne();
	~LevelOne();

	void Run();
	void Update();
	void Draw();
};

