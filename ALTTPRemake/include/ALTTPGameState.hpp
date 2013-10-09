#ifndef ALTTPGAMESTATE_HPP
#define ALTTPGAMESTATE_HPP

#include <Sakura/Core/GameState.hpp>

namespace Sakura
{
namespace Gui
{
class Container;
class Label;
class Widget;
}
}
class Button;

class ALTTPGameState : public Sakura::Core::GameState
{
public:
    void initialize();

    void update(sf::Time dt);
private:
    sf::Time m_currentTime;
    sf::Time m_clipTime;
    void onKeyPress(Sakura::Gui::Widget*, sf::Event::KeyEvent);
    void onKeyRelease(Sakura::Gui::Widget*, sf::Event::KeyEvent);
    void onMouseEnter(Sakura::Gui::Widget*);
    void onMouseLeave(Sakura::Gui::Widget*);
    void onMousePressed(Sakura::Gui::Widget*, sf::Event::MouseButtonEvent);
    void onMouseReleased(Sakura::Gui::Widget*, sf::Event::MouseButtonEvent);
    void onActivated(Sakura::Gui::Widget*);
    void onDeactivated(Sakura::Gui::Widget*);
    Sakura::Gui::Container* m_container;
    Sakura::Gui::Label*    m_newGameLabel;
    Sakura::Gui::Label*    m_loadGameLabel;
    Sakura::Gui::Label*    m_quitLabel;
    Button*   m_button;
};

#endif // ALTTPGAMESTATE_HPP
