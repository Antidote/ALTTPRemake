#include "SFMLSplash.hpp"
#include <Sakura/Core/Engine.hpp>
#include <Sakura/Core/ResourceManager.hpp>
#include <Sakura/Resources/TextureResource.hpp>

SFMLSplash::SFMLSplash()
    : m_splashTime(sf::seconds(5.f)),
      m_fade(false)
{
    m_name = "SFMLSplash";
}

SFMLSplash::~SFMLSplash()
{
    sEngineRef().resourceManager().removeTexture("splash/SFML.png");
}

void SFMLSplash::initialize()
{
    m_sfmlLogo.setTexture(sEngineRef().resourceManager().texture("splash/SFML.png"));
}

void SFMLSplash::update(sf::Time dt)
{
    m_currentTime += dt;
    m_sfmlLogo.setOrigin(m_sfmlLogo.getTextureRect().width/2, m_sfmlLogo.getTextureRect().height);
    m_sfmlLogo.setPosition(sEngineRef().config().settingInt("vid_width", 640)/2, sEngineRef().config().settingInt("vid_height", 480)/2);

    if (m_currentTime > m_splashTime)
        m_isDone = true;

    if (m_currentTime > m_splashTime * .5f)
        m_fade = true;

    if (!m_fade)
        m_sfmlLogo.setColor(sf::Color(255, 255, 255, m_currentTime.asSeconds()*50));
    else
        m_sfmlLogo.setColor(sf::Color(255, 255, 255, -(m_currentTime.asSeconds()*50)));

}

void SFMLSplash::draw(sf::RenderTarget& rt)
{
    rt.draw(m_sfmlLogo);
}

Sakura::Core::RunState* SFMLSplash::nextState() const
{
    return sEngineRef().state("game");
}
