#include "Link.hpp"
#include <Sakura/Core/Engine.hpp>
#include <Sakura/Core/SSpriteFile.hpp>
#include <Sakura/Core/SSprite.hpp>
#include <Sakura/Core/SSpritePart.hpp>

#include <iostream>

Link::Link()
    : m_currentSprite(NULL)
{
    m_linkSprites = sEngineRef().resourceManager().spriteContainer("sprites/Link/Link.sprs");
    if (!m_linkSprites)
        sEngineRef().console().print(Sakura::Core::Console::Fatal, "Unable to load sprite container for player.");
    else
    {
        m_currentSprite = m_linkSprites->sprite("Link_South_Walk");
        m_currentSprite->setCurrentState(RedMail);
    }
}

void Link::onDeath()
{
    sEngineRef().console().print(Sakura::Core::Console::Message, "Oh shit i died D:");
}

void Link::onDamage(Entity* e)
{
    UNUSED(e);
    sEngineRef().console().print(Sakura::Core::Console::Message, "Oh shit i got hurt D:");
}

void Link::collide(Entity* entity)
{
    UNUSED(entity);
}

void Link::update(sf::Time dt)
{
    if (sEngineRef().inputManager().keyboard().isKeyDown(sf::Keyboard::Left))
        move(-64*dt.asSeconds(), 0);
    if (sEngineRef().inputManager().keyboard().isKeyDown(sf::Keyboard::Right))
        move(+64*dt.asSeconds(), 0);
    if (sEngineRef().inputManager().keyboard().isKeyDown(sf::Keyboard::Up))
        move(0, -64*dt.asSeconds());
    if (sEngineRef().inputManager().keyboard().isKeyDown(sf::Keyboard::Down))
        move(0, +64*dt.asSeconds());

    Player::update(dt);
    m_currentSprite->setPosition(m_pos);
    m_currentSprite->update(dt);
}

void Link::draw(sf::RenderTarget& rt)
{
    Player::draw(rt);
    m_currentSprite->draw(rt);
}

sf::IntRect Link::collisionRect() const
{
    return sf::IntRect((sf::Vector2i)m_pos, sf::Vector2i(8, 8));
}
