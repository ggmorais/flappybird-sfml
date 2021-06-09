#include <pch.h>
#include <Player.hpp>

#ifndef PIPES
#define PIPES

class Pipes
{
    private:
        sf::Texture m_texture;
        sf::Sprite m_sprite_top;
        sf::Sprite m_sprite_bottom;

        float m_speed = -4.f;

    public:
        Pipes(std::string texturePath);

        void update(sf::RenderTarget& target);
        void render(sf::RenderTarget& target);
        void setX(float x);
        float getWidth();
        bool checkPlayerCollision(Player& player);
        bool checkPlayerSuccess(Player& player);
};

#endif