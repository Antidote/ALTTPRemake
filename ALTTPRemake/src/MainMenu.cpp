#include "MainMenu.hpp"
#include <Sakura/Core/Engine.hpp>
#include <Sakura/Core/Camera.hpp>

MainMenu::MainMenu()
    : MenuState("mainmenu"),
      m_nextState(NULL)
{
}

void MainMenu::initialize()
{
    MenuState::initialize();
    Sakura::Core::Camera& camera = sEngineRef().camera();
    m_bgTiles = sEngineRef().resourceManager().texture("tilesets/menuBG.png");
    sf::Image tmp = m_bgTiles.copyToImage();
    m_bgTexture.loadFromImage(tmp, sf::IntRect(16, 16, 16, 16));
    m_bgTexture.setRepeated(true);
    m_nameTop.loadFromImage(tmp, sf::IntRect(64, 0, 16, 16));
    m_nameTop.setRepeated(true);
    m_nameBottom.loadFromImage(tmp, sf::IntRect(64, 16, 16, 16));
    m_nameBottom.setRepeated(true);
    m_nameShadow.loadFromImage(tmp, sf::IntRect(48, 32, 16, 16));
    m_nameShadow.setRepeated(true);
    m_nameShadow.setSmooth(false);
    m_bg.setTexture(m_bgTexture);
    m_bg.setTextureRect(sf::IntRect(0, 0, camera.size().x, camera.size().y));
    m_blackRect.setFillColor(sf::Color::Black);
}

void MainMenu::draw(sf::RenderTarget& rt)
{
    MenuState::draw(rt);
    sEngineRef().window().setView(sEngineRef().camera().view());

    rt.draw(m_bg);

    // Draw the background rect;
    m_blackRect.setPosition(32, 23);
    m_blackRect.setSize(sf::Vector2f(128, 16));
    rt.draw(m_blackRect);
    m_nameArea.setTexture(m_bgTiles);
    m_nameArea.setPosition(sEngineRef().camera().position().x + 16, sEngineRef().camera().position().y + 15);
    m_nameArea.setTextureRect(sf::IntRect(48, 0, 16, 16));
    rt.draw(m_nameArea);
    m_nameArea.setPosition(sEngineRef().camera().position().x + 160, sEngineRef().camera().position().y + 15);
    m_nameArea.setTextureRect(sf::IntRect(80, 0, 16, 16));
    rt.draw(m_nameArea);
    m_nameArea.setPosition(sEngineRef().camera().position().x + 16, sEngineRef().camera().position().y + 31);
    m_nameArea.setTextureRect(sf::IntRect(48, 16, 16, 16));
    rt.draw(m_nameArea);
    m_nameArea.setPosition(sEngineRef().camera().position().x + 160, sEngineRef().camera().position().y + 31);
    m_nameArea.setTextureRect(sf::IntRect(80, 16, 16, 16));
    rt.draw(m_nameArea);
    m_nameArea.setTexture(m_nameTop);
    m_nameArea.setPosition(sEngineRef().camera().position().x + 32, sEngineRef().camera().position().y + 15);
    m_nameArea.setTextureRect(sf::IntRect(0, 0, 128, 8));
    rt.draw(m_nameArea);
    m_nameArea.setTexture(m_nameBottom);
    m_nameArea.setPosition(sEngineRef().camera().position().x + 32, sEngineRef().camera().position().y + 39);
    m_nameArea.setTextureRect(sf::IntRect(0, 8, 128, 8));
    rt.draw(m_nameArea);
    m_nameArea.setPosition(sEngineRef().camera().position().x + 16, sEngineRef().camera().position().y + 47);
    m_nameArea.setTexture(m_nameShadow);
    m_nameArea.setTextureRect(sf::IntRect(0, 0, 160, 8));
    rt.draw(m_nameArea);

    sEngineRef().window().setView(sEngineRef().window().getDefaultView());
}
