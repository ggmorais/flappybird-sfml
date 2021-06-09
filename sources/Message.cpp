#include <Message.hpp>
#include <constants.hpp>

Message::Message(std::string texturePath)
{
    if (!m_texture.loadFromFile(texturePath))
        std::cerr << "Error loading message texture.\n";

    m_sprite.setTexture(m_texture);
    m_sprite.setScale(SPRT_SCALE);
}

void Message::render(sf::RenderTarget& target)
{
    if (m_sprite.getPosition().x == 0) {
        m_sprite.setPosition(
            target.getSize().x / 2 - m_sprite.getGlobalBounds().width / 2,
            target.getSize().y / 2 - m_sprite.getGlobalBounds().height / 2
        );
    }

    target.draw(m_sprite);
}
