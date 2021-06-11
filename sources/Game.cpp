#include <Game.hpp>

Game::Game()
{
    m_videoMode = sf::VideoMode(480, 800);
    p_window = new sf::RenderWindow(m_videoMode, "Flappy Bird");
    p_window->setFramerateLimit(60);

    p_background = new Background("./assets/sprites");
    p_player = new Player("./assets/sprites/bluebird-midflap.png");
    p_floor = new Floor("./assets/sprites/base.png");
    p_message = new Message("./assets/sprites/message.png");
    p_scoreBoard = new ScoreBoard();

    spawnPipes();
    updateObjects();
}

Game::~Game()
{
    p_window->close();
}

bool Game::isRunning()
{
    return p_window->isOpen();
}

void Game::spawnPipes()
{
    float fixedDistance = p_window->getSize().x + 200.f;
    
    if (p_pipes.size() > 0) {
        for (int i = 0; i < m_pipeQuantity; i++) {
            p_pipes[i] = nullptr;
        }
        p_pipes.clear();
    }

    for (int i = 0; i < m_pipeQuantity; i++) {
        Pipes *pipes = new Pipes("./assets/sprites/pipe-red.png");
        pipes->setX(fixedDistance + i * 300);
        p_pipes.push_back(pipes);
    }
}

void Game::checkCollisions()
{
    bool collided = false;

    for (auto pipes : p_pipes) {
        if (pipes->checkPlayerCollision(*p_player)) {
            collided = true;
        }
    }

    if (p_floor->checkPlayerCollision(*p_player)) {
        collided = true;
    }

    if (collided) {
        m_paused = true;
        p_player->m_dead = true;
        m_lastScorePipeIdx = 10;
        p_scoreBoard->clearScore();
        spawnPipes();
    }
}

void Game::checkPlayerSuccess()
{
    for (int i = 0; i < p_pipes.size(); i++) {
        if (i == m_lastScorePipeIdx || !p_pipes[i]) continue;
        if (p_pipes[i]->checkPlayerSuccess(*p_player)) {
            p_scoreBoard->updateScore();
            m_lastScorePipeIdx = i;
        }
    }
}

void Game::updateObjects()
{
    p_player->update(*p_window, m_mouseLeftPressed);

    for (auto pipes : p_pipes) {
        pipes->update(*p_window);
    }
}

void Game::update()
{
    pollEvents();

    if (m_paused && m_mouseLeftPressed) {
        m_paused = false;
    }

    p_floor->update(*p_window);

    if (!m_paused) {
        updateObjects();
        checkPlayerSuccess();
    }

    checkCollisions();

    m_mouseLeftPressed = false;
}

void Game::render()
{   
    p_window->clear();

    p_background->render(*p_window);

    if (!m_paused) {
        p_player->render(*p_window);
        
        for (auto pipes : p_pipes) {
            pipes->render(*p_window);
        }

        p_scoreBoard->render(*p_window);
    } else {
        p_message->render(*p_window);
    }

    p_floor->render(*p_window);

    p_window->display();
}

void Game::pollEvents()
{
    while (p_window->pollEvent(m_event)) {
        if (m_event.type == sf::Event::Closed) p_window->close();

        if (m_event.type == sf::Event::MouseButtonPressed && m_event.mouseButton.button == sf::Mouse::Left)
            m_mouseLeftPressed = true; 
    }
}
