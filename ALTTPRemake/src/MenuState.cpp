#include "MenuState.hpp"
#include <utility.hpp>

MenuState::MenuState(const std::string &name)
    : m_name(name),
      m_isDone(false),
      m_isInitialized(false)
{
}

MenuState::~MenuState()
{
}

void MenuState::initialize()
{
    m_isInitialized = true;
}

void MenuState::update(sf::Time dt)
{
    UNUSED(dt);
}

void MenuState::draw(sf::RenderTarget& rt)
{
    UNUSED(rt);
}

bool MenuState::isInitialized() const
{
    return m_isInitialized;
}

Sakura::Core::RunState::Type MenuState::type() const
{
    return Sakura::Core::RunState::Menu;
}

bool MenuState::isDone() const
{
    return m_isDone;
}

std::string MenuState::name() const
{
    return m_name;
}

Sakura::Core::RunState*MenuState::nextState() const
{
    return NULL;
}
