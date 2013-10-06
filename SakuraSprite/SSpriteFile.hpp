#ifndef SSpRITEFILE_HPP
#define SSpRITEFILE_HPP

#include <vector>
#include <unordered_map>
#include <string>
#include <SFML/System/Vector2.hpp>
#include <Types.hpp>
struct STexture
{
    std::string Filepath;
    bool        Preload;
};

class SSprite;
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
    SSpriteFile(Uint32 width, Uint32 height, float originX, float originY);

    /*!
     * \brief SSpriteFile
     * \param size
     * \param origin
     */
    SSpriteFile(const sf::Vector2u& size, const sf::Vector2f origin);

    /*!
     * \brief setSize
     * \param width
     * \param height
     */
    void setSize(Uint32 width, Uint32 height);

    /*!
     * \brief setSize
     * \param size
     */
    void setSize(const sf::Vector2u& size);

    /*!
     * \brief size
     * \return
     */
    sf::Vector2u size() const;

    /*!
     * \brief width
     * \return
     */
    Uint32 width() const;

    /*!
     * \brief height
     * \return
     */
    Uint32 height() const;

    /*!
     * \brief setOrigin
     * \param x
     * \param y
     */
    void setOrigin(const float x, const float y);

    /*!
     * \brief setOrigin
     * \param origin
     */
    void setOrigin(const sf::Vector2f& origin);

    /*!
     * \brief origin
     * \return
     */
    sf::Vector2f origin() const;

    /*!
     * \brief originX
     * \return
     */
    float originX() const;

    /*!
     * \brief originY
     * \return
     */
    float originY() const;

    /*!
     * \brief addTexture
     * \param texture
     */
    void addTexture(STexture* texture);

    /*!
     * \brief removeTexture
     * \param id
     */
    void removeTexture(int id);

    /*!
     * \brief texture
     * \param id
     * \return
     */
    STexture* texture(Uint32 id);

    void addSprite(SSprite* sprite);
private:
    std::vector<STexture*> m_textures;
    sf::Vector2u         m_size;
    sf::Vector2f         m_origin;
    std::unordered_map<std::string, SSprite*> m_sprites;
};

#endif // SSpRITE_HPP
