#include "SSprite.hpp"
#include "SSpritePart.hpp"

SSprite::SSprite()
{
}

SSprite::SSprite(const std::string& name, SSprite::Direction dir)
    : m_name(name),
      m_direction(dir)
{
}

void SSprite::setName(const std::string& name)
{
    m_name = name;
}

std::string SSprite::name() const
{
    return m_name;
}

void SSprite::setDirection(const SSprite::Direction dir)
{
    m_direction = dir;
}

SSprite::Direction SSprite::direction() const
{
    return m_direction;
}

void SSprite::addStateId(int id)
{
    if (m_stateIds.size() > 255)
        return;

    m_stateIds.push_back(id);
}

int SSprite::stateId(int index)
{
    if (index >= (int)m_stateIds.size())
        return -1;

    return m_stateIds[index];
}

void SSprite::addPart(SSpritePart* part)
{
    if (m_parts.find(part->name()) != m_parts.end())
        return;

    m_parts[part->name()] = part;
}
