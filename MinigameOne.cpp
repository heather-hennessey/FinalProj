#include "Main.h"



MinigameOne::MinigameOne()
{
	srand(time(NULL));

	bg = al_load_bitmap("hp.jpg");
	bbmp = al_load_bitmap("bag.png");
	cbmp = al_load_bitmap("coin.png");

	for (int i = 0; i < NUM_COINS; i++)
	{
		coins[i].x = rand() % 640;
		coins[i].y = rand() % 200 - 300;
		coins[i].SetBitmap(cbmp);
		coins[i].sx = 0;
		coins[i].sy = rand() % 20 + 10;
	}

	bag.x = 100;
	bag.y = 250;

	score = 0;
	
	lose = false;

	timer.reset();

	physics.collisionMethod = CollisionMethod::Centre;

	beginPic = al_load_bitmap("Minigame1.png");
	begin.SetBitmap(beginPic);
	begin.x = begin.y = 0;
}


MinigameOne::~MinigameOne()
{
	al_destroy_bitmap(bbmp);
	al_destroy_bitmap(cbmp);
}

void MinigameOne::Run()
{
	while (!end)
	{
		Update();
		Draw();
		al_rest(0.1);
	}
}

void MinigameOne::Update()
{
	timer.start();
	bag.sx = bag.sy = 0;

	al_get_keyboard_state(&key_state);

	if (al_key_down(&key_state, ALLEGRO_KEY_ENTER))
	{
		begin.y = 1000;
	}

	bag.SetBitmap(bbmp);

	if (al_key_down(&key_state, ALLEGRO_KEY_RIGHT))
		bag.sx = 10;
	if (al_key_down(&key_state, ALLEGRO_KEY_LEFT))
		bag.sx = -10;

	bag.Move();

	for (int i = 0; i < NUM_COINS; i++)
	{
		if (coins[i].y >= 500)
		{
			coins[i].y = rand() % 50 - 150;
			coins[i].x = rand() % 640;
		}
		else
			coins[i].Move();
		physics.dist = 15;
		if (physics.Collision(&coins[i], &bag))
		{
			coins[i].x = 700;
			coins[i].sx = coins[i].sy = 0;
			if (score >= 10)
			{
				timer.stop();
				end = true;
			}
			else
				score++;

		}
	}

	if (timer.getTime() == 30)
	{
		timer.reset();
		score = 0;
		for (int i = 0; i < NUM_COINS; i++)
		{
			coins[i].y = rand() % 50 - 150;
			coins[i].x = rand() % 640;
		}
	}
}

void MinigameOne::Draw()
{
	render.Begin(bg);

	render.Draw2(&bag);
	for (int i = 0; i < NUM_COINS; i++)
		render.Draw2(&coins[i]);

	int time = timer.getTime();
	char scoretxt[] = "Score:";
	char timetxt[] = "Time:";
	render.Speak(scoretxt, 10, 30);
	render.Speak(timetxt, 10, 45);
	render.Value(score, 75, 10);
	render.Value(time, 65, 25);

	render.Draw2(&begin);
	render.End();
}
