#ifndef SPRITE_RENDERER_H
#define SPRITE_RENDERER_H

#include"core.h"
#include"Texture.h"
#include"Shader.h"

class SpriteRenderer
{
public:
	SpriteRenderer(Shader& shader);
	SpriteRenderer(Shader&& shader);
	~SpriteRenderer();
	void DrawSprite(Texture2D& texture, glm::vec2 position, 
		glm::vec2 size = glm::vec2(10.0f, 10.0f), float rotate = 0.0f, 
		glm::vec3 color = glm::vec3(1.0f));

private:
	// render state
	Shader shader;
	unsigned int quadVAO;
	// initializes and configures the quad's buffer and vertex attribs
	void initRenderData();
};


#endif // !SPRITE_RENDERER_H