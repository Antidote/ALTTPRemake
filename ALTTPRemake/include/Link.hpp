#ifndef LINK_HPP
#define LINK_HPP

#include <Player.hpp>


class Link : public Player
{
public:
    Link();

    void onDeath();
    void onDamage(Entity *e);
};

#endif // LINK_HPP
