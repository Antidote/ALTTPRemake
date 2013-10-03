#include "SSpriteFile.hpp"

SSpriteFile::SSpriteFile()
    : m_width(1),
      m_height(1),
      m_originX(0),
      m_originY(0)
{
}

SSpriteFile::SSpriteFile(int width, int height, float originX, float originY)
    : m_width(width),
      m_height(height),
      m_originX(originX),
      m_originY(originY)
{
}

