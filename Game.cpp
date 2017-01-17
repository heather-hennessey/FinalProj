#include "Main.h"



Game::Game()
{
}


Game::~Game()
{
}

void Game::Run()
{
	while (!endGame)
	{
		al_get_keyboard_state(&key_state);
		if (al_key_down(&key_state, ALLEGRO_KEY_ESCAPE))
			endGame = true;

		if (!l1.nifflerCaptured && !l2.demiCaptured&& !l3.pixieCaptured)
			l1.Run();
		if (l1.nifflerCaptured)
			l2.Run();
		if (l2.demiCaptured)
			l3.Run();
		if (l1.nifflerCaptured && l2.demiCaptured && l3.pixieCaptured)
			endGame = true;
	}
}

void Game::Update()
{

}

void Game::Draw()
{

}
