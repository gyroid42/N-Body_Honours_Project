#include "BruteForce.h"



BruteForce::BruteForce()
{
}


BruteForce::~BruteForce()
{
}


void BruteForce::Init(int numBodies) {


	// Create the bodies



}


void BruteForce::TimeStep(double dt) {


	// Evaluate each body against each other body
	for (auto i = bodies_.begin(); i != bodies_.end(); i++) {

		(*i)->ResetForce();
		for (auto j = i; j != bodies_.end(); j++) {

			if (i != j) {

				PhysicsUtil::AddForcesBetweenBodies(*i, *j);
				//(*i)->AddForce(*j);
			}
		}

	}

	for (auto i = bodies_.begin(); i != bodies_.end(); i++) {

		(*i)->Integrate_SemiImplicitEuler(dt);
	}

}
