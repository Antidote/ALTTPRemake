#include "ALTTPGameState.hpp"
#include "Link.hpp"
#include <Engine.hpp>
#include <EntityManager.hpp>
#include <Camera.hpp>
#include <Container.hpp>
#include <Label.hpp>
#include <Keys.hpp>

void ALTTPGameState::initialize()
{
    m_clipTime = sf::seconds(.5f);
    GameState::initialize();

    Link* link = new Link();

    int windowW = sEngineRef().config().settingInt("vid_width", 640);
    int windowH = sEngineRef().config().settingInt("vid_height", 480);
    m_container = new Container(0, 0, windowW, windowH);
    int startY = 14;

    // New Game
    m_newGameLabel = new Label("newGameLabel", *sEngineRef().resourceManager().font("fonts/debug.ttf"), "New Game");
    m_newGameLabel->setAlignment(Label::Center);
    m_newGameLabel->setPosition(m_container->size().x/2, startY);
    m_newGameLabel->setFontSize(14);
    m_newGameLabel->mouseEnter()->Connect(this, &ALTTPGameState::onMouseEnter);
    m_newGameLabel->mouseLeave()->Connect(this, &ALTTPGameState::onMouseLeave);
    m_newGameLabel->mousePressed()->Connect(this, &ALTTPGameState::onMousePressed);
    m_newGameLabel->mouseReleased()->Connect(this, &ALTTPGameState::onMouseReleased);
    m_newGameLabel->activated()->Connect(this, &ALTTPGameState::onActivated);
    m_newGameLabel->deactivated()->Connect(this, &ALTTPGameState::onDeactivated);
    startY += m_newGameLabel->height();
    m_container->addWidget(m_newGameLabel);


    // Load game
    m_loadGameLabel = new Label("loadGameLabel", *sEngineRef().resourceManager().font("fonts/debug.ttf"), "Load Game");
    m_loadGameLabel->setAlignment(Label::Center);
    m_loadGameLabel->setPosition(m_container->size().x/2, startY);
    m_loadGameLabel->setFontSize(14);
    m_loadGameLabel->mouseEnter()->Connect(this, &ALTTPGameState::onMouseEnter);
    m_loadGameLabel->mouseLeave()->Connect(this, &ALTTPGameState::onMouseLeave);
    m_loadGameLabel->mousePressed()->Connect(this, &ALTTPGameState::onMousePressed);
    m_loadGameLabel->mouseReleased()->Connect(this, &ALTTPGameState::onMouseReleased);
    m_loadGameLabel->activated()->Connect(this, &ALTTPGameState::onActivated);
    m_loadGameLabel->deactivated()->Connect(this, &ALTTPGameState::onDeactivated);
    startY += m_newGameLabel->height();
    m_container->addWidget(m_loadGameLabel);

    // Quit game
    m_quitLabel = new Label("quitLabel", *sEngineRef().resourceManager().font("fonts/debug.ttf"), "Quit");
    m_quitLabel->setAlignment(Label::Center);
    m_quitLabel->setPosition(windowW/2, startY);
    m_quitLabel->setFontSize(14);
    m_quitLabel->mouseEnter()->Connect(this, &ALTTPGameState::onMouseEnter);
    m_quitLabel->mouseLeave()->Connect(this, &ALTTPGameState::onMouseLeave);
    m_quitLabel->mousePressed()->Connect(this, &ALTTPGameState::onMousePressed);
    m_quitLabel->mouseReleased()->Connect(this, &ALTTPGameState::onMouseReleased);
    m_quitLabel->activated()->Connect(this, &ALTTPGameState::onActivated);
    m_quitLabel->deactivated()->Connect(this, &ALTTPGameState::onDeactivated);
    startY += m_newGameLabel->height();
    m_container->addWidget(m_quitLabel);

    sEngineRef().uiManager().addContainer(m_container);
    sEngineRef().entityManager().addEntity(link);
    sEngineRef().camera().setLockedOn(link);
    sEngineRef().resourceManager().playSong("music/rem_Dark_World.ogg", true);
}

void ALTTPGameState::update(sf::Time dt)
{
    int windowW = sEngineRef().config().settingInt("vid_width", 640);
    int windowH = sEngineRef().config().settingInt("vid_height", 480);

    if (sf::Vector2i(windowW, windowH) != m_container->size())
        m_container->setSize(windowW, windowH);

    int startY = 14;
    m_newGameLabel->setPosition(m_container->size().x/2, startY);
    startY += m_newGameLabel->height();
    m_loadGameLabel->setPosition(m_container->size().x/2, startY);
    startY += m_loadGameLabel->height();
    m_quitLabel->setPosition(windowW/2, startY);
    startY += m_quitLabel->height();


    GameState::update(dt);
}

void ALTTPGameState::onMouseEnter(Widget* w)
{
    w->setColor(sf::Color::Red);
    sEngineRef().console().print(Console::Message, "Mouse entered wiget %s", w->name().c_str());
}

void ALTTPGameState::onMouseLeave(Widget* w)
{
    w->setColor(sf::Color::White);
    sEngineRef().console().print(Console::Message, "Mouse left wiget %s", w->name().c_str());
}

void ALTTPGameState::onMousePressed(Widget* w, sf::Mouse::Button button)
{
    sEngineRef().console().print(Console::Message, "Mouse button %s pressed on widget %s", MouseButtonInfo[button].name.c_str(), w->name().c_str());
}

void ALTTPGameState::onMouseReleased(Widget* w, sf::Mouse::Button button)
{
    sEngineRef().console().print(Console::Message, "Mouse button %s released on widget %s", MouseButtonInfo[button].name.c_str(), w->name().c_str());
    if (button == sf::Mouse::Left && w == m_quitLabel)
        sEngineRef().quit();
}

void ALTTPGameState::onActivated(Widget* w)
{
    w->setColor(sf::Color::Red);
}

void ALTTPGameState::onDeactivated(Widget* w)
{
    w->setColor(sf::Color::White);
}
