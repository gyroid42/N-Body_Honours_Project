#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
//#include <SFML/OpenGL.hpp>
#include <Windows.h>
#include <GL\glew.h>
#include <GL\freeglut.h>

#include "SETTINGS.h"

class Renderer;
class Simulation;
class Camera;

class Application
{
public:
	Application();
	~Application();


	bool Init();

	void CleanUp();


	bool Update(float frameTime);
	bool SimulationStep(float t, float dt);

	bool Render(float alpha);


protected:

	bool CheckEvents(float dt);
	bool CheckInputs(float dt);

	sf::RenderWindow* window_;
	//sf::CircleShape* shape_;

	Renderer* renderer_;
	Simulation* simulation_;
	Camera* camera_;

	bool keyPressed_;
	bool createdBody_;
};

