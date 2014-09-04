#include "AI_snake.h"

AI_snake::AI_snake(int x, int y, int b)
	:Snake(x, y, b), solution(){}

// Always calculate current solution, but each time that assign direction is called
// check how safe current solution is and replan in case necessary (some cost threshold perhaps?)

void AI_snake::assign_direction(SDL_Keycode k, pair<int, int> f, vector<pair<int, int>> obstacles)
{
	
	pair<int, int> current = body.at(0);

	// In case there is not yet a solution or in case the goal changed OR TODO: if path is too risky
	// recalculate a solution
	// Plan a new solution in any of these cases:
	// - there is no active solution
	// - the food pellet changed position
	// - current solution is infeasible (other snakes got in the way)
	//	RIGHT NOW WE PLAN EVERY STEP
	solution = solve(current, f, obstacles);

	// in case other snakes are way closer or (TODO)
	// we took too long to find a solution (there is no current path
	if (solution.size() == 0)
	{
		// Just take a random position
		if (!pair_in_vector(pair<int, int>(current.first - 1, current.second), obstacles))
		{
			cout << "Go left" << endl;
			d = LEFT;
		}
		if (!pair_in_vector(pair<int, int>(current.first + 1, current.second), obstacles))
		{
			cout << "Go r" << endl;
			d = RIGHT;
		}
		if (!pair_in_vector(pair<int, int>(current.first , current.second + 1), obstacles))
		{
			cout << "Go d" << endl;
			d = DOWN;
		}
		if (!pair_in_vector(pair<int, int>(current.first, current.second - 1), obstacles))
		{
			cout << "Go u" << endl;
			d = UP;
		}
		cout << "New solution!" <<solution.size()<< endl;
	}
	else
	{
		apply_direction(solution);
	}

}

void AI_snake::apply_direction(vector<pair<int, int>> s)
{

	pair<int, int> current = body.at(0);

	if (!goal_reached(s.at(0), body.at(0)))
	{
		s.erase(s.begin());
	}

	// Change direction depending on the first next movement
	if (s.at(1).first != current.first)
	{
		if (current.first == 0)
		{
			if (s.at(1).first == 1)
			{
				d = RIGHT;
			}
			else
			{
				d = LEFT;
			}
		}
		else if (current.first == (WINDOW_WIDTH / UNIT_SIZE) - 1)
		{
			if (s.at(1).first == 0)
			{
				d = RIGHT;
			}
			else
			{
				d = LEFT;
			}
		}
		else if (s.at(1).first > current.first)
		{
			d = RIGHT;
		}
		else
		{
			d = LEFT;
		}
	}
	if (s.at(1).second != current.second)
	{
		if (current.second == 0)
		{
			if (s.at(1).second == 1)
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
			if (s.at(1).second == 0)
			{
				d = DOWN;
			}
			else
			{
				d = UP;
			}
		}
		else if (s.at(1).second > current.second)
		{
			d = DOWN;
		}
		else
		{
			d = UP;
		}
	}
}