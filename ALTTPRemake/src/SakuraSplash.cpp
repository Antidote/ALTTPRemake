#include "SakuraSplash.hpp"
#include <Sakura/Core/Engine.hpp>
#include <Sakura/Core/ResourceManager.hpp>
#include <Sakura/Resources/TextureResource.hpp>


SakuraSplash::SakuraSplash()
    : m_splashTime(sf::seconds(5.f)),
      m_fade(false)
{
    m_name = "SakuraSplash";
}

SakuraSplash::~SakuraSplash()
{
    // We need to clean up after ourselves
    sEngineRef().resourceManager().removeTexture("splash/SakuraLogo.png");
}

void SakuraSplash::initialize()
{
    m_sakuraLogo.setTexture(sEngineRef().resourceManager().texture("splash/SakuraLogo.png"));
    sEngineRef().setClearColor(sf::Color(232, 150, 142));
    m_fader.setPosition(0, 0);

    SplashState::initialize();
}

void SakuraSplash::update(sf::Time dt)
{
    m_currentTime += dt;
    m_sakuraLogo.setOrigin(m_sakuraLogo.getTextureRect().width/2, m_sakuraLogo.getTextureRect().height/2);
    m_sakuraLogo.setPosition(sEngineRef().config().settingInt("vid_width", 640)/2, sEngineRef().config().settingInt("vid_height", 480)/2);
    m_fader.setSize(sf::Vector2f(sEngineRef().config().settingInt("vid_width", 640), sEngineRef().config().settingInt("vid_height", 640)));

    if (m_currentTime > m_splashTime)
    {
        sEngineRef().setClearColor(sf::Color::Black);
        m_isDone = true;
    }

    if (m_currentTime > m_splashTime * .5f)
        m_fade = true;
    if (!m_fade)
        m_fader.setFillColor(sf::Color(0, 0, 0, -(m_currentTime.asSeconds()*50)));
    else
        m_fader.setFillColor(sf::Color(0, 0, 0, m_currentTime.asSeconds()*50));
}

void SakuraSplash::draw(sf::RenderTarget& rt)
{
    rt.draw(m_sakuraLogo);
    rt.draw(m_fader);
}

Sakura::Core::RunState* SakuraSplash::nextState() const
{
    return sEngineRef().state("SFMLSplash");
}
