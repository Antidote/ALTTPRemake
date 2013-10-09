#ifndef LINK_HPP
#define LINK_HPP

#include <Sakura/Core/Player.hpp>


class Link : public Sakura::Core::Player
{
public:
    Link();

    void onDeath();
    void onDamage(Entity *e);
    void collide(Entity *entity);
    sf::IntRect collisionRect() const;
};

#endif // LINK_HPP
