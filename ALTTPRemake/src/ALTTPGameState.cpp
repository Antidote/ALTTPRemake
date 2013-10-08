#include "ALTTPGameState.hpp"
#include "Link.hpp"
#include <Engine.hpp>
#include <EntityManager.hpp>
#include <Camera.hpp>
#include <Container.hpp>
#include <Label.hpp>
#include <Keys.hpp>
#include <Button.hpp>

#include <iostream>

void ALTTPGameState::initialize()
{
    m_clipTime = sf::seconds(.5f);
    GameState::initialize();

    Link* link = new Link();

    int windowW = sEngineRef().config().settingInt("vid_width", 640);
    int windowH = sEngineRef().config().settingInt("vid_height", 480);
    m_container = new Container(0, 0, windowW, windowH);
    int startY = 16;

    // New Game
    m_newGameLabel = new Label(m_container, "newGameLabel", *sEngineRef().resourceManager().font("fonts/debug.ttf"), "New Game");
    m_container->addWidget(m_newGameLabel);
    m_newGameLabel->setAlignment(Label::Center);
    m_newGameLabel->setPosition(0, startY);
    m_newGameLabel->mouseEnter()   ->Connect(this, &ALTTPGameState::onMouseEnter);
    m_newGameLabel->mouseLeave()   ->Connect(this, &ALTTPGameState::onMouseLeave);
    m_newGameLabel->mousePressed() ->Connect(this, &ALTTPGameState::onMousePressed);
    m_newGameLabel->mouseReleased()->Connect(this, &ALTTPGameState::onMouseReleased);
    m_newGameLabel->activated()    ->Connect(this, &ALTTPGameState::onActivated);
    m_newGameLabel->deactivated()  ->Connect(this, &ALTTPGameState::onDeactivated);
    startY += m_newGameLabel->height();


    // Load game
    m_loadGameLabel = new Label(m_container, "loadGameLabel", *sEngineRef().resourceManager().font("fonts/debug.ttf"), "Load Game");
    m_container->addWidget(m_loadGameLabel);
    m_loadGameLabel->setAlignment(Label::Center);
    m_loadGameLabel->setPosition(0, startY);
    m_loadGameLabel->mouseEnter()->Connect(this, &ALTTPGameState::onMouseEnter);
    m_loadGameLabel->mouseLeave()->Connect(this, &ALTTPGameState::onMouseLeave);
    m_loadGameLabel->mousePressed()->Connect(this, &ALTTPGameState::onMousePressed);
    m_loadGameLabel->mouseReleased()->Connect(this, &ALTTPGameState::onMouseReleased);
    m_loadGameLabel->activated()->Connect(this, &ALTTPGameState::onActivated);
    m_loadGameLabel->deactivated()->Connect(this, &ALTTPGameState::onDeactivated);
    startY += m_newGameLabel->height();
    std::cout << startY << std::endl;

    // Quit game
    m_quitLabel = new Label(m_container, "quitLabel", *sEngineRef().resourceManager().font("fonts/debug.ttf"), "Quit");
    m_container->addWidget(m_quitLabel);
    m_quitLabel->setAlignment(Label::Center);
    m_quitLabel->setPosition(0, startY);
    m_quitLabel->keyPress()->Connect(this, &ALTTPGameState::onKeyPress);
    m_quitLabel->keyRelease()->Connect(this, &ALTTPGameState::onKeyRelease);
    m_quitLabel->mouseEnter()->Connect(this, &ALTTPGameState::onMouseEnter);
    m_quitLabel->mouseLeave()->Connect(this, &ALTTPGameState::onMouseLeave);
    m_quitLabel->mousePressed()->Connect(this, &ALTTPGameState::onMousePressed);
    m_quitLabel->mouseReleased()->Connect(this, &ALTTPGameState::onMouseReleased);
    m_quitLabel->activated()->Connect(this, &ALTTPGameState::onActivated);
    m_quitLabel->deactivated()->Connect(this, &ALTTPGameState::onDeactivated);
    startY += m_newGameLabel->height();
    std::cout << startY << std::endl;

    m_button = new Button(m_container, "testButton");
    m_container->addWidget(m_button);
    m_button->setPosition(32, startY);
    std::cout << m_button->position().x << " " << m_button->position().y << std::endl;
    m_button->keyPress()->Connect(this, &ALTTPGameState::onKeyPress);
    m_button->keyRelease()->Connect(this, &ALTTPGameState::onKeyRelease);
    m_button->mouseEnter()->Connect(this, &ALTTPGameState::onMouseEnter);
    m_button->mouseLeave()->Connect(this, &ALTTPGameState::onMouseLeave);
    m_button->mousePressed()->Connect(this, &ALTTPGameState::onMousePressed);
    m_button->mouseReleased()->Connect(this, &ALTTPGameState::onMouseReleased);
    m_button->activated()->Connect(this, &ALTTPGameState::onActivated);
    m_button->deactivated()->Connect(this, &ALTTPGameState::onDeactivated);
    startY += m_button->height();
    std::cout << startY << std::endl;


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


    GameState::update(dt);
}

void ALTTPGameState::onKeyPress(Widget* w, sf::Event::KeyEvent keyEvent)
{
    sEngineRef().console().print(Console::Message, "Key %s pressed on %s", KeyInfo[keyEvent.code].name.c_str(), w->name().c_str());
}

void ALTTPGameState::onKeyRelease(Widget* w, sf::Event::KeyEvent keyEvent)
{
    sEngineRef().console().print(Console::Message, "Key %s released on %s", KeyInfo[keyEvent.code].name.c_str(), w->name().c_str());

    if (w == m_quitLabel && keyEvent.code == sf::Keyboard::Return)
        sEngineRef().quit();
}

void ALTTPGameState::onMouseEnter(Widget* w)
{
    w->setColor(sf::Color::Red);
}

void ALTTPGameState::onMouseLeave(Widget* w)
{
    w->setColor(sf::Color::White);
}

void ALTTPGameState::onMousePressed(Widget* w, sf::Event::MouseButtonEvent buttonEvent)
{
}

void ALTTPGameState::onMouseReleased(Widget* w, sf::Event::MouseButtonEvent buttonEvent)
{
    if (buttonEvent.button == sf::Mouse::Left && w == m_quitLabel)
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
