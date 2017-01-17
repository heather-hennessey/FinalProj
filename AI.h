#pragma once
class AI :public GameObject
{
public:
	GameObject* target; 

	bool follow;
	int farness;
	int hint;

	AI();
	~AI();
	void Move();
};

