#include "Application.h"



Application::Application()
{
}


Application::~Application()
{
}



bool Application::Init() {

	// initialise stuff
	window_ = new sf::RenderWindow(sf::VideoMode(1280, 720), "SFML works!");
	
	window_->setVerticalSyncEnabled(true);

	window_->setActive(true);

	window_->setActive(false);


	// start threads
	// physics thread


	// create stuff for simulation
	shape_ = new sf::CircleShape(100.0f);
	shape_->setFillColor(sf::Color::Green);

	return true;
}


void Application::CleanUp() {


	if (window_) {

		window_->close();
		delete window_;
		window_ = nullptr;
	}

	if (shape_) {

		delete shape_;
		shape_ = nullptr;
	}

}


bool Application::Update(float frameTime) {

	if (!window_) {
		
		return false;
	}

	if (!window_->isOpen()) {

		return false;
	}

	CheckEvents(frameTime);
	CheckInputs(frameTime);
	Render();


	return true;
}


bool Application::SimulationStep(float t, float dt) {




	return true;
}



bool Application::CheckEvents(float dt) {

	sf::Event event;
	while (window_->pollEvent(event)) {

		if (event.type == sf::Event::Closed) {

			window_->close();
			return false;
		}
		else if (event.type == sf::Event::Resized) {

			glViewport(0, 0, event.size.width, event.size.height);
		}
	}

	shape_->setPosition(shape_->getPosition() + sf::Vector2f(10.0f * dt, 10.0f * dt));

	return true;
}

bool Application::CheckInputs(float dt) {


	return true;
}


bool Application::Render() {

	window_->setActive(true);

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);

	glPushMatrix();
		
	window_->draw(*shape_);
	window_->display();

	window_->setActive(false);

	return true;
}
