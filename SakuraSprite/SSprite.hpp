#ifndef SSpRITE_HPP
#define SSpRITE_HPP

#include <unordered_map>
#include <vector>
#include <string>
#include <Types.hpp>
#include <SFML/Graphics.hpp>

class SSpriteFile;
class SSpritePart;

class SSprite
{
public:
    enum Direction
    {
        North,
        South,
        East,
        West
    };

    SSprite(SSpriteFile* root);
    SSprite(SSpriteFile* root, const std::string& name, Direction dir = North);
    virtual ~SSprite();

    virtual void setPosition(const float x, const float y);
    virtual void setPosition(const sf::Vector2f& pos);
    sf::Vector2f position() const;
    void setName(const std::string& name);
    std::string name() const;

    void setDirection(const Direction dir);
    Direction direction() const;

    void addStateId(int id);

    /*!
     * \brief Returns the texture id of a given state
     * \param index The index of the id.
     * \return return the state id if it exists, -1 otherwise
     */
    int stateId(int index) const;
    void setStateIds(std::vector<int> ids);
    Uint32 stateCount() const;

    void addPart(SSpritePart* part);
    SSpritePart* part(const std::string& name);
    void setParts(std::vector<SSpritePart*> parts);
    Uint32 partCount() const;

    std::vector<SSpritePart*> parts() const;

    virtual void update(const sf::Time& dt);
    virtual void draw(sf::RenderTarget& rt);

    sf::Texture& sfTexture() const;
private:
    SSpriteFile* m_root;
    std::string  m_name;
    sf::Time     m_currentTime;
    Direction    m_direction;
    sf::Vector2f m_position;

    std::vector<int> m_stateIds; //!< Stores the texture id's for each state.
    std::vector<SSpritePart*> m_parts;
    Uint32 m_currentState;
};

#endif // SSpRITE_HPP
