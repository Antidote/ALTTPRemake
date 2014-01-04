#include "ALTTPGameState.hpp"
#include "Link.hpp"
#include <Sakura/Core/Engine.hpp>
#include <utility.hpp>
#include <iostream>

void ALTTPGameState::initialize()
{
    Sakura::Core::Engine& sEngine = sEngineRef();
    m_clipTime = sf::seconds(.5f);
    GameState::initialize();
    sEngineRef().setClearColor(sf::Color(72, 160, 72));
    Link* link = new Link();
    sEngine.entityManager().addEntity(link);
    sEngine.camera().setLockedOn(link);
    sEngine.console().print(Sakura::Core::Console::Message, "Width: %f", sEngineRef().camera().size().x);
    sEngine.console().print(Sakura::Core::Console::Message, "Height: %f", sEngineRef().camera().size().y);
    m_hudTest.setTexture(sEngineRef().resourceManager().texture("gui/hud_life.png"));
    m_hudTest.setPosition(100, 100);
}

void ALTTPGameState::update(sf::Time dt)
{
    updateHud(dt);
}

void ALTTPGameState::draw(sf::RenderTarget& rt)
{
    drawHud(rt);
}

void ALTTPGameState::updateHud(sf::Time dt)
{
    UNUSED(dt);
}

void ALTTPGameState::drawHud(sf::RenderTarget& rt)
{
    // First lets get the camera's size and position
    sf::Vector2f camSize = sEngineRef().camera().size();
    sf::Vector2f camPos = sEngineRef().camera().position();
    // We want the Hud drawn to the camera's viewport
    // This way it's affected by the view's size
    sEngineRef().window().setView(sEngineRef().camera().view());
    // We want the life bar to be drawn on the upper left hand side of the view

    // Left bracket
    m_hudTest.setTextureRect(sf::IntRect(0, 0, 16, 8));
    m_hudTest.setPosition(camSize.x + camPos.x - 64, camPos.y + 2);
    rt.draw(m_hudTest);

    // Life text
    m_hudTest.setTextureRect(sf::IntRect(16, 0, 16, 8));
    m_hudTest.setPosition(camSize.x + camPos.x - 48, camPos.y + 2);
    rt.draw(m_hudTest);

    // Right bracket
    m_hudTest.setTextureRect(sf::IntRect(0, 0, 16, 8));
    m_hudTest.setPosition(camSize.x + camPos.x - 32, camPos.y + 2);
    rt.draw(m_hudTest);

    sEngineRef().window().setView(sEngineRef().window().getDefaultView());
}
