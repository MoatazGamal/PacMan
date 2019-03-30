#pragma once

#include<SFML/Graphics.hpp>

using namespace sf;

#ifndef Node_H
#define Node_H


class Node
{
private:
	
	CircleShape node;

public:
	Node(Vector2f position,float width,float height)
	{
		float row = position.x;    
		float columns = position.y;
		node.setFillColor(Color::Red);
		node.setPosition(row*width, columns*height);
	}
    
	

};

#endif