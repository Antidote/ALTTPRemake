#ifndef SAKURASPLASH_HPP
#define SAKURASPLASH_HPP

#include "SplashState.hpp"

class SakuraSplash : public SplashState
{
public:
    SakuraSplash();
    ~SakuraSplash();

    void initialize();
    void update(sf::Time dt);
    void draw(sf::RenderTarget &rt);
    RunState* nextState() const;

private:
    sf::Time   m_splashTime;
    sf::Time   m_currentTime;
    sf::Sprite m_sakuraLogo;
    sf::RectangleShape m_fader;
    bool       m_fade;
};


#endif // SAKURASPLASH_HPP
