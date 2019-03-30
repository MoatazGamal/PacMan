//whenever you want to add something,change this main and do a pull-request.
//if you have an extra class or header file, upload that header file using upload file.
//NEVER upload folders, only headers,cpps and images or audio files.
//we both well have the same main.cpp, copy and past the new files into your visual studio solution.

//example

#include<SFML/Graphics.hpp>
#include"Player.h"
#include "Animation.h"

using namespace sf;





int main() {

	RenderWindow window(VideoMode(960, 960), "Pacman");

	Player Pacman({ 100.0f,100.0f });

	Texture texture;
	texture.loadFromFile("map.png");
	Sprite S_map(texture);
	S_map.setScale(0.4, 0.4);
	S_map.setPosition(100,50 );
	
	// start game loop.
	while (window.isOpen())
	{
		Event event;

		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();

			if (Keyboard::isKeyPressed(Keyboard::Escape))
				window.close();
		}
		//handel input;
		Vector2f direction = { 0.0f,0.0f };
		if (Keyboard::isKeyPressed(Keyboard::Up))
		{

			direction.y -= 1.0f;
		}
		else if (Keyboard::isKeyPressed(Keyboard::Down))
		{
			direction.y += 1.0f;
		}
		else if (Keyboard::isKeyPressed(Keyboard::Right))
		{
			direction.x += 1.0f;
		}
		else if (Keyboard::isKeyPressed(Keyboard::Left))
		{
			direction.x -= 1.0f;
		}
		Pacman.SetDirection(direction);

		//update model
		Pacman.Update(1.0f / 60.0f);

		window.clear();
		window.draw(S_map);
		Pacman.Draw(window);
		
		window.display();

	}


	return EXIT_SUCCESS;
}
