#ifndef ASTAR_H
#define	ASTAR_H

#include <vector>
#include <queue>
#include <iostream>
#include "game_specs.h"
using namespace std;

// Solve the route towards the food
vector<pair<int, int>> solve(pair< int,int> begin, pair<int, int> goal, vector<pair<int, int>> obstacles);
bool pair_in_vector(pair<int, int> p, vector<pair<int, int>> v);
vector<pair<int, int>> get_moves(pair<int, int> p, vector<pair<int, int>> obstacles);
int calculate_cost(pair<int, int> p1, pair<int, int> p2);
bool goal_reached(pair<int, int> p1, pair<int, int> p2);
int get_move(int i, int board_size);

#endif // !ASTAR_H
