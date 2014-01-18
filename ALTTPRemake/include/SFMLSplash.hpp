#ifndef SFMLSPLASH_HPP
#define SFMLSPLASH_HPP

#include "SplashState.hpp"

class SFMLSplash : public SplashState
{
public:
    SFMLSplash();
    ~SFMLSplash();

    void initialize();
    void update(sf::Time dt);
    void draw(sf::RenderTarget &rt);
    RunState* nextState() const;

private:
    sf::Time   m_splashTime;
    sf::Time   m_currentTime;
    sf::Sprite m_sfmlLogo;
    bool       m_fade;
};

#endif // SFMLSPLASH_HPP
