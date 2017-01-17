#pragma once
class Game
{
public:
	bool endGame;
	LevelOne l1;
	LevelTwo l2;
	LevelThree l3;
	ALLEGRO_KEYBOARD_STATE key_state;
	Game();
	~Game();
	void Run();
	void Update();
	void Draw();
};

