#pragma once

#include <SFML\Graphics.hpp>



struct State {

	sf::Vector2<double> position_;
	sf::Vector2<double> velocity_;



	State() {
		position_.x = 0.0;
		position_.y = 0.0;

		velocity_.x = 0.0;
		velocity_.y = 0.0;
	}

	State(sf::Vector2<double> newPos, sf::Vector2<double> newVel) {

		position_ = newPos;
		velocity_ = newVel;
	}


	inline State operator*(double a) {

		
		return { position_ * a, velocity_ * a };
	}

	inline State operator+(const State& a) {
		//position_ += a.position_;
		//position_ += a.velocity_;
		return { position_ + a.position_, velocity_ + a.velocity_ };
	}

};


class Body
{
public:
	Body();
	~Body();

	void Init(sf::Vector2<double> newPos, sf::Vector2<double> newVel, double newMass);

	//void AddForce(Body* b);
	void AddForce(sf::Vector2<double> newForce);
	void ResetForce();
	void Integrate_SemiImplicitEuler(double dt);
	State InterpolateState(double alpha);
	//void Integrate_Rk4(double t, float dt);
	//void Integrate_Verlet();

	inline double Mass() { return mass_; }
	inline State CurrentState() { return currentState_; }

private:

	State prevState_;
	State currentState_;

	sf::Vector2<double> force_;
	double mass_;

};

