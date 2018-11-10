#include "PhysicsUtil.h"

#include "Body.h"

PhysicsUtil::PhysicsUtil()
{


}


PhysicsUtil::~PhysicsUtil()
{
}


float PhysicsUtil::DistanceToSqr(const sf::Vector2<float>& pos1, const sf::Vector2<float>& pos2) {

	float dX = pos1.x - pos2.x;
	float dY = pos1.y - pos2.y;

	return dX*dX + dY*dY;
}

float PhysicsUtil::VectorLengthSqr(const sf::Vector2f& vector) {

	return vector.x * vector.x + vector.y*vector.y;
}


sf::Vector2<float> PhysicsUtil::VectorBetween(const sf::Vector2<float>& pos1, const sf::Vector2<float>& pos2) {

	return pos1 - pos2;
}

float PhysicsUtil::Normalise(sf::Vector2<float>& vector) {

	float distance = sqrt(vector.x * vector.x + vector.y * vector.y);

	vector = vector / distance;

	return distance;
}


void PhysicsUtil::AddForcesBetween(Body* body1, Body* body2) {


	sf::Vector2<float> distanceVector = PhysicsUtil::VectorBetween(body1->CurrentState().position_, body2->CurrentState().position_);
	float distance = PhysicsUtil::Normalise(distanceVector);
	distance += dampeningFactor;

	sf::Vector2<float> force = (PhysicsUtil::G * body1->Mass() * body2->Mass() / (distance * distance * distance)) * distanceVector;

	body1->AddForce(-force);
	//body2->AddForce(force);
}


const float PhysicsUtil::G = 6.673E-11f;
const float PhysicsUtil::pi = 3.14159f;
const float PhysicsUtil::dampeningFactor = DAMPENING_FACTOR;
