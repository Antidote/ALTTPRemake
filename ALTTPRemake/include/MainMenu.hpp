#ifndef MAINMENU_HPP
#define MAINMENU_HPP

#include "MenuState.hpp"

class MainMenu : public MenuState
{
public:
    MainMenu();

    void initialize();
private:
    RunState* m_nextState;
};

#endif // MAINMENU_HPP
