#ifndef PARTICLE_H
#define PARTICLE_H

#include"core.h"
#include"Shader.h"
#include"Texture.h"
#include"Game_Object.h"

struct Particle
{
	glm::vec2 Position, Velocity;
	glm::vec4 Color;
	float Life;

	Particle() : Position(0.0f), Velocity(0.0f), Color(1.0f), Life(0.0f) {}
};

class ParticleGenerator
{
public:
	ParticleGenerator(Shader shader, Texture2D texture, unsigned int amount);

	void Update(float dt, GameObject& object, unsigned int newParticles, glm::vec2 offset = glm::vec2(0.0f, 0.0f));

	void Draw();

private:
	std::vector<Particle> particles;
	unsigned int amount;

	Shader shader;
	Texture2D texture;
	unsigned int VAO;
	//initializes buffer and vertex attribs
	void init();
	// returns first particle index that's unused
	unsigned int firstUnusedParticle();

	void respawnParticle(Particle& particle, GameObject& object, glm::vec2 offset = glm::vec2(0.0f, 0.0f));
};


#endif // !PARTICLE_H