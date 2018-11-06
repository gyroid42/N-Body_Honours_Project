#include "Body.h"

#include "PhysicsUtil.h"


Body::Body()
{
}


Body::~Body()
{
}


void Body::Init(sf::Vector2<double> newPos, sf::Vector2<double> newVel, double newMass) {

	
	mass_ = newMass;
	ResetForce();

}



void Body::AddForce(sf::Vector2<double> newForce) {

	force_ += newForce;
}


void Body::ResetForce() {

	force_.x = 0.0f;
	force_.y = 0.0f;
}


void Body::Integrate_SemiImplicitEuler(double dt) {

	prevState_ = currentState_;

	currentState_.velocity_ += (force_ / mass_) * dt;
	currentState_.position_ += currentState_.velocity_ * dt;
}


State Body::InterpolateState(double alpha) {

	return (currentState_ * alpha) + (prevState_ * (1.0 - alpha));
}

