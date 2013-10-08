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
    m_title = config().settingLiteral("sys_title", "A Link to the Past Remake " + ALTTPEngine::gameVersion());
    window().setTitle(m_title);
    console().print(Console::Info, "Initializing gamestates");
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
    console().print(Console::Info, "A Link to the Past Remake " + ALTTPEngine::gameVersion() + " Initialized");
}

std::string ALTTPEngine::gameVersion()
{
    return "0.1 INTERNAL PRE-ALPHA";
}
