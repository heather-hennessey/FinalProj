#pragma once
class Render
{
public:
	Effect effect;

	int xscroll, yscroll;

	Render();
	~Render();
	void Speak(char* text, int x, int y);
	void Value(int var, int x, int y);
	void Draw(GameObject* obj);	
	void Draw2(GameObject*obj);
	void Begin(ALLEGRO_BITMAP* bg);
	void End();
};

