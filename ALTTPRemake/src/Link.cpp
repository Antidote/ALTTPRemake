#include "Link.hpp"
#include <Sakura/Core/Engine.hpp>
#include <Sakura/Core/SSpriteFile.hpp>
#include <Sakura/Core/SSprite.hpp>
#include <Sakura/Core/SSpritePart.hpp>
#include "Sakura/Core/CVar.hpp"

#include <iostream>

Sakura::Core::CVar* imp_playerLeft  = NULL;
Sakura::Core::CVar* imp_playerRight = NULL;
Sakura::Core::CVar* imp_playerUp    = NULL;
Sakura::Core::CVar* imp_playerDown  = NULL;

Link::Link()
    : m_currentSprite(NULL)
{
    registerBindings();
    m_linkSprites = sEngineRef().resourceManager().spriteContainer("sprites/Link/Link.sprs");
    if (!m_linkSprites)
        sEngineRef().console().print(Sakura::Core::Console::Fatal, "Unable to load sprite container for player.");
    else
    {
        m_currentSprite = m_linkSprites->sprite("Link_North_Walk");
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
    if (sEngineRef().inputManager().keyboard().isKeyDown(imp_playerLeft->toBinding().Key))
        move(-64*dt.asSeconds(), 0);
    if (sEngineRef().inputManager().keyboard().isKeyDown(imp_playerRight->toBinding().Key))
        move(+64*dt.asSeconds(), 0);
    if (sEngineRef().inputManager().keyboard().isKeyDown(imp_playerUp->toBinding().Key))
        move(0, -64*dt.asSeconds());
    if (sEngineRef().inputManager().keyboard().isKeyDown(imp_playerDown->toBinding().Key))
        move(0, +64*dt.asSeconds());

    Player::update(dt);
    m_currentSprite->setPosition(m_pos);
    m_currentSprite->update(dt);
}

void Link::draw(sf::RenderTarget& rt)
{
    m_currentSprite->draw(rt);
    Player::draw(rt);
}

sf::IntRect Link::collisionRect() const
{
    return sf::IntRect((sf::Vector2i)m_pos, sf::Vector2i(8, 8));
}

void Link::registerBindings()
{
    if (imp_playerLeft == NULL)
    {
        Sakura::Core::CVar::Binding defaultBinding;
        defaultBinding.Key = sf::Keyboard::Left;
        imp_playerLeft     = new Sakura::Core::CVar("playerleft", defaultBinding, "Moves the player left", (Sakura::Core::CVar::Game | Sakura::Core::CVar::Archive));
        sEngineRef().cvarManager().registerCVar(imp_playerLeft);
        defaultBinding.Key = sf::Keyboard::Right;
        imp_playerRight    = new Sakura::Core::CVar("playerright", defaultBinding, "Moves the player right", (Sakura::Core::CVar::Game | Sakura::Core::CVar::Archive));
        sEngineRef().cvarManager().registerCVar(imp_playerRight);
        defaultBinding.Key = sf::Keyboard::Up;
        imp_playerUp       = new Sakura::Core::CVar("playerup", defaultBinding, "Moves the player up", (Sakura::Core::CVar::Game | Sakura::Core::CVar::Archive));
        sEngineRef().cvarManager().registerCVar(imp_playerUp);
        defaultBinding.Key = sf::Keyboard::Down;
        imp_playerDown     = new Sakura::Core::CVar("playerdown", defaultBinding, "Moves the player down", (Sakura::Core::CVar::Game | Sakura::Core::CVar::Archive));
        sEngineRef().cvarManager().registerCVar(imp_playerDown);

    }
}
