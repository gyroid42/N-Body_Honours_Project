#include "Application.h"
#include "Renderer.h"
#include "BruteForce.h"
#include "Camera.h"


Application::Application() :
	window_(nullptr),
	renderer_(nullptr),
	camera_(nullptr),
	simulation_(nullptr),
	keyPressed_(false),
	createdBody_(false)
{
}


Application::~Application()
{
}



bool Application::Init() {

	// initialise stuff
	window_ = new sf::RenderWindow(sf::VideoMode(WINDOW_SIZE_X, WINDOW_SIZE_Y), "SFML works!");
	
	window_->setVerticalSyncEnabled(true);

	window_->setActive(true);
	window_->setActive(false);

	renderer_ = new Renderer();
	renderer_->Init(window_);

	camera_ = new Camera();
	camera_->Init(window_);



	simulation_ = new BruteForce();
	simulation_->Init();
	simulation_->Reset();

	// start threads
	// physics thread


	// create stuff for simulation
	//shape_ = new sf::CircleShape(100.0f);
	//shape_->setFillColor(sf::Color::Green);
	keyPressed_ = false;
	return true;
}


void Application::CleanUp() {


	if (window_) {

		window_->close();
		delete window_;
		window_ = nullptr;
	}

	if (renderer_) {

		renderer_->CleanUp();
		delete renderer_;
		renderer_ = nullptr;
	}

	if (camera_) {

		camera_->CleanUp();
		delete camera_;
		camera_ = nullptr;
	}

	if (simulation_) {

		simulation_->CleanUp();
		delete simulation_;
		simulation_ = nullptr;
	}

	//if (shape_) {

	//	delete shape_;
	//	shape_ = nullptr;
	//}

}


bool Application::Update(float frameTime) {

	if (!window_) {
		
		return false;
	}

	if (!window_->isOpen()) {

		return false;
	}

	if (!CheckEvents(frameTime)) {

		return false;
	}
	if (!CheckInputs(frameTime)) {

		return false;
	}

	camera_->Update(frameTime);


	return true;
}


bool Application::SimulationStep(float t, float dt) {

	simulation_->TimeStep(dt);


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

			//window_->setSize(sf::Vector2u(event.size.width, event.size.height));
			sf::View newView = window_->getView();
			newView.setSize((float)event.size.width, (float)event.size.height);
			window_->setView(newView);

			//glViewport(0, 0, event.size.width, event.size.height);
		}

		if (!createdBody_) {
			if (event.type == sf::Event::MouseButtonPressed) {

				if (event.mouseButton.button == sf::Mouse::Button::Left) {

					createdBody_ = true;

					Body* newBody = new Body();
					newBody->Init(window_->mapPixelToCoords(sf::Vector2i(event.mouseButton.x, event.mouseButton.y)), sf::Vector2f(0.0f, 0.0f), PLACE_BODY_MASS);
					simulation_->AddBody(newBody);
				}
			}
		}
		else {
			if (event.type == sf::Event::MouseButtonReleased) {

				if (event.mouseButton.button == sf::Mouse::Button::Left) {

					createdBody_ = false;
				}
			}
		}

		camera_->OnEvent(event);
	}

	//shape_->setPosition(shape_->getPosition() + sf::Vector2f(10.0f * dt, 10.0f * dt));

	return true;
}

bool Application::CheckInputs(float dt) {


	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {

		if (!keyPressed_) {
			keyPressed_ = true;

			simulation_->Reset();
		}
	}
	else {

		keyPressed_ = false;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {

		return false;
	}

	return true;
}


bool Application::Render(float alpha) {

	window_->setView(*camera_);

	renderer_->StartRender();

	//window_->setActive(true);

	//glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	//glMatrixMode(GL_MODELVIEW);

	//glPushMatrix();
		
	//window_->draw(*shape_);
	//window_->display();

	//window_->setActive(false);

	simulation_->Render(renderer_, alpha);


	renderer_->EndRender();

	return true;
}
