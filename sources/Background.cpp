#include <Background.hpp>
#include<constants.hpp>

Background::Background(std::string textureFolder) : m_textureFolder(textureFolder)
{
    swapTexture();
}

void Background::render(sf::RenderTarget& target)
{
    target.draw(m_sprite);
}

void Background::swapTexture()
{
    m_mode = m_mode == "day" ? "night" : "day";

    std::string textureName = m_textureFolder + "/background-" + m_mode + ".png";

    std::cout << textureName << "\n";

    if (!m_texture.loadFromFile(textureName))
        std::cerr << "Erro loading background texture.\n";

    m_sprite.setTexture(m_texture);
    m_sprite.setScale(SPRT_SCALE);
}