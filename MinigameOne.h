#pragma once
#define NUM_COINS 20


class MinigameOne :
	public MinigameThree
{
public:
	int score;
	GameObject bag;
	ALLEGRO_BITMAP* bbmp;
	GameObject coins[NUM_COINS];
	ALLEGRO_BITMAP* cbmp;
	Timer timer;
	bool lose;


	MinigameOne();
	~MinigameOne();

	void Run();
	void Update();
	void Draw();
};

