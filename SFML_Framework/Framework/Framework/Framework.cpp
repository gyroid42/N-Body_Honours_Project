// Framework.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <SFML/Graphics.hpp>
#include "Application.h"



Application* app;




int main()
{


	app = new Application();
	app->Init();

	bool running = true;



	//const double kTargetFrameTime = 1.0 / 60.0;
	//const double kTooLargeFrameTime = 1.0 / 10.0;


	sf::Clock clock;


	double t = 0.0;
	const double dt = 1.0 / 60.0;
	//dt = 1.0 / 60.0;

	clock.restart();
	double accumulator = 0.0;
	
	//State previous;
	//State current;

	while (running) {

		double frameTime = clock.restart().asSeconds();

		accumulator += frameTime;

		while (accumulator >= dt) {

			app->SimulationStep(t, dt);
			accumulator -= dt;
			t += dt;
		}

		running = app->Update(frameTime);

		app->Render();
	}


	app->CleanUp();
	delete app;

	return 0;

}





