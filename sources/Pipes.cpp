#include <Pipes.hpp>
#include <Player.hpp>
#include <constants.hpp>

Pipes::Pipes(std::string texturePath)
{
    if (!m_texture.loadFromFile(texturePath))
        std::cerr << "Error loading pipes texture\n";

    m_sprite_top.setTexture(m_texture);
    m_sprite_bottom.setTexture(m_texture);

    m_sprite_top.setScale(2.f, -2.f);
    m_sprite_bottom.setScale(SPRT_SCALE);
}

float Pipes::getWidth()
{
    return m_sprite_top.getGlobalBounds().width;
}

void Pipes::setX(float x)
{
    m_sprite_top.setPosition(x, m_sprite_top.getPosition().y);
    m_sprite_bottom.setPosition(x, m_sprite_bottom.getPosition().y);
}

void Pipes::update(sf::RenderTarget& target)
{
    if (m_sprite_bottom.getPosition().y == 0) {
        m_sprite_top.setPosition(m_sprite_top.getPosition().x, m_sprite_top.getGlobalBounds().height - 400.f);
        m_sprite_bottom.setPosition(m_sprite_bottom.getPosition().x, target.getSize().y - m_sprite_bottom.getGlobalBounds().height + 400.f);
    }

    m_sprite_top.move(m_speed, 0.f);
    m_sprite_bottom.move(m_speed, 0.f);

    if (m_sprite_top.getPosition().x + m_sprite_top.getGlobalBounds().width < 0) {
        float newPosX = target.getSize().x + m_sprite_top.getGlobalBounds().width;

        float randomY = rand() % 150 + 1;

        m_sprite_top.setPosition(newPosX, m_sprite_top.getGlobalBounds().height - 550.f + randomY);
        m_sprite_bottom.setPosition(newPosX, target.getSize().y - m_sprite_bottom.getGlobalBounds().height + 150.f + randomY);
    }
}

void Pipes::render(sf::RenderTarget& target)
{
    target.draw(this->m_sprite_top);
    target.draw(this->m_sprite_bottom);
}

bool Pipes::checkPlayerSuccess(Player& player)
{
    if (player.getPosition().x > m_sprite_bottom.getPosition().x && 
        // player.getPosition().y > m_sprite_bottom.getPosition().y &&
        // player.getPosition().x + player.getRect().width > m_sprite_bottom.getPosition().x &&
        player.getPosition().x + player.getRect().width < m_sprite_bottom.getPosition().x + m_sprite_bottom.getGlobalBounds().width) {
            return true;
    }

    return false;
}

bool Pipes::checkPlayerCollision(Player& player)
{
    if (m_sprite_top.getGlobalBounds().intersects(player.getRect())) {
        return true;
    }

    if (m_sprite_bottom.getGlobalBounds().intersects(player.getRect())) {
        return true;
    }

    return false;
}
