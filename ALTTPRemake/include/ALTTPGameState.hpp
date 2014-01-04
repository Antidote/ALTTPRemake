#ifndef ALTTPGAMESTATE_HPP
#define ALTTPGAMESTATE_HPP

#include <Sakura/Core/GameState.hpp>
#include <Sakura/Resources/TextureResource.hpp>

class ALTTPGameState : public Sakura::Core::GameState
{
public:
    void initialize();

    void update(sf::Time dt);
    void draw(sf::RenderTarget &rt);

private:
    void updateHud(sf::Time dt);
    void drawHud(sf::RenderTarget& rt);

    sf::Time   m_currentTime;
    sf::Time   m_clipTime;
    sf::Sprite m_hudTest;
};

#endif // ALTTPGAMESTATE_HPP
