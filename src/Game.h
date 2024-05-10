#ifndef GAME_H
#define GAME_H

#include"core.h"
#include"Game_Level.h"
#include"Ball_Object.h"

enum GameState
{
	GAME_ACTIVE,
	GAME_MENU,
	GAME_WIN
};


enum Direction
{
	UP,
	RIGHT,
	DOWN,
	LEFT
};
typedef std::tuple<bool, Direction, glm::vec2> Collision;


// initial size of player paddle
const glm::vec2 PLAYER_SIZE(100.0f, 20.0f);
// inital velocity
const float PLAYER_VELOCITY = 500.0f;


// initial size of ball
const float BALL_RADIUS = 12.5f;
// initial ball velocity
const glm::vec2 INITIAL_BALL_VELOCITY(100.0f, -350.0f);


class Game
{
public:
	GameState				State;
	bool					Keys[1024];
	unsigned int			Width, Height;
	std::vector<GameLevel>	Levels;
	unsigned int			Level;

	Game(unsigned int width, unsigned int height);
	~Game();

	// load shaders / textures / levels
	void Init();

	// game loop
	void ProcessInput(float dt);
	void Update(float dt);
	void Render();
	void ResetLevel();
	void ResetPlayer();
	void DoCollisions();
};

#endif // !GAME_H