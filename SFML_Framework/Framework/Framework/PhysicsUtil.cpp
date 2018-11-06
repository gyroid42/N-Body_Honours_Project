#include "PhysicsUtil.h"

#include "Body.h"

PhysicsUtil::PhysicsUtil()
{


}


PhysicsUtil::~PhysicsUtil()
{
}


double PhysicsUtil::DistanceToSqr(const sf::Vector2<double>& pos1, const sf::Vector2<double>& pos2) {

	double dX = pos1.x - pos2.x;
	double dY = pos1.y - pos2.y;

	return dX*dX + dY*dY;
}


sf::Vector2<double> PhysicsUtil::VectorBetween(const sf::Vector2<double>& pos1, const sf::Vector2<double>& pos2) {

	return pos1 - pos2;
}

double PhysicsUtil::Normalise(sf::Vector2<double>& vector) {

	double distance = sqrt(vector.x * vector.x + vector.y * vector.y);

	vector = vector / distance;

	return distance;
}


void PhysicsUtil::AddForcesBetweenBodies(Body* body1, Body* body2) {


	sf::Vector2<double> distanceVector = PhysicsUtil::VectorBetween(body1->CurrentState().position_, body2->CurrentState().position_);
	double distance = PhysicsUtil::Normalise(distanceVector);

	sf::Vector2<double> force = (PhysicsUtil::G * body1->Mass() * body2->Mass() / (distance * distance * distance)) * distanceVector;

	body1->AddForce(force);
	body2->AddForce(-force);
}


const double PhysicsUtil::G = 6.673E-11;
