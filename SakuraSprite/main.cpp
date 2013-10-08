#include <iostream>
#include "SSpriteFileReader.hpp"
#include "SSpriteFile.hpp"
#include "SSprite.hpp"
#include "SSpritePart.hpp"
#include "SSpriteFrame.hpp"
#include <Exception.hpp>
#include <SFML/Graphics.hpp>
#include <sstream>
#include "Entity.hpp"
#include <GL/gl.h>

int main()
{
    sf::RenderWindow window(sf::VideoMode(640, 480), "Sprite Test");
    sf::View view(sf::FloatRect(0, 0, 320, 240));
    sf::Clock sysClock;
    sf::Time currentTime;
    sf::Time lastTime;
    float fps = 0;

    sf::Font font;
    sf::Text fpsText;

    if (!font.loadFromFile("debug.ttf"))
        return 1;

    fpsText.setFont(font);

    Entity entity("test", Entity::Player);


    while (window.isOpen())
    {
        lastTime = currentTime;
        currentTime = sysClock.restart();
        fps = 1.f/lastTime.asSeconds();
        std::stringstream fpsStream;
        fpsStream << "FPS: " << fps;

        fpsText.setString(fpsStream.str());
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        entity.update(lastTime);

        window.clear();
        window.setView(view);
        entity.draw(window);
        glDisable(GL_TEXTURE_2D);
        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
        entity.draw(window);
        glEnable(GL_TEXTURE_2D);
        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

        window.setView(window.getDefaultView());
        window.draw(fpsText);
        window.display();
    }
    return 0;
}

