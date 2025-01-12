#ifndef BALL_OBJECT_H
#define BALL_OBJECT_H

#include"Game_Object.h"
#include"Texture.h"

class BallObject : public GameObject
{
public:
	// ball state
	float	Radius;
	bool	Stuck;

	BallObject();
	BallObject(glm::vec2 pos, float radius, glm::vec2 velocity, Texture2D sprite);
	// moves ball and returns its new position
	glm::vec2 Move(float dt, unsigned int window_width);
	void Reset(glm::vec2 position, glm::vec2 velocity);
};


#endif // !BALL_OBJECT_H