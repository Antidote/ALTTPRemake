////////////////////////////////////////////////////////////
//
// This software is provided 'as-is', without any express or implied warranty.
// In no event will the authors be held liable for any damages arising from the use of this software.
//
// Permission is granted to anyone to use this software for any purpose,
// including commercial applications, and to alter it and redistribute it freely,
// subject to the following restrictions:
//
// 1. The origin of this software must not be misrepresented;
// you must not claim that you wrote the original software.
// If you use this software in a product, an acknowledgment
// in the product documentation would be appreciated but is not required.
//
// 2. Altered source versions must be plainly marked as such,
// and must not be misrepresented as being the original software.
//
// 3. This notice may not be removed or altered from any source distribution.
//
////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include "RoundedRectangleShape.hpp"
#include <cmath>

////////////////////////////////////////////////////////////
RoundedRectangleShape::RoundedRectangleShape(const sf::Vector2f& size, float radius, unsigned int cornerPointCount)
{
    m_size = size;
    m_radius = radius;
    m_cornerPointCount = cornerPointCount;
    update();
}

////////////////////////////////////////////////////////////
void RoundedRectangleShape::setSize(const sf::Vector2f& size)
{
    m_size = size;
    update();
}

////////////////////////////////////////////////////////////
const sf::Vector2f& RoundedRectangleShape::getSize() const
{
    return m_size;
}

////////////////////////////////////////////////////////////
void RoundedRectangleShape::setCornersRadius(float radius)
{
    m_radius = radius;
    update();
}

////////////////////////////////////////////////////////////
float RoundedRectangleShape::getCornersRadius() const
{
    return m_radius;
}

////////////////////////////////////////////////////////////
void RoundedRectangleShape::setCornerPointCount(unsigned int count)
{
    m_cornerPointCount = count;
    update();
}

////////////////////////////////////////////////////////////
unsigned int RoundedRectangleShape::getPointCount() const
{
    return m_cornerPointCount*4;
}

////////////////////////////////////////////////////////////
sf::Vector2f RoundedRectangleShape::getPoint(unsigned int index) const
{
    if(index >= m_cornerPointCount*4)
        return sf::Vector2f(0,0);

    float deltaAngle = 90.0f/(m_cornerPointCount-1);
    sf::Vector2f center;
    unsigned int centerIndex = index/m_cornerPointCount;
    unsigned int offset = 0;
    static const float pi = 3.141592654f;

    switch(centerIndex)
    {
        case 0: center.x = m_size.x - m_radius; center.y = m_size.y - m_radius; break;
        case 1: center.x = m_radius; center.y = m_size.y - m_radius; break;
        case 2: center.x = m_radius; center.y = m_radius; break;
        case 3: center.x = m_size.x - m_radius; center.y = m_radius; break;
    }

    return sf::Vector2f(m_radius*cos(deltaAngle*(index-centerIndex)*pi/180)+center.x,
                        m_radius*sin(deltaAngle*(index-centerIndex)*pi/180)+center.y);
}
