#ifndef ALTTPGAMESTATE_HPP
#define ALTTPGAMESTATE_HPP

#include <GameState.hpp>

class Container;
class Label;
class Widget;

class ALTTPGameState : public GameState
{
public:
    void initialize();

    void update(sf::Time dt);
private:
    sf::Time m_currentTime;
    sf::Time m_clipTime;
    void onMouseEnter(Widget*);
    void onMouseLeave(Widget*);
    void onMousePressed(Widget*, sf::Mouse::Button);
    void onMouseReleased(Widget*, sf::Mouse::Button);
    void onActivated(Widget*);
    void onDeactivated(Widget*);
    Container* m_container;
    Label*    m_newGameLabel;
    Label*    m_loadGameLabel;
    Label*    m_quitLabel;
};

#endif // ALTTPGAMESTATE_HPP
