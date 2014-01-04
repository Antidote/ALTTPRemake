#include <ALTTPEngine.hpp>
#include <SakuraSplash.hpp>
#include <SFMLSplash.hpp>
#include <ALTTPGameState.hpp>
#include <MainMenu.hpp>

ALTTPEngine::ALTTPEngine()
{
}

bool ALTTPEngine::initialize(int argc, char *argv[])
{
    if (Engine::initialize(argc, argv))
    {
        console().print(Sakura::Core::Console::Info, "Initializing gamestates");
        // Sakura Splash
        SakuraSplash* sakuraSplash = new SakuraSplash();
        addState(sakuraSplash);
        // SFML Splash
        SFMLSplash* sfmlSplash = new SFMLSplash();
        addState(sfmlSplash);
        addState(new MainMenu());
        // ALTTP Game state
        ALTTPGameState* gameState = new ALTTPGameState();
        addState(gameState);
//        setCurrentState("game");
        console().print(Sakura::Core::Console::Info, "A Link to the Past Remake " + gameVersion() + " Initialized");
        return true;
    }

    return false;
}

void ALTTPEngine::onEvent(const sf::Event& event)
{
    Sakura::Core::Engine::onEvent(event);
}

void ALTTPEngine::beforeUpdate()
{
}

void ALTTPEngine::onUpdate()
{
    Sakura::Core::Engine::onUpdate();
}

void ALTTPEngine::afterUpdate()
{
}

void ALTTPEngine::beforeDraw()
{
}

void ALTTPEngine::onDrawEntities()
{
    Sakura::Core::Engine::onDrawEntities();
}

void ALTTPEngine::onDraw()
{
    // Before engine's draw event renders everything to the camera's view,
    // above entities
    Sakura::Core::Engine::onDraw();
}

void ALTTPEngine::onDrawConsole()
{
    Sakura::Core::Engine::onDrawConsole();
}

void ALTTPEngine::afterDraw()
{
}

std::string ALTTPEngine::gameVersion() const
{
    return "0.1 INTERNAL PRE-ALPHA";
}

std::string ALTTPEngine::defaultTitle() const
{
    return "A Link to the Past Remake " + gameVersion();
}
