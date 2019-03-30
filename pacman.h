#pragma once
#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>
using namespace std;

#ifndef pacman_H
#define pacman_H

class pacman 
{
public:
	pacman(sf::Vector2f size)
	{
		player.setSize(size);
		player.setFillColor(sf::Color::Yellow);
	}

	void draw(sf::RenderWindow &window)
	{
		window.draw(player);
	}

	void setpos(sf::Vector2f pos)
	{
		player.setPosition(pos);
	}

	void move(sf::Vector2f dir)
	{
		player.move(dir);
	}
private:
	sf::RectangleShape player;
};


#endif
