#include <ScoreBoard.hpp>

ScoreBoard::ScoreBoard()
{
    p_digits.push_back(new ScoreDigit("assets/sprites/", 0));
}

void ScoreBoard::update()
{

}

void ScoreBoard::render(sf::RenderTarget& target)
{
    float adjustX = p_digits.size() * p_digits[0]->getRect().width / 2;

    for (int i = 0; i < p_digits.size(); i++) {
        if (!p_digits[i]) continue;

        // Center the sprite
        p_digits[i]->setPosition(sf::Vector2f((target.getSize().x / 2 + p_digits[i]->getRect().width * i) - adjustX, 100.f));

        p_digits[i]->render(target);
    }
}

void ScoreBoard::updateScore()
{
    m_score += 1;

    std::string scoreStr = std::to_string(m_score);

    for (int i = 0; i < scoreStr.size(); i++) {
        if (!p_digits[i]) {
            p_digits.push_back(new ScoreDigit("assets/sprites/", 0));
        }
        p_digits[i]->setValue((int) (scoreStr[i] - '0'));
    }
}

void ScoreBoard::clearScore()
{
    for (int i = 1; i < p_digits.size(); i++) {
        p_digits[i] = nullptr;
    }

    p_digits.clear();
    p_digits.push_back(new ScoreDigit("assets/sprites/", 0));
    m_score = 0;
}
