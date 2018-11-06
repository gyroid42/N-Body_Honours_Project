#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>

class Application
{
public:
	Application();
	~Application();


	bool Init();

	void CleanUp();


	bool Update(float frameTime);
	bool SimulationStep(float t, float dt);

	bool CheckEvents(float dt);
	bool CheckInputs(float dt);
	bool Render();

protected:

	sf::RenderWindow* window_;
	sf::CircleShape* shape_;
};

