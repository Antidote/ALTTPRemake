#ifndef SSpRITEPART_HPP
#define SSpRITEPART_HPP

#include <Types.hpp>
#include <vector>
#include <string>

class SSpriteFrame;

class SSpritePart
{
public:
    SSpritePart();
    SSpritePart(const std::string& name, bool hasCollision = false);

    void setName(const std::string& name);
    std::string name() const;

    void setCollision(bool col);
    bool hasCollision() const;

    void addFrame(SSpriteFrame* frame);
    SSpriteFrame* frame(int id);
private:
    std::string m_name;
    bool        m_hasCollision;

    // The collection of frames for this part
    std::vector<SSpriteFrame*> m_frames;
};

#endif // SSpRITEPART_HPP
