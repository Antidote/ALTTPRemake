#include "Link.hpp"
#include <Sakura/Core/Engine.hpp>
#include <Sakura/Core/SSpriteFile.hpp>
#include <Sakura/Core/SSprite.hpp>
#include <Sakura/Core/SSpritePart.hpp>

Link::Link()
{
    sEngineRef().console().print(Sakura::Core::Console::Message, "Created player with id %i", m_playerId);

    Sakura::Core::SSpriteFile* test = sEngineRef().resourceManager().sprite("sprites/Link/Link.sprs");
    sEngineRef().resourceManager().texture("arglebargle.png");
    sEngineRef().resourceManager().playSound("arglebargle.wav");
    sEngineRef().resourceManager().playSong("arglebargle.ogg");
    sEngineRef().resourceManager().font("arglebargle.ttf");
    if (!test)
        sEngineRef().console().print(Sakura::Core::Console::Fatal, "Unable to load sprite container for player.");
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

sf::IntRect Link::collisionRect() const
{
    return sf::IntRect((sf::Vector2i)m_pos, sf::Vector2i(8, 8));
}
