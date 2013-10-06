#ifndef SSpRITE_HPP
#define SSpRITE_HPP

#include <unordered_map>
#include <vector>
#include <string>

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

    SSprite();
    SSprite(const std::string& name, Direction dir = North);

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
    int stateId(int index);

    void addPart(SSpritePart* part);
    SSpritePart* part(const std::string& name);

private:
    std::string  m_name;
    Direction    m_direction;

    std::vector<int> m_stateIds; //!< Stores the texture id's for each state.
    std::unordered_map<std::string, SSpritePart*> m_parts;
};

#endif // SSpRITE_HPP
