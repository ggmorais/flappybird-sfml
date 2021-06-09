#include <pch.h>
#include <Player.hpp>
#include <Floor.hpp>
#include <Pipes.hpp>
#include <Message.hpp>
#include <ScoreBoard.hpp>

#ifndef GAME
#define GAME

class Game
{
    private:
        sf::Event m_event;
        sf::VideoMode m_videoMode;
        sf::RenderWindow* p_window;

        Player* p_player;
        Floor* p_floor;
        Message* p_message;
        ScoreBoard* p_scoreBoard; 

        std::vector<Pipes*> p_pipes;

        int m_pipeQuantity = 2;
        bool m_mouseLeftPressed = false;
        bool m_paused = true;
        int m_lastScorePipeIdx = 10;

    public:
        Game();
        ~Game();

        void render();
        void update();
        void pollEvents();
        bool isRunning();
        void spawnPipes();
        void updateObjects();
        void checkCollisions();
};

#endif