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
#include "RoundedRectangleShape.hpp"

int main()
{
    sf::RenderWindow window(sf::VideoMode(640, 480), "Sprite Test");
    sf::View view(sf::FloatRect(0, 0, 320, 240));
    sf::Clock sysClock;
    sf::Time currentTime;
    sf::Time lastTime;
    sf::RectangleShape testRect(sf::Vector2f(32, 32));
    testRect.move(100, 100);
    RoundedRectangleShape rectShape(sf::Vector2f(100, 5), 10, 5);
//    rectShape.setOutlineColor(sf::Color::Blue);
    rectShape.setOutlineThickness(2.f);
    rectShape.move(50, 100);
    //rectShape.scale(5.f, 5.f);
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
//        glDisable(GL_TEXTURE_2D);
//        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
        entity.draw(window);
        //window.draw(testRect);

        window.draw(rectShape);
//        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
//        glEnable(GL_TEXTURE_2D);
        window.setView(window.getDefaultView());
        window.draw(fpsText);
        window.display();
    }
    return 0;
}

