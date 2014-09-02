#include "board.h"


// Possibility:
/*
	Run AStar from start to finish (= apple
	Take a single move, Rerun A* again, etc
	make positions close to snake parts cost more
	*/

// TODO: COnstruct freespace matrix to deliver to changepos in food object
Board::Board(string location)
	:snake(2, 2), food(4, 4)
{
	obstacle = SDL_util::load_bmp("../Images/obstacle.bmp");
	load_obstacles(location);
}

// Loads the position of the obstacles
void Board::load_obstacles(string location)
{
	// open a file in read mode.
	ifstream infile;
	infile.open(location);
	string data;

	int x, y;
	while (infile >> x >> y)
	{
		// TODO: Use negative coordinates too
		obstacles.push_back(pair<int, int>(x, y));
	}
	// close the opened file.
	infile.close();
}

void Board::draw_board(SDL_Surface* surface)
{
	SDL_FillRect(surface, NULL, 0x000000);

	// Draw all obstacles 
	for (int i = 0; i < obstacles.size(); i++)
	{
		SDL_BlitSurface(obstacle, NULL, surface, SDL_util::create_rect(obstacles.at(i).first * UNIT_SIZE, obstacles.at(i).second * UNIT_SIZE, UNIT_SIZE, UNIT_SIZE));
	}

	snake.draw_snake(surface);
	food.draw_food(surface);
}

// Detect collisions between elements on the board
void Board::handle_collision()
{
	// Get head of the snake
	pair<int, int> head = snake.body.at(0);

	// Check if snake hits its body or other boundaries
	if (snake.check_self_collision() || snake.check_collision(obstacles))
	{
		cout << "I killed myself" << endl;
		SDL_Delay(10000);
	}

	// Check if it hit a pellet
	if (food.pos.first == head.first && food.pos.second == head.second)
	{
		// Add an extra element to the snake
		snake.grow();
		// Change pellet position
		food.change_pos(get_unoccupied());
	}
}

// Get all unoccupied spaces on the board
vector<pair<int, int>> Board::get_unoccupied()
{
	vector<pair<int, int>>unoccupied;
	// Combine static and dynamic obstacles
	vector<pair<int, int>> b(obstacles);
	b.insert(b.end(), snake.body.begin(), snake.body.end());

	// Loop through board position and add pos in case it does not belong to obstacles
	for (int i = 0; i < WINDOW_WIDTH / UNIT_SIZE; i++)
	{
		for (int j = 0; j < WINDOW_HEIGHT / UNIT_SIZE; j++)
		{
			if (!pair_in_vector(pair<int, int>(i, j), b))
			{
				unoccupied.push_back(pair<int, int>(i, j));
			}
		}
	}
	return unoccupied;
}



void Board::assign_movement(SDL_Keycode k)
{
	vector<pair<int, int>> b(obstacles);
	b.insert(b.end(), snake.body.begin(), snake.body.end());
	snake.assign_direction(k, food.pos, b);
}

// Moves the snakes on the board a single position
void Board::move_snakes()
{
	snake.move();
}