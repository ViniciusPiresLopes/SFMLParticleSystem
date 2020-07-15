/*
 * ParticleSystem.h
 *
 *  Created on: 27/06/2020
 *      Author: vinicius
 */

#ifndef PARTICLESYSTEM_H_
#define PARTICLESYSTEM_H_

#include "Random.h"
#include "Particle.h"

#include <SFML/Graphics.hpp>
#include <vector>

struct SpawnAreaSpecs
{
	sf::Vector2f position;
	sf::Vector2f size;
};

struct ParticleSystemSpecs
{
	int fps;
	unsigned int amount;
	sf::Vector2f particleSize;
	sf::Color color;
	float lifetime;
	sf::Vector2f gravity;
	sf::Vector2f speed;
	float gravityEffect;
	bool visible = true;
};

class ParticleSystem : public sf::Drawable
{
private:
	// Spawn Area
	sf::Vector2f m_pos;
	sf::Vector2f m_size;

	// Particle System specs
	std::vector<Particle> m_particles;

	int m_fps;
	unsigned int m_amount;
	sf::Vector2f m_particleSize;
	sf::Color m_color;
	float m_lifetime;
	sf::Vector2f m_gravity;
	sf::Vector2f m_speed;
	float m_gravityEffect;
	bool m_visible;
	float m_gap;
	unsigned int m_currentParticle = 0;
	unsigned int m_frame = 0;
private:
	float m_frame2sec(const int& frame) const;
	unsigned int m_sec2frame(const float& sec) const;
public:
	// Constructor and destructor
	ParticleSystem(const SpawnAreaSpecs& saSpecs, const ParticleSystemSpecs& psSpecs);
	virtual ~ParticleSystem();

	// Functions
	void restart();

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	void updatePhysics(const float& delta);

	void setPosition(const sf::Vector2i& pos);

	void setPosition(const sf::Vector2f& pos);

	sf::Vector2f getPosition() const;

	void setColor(const sf::Color& color);

	sf::Color getColor() const;

	void setGravity(const sf::Vector2f& gravity);

	sf::Vector2f getGravity() const;

	void hide();

	void show();

	void updateVariables();
};

#endif /* PARTICLESYSTEM_H_ */
