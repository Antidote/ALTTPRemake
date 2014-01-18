#ifndef MAINMENU_HPP
#define MAINMENU_HPP

#include "MenuState.hpp"

class MainMenu : public MenuState
{
public:
    MainMenu();

    void initialize();

    void draw(sf::RenderTarget &rt);
private:
    RunState* m_nextState;
    sf::Texture m_bgTiles;
    sf::Texture m_bgTexture;
    sf::Texture m_nameTop;
    sf::Texture m_nameBottom;
    sf::Texture m_nameShadow;
    sf::Sprite m_bg;
    sf::Sprite m_nameArea;
    sf::Sprite m_fileArea;
    sf::RectangleShape m_blackRect;
};

#endif // MAINMENU_HPP
