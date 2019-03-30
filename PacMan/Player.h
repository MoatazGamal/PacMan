#pragma once
#include<SFML/Graphics.hpp>
#include"Player.h"
#include "Animation.h"

using namespace sf;

#ifndef Player_H

#define Player_H


class Player
{
private:
	enum class AnimationIndex
	{
		upDirection,
		downDirection,
		rightDirection,
		leftDirection,
		Count
	};
public:
	Player(const Vector2f& position)
		:
		position(position)

	{



		sprite.setTextureRect({ 0,0,153,168 });
		animations[int(AnimationIndex::rightDirection)] = Animation(153, 0, 153, 168);
		animations[int(AnimationIndex::leftDirection)] = Animation(153, 168, 153, 168);
		animations[int(AnimationIndex::upDirection)] = Animation(153, 336, 153, 168);
		animations[int(AnimationIndex::downDirection)] = Animation(153, 504, 153, 168);


	}
	void Draw(RenderTarget& rt) const
	{
		rt.draw(sprite);


	}
	void SetDirection(const Vector2f& dir)
	{
		velocity = dir * speed;
		if (dir.x > 0.0f)
		{
			currentAnimation = AnimationIndex::rightDirection;
		}
		else if (dir.x < 0.0f)
		{
			currentAnimation = AnimationIndex::leftDirection;
		}
		else if (dir.y < 0.0f)
		{
			currentAnimation = AnimationIndex::upDirection;
		}
		else if (dir.y > 0.0f)
		{
			currentAnimation = AnimationIndex::downDirection;
		}
	}
	void Update(float deltaTime)
	{
		position += velocity * deltaTime;
		animations[int(currentAnimation)].Update(deltaTime);
		animations[int(currentAnimation)].ApplyToSprite(sprite);
		sprite.setPosition(position);
	}

private:
	static constexpr float speed = 10.0f;
	Vector2f position;
	Vector2f velocity = { 0.0f,0.0f };
	Sprite sprite;
	Animation animations[int(AnimationIndex::Count)];
	AnimationIndex currentAnimation = AnimationIndex::rightDirection;

};


#endif