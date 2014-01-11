#ifndef LINK_HPP
#define LINK_HPP

#include <Sakura/Core/Player.hpp>

namespace Sakura
{
namespace Core
{
class SSpriteFile;
class SSprite;
}
}

class Link : public Sakura::Core::Player
{
public:
    enum TunicState
    {
        GreenJerkin,
        RedMail,
        BlueMail
    };

    Link();

    void onDeath();
    void onDamage(Entity *e);
    void collide(Entity *entity);

    void update(sf::Time dt);
    void draw(sf::RenderTarget& rt);
    sf::IntRect collisionRect() const;

private:
    void registerBindings();

    Sakura::Core::SSpriteFile* m_linkSprites;
    Sakura::Core::SSprite*     m_currentSprite;
    sf::Texture                m_currentTexture;
};

#endif // LINK_HPP
