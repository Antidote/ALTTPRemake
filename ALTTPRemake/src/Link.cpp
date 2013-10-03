#include "Link.hpp"
#include <Engine.hpp>

Link::Link()
{
    sEngineRef().console().print(Console::Message, "Created player with id %i", m_playerId);
}

void Link::onDeath()
{
    sEngineRef().console().print(Console::Message, "Oh shit i died D:");
}

void Link::onDamage(Entity* e)
{
    UNUSED(e);
    sEngineRef().console().print(Console::Message, "Oh shit i got hurt D:");
}
