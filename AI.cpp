#include "Main.h"



AI::AI()
{
	target = NULL;
	follow = false;
	sx = 0;
}


AI::~AI()
{
}

void AI::Move()
{
	if (target != NULL)
	{
		if (follow == true)
		{
			sx = sy = 0;
			if (x > target->x + 20)
				sx = -5;
			else if (x < target->x - 20)
				sx = 5;
			
		}
		else if (follow == false)
		{
				
				if (x >= 1150)
					sx *= -1;
				else if (x <= 850)
					sx *= -1;
				
		}
	}
}

	//rest of move in Physics class

