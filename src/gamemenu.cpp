#include <iostream>

#include "game.h"
#include "gamemenu.h"
#include "renderer.h"

GameMenu::GameMenu(Game &game, Renderer &renderer)
    : _game(game)
    , _renderer(renderer)
{
}

void GameMenu::run()
{
    Option userSelection;
    do
    {
        displayMenu();
        userSelection = getUserSelection();
        switch (userSelection)
        {
        case Option::PlayEasyMode:
            launchGame(Difficulty::Easy);
            break;
        case Option::PlayHardMode:
            launchGame(Difficulty::Normal);
            break;
        case Option::ShowScores:
            _game.displayScores();
            break;
        case Option::Exit:
            break;
        default:
            break;
        }
    } while (userSelection != Option::Exit);
}

void GameMenu::displayMenu()
{
    std::cout << std::endl;
    std::cout << "\t---- Options menu ----" << std::endl;
    std::cout << "\t 1.- Play easy mode" << std::endl;
    std::cout << "\t 2.- Play normal mode" << std::endl;
    std::cout << "\t 3.- Scoreboar" << std::endl;
    std::cout << "\t 4.- Exit" << std::endl;
}

Option GameMenu::getUserSelection()
{
    int choice = 0;
    while (choice < 1 || choice > N_GAME_OPTIONS)
    {
        std::cout << "Enter your choice (1-" << N_GAME_OPTIONS << "): ";
        std::cin >> choice;
    }
    std::cin.clear();
    std::cout << std::endl;
    return static_cast<Option>(choice);
}

void GameMenu::launchGame(Difficulty difficulty)
{
    constexpr std::size_t kFramesPerSecond{60};
    constexpr std::size_t kMsPerFrame{1000 / kFramesPerSecond};
    _game.initialize();
    _game.setDifficulty(difficulty);
    _game.run(_renderer, kMsPerFrame);
    std::cout << "Game has terminated successfully!" << std::endl;
    std::cout << "Score: " << _game.getScore() << std::endl;
    std::cout << "Size: " << _game.getSize() << std::endl;
    _game.checkAndUpdateScores();
}
