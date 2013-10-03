#ifndef SSPRITEFILE_HPP
#define SSPRITEFILE_HPP

#include <list>
#include <string>

struct STexture
{
    std::string Filepath;
    bool        Preload;
};

class SSpriteFile
{
public:
    /*!
     * \brief SSprite
     */
    SSpriteFile();

    /*!
     * \brief SSpriteFile
     * \param width
     * \param height
     * \param originX
     * \param originY
     */
    SSpriteFile(int width, int height, float originX, float originY);

    /*!
     * \brief setWidth
     * \param width
     */
    void setWidth(int width);
    /*!
     * \brief width
     * \return
     */
    int width() const;

    /*!
     * \brief setHeight
     * \param height
     */
    void setHeight(int height);

    /*!
     * \brief height
     * \return
     */
    int height() const;

    /*!
     * \brief setOriginX
     * \param originX
     */
    void setOriginX(float originX);

    /*!
     * \brief originX
     * \return
     */
    float originX() const;

    /*!
     * \brief setOriginY
     * \param originY
     */
    void setOriginY(float originY);

    /*!
     * \brief originY
     * \return
     */
    float originY() const;
    
    
private:
    std::list<STexture*> m_textures;
    int                  m_width;
    int                  m_height;
    float                m_originX;
    float                m_originY;

};

#endif // SSPRITE_HPP
