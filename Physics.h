#pragma once

enum CollisionMethod
{
	TopLeft,
	Centre,
	InsideRect
};

class Physics
{
public:
	CollisionMethod collisionMethod;
	int numLevels;
	float* yLevel;
	float* xLevel;
	int newx;
	int ground;
	int new_ground;
	bool hitWall;
	int dist;

	Physics();
	~Physics();

	bool Collision(GameObject* o1, GameObject* o2);
	bool Collision1(GameObject* o1, GameObject* o2);
	bool Collision2(GameObject* o1, GameObject* o2);
	bool Collision3(GameObject* o1, GameObject* o2);
	bool Collision5(GameObject o1, GameObject o2);

	void Move(GameObject* obj);
};

