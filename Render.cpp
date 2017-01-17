#include "Main.h"

extern ALLEGRO_FONT* font;

Render::Render()
{
	xscroll = yscroll = 0;
}


Render::~Render()
{
}

void Render::Speak(char* text, int x, int y)
{
	al_draw_text(font, al_map_rgb(255, 255, 255), x, y - 20, 0, text);
}

void Render::Value(int var, int x, int y)
{
	al_draw_textf(font, al_map_rgb(255, 255, 255), x, y, 0, "%d", var);
}

void Render::Draw(GameObject* obj)
{
	
	al_draw_bitmap(obj->GetBitmap(), obj->x - xscroll, obj->y, 0);
	
}

void Render::Draw2(GameObject* obj)
{
	if (obj->GetBitmap() != NULL)
		al_draw_bitmap(obj->GetBitmap(), obj->x, obj->y, 0);
}

void Render::Begin(ALLEGRO_BITMAP* bg)
{
	al_draw_bitmap(bg, 0 - xscroll, 0 - yscroll, 0);
}

void Render::End()
{

	al_flip_display();
}