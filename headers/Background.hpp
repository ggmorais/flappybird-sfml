#include <pch.h>

#ifndef BACKGROUND
#define BACKGROUND

class Background
{
    private:
        sf::Texture m_texture;
        sf::Sprite m_sprite;

        std::string m_textureFolder;

    public:
        Background(std::string textureFolder);
        
        std::string m_mode = "night";

        void render(sf::RenderTarget& target);
        void swapTexture();
};

#endif