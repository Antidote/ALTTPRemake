#include "ALTTPGameState.hpp"
#include "Link.hpp"
#include <Engine.hpp>
#include <EntityManager.hpp>
#include <Camera.hpp>

void ALTTPGameState::initialize()
{
    GameState::initialize();

    Link* link = new Link();

    sEngineRef().entityManager().addEntity(link);
    sEngineRef().camera().setLockedOn(link);
}
