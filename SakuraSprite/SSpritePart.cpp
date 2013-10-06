#include "SSpritePart.hpp"

SSpritePart::SSpritePart()
{
}

SSpritePart::SSpritePart(const std::string& name, bool hasCollision)
    : m_name(name),
      m_hasCollision(hasCollision)
{
}

void SSpritePart::setName(const std::string& name)
{
    m_name = name;
}

std::string SSpritePart::name() const
{
    return m_name;
}

void SSpritePart::setCollision(bool col)
{
    m_hasCollision = col;
}

bool SSpritePart::hasCollision() const
{
    return m_hasCollision;
}

void SSpritePart::addFrame(SSpriteFrame* frame)
{
    m_frames.push_back(frame);
}

SSpriteFrame* SSpritePart::frame(int id)
{
    if (id < 0 || id >= (int)m_frames.size())
        return NULL;

    return m_frames[id];
}
