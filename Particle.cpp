/*
 * Particle.cpp
 *
 *  Created on: 27/06/2020
 *      Author: vinicius
 */

#include "Particle.h"

Particle::Particle(const ParticleSpecs& specs)
	: sf::RectangleShape(specs.size), m_lifetime(specs.lifetime), m_gravity(specs.gravity), m_speed(specs.speed), m_gravityEffect(specs.gravityEffect)
{
	Random::init();

	setPosition(specs.position);
	setFillColor(specs.color);
}

Particle::~Particle() {}

void Particle::start()
{
	m_started = true;
	m_visible = true;
}

void Particle::restart(const sf::Vector2f& pos)
{
	m_frame = 0;
	setPosition(pos);
}

void Particle::updatePhysics(const float& delta)
{
	if (m_started)
	{
		m_velocity += (m_gravity * (float)(m_frame)) + m_speed;
		m_velocity *= delta;

		move(m_velocity);

		m_frame++;
	}
}

unsigned int Particle::getFrame() const
{
	return m_frame;
}

float Particle::getLifetime() const
{
	return m_lifetime;
}

void Particle::setVisible(const bool& state)
{
	m_visible = state;
}

bool Particle::getVisible() const
{
	return m_visible;
}

void Particle::show()
{
	m_visible = true;
}

void Particle::hide()
{
	m_visible = false;
}
