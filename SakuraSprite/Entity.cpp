#include "Entity.hpp"
#include <sstream>
#include <iostream>
#include <Types.hpp>
#include "SSpriteFile.hpp"
#include "SSpriteFileReader.hpp"
#include "SSprite.hpp"
#include "SSpritePart.hpp"
#include "SSpriteFrame.hpp"

Entity::Entity(const std::string& name, Type type)
    : m_name(name),
      m_id(0),
      m_type(type),
      m_facing(North),
      m_lastFacing(North),
      m_velocity(sf::Vector2f(0, 0))
{
    try
    {
        SSpriteFileReader reader("sprites/Link/Link.sprs");
        m_spriteContainer = reader.readFile();
        m_spriteContainer->removeTexture(0);
        m_currentSprite = m_spriteContainer->sprite("Link_North_Walk");
    }
    catch(...)
    {
        m_spriteContainer = NULL;
        m_currentSprite = NULL;
    }
}

Entity::~Entity()
{
}

void Entity::setPosition(const float x, const float y)
{
    setPosition(sf::Vector2f(x, y));
}

void Entity::setPosition(const sf::Vector2f& pos)
{
    m_pos = pos;
}

sf::Vector2f Entity::position() const
{
    return m_pos;
}

void Entity::move(float x, float y)
{
    move(sf::Vector2f(x, y));
}

void Entity::move(const sf::Vector2f &moveToward)
{
    m_pos += moveToward;
}

void Entity::setSize(const float w, const float h)
{
    setSize(sf::Vector2f(w, h));
}

void Entity::setSize(const sf::Vector2f& size)
{
    m_size = size;
}

sf::Vector2f Entity::size() const
{
    return m_size;
}

sf::FloatRect Entity::bounds() const
{
    return sf::FloatRect(m_pos, m_size);
}

std::string Entity::name() const
{
    return m_name;
}

void Entity::setName(const std::string& name)
{
    m_name = name;
}

int Entity::id() const
{
    return m_id;
}

Entity::Type Entity::type() const
{
    return m_type;
}

void Entity::update(sf::Time delta)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        m_pos.x -= 64.f*delta.asSeconds();
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        m_pos.x += 64.f*delta.asSeconds();
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        m_pos.y -= 64.f*delta.asSeconds();
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        m_pos.y += 64.f*delta.asSeconds();

    if (m_currentSprite)
    {
        m_currentSprite->setPosition(m_pos);
        m_currentSprite->update(delta);
    }
}

void Entity::draw(sf::RenderTarget& rt)
{
    if (m_currentSprite)
        m_currentSprite->draw(rt);
    rt.draw(m_debugInfo);
}
