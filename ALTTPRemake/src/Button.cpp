#include "Button.hpp"
#include <Sakura/Core/Engine.hpp>

Button::Button(Sakura::Gui::Container* owner, const std::string& name, bool visible, bool enabled)
    : Sakura::Gui::Widget(owner, name, visible, enabled)
{
    m_texture = sEngineRef().resourceManager().texture("gui/testButton.png");
    m_text.setFont(*sEngineRef().resourceManager().font("fonts/debug.ttf"));
    m_text.setString("Test");
    m_text.setCharacterSize(16);
    updateButton();
}

void Button::setPosition(const float x, const float y)
{
    setPosition(sf::Vector2f(x, y));
}

void Button::setPosition(const sf::Vector2f& position)
{
    Sakura::Gui::Widget::setPosition(position);
    updateButton();
}

void Button::setSize(const float w, const float h)
{
    setSize(sf::Vector2f(w, h));
}

void Button::setSize(const sf::Vector2f& size)
{
    if (size.x < 16 || size.y < 16)
    {
        sf::Vector2f tmp = size;
        if (size.x < 16)
            tmp.x = 16;
        if (size.y < 16)
            tmp.y = 16;
        Widget::setSize(tmp);
    }
    else
        Widget::setSize(size);
    updateButton();
}

void Button::update(sf::Time dt)
{
    updateButton();
    Widget::update(dt);
}

void Button::draw(sf::RenderTarget& rt)
{
    rt.draw(m_vertices, &m_texture);
    rt.draw(m_text);
    Widget::draw(rt);
}

void Button::updateButton()
{
    m_vertices.clear();
    m_vertices.setPrimitiveType(sf::Quads);


    m_text.setPosition(m_position.x + 5.f, m_position.y + 5.f);
    m_size = sf::Vector2f(m_text.getLocalBounds().width + 9.f, (m_text.getLocalBounds().height * 2) + 9.f);
    corners();
    borders();

    if (m_size.x > 16 && m_size.y > 16)
    {
        // Now draw the center
        sf::Vertex point;
        point.color = m_color;
        point.position.x = m_position.x + 8.f;
        point.position.y = m_position.y + 8.f;
        point.texCoords = sf::Vector2f(8, 8);
        m_vertices.append(point);
        point = sf::Vertex();
        point.color = m_color;
        point.position.x = m_position.x + (m_size.x - 8.f);
        point.position.y = m_position.y + 8.f;
        point.texCoords = sf::Vector2f(9, 8);
        m_vertices.append(point);
        point = sf::Vertex();
        point.color      = m_color;
        point.position.x = m_position.x + (m_size.x - 8.f);
        point.position.y = m_position.y + (m_size.y - 8.f);
        point.texCoords = sf::Vector2f(9, 9);
        m_vertices.append(point);
        point = sf::Vertex();
        point.color      = m_color;
        point.position.x = m_position.x + 8.f;
        point.position.y = m_position.y + (m_size.y - 8.f);
        point.texCoords = sf::Vector2f(8, 9);
        m_vertices.append(point);
    }
}

void Button::corners()
{
    sf::Vertex point;

    // Top left corner
    point.color = m_color;
    point.position = m_position;
    point.texCoords = sf::Vector2f();
    m_vertices.append(point);
    point.color = m_color;
    point.position.x = m_position.x + 8.f;
    point.position.y = m_position.y;
    point.texCoords.x = 8;
    point.texCoords.y = 0;
    m_vertices.append(point);
    point.color      = m_color;
    point.position.x = m_position.x + 8.f;
    point.position.y = m_position.y + 8.f;
    point.texCoords.x = 8;
    point.texCoords.y = 8;
    m_vertices.append(point);
    point.color      = m_color;
    point.position.x = m_position.x;
    point.position.y = m_position.y + 8.f;
    point.texCoords.x = 0;
    point.texCoords.y = 8;
    m_vertices.append(point);

    // Bottom left corner
    point.color = m_color;
    point.position.x = m_position.x;
    point.position.y = m_position.y + (m_size.y - 8.f);
    point.texCoords = sf::Vector2f(0, 8);
    m_vertices.append(point);
    point.color = m_color;
    point.position.x = m_position.x + 8.f;
    point.position.y = m_position.y + (m_size.y - 8.f);
    point.texCoords.x = 8;
    point.texCoords.y = 8;
    m_vertices.append(point);
    point.color = m_color;
    point.position.x = m_position.x + 8.f;
    point.position.y = m_position.y + m_size.y;
    point.texCoords.x = 8;
    point.texCoords.y = 16;
    m_vertices.append(point);
    point.color = m_color;
    point.position.x = m_position.x;
    point.position.y = m_position.y + m_size.y;
    point.texCoords.x = 0;
    point.texCoords.y = 16;
    m_vertices.append(point);

    // Top Right corner
    point.color = m_color;
    point.position.x = m_position.x + (m_size.x - 8.f);
    point.position.y = m_position.y;
    point.texCoords = sf::Vector2f(8, 0);
    m_vertices.append(point);
    point.color = m_color;
    point.position.x = m_position.x + (m_size.x);
    point.position.y = m_position.y;
    point.texCoords.x = 16;
    point.texCoords.y = 0;
    m_vertices.append(point);
    point.color = m_color;
    point.position.x = m_position.x + m_size.x;
    point.position.y = m_position.y + 8.f;
    point.texCoords.x = 16;
    point.texCoords.y = 8;
    m_vertices.append(point);
    point.color = m_color;
    point.position.x = m_position.x + (m_size.x - 8.f);
    point.position.y = m_position.y + 8.f;
    point.texCoords.x = 8;
    point.texCoords.y = 8;
    m_vertices.append(point);

    // Bottom right corner
    point.color = m_color;
    point.position.x = m_position.x + (m_size.x - 8.f);
    point.position.y = m_position.y + (m_size.y - 8.f);
    point.texCoords = sf::Vector2f(8, 8);
    m_vertices.append(point);
    point.color = m_color;
    point.position.x = m_position.x + m_size.x;
    point.position.y = m_position.y + (m_size.y - 8.f);
    point.texCoords.x = 16;
    point.texCoords.y = 8;
    m_vertices.append(point);
    point.color = m_color;
    point.position.x = m_position.x + m_size.x;
    point.position.y = m_position.y + m_size.y;
    point.texCoords.x = 16;
    point.texCoords.y = 16;
    m_vertices.append(point);
    point.color = m_color;
    point.position.x = m_position.x + (m_size.x - 8.f);
    point.position.y = m_position.y + m_size.y;
    point.texCoords.x = 8;
    point.texCoords.y = 16;
    m_vertices.append(point);
}

void Button::borders()
{
    sf::Vertex point;
    if (m_size.x > 16)
    {
        // Top border
        point.color = m_color;
        point.position.x = m_position.x + 8.f;
        point.position.y = m_position.y;
        point.texCoords = sf::Vector2f(8, 0);
        m_vertices.append(point);
        point = sf::Vertex();
        point.color = m_color;
        point.position.x = m_position.x + (m_size.x - 8.f);
        point.position.y = m_position.y;
        point.texCoords = sf::Vector2f(9, 0);
        m_vertices.append(point);
        point = sf::Vertex();
        point.color      = m_color;
        point.position.x = m_position.x + (m_size.x - 8.f);
        point.position.y = m_position.y + 8.f;
        point.texCoords = sf::Vector2f(9, 8);
        m_vertices.append(point);
        point = sf::Vertex();
        point.color      = m_color;
        point.position.x = m_position.x + 8.f;
        point.position.y = m_position.y + 8.f;
        point.texCoords = sf::Vector2f(8, 8);
        m_vertices.append(point);
        // Bottom border
        point = sf::Vertex();
        point.color = m_color;
        point.position.x = m_position.x + 8.f;
        point.position.y = m_position.y + (m_size.y - 8.f);
        point.texCoords = sf::Vector2f(8, 8);
        m_vertices.append(point);
        point = sf::Vertex();
        point.color = m_color;
        point.position.x = m_position.x + (m_size.x - 8.f);
        point.position.y = m_position.y + (m_size.y - 8.f);;
        point.texCoords = sf::Vector2f(9, 8);
        m_vertices.append(point);
        point = sf::Vertex();
        point.color      = m_color;
        point.position.x = m_position.x + (m_size.x - 8.f);
        point.position.y = m_position.y + m_size.y;
        point.texCoords = sf::Vector2f(9, 16);
        m_vertices.append(point);
        point = sf::Vertex();
        point.color      = m_color;
        point.position.x = m_position.x + 8.f;
        point.position.y = m_position.y + m_size.y;
        point.texCoords = sf::Vector2f(8, 16);
        m_vertices.append(point);
    }

    if (m_size.y > 16)
    {
        // Left border
        point = sf::Vertex();
        point.color = m_color;
        point.position.x = m_position.x;
        point.position.y = m_position.y + 8.f;
        point.texCoords = sf::Vector2f(0, 8);
        m_vertices.append(point);
        point = sf::Vertex();
        point.color = m_color;
        point.position.x = m_position.x + 8.f;
        point.position.y = m_position.y + 8.f;
        point.texCoords = sf::Vector2f(8, 8);
        m_vertices.append(point);
        point = sf::Vertex();
        point.color      = m_color;
        point.position.x = m_position.x + 8.f;
        point.position.y = m_position.y + (m_size.y - 8.f);
        point.texCoords = sf::Vector2f(8, 9);
        m_vertices.append(point);
        point = sf::Vertex();
        point.color      = m_color;
        point.position.x = m_position.x;
        point.position.y = m_position.y + (m_size.y - 8.f);
        point.texCoords = sf::Vector2f(0, 9);
        m_vertices.append(point);

        // Right border
        point = sf::Vertex();
        point.color = m_color;
        point.position.x = m_position.x + (m_size.x - 8.f);
        point.position.y = m_position.y + 8.f;
        point.texCoords = sf::Vector2f(8, 8);
        m_vertices.append(point);
        point = sf::Vertex();
        point.color = m_color;
        point.position.x = m_position.x + m_size.x;
        point.position.y = m_position.y + 8.f;
        point.texCoords = sf::Vector2f(16, 8);
        m_vertices.append(point);
        point = sf::Vertex();
        point.color      = m_color;
        point.position.x = m_position.x + m_size.x;
        point.position.y = m_position.y + (m_size.y - 8.f);
        point.texCoords = sf::Vector2f(16, 9);
        m_vertices.append(point);
        point = sf::Vertex();
        point.color      = m_color;
        point.position.x = m_position.x + (m_size.x - 8.f);
        point.position.y = m_position.y + (m_size.y - 8.f);
        point.texCoords = sf::Vector2f(8, 9);
        m_vertices.append(point);
    }
}
