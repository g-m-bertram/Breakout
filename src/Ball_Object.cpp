#include"Ball_Object.h"

BallObject::BallObject()
	: GameObject(), Radius(12.5f), Stuck(true)
{}

BallObject::BallObject(glm::vec2 pos, float radius, glm::vec2 velocity, Texture2D sprite)
	: GameObject(pos, glm::vec2(radius * 2.0f, radius * 2.0f), sprite, glm::vec3(1.0f), velocity),
	Radius(radius), Stuck(true)
{}

glm::vec2 BallObject::Move(float dt, unsigned int window_width)
{
	if (!this->Stuck)
	{
		this->Position += this->Velocity * dt;
		// bounds
		if (this->Position.x <= 0.0f)
		{
			this->Velocity.x *= -1;		// reverse direction
			this->Position.x = 0.0f;
		}
		else if (this->Position.x + this->Size.x >= window_width)
		{
			this->Velocity.x *= -1;
			this->Position.x = (float)window_width - this->Size.x;
		}
		if (this->Position.y <= 0.0f)	// bounces off bottom for now (actually a failstate)
		{
			this->Velocity.y *= -1;
			this->Position.y = 0.0f;
		}
		
	}
	return this->Position;
}

void BallObject::Reset(glm::vec2 position, glm::vec2 velocity)
{
	this->Position = position;
	this->Velocity = velocity;
	this->Stuck = true;
}