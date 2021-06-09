#include <pch.h>

#ifndef SCOREDIGIT
#define SCOREDIGIT

class ScoreDigit
{
    private:
        sf::Texture m_texture;
        sf::Sprite m_sprite;

        int m_value;
        std::string m_textureFolder;

    public:
        ScoreDigit(std::string textureFolder, int value);
        
        void update();
        void render(sf::RenderTarget& target);
        void setValue(int value);
        void setPosition(sf::Vector2f position);
        sf::FloatRect getRect();
        sf::Vector2f getPosition();
};

#endif