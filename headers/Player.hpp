#include <pch.h>

#ifndef PLAYER
#define PLAYER

class Player
{
    private:
        sf::Texture m_texture;
        sf::Sprite m_sprite;

        float m_jumpHeight = -16.f;
        float m_speedYMax = 10.f;
        float m_speedY = 0.f;

    public:
        Player(std::string texturePath);

        bool m_dead = false;
        void kill();

        void update(sf::RenderTarget& target, bool mousePressed);
        void render(sf::RenderTarget& target);

        sf::Vector2f getPosition();
        sf::FloatRect getRect();
};

#endif