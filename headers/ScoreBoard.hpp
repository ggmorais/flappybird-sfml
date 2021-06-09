#include <pch.h>
#include <ScoreDigit.hpp>

#ifndef SCOREBOARD
#define SCOREBOARD

class ScoreBoard 
{
    private:
        // ScoreDigit* p_digits[3];
        std::vector<ScoreDigit*> p_digits;

        int m_score = 0;
        int m_maxDigits = 3;

    public:
        ScoreBoard();

        void update();
        void render(sf::RenderTarget& target);
        void updateScore();
        void clearScore();
};

#endif
