/*
 * ParticleSystem.cpp
 *
 *  Created on: 27/06/2020
 *      Author: vinicius
 */

#include "ParticleSystem.h"

ParticleSystem::ParticleSystem(const SpawnAreaSpecs& saSpecs, const ParticleSystemSpecs& psSpecs)
	: m_pos(saSpecs.position), m_size(saSpecs.size), m_fps(psSpecs.fps), m_amount(psSpecs.amount), m_particleSize(psSpecs.particleSize), m_color(psSpecs.color), m_lifetime(psSpecs.lifetime), m_gravity(psSpecs.gravity), m_speed(psSpecs.speed), m_gravityEffect(psSpecs.gravityEffect), m_visible(psSpecs.visible), m_gap(psSpecs.lifetime / psSpecs.amount)
{
	Random::init();

	for (unsigned int i = 0; i < m_amount; i++)
	{
		ParticleSpecs specs = {sf::Vector2f(0.0f, 0.0f), m_particleSize, m_color, m_lifetime, m_gravity, m_speed, m_gravityEffect};
		m_particles.emplace_back(specs);
	}

	restart();
}

ParticleSystem::~ParticleSystem() {}

float ParticleSystem::m_frame2sec(const int& frame) const
{
	return frame / m_fps;
}

unsigned int ParticleSystem::m_sec2frame(const float& sec) const
{
	return (int)(sec * m_fps);
}

void ParticleSystem::restart()
{
	for (unsigned int i = 0; i < m_amount; i++)
	{
		sf::Vector2f pos(Random::randf() * m_size.x + m_pos.x, Random::randf() * m_size.y + m_pos.y);
		m_particles[i].restart(pos);
	}
}

void ParticleSystem::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	for (unsigned int i = 0; i < m_amount; i++)
	{
		if (m_particles[i].getVisible())
		{
			target.draw(m_particles[i], states);
		}
	}
}

void ParticleSystem::updatePhysics(const float& delta)
{
	for (unsigned int i = 0; i < m_amount; i++)
	{
		if (m_particles[i].getFrame() >= m_sec2frame(m_particles[i].getLifetime()))
		{
			sf::Vector2f pos(Random::randf() * m_size.x + m_pos.x, Random::randf() * m_size.y + m_pos.y);
			m_particles[i].restart(pos);
		}

		m_particles[i].updatePhysics(delta);
	}

	if (m_frame >= m_sec2frame(m_gap) * (m_currentParticle + 1))
	{
		m_particles[m_currentParticle].start();

		if (m_currentParticle == m_amount - 1)
		{
			m_currentParticle = 0;
		}
		else
		{
			m_currentParticle++;
		}
	}

	m_frame++;
}

void ParticleSystem::setPosition(const sf::Vector2i& pos)
{
	m_pos = sf::Vector2f((float)pos.x, (float)pos.y);
	updateVariables();
}

void ParticleSystem::setPosition(const sf::Vector2f& pos)
{
	m_pos = pos;
	updateVariables();
}

void ParticleSystem::updateVariables()
{
	for (unsigned int i = 0; i < m_amount; i++)
	{
		if (!m_particles[i].getVisible())
		{
			sf::Vector2f pos(Random::randf() * m_size.x + m_pos.x, Random::randf() * m_size.y + m_pos.y);
			m_particles[i].setPosition(pos);
		}
	}
}
