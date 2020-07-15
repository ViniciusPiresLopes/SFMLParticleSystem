/*
 * Particle.h
 *
 *  Created on: 27/06/2020
 *      Author: vinicius
 */

#ifndef PARTICLE_H_
#define PARTICLE_H_

#include "Random.h"

#include <SFML/Graphics.hpp>

struct ParticleSpecs
{
	sf::Vector2f position;
	sf::Vector2f size;
	sf::Color color;
	float lifetime;
	sf::Vector2f gravity;
	sf::Vector2f speed;
	float gravityEffect;
};

class Particle : public sf::RectangleShape
{
private:
	float m_lifetime;
	sf::Vector2f m_gravity;
	sf::Vector2f m_speed;
	float m_gravityEffect;

	sf::Vector2f m_velocity;
	unsigned int m_frame = 1;
	bool m_started = false;
	bool m_visible = false;
public:
	Particle(const ParticleSpecs& specs);
	virtual ~Particle();

	void start();

	void restart(const sf::Vector2f& pos);

	void updatePhysics(const float& delta);

	unsigned int getFrame() const;

	float getLifetime() const;

	void setVisible(const bool& state);

	bool getVisible() const;

	void show();

	void hide();

	void setGravity(const sf::Vector2f& gravity);

	sf::Vector2f getGravity() const;

	void setSpeed(const sf::Vector2f& speed);

	sf::Vector2f getSpeed() const;
};

#endif /* PARTICLE_H_ */









