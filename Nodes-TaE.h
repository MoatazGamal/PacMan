#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
//#include <list>
#include <iterator>
#include <vector>
using namespace std;

#ifndef Node-TaE_H
#define NodeTaE_H

class Node
{
public:
	Node() { }

	Node(float row, float column, float width, float height)//confusing stuff try to figure out later.
	{
		//float row = position.x;
		//float column = position.y;
		circle.setRadius(width);
		circle.setPosition(sf::Vector2f(row*width, column*height));
		circle.setFillColor(sf::Color::Red);
		circle.setOrigin(width,width);
	}

	void setradius(float radius)//will keep for now.
	{
		circle.setRadius(radius);
	}

	void draw_all(vector<sf::CircleShape> neighbors, sf::RenderWindow &window) 
		//for every element in neighbors draw a line-
		//-between the original node's position and each member of the list.
	
	{	
		sf::VertexArray lines(sf::LineStrip, 2);//to draw the line.
		
		vector <sf::CircleShape>::iterator it;//iterator to iterate throw the list of neighbors.

		for (it = neighbors.begin(); it != neighbors.end(); ++it)
		{
			int i = 0;
			
			sf::CircleShape &current = neighbors[i];//made neighbors of cirleshape type to make it easier to deal-
			//-with, another solution maybe to creat a get_position method for the nodes-
			//-also this line is necessary for some reason.
			
			lines[0].position = circle.getPosition();
			lines[1].position = current.getPosition();
			
			i++;
			//have we solved this issue?		
		}
		window.draw(lines);
		window.draw(circle);
	}

	~Node() { }
//private:
	sf::CircleShape circle;
	vector <sf::CircleShape> neighbors;
};

#endif