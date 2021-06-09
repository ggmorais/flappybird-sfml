#include <pch.h>
#include <Player.hpp>

#ifndef FLOOR
#define FLOOR

class Floor
{
    private:
        sf::Texture m_texture;
        std::vector<sf::Sprite> m_sprites;

        float m_speed = -4.f;
    
    public:
        Floor(std::string texturePath);

        void update(sf::RenderTarget& target);
        void render(sf::RenderTarget& target);

        bool checkPlayerCollision(Player& player);
};

#endif