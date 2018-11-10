#pragma once

#include <SFML\Graphics.hpp>


class Renderer;


struct State {

	sf::Vector2<float> position_;
	sf::Vector2<float> velocity_;



	State() {
		position_.x = 0.0f;
		position_.y = 0.0f;

		velocity_.x = 0.0f;
		velocity_.y = 0.0f;
	}

	State(sf::Vector2<float> newPos, sf::Vector2<float> newVel) {

		position_ = newPos;
		velocity_ = newVel;
	}


	inline State operator*(float a) {

		
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

	void Init(sf::Vector2<float> newPos, sf::Vector2<float> newVel, float newMass);

	//void AddForce(Body* b);
	void AddForce(sf::Vector2<float> newForce);
	void ResetForce();
	void Integrate_SemiImplicitEuler(float dt);
	State InterpolateState(float alpha);
	void Draw(Renderer* renderer, float alpha);
	//void Integrate_Rk4(float t, float dt);
	//void Integrate_Verlet();

	void SetColour(sf::Color newColor);

	inline float Mass() { return mass_; }
	inline State CurrentState() { return currentState_; }
	inline sf::CircleShape* Sprite() { return sprite_; }

private:

	State prevState_;
	State currentState_;

	sf::Vector2<float> force_;
	float mass_;

	sf::CircleShape* sprite_;

};

