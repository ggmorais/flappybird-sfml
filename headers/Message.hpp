#include <pch.h>

#ifndef MESSAGE
#define MESSAGE

class Message
{
    private:
        sf::Texture m_texture;
        sf::Sprite m_sprite;

    public:
        Message(std::string texturePath);

        void render(sf::RenderTarget& target);
};

#endif