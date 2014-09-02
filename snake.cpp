#include "snake.h"

Snake::Snake()
{
	d = NONE;
	// Set the snake image
	img = SDL_util::load_bmp("../Images/snake_body.bmp");
	// Initialize snake position
	pair <int, int> p(15, 15);
	body.push_back(p);
}

Snake::Snake(int x, int y)
{
	d = NONE;
	// Set the snake image
	img = SDL_util::load_bmp("../Images/snake_body.bmp");
	// Initialize snake position
	pair <int, int> p(x, y);
	body.push_back(p);
}

// Draw snake on the provided surface
void Snake::draw_snake(SDL_Surface* surface)
{
	// Draw all elements in the vector stack
	for (int i = 0; i < body.size(); i++)
	{
		SDL_BlitSurface(img, NULL, surface, SDL_util::create_rect(body.at(i).first * UNIT_SIZE, body.at(i).second * UNIT_SIZE, UNIT_SIZE, UNIT_SIZE));
	}
}

// Increase the size of the snake by a single element
void Snake::grow()
{
	pair <int, int> p = body.at(body.size() - 1);
	body.push_back(p);
}

void Snake::move()
{
	switch (d)
	{
	case UP:
		move(0, -1); break;
	case DOWN:
		move(0, 1); break;
	case LEFT:
		move(-1, 0); break;
	case RIGHT:
		move(1, 0); break;
	}
}

void Snake::move(int x, int y)
{
	if (body.at(0).first + x < 0)
	{
		pair<int, int> p((WINDOW_WIDTH / UNIT_SIZE) - 1, (body.at(0).second + y) % (WINDOW_HEIGHT / UNIT_SIZE));
		body.insert(body.begin(), p);
	}
	else if (body.at(0).second + y < 0)
	{
		// Remove last element and push a new element in front
		pair<int, int> p((body.at(0).first + x) % (WINDOW_WIDTH / UNIT_SIZE), (WINDOW_HEIGHT / UNIT_SIZE) -1);
		body.insert(body.begin(), p);
	}
	else
	{
		// Remove last element and push a new element in front
		pair<int, int> p((body.at(0).first + x) % (WINDOW_WIDTH / UNIT_SIZE), (body.at(0).second + y) % (WINDOW_HEIGHT / UNIT_SIZE));
		body.insert(body.begin(), p);
	}

	body.pop_back();
}

// Prints position of all the body blocks
void Snake::print_body()
{
	for (int i = 0; i < body.size(); i++)
	{
		cout << "pos: " << body.at(i).first << ", " << body.at(i).second << endl;
	}
	cout << endl;
}

// Check if snake collided with its own body
bool Snake::check_self_collision()
{
	vector<pair<int, int>>::const_iterator first = body.begin() + 1;
	vector<pair<int, int>>::const_iterator last = body.begin() + body.size();
	return check_collision(vector<pair<int, int>>(first, last));
}

bool Snake::check_collision(vector<pair<int, int>> colliders)
{
	pair<int, int> p = body.at(0);
	for (int i = 1; i < colliders.size(); i++)
	{
		if (p.first == colliders.at(i).first && p.second == colliders.at(i).second)
		{
			return true;
		}
	}
	return false;
}