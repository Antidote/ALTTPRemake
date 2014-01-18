#include "SplashState.hpp"
#include <Sakura/Core/Engine.hpp>

SplashState::SplashState()
    : m_isInitialized(false),
      m_isDone(false),
      m_name("UnnamedSplashState"),
      m_nextState(NULL)
{
}

SplashState::~SplashState()
{

}

void SplashState::initialize()
{
    m_isInitialized = true;
}

void SplashState::update(sf::Time dt)
{
    UNUSED(dt);
}

void SplashState::draw(sf::RenderTarget& rt)
{
    UNUSED(rt);
}

bool SplashState::isInitialized() const
{
    return m_isInitialized;
}

Sakura::Core::RunState::Type SplashState::type() const
{
    return Splash;
}

bool SplashState::isDone() const
{
    return m_isDone;
}

std::string SplashState::name() const
{
    return m_name;
}

Sakura::Core::RunState* SplashState::nextState() const
{
    return NULL;
}
