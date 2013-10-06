#include "SSpriteFile.hpp"
#include "SSprite.hpp"

SSpriteFile::SSpriteFile()
    : m_size(sf::Vector2u(1, 1))
{
}

SSpriteFile::SSpriteFile(Uint32 width, Uint32 height, float originX, float originY)
    : m_size(sf::Vector2u(width, height)),
      m_origin(sf::Vector2f(originX, originY))
{
}

SSpriteFile::SSpriteFile(const sf::Vector2u& size, const sf::Vector2f origin)
    : m_size(size),
      m_origin(origin)
{
}

void SSpriteFile::setSize(Uint32 width, Uint32 height)
{
    setSize(sf::Vector2u(width, height));
}

void SSpriteFile::setSize(const sf::Vector2u& size)
{
    m_size = size;
}

sf::Vector2u SSpriteFile::size() const
{
    return m_size;
}

void SSpriteFile::setOrigin(const float x, const float y)
{
    setOrigin(sf::Vector2f(x, y));
}

void SSpriteFile::setOrigin(const sf::Vector2f& origin)
{
    m_origin = origin;
}

sf::Vector2f SSpriteFile::origin() const
{
    return m_origin;
}

float SSpriteFile::originX() const
{
    return m_origin.x;
}

float SSpriteFile::originY() const
{
    return m_origin.y;
}

void SSpriteFile::addTexture(STexture* texture)
{
    m_textures.push_back(texture);
}

void SSpriteFile::removeTexture(int id)
{
    ((void)id);
    // TODO: Implement;
}

STexture* SSpriteFile::texture(Uint32 id)
{
    if (id >= m_textures.size())
        return NULL;

    return m_textures[id];
}

void SSpriteFile::addSprite(SSprite* sprite)
{
    if (m_sprites.find(sprite->name()) != m_sprites.end())
        return;

    m_sprites[sprite->name()] = sprite;
}

