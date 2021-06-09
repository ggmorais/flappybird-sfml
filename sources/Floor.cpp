#include <Floor.hpp>
#include <Player.hpp>
#include <constants.hpp>

Floor::Floor(std::string texturePath)
{
    if (!m_texture.loadFromFile(texturePath))
        std::cerr << "Error loading floor texture\n";

    for (int i = 0; i <= 3; i++) {
        sf::Sprite sprite;
        sprite.setTexture(m_texture);
        m_sprites.push_back(sprite);
    }
}

void Floor::update(sf::RenderTarget& target)
{
    for (int i = 0; i < m_sprites.size(); i++) {
        if (m_sprites[i].getPosition().y == 0) {
            m_sprites[i].setPosition(i * m_sprites[i].getGlobalBounds().width, target.getSize().y - m_sprites[0].getGlobalBounds().height);
        }

        m_sprites[i].move(m_speed, 0.f);

        if (m_sprites[i].getPosition().x + m_sprites[i].getGlobalBounds().width < 0) {
            m_sprites[i].setPosition(2 * m_sprites[i].getGlobalBounds().width, target.getSize().y - m_sprites[0].getGlobalBounds().height);
        }
    }
}

void Floor::render(sf::RenderTarget& target)
{
    for (auto sprite : m_sprites)
        target.draw(sprite);
}

bool Floor::checkPlayerCollision(Player& player)
{
    for (auto sprite : m_sprites) {
        if (sprite.getGlobalBounds().intersects(player.getRect())) {
            return true;
        }
    }

    return false;
}
