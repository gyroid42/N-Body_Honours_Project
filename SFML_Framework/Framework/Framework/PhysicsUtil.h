#pragma once
#include <SFML\Graphics.hpp>
#include <cmath>

class Body;

class PhysicsUtil
{
public:
	PhysicsUtil();
	~PhysicsUtil();

	static double DistanceToSqr(const sf::Vector2<double>& pos1, const sf::Vector2<double>& pos2);
	static sf::Vector2<double> VectorBetween(const sf::Vector2<double>& pos1, const sf::Vector2<double>& pos2);

	static double Normalise(sf::Vector2<double>& vector);
	static void AddForcesBetweenBodies(Body* body1, Body* body2);

	static const double G;
};

