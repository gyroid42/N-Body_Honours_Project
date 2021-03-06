// Framework.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <SFML/Graphics.hpp>
#include "Application.h"
#include "SETTINGS.h"

#include <GL\freeglut.h>





Application* app;




int main(int argc, char* argv[])
{


	glutInit(&argc, argv);


	app = new Application();
	app->Init();

	bool running = true;



	const float kTargetFrameTime = 1.0 / 60.0;
	const float kTooLargeFrameTime = 1.0 / 10.0;


	sf::Clock clock;


	float t = 0.0f;
	//const float dt = 1.0f / 60.0f;
	const float dt = 1.0f / STEPS_PER_SECOND;

	//dt = 1.0 / 60.0;

	clock.restart();
	float accumulator = 0.0;
	
	//State previous;
	//State current;

	while (running) {

		float frameTime = clock.restart().asSeconds();

		if (frameTime > kTooLargeFrameTime) {
			frameTime = kTargetFrameTime;
		}
		//frameTime *= SIMULATION_SPEED;

		accumulator += frameTime;

		while (accumulator >= dt) {

			app->SimulationStep(t, dt * SIMULATION_SPEED);
			accumulator -= dt;
			t += dt;// *1000000000.0f;
		}

		running = app->Update(frameTime);

		
		if (INTERPOLATE_BETWEEN_FRAMES) {

			const float alpha = accumulator / dt;
			app->Render(alpha);
		}
		else {

			app->Render(1.0f);
		}

		//app->Render();
		//float meh = 1;
	}


	app->CleanUp();
	delete app;

	return 0;

}




