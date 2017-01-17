#include "Main.h"



LevelOne::LevelOne()
{
	srand(time(NULL));

	//load background
	bg = al_load_bitmap("bg-01.png");
	bgw = al_get_bitmap_width(bg);
	bgh = al_get_bitmap_height(bg);

	//initialize load screen
	beginPic = al_load_bitmap("Begin.png");
	begin.x = begin.y = 0;
	begin.SetBitmap(beginPic);

	end = false;
	nifflerCaptured = false;
	demiCaptured = false;
	pixieCaptured = false;
	pushedBack = false;
	menu = true;

	physics.collisionMethod = CollisionMethod::InsideRect;

	//initialize ground level changes
	physics.numLevels = 6;
	physics.yLevel = (float*)malloc(6.0 * sizeof(float));
	physics.xLevel = (float*)malloc(6.0 * sizeof(float));

	physics.xLevel[0] = 100;
	physics.xLevel[1] = 450;
	physics.xLevel[2] = 705;
	physics.xLevel[3] = 810;
	physics.xLevel[4] = 1225;
	physics.xLevel[5] = 1475;

	physics.yLevel[0] = physics.yLevel[3] = physics.yLevel[5] = 395;
	physics.yLevel[1] = physics.yLevel[4] = 355;
	physics.yLevel[2] = 315;

	//initialize player
	pbmp = al_load_bitmap("player.png");
	player.SetBitmap(pbmp);
	player.x = 100;
	player.y = physics.yLevel[0] - al_get_bitmap_height(player.GetBitmap());
	player.sx = player.sy = 0;

	//initialize elf
	ebmp = al_load_bitmap("elf.png");
	elf.SetBitmap(ebmp);
	elf.x = player.x - 20;
	elf.y = physics.yLevel[0] - al_get_bitmap_height(elf.GetBitmap());
	elf.target = &player;
	
	elf.hint = -1;


	//initialize snape
	sbmp = al_load_bitmap("snape.png");
	snape.SetBitmap(sbmp);
	snape.x = physics.xLevel[3] + 200;
	snape.y = physics.yLevel[3] - al_get_bitmap_height(sbmp);
	snape.target = &player;
	snape.sx = -2;


	//initialize caught creatures display
	cbmp = al_load_bitmap("caught0.png");
	cbmp1 = al_load_bitmap("caught1.png");
	cbmp2 = al_load_bitmap("caught2.png");
	cbmp3 = al_load_bitmap("caught3.png");
	caught.SetBitmap(cbmp);
	caught.x = 0;
	caught.y = 0;

	//initialize health display
	hbmp = al_load_bitmap("health5.png");
	healthT.SetBitmap(hbmp);
	hbmp2 = al_load_bitmap("health4.png");
	hbmp3 = al_load_bitmap("health3.png");
	hbmp4 = al_load_bitmap("health2.png");
	hbmp5 = al_load_bitmap("health1.png");
	healthT.x = 545;
	healthT.y = 5;

	health = 5;
	
	ofstream file("NewHCCGame.txt");
	if (file.is_open())
	{
		//output
		file << player.x << "\n" << player.y << "\n" << health << "\n" << elf.x << "\n" << elf.y << "\n" << nifflerCaptured << "\n" << demiCaptured << "\n" << pixieCaptured << "\n" << render.xscroll;
		file.close();
	}
}


LevelOne::~LevelOne()
{

}

void LevelOne::Run()
{
	while (!end)
	{
		Update();
		Draw();
		al_rest(0.1);
	}
}

void LevelOne::Update()
{
	if (nifflerCaptured)
		end = true;

	if (player.x >= bgw - 80)
		mg1.Run();
	
	if (mg1.end)
		nifflerCaptured = true;

	physics.collisionMethod = CollisionMethod::TopLeft;

	al_get_keyboard_state(&key_state);

	if (al_key_down(&key_state, ALLEGRO_KEY_ENTER))
	{
		begin.y = 1000;
	}

	if (al_key_down(&key_state, ALLEGRO_KEY_ESCAPE))
	{
		//end = true;
		menu = true;
		elf.hint = -1;
		snape.follow = false;
	}

	if (nifflerCaptured)
		end = true;

	player.SetBitmap(pbmp);
	player.sx = player.sy = 0;
	elf.follow = true;
	
	snape.follow = false;

	if (menu == true)
	{
		if (al_key_down(&key_state, ALLEGRO_KEY_0))
		{
			//Resume
			menu = false;
			
		}
		if (al_key_down(&key_state, ALLEGRO_KEY_1))
		{
			//Load New Game
			ifstream inputFile("NewHCCGame.txt");
			if (inputFile.is_open())
			{
				//input
				while (inputFile >> player.x >> player.y >> health >> elf.x >> elf.y >> nifflerCaptured >> demiCaptured >> pixieCaptured >> render.xscroll)
				{
					menu = false;
				}

				inputFile.close();
			}
		}
		if (al_key_down(&key_state, ALLEGRO_KEY_2))
		{
			//Save Game
			ofstream file("HCCGameSave.txt");
			if (file.is_open())
			{
				//output
				file << player.x << "\n" << player.y << "\n" << health << "\n" << elf.x << "\n" << elf.y << "\n" << nifflerCaptured << "\n" << demiCaptured << "\n" << pixieCaptured << "\n" << render.xscroll;
				file.close();
			}
		}
		if (al_key_down(&key_state, ALLEGRO_KEY_3))
		{
			//Load Saved Game
			ifstream inputFile("HCCGameSave.txt");
			if (inputFile.is_open())
			{
				//input
				while (inputFile >> player.x >> player.y >> health >> elf.x >> elf.y >> nifflerCaptured >> demiCaptured >> pixieCaptured >> render.xscroll)
				{
					menu = false;
				}

				inputFile.close();
			}
		}
		if (al_key_down(&key_state, ALLEGRO_KEY_4))
		{
			//Quit
			exit(0);
		}
	}
	if (menu == false)
	{
		
		//moving player using arrow keys
		if (al_key_down(&key_state, ALLEGRO_KEY_RIGHT))
		{
			
			if (render.xscroll < bgw - 640)
			{
				if (!physics.hitWall)
					player.sx = 5;
					
				else
					player.sx = 0;
				//player.Advance();
			}
			if (player.x < bgw - 80)
				player.sx = 5;
			else if (player.x >= bgw - 80)
				player.sx = 0;
		}
		if (al_key_down(&key_state, ALLEGRO_KEY_LEFT))
		{
			if (render.xscroll > 0)
			{
				if (player.x < bgw - 550)
				{
					if (!physics.hitWall)
						player.sx = -5;
					else
						player.sx = 0;
				}
				player.sx = -5;
				//player.Advance();
			}
		}
		if (al_key_down(&key_state, ALLEGRO_KEY_SPACE))
		{
			player.jump = true;
			elf.jump = true;
			player.v0 = elf.v0 = -15;
			player.y0 = player.y;
			elf.y0 = elf.y;
			
		}

		if (al_key_down(&key_state, ALLEGRO_KEY_E))
		{
			//Evanesco
			snape.y = 1000;
			snape.x = -500;
			snape.follow = false;
			elf.hint = 2;
			evanesco = true;
		}
		if (physics.Collision(&snape, &player))
		{
			health--;
			pushedBack = true;
			if (health == 4) {
				healthT.SetBitmap(hbmp2);
			}
			if (health == 3) {
				healthT.SetBitmap(hbmp3);
			}
			if (health == 2) {
				healthT.SetBitmap(hbmp4);
			}
			if (health == 1) {
				healthT.SetBitmap(hbmp5);
			}
			if (health == 0) {
				end = true;
			}
		}

		//move player, elf and snape
		oldx = player.x;
		physics.Move(&player);
		if (pushedBack)
			player.x -= 110;
		pushedBack = false;
		dx = oldx - player.x;
		if (player.x < bgw - 550)
			render.xscroll -= dx;

		
		
		elf.Move();
		physics.Move(&elf);
		if (pushedBack)
			elf.x -= 110;
		pushedBack = false;
		
		//physics.Move(&elf);
		physics.dist = 400;
		if (physics.Collision(&elf, &snape))
			elf.hint = 0;
		physics.dist = 100;
		if (physics.Collision(&snape, &player))
		{
			snape.follow = true;
			elf.hint = 1;
		}
		if (evanesco == false)
		{
			snape.Move();
			physics.Move(&snape);
		}
		
	}
}

void LevelOne::Draw()
{
	render.Begin(bg);

	render.Draw2(&caught);
	render.Draw2(&healthT);
	render.Draw(&player);
	render.Draw(&elf);
	render.Draw(&snape);

	if (menu == true)
	{
		char Menu[] = "0-Resume 1-New Game 2-Save Game 3-Load Game 4-Exit";
		render.Speak(Menu, 40, 150);

	}
	if (elf.hint == 0)
	{
		char elftxt1[] = "Press e to use evanesco it makes enemies disappear";
		render.Speak(elftxt1, elf.x - render.xscroll - 30, elf.y - 50);
	}
	if (elf.hint == 1)
	{
		char elftxt1[] = "Use evanesco!";
		render.Speak(elftxt1, elf.x - render.xscroll, elf.y - 50);
	}
	if (elf.hint == 2)
	{
		char elftxt2[] = "Good job, that was close";
		render.Speak(elftxt2, elf.x - render.xscroll, elf.y);
	}
	if (snape.follow == true)
	{
		char snapetxt[] = "Go back to bed!";
		render.Speak(snapetxt, snape.x, snape.y);
	}

	render.Draw2(&begin);

	render.End();
}
