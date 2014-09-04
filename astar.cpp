#include "astar.h"

// Comparison material of priority queue
struct compare
{
	bool operator()(const pair<int, vector<pair<int, int>>> l, const pair<int, vector<pair<int, int>>> r)
	{
		if (l.first > r.first)
			return true;
		if (l.first == r.first)
		{
			if (l.second.size() < r.second.size())
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		else
		{
			return false;
		}
	}
};

int expanded_nodes = 0;
// TODO: in case amount of expanded nodes gets too high, we shall have to create some kind of 
vector<pair<int, int>> solve(pair<int, int> begin, pair<int, int> goal, vector<pair<int, int>> obstacles)
{

	vector<pair<int, int>> evaluated;
	priority_queue < pair<int, vector<pair <int, int>>>, vector < pair<int, vector<pair<int, int>>>>, compare> to_evaluate;

	int g = 0;
	int f = g + calculate_cost(begin, goal);
	//pair<int, vector<pair<int, int>>>pair (f, vector<pair<int, int>>(1, begin));
	vector<pair<int, int>> v(1, begin);
	pair<int, vector<pair<int, int>>> gg(f, v);
	to_evaluate.push(gg);
	expanded_nodes = 0;
	while (to_evaluate.size() > 0)
	{
		expanded_nodes += 1;
		// Pop position with lowest value
		pair<int, vector<pair<int, int>>> p = to_evaluate.top();

		to_evaluate.pop();
		if (expanded_nodes == 100)
		{
			return vector<pair<int, int>>();
		}
		// Check if destination is reached
		if (goal_reached(p.second.at(p.second.size()-1), goal))
		{
			cout << "Total expanded nodes: " << expanded_nodes << endl;
			return p.second;
		}
		else
		{
			// check all moves from last position and make sure that this is not already visited
			vector<pair<int, int>> moves = get_moves(p.second.at(p.second.size() -1), obstacles);
			for (const pair<int, int>& move : moves)
			{
				if (!pair_in_vector(move, p.second))
				{
					
					vector<pair<int, int>> temp(p.second);
					temp.push_back(move);
					int new_f = calculate_cost(move, goal);
					to_evaluate.push(pair<int, vector<pair<int, int>>>(p.second.size() + new_f, temp));	
				}
			}
		}
	}
}

bool goal_reached(pair<int, int> p1, pair<int, int> p2)
{
	bool b;
	p1.first == p2.first && p1.second == p2.second ? b = true : b = false;
	return b;
}

// TODO: make manhattan distance of that on torus
// min(|x1-x2|, w - |x1-x2|) ?
int calculate_cost(pair<int, int> p1, pair<int, int> p2)
{

	return min(abs(p1.first - p2.first), abs(WINDOW_WIDTH/UNIT_SIZE - abs(p1.first - p2.first))) + 
		min(abs(p1.second - p2.second), abs(WINDOW_HEIGHT / UNIT_SIZE - abs(p1.second - p2.second)));
}

vector<pair<int, int>> get_moves(pair<int, int> p, vector<pair<int, int>> obstacles)
{
	vector<pair<int, int>> feasible_moves;
	// 4 Possible moves; up down left right
	if (!pair_in_vector(pair<int, int>(p.first, get_move(p.second - 1, WINDOW_HEIGHT/UNIT_SIZE)), obstacles))
	{
		feasible_moves.push_back(pair<int, int>(p.first, get_move(p.second - 1, WINDOW_HEIGHT/UNIT_SIZE)));
	}
	if (!pair_in_vector(pair<int, int>(p.first, get_move(p.second + 1, WINDOW_HEIGHT/UNIT_SIZE)), obstacles))
	{
		feasible_moves.push_back(pair<int, int>(p.first, get_move(p.second + 1, WINDOW_HEIGHT/UNIT_SIZE)));
	}
	if (!pair_in_vector(pair<int, int>(get_move(p.first + 1, WINDOW_WIDTH/UNIT_SIZE), p.second), obstacles))
	{
		feasible_moves.push_back(pair<int, int>(get_move(p.first + 1, WINDOW_WIDTH/UNIT_SIZE), p.second));
	}
	if (!pair_in_vector(pair<int, int>(get_move(p.first - 1, WINDOW_WIDTH/UNIT_SIZE), p.second), obstacles))
	{
		feasible_moves.push_back(pair<int, int>(get_move(p.first - 1, WINDOW_WIDTH/UNIT_SIZE), p.second));
	}
	return feasible_moves;
}

int get_move(int i, int board_size)
{
	return i >= 0 ? (i  % board_size) : board_size + (i);
}

// Checks if pair is in vector
bool pair_in_vector(pair<int, int> p, vector<pair<int, int>> v)
{
	for (const pair<int, int>& p2 : v)
	{
		if (goal_reached(p, p2))
		{
			return true;
		}
	}
	return false;
}

