#include <ScoreDigit.hpp>
#include <constants.hpp>

ScoreDigit::ScoreDigit(std::string textureFolder, int value) 
    : m_value(value), m_textureFolder(textureFolder)
{
    setValue(m_value);
}

void ScoreDigit::setValue(int value)
{
    m_value = value;

    if (!m_texture.loadFromFile(m_textureFolder + std::to_string(m_value) + ".png"))
        std::cerr << "Error loading score digit texture.\n";

    m_sprite.setTexture(m_texture);
    m_sprite.setScale(SPRT_SCALE);
}

void ScoreDigit::setPosition(sf::Vector2f position)
{
    m_sprite.setPosition(position);
}

sf::Vector2f ScoreDigit::getPosition()
{
    return m_sprite.getPosition();
}

sf::FloatRect ScoreDigit::getRect()
{
    return m_sprite.getGlobalBounds();
}

void ScoreDigit::update()
{

}

void ScoreDigit::render(sf::RenderTarget& target)
{
    target.draw(m_sprite);
}
