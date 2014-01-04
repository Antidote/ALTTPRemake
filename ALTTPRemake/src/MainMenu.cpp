#include "MainMenu.hpp"
#include <Sakura/Core/Engine.hpp>

MainMenu::MainMenu()
    : MenuState("mainmenu"),
      m_nextState(NULL)
{
}

void MainMenu::initialize()
{
    MenuState::initialize();

    sEngineRef().console().print(Sakura::Core::Console::Info, "Blarg");
}
