#ifndef ALTTPGAMESTATE_HPP
#define ALTTPGAMESTATE_HPP

#include <GameState.hpp>

class Container;
class Label;
class Widget;
class Button;

class ALTTPGameState : public GameState
{
public:
    void initialize();

    void update(sf::Time dt);
private:
    sf::Time m_currentTime;
    sf::Time m_clipTime;
    void onKeyPress(Widget*, sf::Event::KeyEvent);
    void onKeyRelease(Widget*, sf::Event::KeyEvent);
    void onMouseEnter(Widget*);
    void onMouseLeave(Widget*);
    void onMousePressed(Widget*, sf::Event::MouseButtonEvent);
    void onMouseReleased(Widget*, sf::Event::MouseButtonEvent);
    void onActivated(Widget*);
    void onDeactivated(Widget*);
    Container* m_container;
    Label*    m_newGameLabel;
    Label*    m_loadGameLabel;
    Label*    m_quitLabel;
    Button*   m_button;
};

#endif // ALTTPGAMESTATE_HPP
