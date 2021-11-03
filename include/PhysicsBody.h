#ifndef PHYSICS_BODY_H
#define PHYSICS_BODY_H

#include "Clock.h"
#include "InputHandler.h"

class Vector2
{
public:
	float x, y;
	Vector2(int t_x = 0.0f, int t_y = 0.0f) : x(t_x), y(t_y) {}

	Vector2& operator+=(const Vector2& rhs)
	{
		this->x += rhs.x;
		this->y += rhs.y;
		return *this;
	}
};

class PhysicsBody
{
public:
	PhysicsBody(float t_maxSpeed = 200.0f, float t_acceleration = 1.0f, float t_deceleration = 5.0f) :
		MAX_SPEED(t_maxSpeed),
		ACCELERATION(t_acceleration),
		DECELERATION(t_deceleration),
		m_position(Vector2(200.0f,200.0f)),
		m_velocity(Vector2(0.0f,0.0f))
	{}

	void setPosition(Vector2 t_pos) { m_position = t_pos; }
	Vector2 getPosition() { return m_position; }
	Vector2 getVelocity() { return m_velocity; }

	void isCrouching(bool t_isCrouching) { m_isCrouching = t_isCrouching; }

	void update(Time t_dT);

	void moveLeft(Time t_dT);
	void moveRight(Time t_dT);
	void jump();

private:
	void decelerate(Time t_dT);

	bool m_isCrouching{ false };

	Vector2 m_position;
	Vector2 m_velocity;

	const float MAX_SPEED;
	const float ACCELERATION;
	const float DECELERATION;

	const float GRAVITY{ 1.2f };
	const float JUMP_FORCE{ -1.0f };
	const float GROUND_LEVEL{ 640.0f };
};

#endif