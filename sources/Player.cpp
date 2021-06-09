#include <Player.hpp>
#include <constants.hpp>

Player::Player(std::string texturePath)
{
    if (!m_texture.loadFromFile(texturePath)) {
        std::cerr << "Error loading players texture.\n";
    }

    m_sprite.setTexture(m_texture);
    m_sprite.setScale(SPRT_SCALE);
}

void Player::update(sf::RenderTarget& target, bool mousePressed)
{
    if (m_sprite.getPosition().x == 0 || m_dead) {
        m_sprite.setPosition(
            target.getSize().x / 2 - m_sprite.getGlobalBounds().width / 2, 
            target.getSize().y / 2 - m_sprite.getGlobalBounds().height / 2
        );
    }

    if (mousePressed) m_speedY = m_jumpHeight;
    if (m_speedY < m_speedYMax) m_speedY += 1.f;

    m_sprite.move(0.f, m_speedY);

    if (m_sprite.getPosition().y < 0) {
        m_sprite.move(0.f, -m_speedY);
    }

    if (m_dead) m_dead = false;
}

void Player::render(sf::RenderTarget& target)
{
    target.draw(m_sprite);
}

sf::FloatRect Player::getRect()
{
    return m_sprite.getGlobalBounds();
}

sf::Vector2f Player::getPosition()
{
    return m_sprite.getPosition();
}
