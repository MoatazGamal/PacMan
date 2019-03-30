#pragma once

#include<SFML/Graphics.hpp>
using namespace sf;

#ifndef Animation_H

#define Animation_H
  

class Animation
{
public:
	Animation() = default;
	Animation(int x, int y, int width, int height)
	{
		texture.loadFromFile("Pacman.png");
		for (int i = 0; i < nFrame; i++)
		{
			frames[i] = { x + i * width,y,width, height };


		}
	}
	void ApplyToSprite(Sprite& s)const
	{
		s.setTexture(texture);
		s.setScale(0.24, 0.24);
		s.setTextureRect(frames[iFrame]);
	}
	void Update(float deltaTime)
	{
		time += deltaTime;
		while (time >= holdTime)
		{
			time -= holdTime;
			Advance();
		}
	}
private:
	void Advance()
	{
		if (++iFrame >= nFrame)
		{
			iFrame = 0;
		}
	}
private:
	static constexpr int nFrame = 3;
	static constexpr float holdTime = 3.0f;
	Texture texture;
	IntRect frames[nFrame];
	int iFrame = 0;
	float time = 0.0f;
};

#endif // !Animation
