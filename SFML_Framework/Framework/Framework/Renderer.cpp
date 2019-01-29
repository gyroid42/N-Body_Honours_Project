#include "Renderer.h"

#include <GL\freeglut.h>


Renderer::Renderer() :
	window_(nullptr)
{
}


Renderer::~Renderer()
{
}


bool Renderer::Init(sf::RenderWindow* newWindow) {

	window_ = newWindow;


	return true;
}

void Renderer::CleanUp() {


}


void Renderer::StartRender(bool clear) {

	window_->setActive(true);

	if (clear) {

		//window_->clear();
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	}

	//glMatrixMode(GL_MODELVIEW);

	//glPushMatrix();

}


void Renderer::EndRender() {

	window_->display();
	window_->setActive(false);
}


void Renderer::SetRenderWindow(sf::RenderWindow* newRenderWindow) {

	window_ = newRenderWindow;

}


void Renderer::ClearRenderTarget() {

	window_ = nullptr;
}


void Renderer::Draw(const sf::Drawable& drawable, const sf::RenderStates& states) {

	if (window_) {

		window_->draw(drawable, states);
	}
}

