#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <list>


using namespace sf;


void RunGame()
{
	RenderWindow win(VideoMode(960, 540), "Space Invaders");
	
	Clock clock;

	while (win.isOpen())
	{
		float time = clock.getElapsedTime().asMicroseconds();
		clock.restart();

		time = time / 500;

		if (time > 40) time = 40;

		Event event;
		while (win.pollEvent(event))
		{
			if (event.type == Event::Closed)
				win.close();

		}


		win.clear(Color::Black);

		win.display();
	}
}

#endif GAME_H

