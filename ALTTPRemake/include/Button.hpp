#ifndef BUTTON_HPP
#define BUTTON_HPP

#include <Sakura/Gui/Widget.hpp>
class Button : public Sakura::Gui::Widget
{
public:
    Button(Sakura::Gui::Container* owner, const std::string& name, bool visible = true, bool enabled = true);

    void setPosition(const float x, const float y);
    void setPosition(const sf::Vector2f &position);
    void update(sf::Time dt);
    void draw(sf::RenderTarget &rt);

private:
    void setSize(const float w, const float h);
    void setSize(const sf::Vector2f& size);
    void updateButton();
    void corners();
    void borders();
    sf::VertexArray m_vertices;
    sf::Texture     m_texture;
    sf::Text        m_text;
};

#endif // BUTTON_HPP
