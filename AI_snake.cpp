#include "AI_snake.h"

AI_snake::AI_snake(int x, int y)
	:Snake(x, y), solution(){}

// Always calculate current solution, but each time that assign direction is called
// check how safe current solution is and replan in case necessary (some cost threshold perhaps?)

void AI_snake::assign_direction(SDL_Keycode k, pair<int, int> f, vector<pair<int, int>> obstacles)
{
	
	pair<int, int> current = body.at(0);

	// In case there is not yet a solution or in case the goal changed OR TODO: if path is too risky
	// recalculate a solution
	if (solution.size() == 0 || !goal_reached(solution.at(solution.size() - 1), f))
	{
		solution = solve(current, f, obstacles);
	}
	cout << endl;

	if (!goal_reached(solution.at(0), body.at(0)))
	{
		solution.erase(solution.begin());
	}
	/*
	cout << "solution size: " << solution.size() << endl;
	for (int i = 0; i < solution.size(); i++)
	{
		cout << solution.at(i).first << " " << solution.at(i).second << endl;
	}
	cout << "Current: " << current.first << " " << current.second << endl;
	cout << "Second: " << solution.at(1).first << " " << solution.at(1).second << endl;
	*/
	// Change direction depending on the first next movement
	if (solution.at(1).first != current.first)
	{
		if (current.first == 0)
		{
			if (solution.at(1).first == 1)
			{
				d = RIGHT;
			}
			else
			{
				d = LEFT;
			}
		}
		else if (current.first == (WINDOW_WIDTH/UNIT_SIZE)-1)
		{
			if (solution.at(1).first == 0)
			{
				d = RIGHT;
			}
			else
			{
				d = LEFT;
			}
		}
		else if (solution.at(1).first > current.first)
		{
			d = RIGHT;
		}
		else
		{
			d = LEFT;
		}
	}
	if (solution.at(1).second != current.second)
	{
		if (current.second == 0)
		{
			if (solution.at(1).second == 1)
			{
				d = DOWN;
			}
			else
			{
				d = UP;
			}
		}
		else if (current.second == (WINDOW_HEIGHT / UNIT_SIZE) - 1)
		{
			if (solution.at(1).second == 0)
			{
				d = DOWN;
			}
			else
			{
				d = UP;
			}
		}
		else if (solution.at(1).second > current.second)
		{
			d = DOWN;
		}
		else
		{
			d = UP;
		}
	}
}