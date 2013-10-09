#include "ALTTPGameState.hpp"
#include "Link.hpp"
#include <Sakura/Core/Engine.hpp>
#include <Sakura/Core/EntityManager.hpp>
#include <Sakura/Core/Keys.hpp>
#include <Sakura/Core/Camera.hpp>
#include <Sakura/Gui/Container.hpp>
#include <Sakura/Gui/Label.hpp>
#include "Button.hpp"

#include <iostream>

void ALTTPGameState::initialize()
{
    m_clipTime = sf::seconds(.5f);
    GameState::initialize();

    Link* link = new Link();

    int windowW = sEngineRef().config().settingInt("vid_width", 640);
    int windowH = sEngineRef().config().settingInt("vid_height", 480);
    m_container = new Sakura::Gui::Container(0, 0, windowW, windowH);
    int startY = 16;

    // New Game
    m_newGameLabel = new Sakura::Gui::Label(m_container, "newGameLabel", *sEngineRef().resourceManager().font("fonts/debug.ttf"), "New Game");
    m_container->addWidget(m_newGameLabel);
    m_newGameLabel->setAlignment(Sakura::Gui::Label::Center);
    m_newGameLabel->setPosition(0, startY);
    m_newGameLabel->mouseEnter()   ->Connect(this, &ALTTPGameState::onMouseEnter);
    m_newGameLabel->mouseLeave()   ->Connect(this, &ALTTPGameState::onMouseLeave);
    m_newGameLabel->mousePressed() ->Connect(this, &ALTTPGameState::onMousePressed);
    m_newGameLabel->mouseReleased()->Connect(this, &ALTTPGameState::onMouseReleased);
    m_newGameLabel->activated()    ->Connect(this, &ALTTPGameState::onActivated);
    m_newGameLabel->deactivated()  ->Connect(this, &ALTTPGameState::onDeactivated);
    startY += m_newGameLabel->height();


    // Load game
    m_loadGameLabel = new Sakura::Gui::Label(m_container, "loadGameLabel", *sEngineRef().resourceManager().font("fonts/debug.ttf"), "Load Game");
    m_container->addWidget(m_loadGameLabel);
    m_loadGameLabel->setAlignment(Sakura::Gui::Label::Center);
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
    m_quitLabel = new Sakura::Gui::Label(m_container, "quitLabel", *sEngineRef().resourceManager().font("fonts/debug.ttf"), "Quit");
    m_container->addWidget(m_quitLabel);
    m_quitLabel->setAlignment(Sakura::Gui::Label::Center);
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

void ALTTPGameState::onKeyPress(Sakura::Gui::Widget* w, sf::Event::KeyEvent keyEvent)
{
    sEngineRef().console().print(Sakura::Core::Console::Message, "Key %s pressed on %s", KeyInfo[keyEvent.code].name.c_str(), w->name().c_str());
}

void ALTTPGameState::onKeyRelease(Sakura::Gui::Widget* w, sf::Event::KeyEvent keyEvent)
{
    sEngineRef().console().print(Sakura::Core::Console::Message, "Key %s released on %s", KeyInfo[keyEvent.code].name.c_str(), w->name().c_str());

    if (w == m_quitLabel && keyEvent.code == sf::Keyboard::Return)
        sEngineRef().quit();
}

void ALTTPGameState::onMouseEnter(Sakura::Gui::Widget* w)
{
    w->setColor(sf::Color::Red);
}

void ALTTPGameState::onMouseLeave(Sakura::Gui::Widget* w)
{
    w->setColor(sf::Color::White);
}

void ALTTPGameState::onMousePressed(Sakura::Gui::Widget* w, sf::Event::MouseButtonEvent buttonEvent)
{
}

void ALTTPGameState::onMouseReleased(Sakura::Gui::Widget* w, sf::Event::MouseButtonEvent buttonEvent)
{
    if (buttonEvent.button == sf::Mouse::Left && w == m_quitLabel)
        sEngineRef().quit();
}

void ALTTPGameState::onActivated(Sakura::Gui::Widget* w)
{
    w->setColor(sf::Color::Red);
}

void ALTTPGameState::onDeactivated(Sakura::Gui::Widget* w)
{
    w->setColor(sf::Color::White);
}
