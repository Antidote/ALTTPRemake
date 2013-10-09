#include <ALTTPEngine.hpp>
#include <SakuraSplash.hpp>
#include <SFMLSplash.hpp>
#include <ALTTPGameState.hpp>

ALTTPEngine::ALTTPEngine()
{
}

void ALTTPEngine::initialize(int argc, char *argv[])
{
    Engine::initialize(argc, argv);
    console().print(Sakura::Core::Console::Info, "Initializing gamestates");
    // Sakura Splash
    /*SakuraSplash* sakuraSplash = new SakuraSplash();
    addState(sakuraSplash);
    // SFML Splash
    SFMLSplash* sfmlSplash = new SFMLSplash();
    addState(sfmlSplash);
*/
    // ALTTP Game state
    ALTTPGameState* gameState = new ALTTPGameState();
    addState(gameState);
    console().print(Sakura::Core::Console::Info, "A Link to the Past Remake " + gameVersion() + " Initialized");
}

std::string ALTTPEngine::gameVersion() const
{
    return "0.1 INTERNAL PRE-ALPHA";
}

std::string ALTTPEngine::defaultTitle() const
{
    return "A Link to the Past Remake " + gameVersion();
}
