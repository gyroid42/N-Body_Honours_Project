#pragma once

#include <list>
#include "Body.h"
#include "PhysicsUtil.h"

class BruteForce
{
public:
	BruteForce();
	~BruteForce();

	void Init(int numBodies);

	void TimeStep(double dt);

private:

	std::list<Body*> bodies_;

};

