#ifndef GAMEMENU_H
#define GAMEMENU_H

enum class Option : unsigned int
{
    Play = 1,
    ShowScores = 2,
    Exit = 3,
    TestScoreboard = 4
};

class Game;
class Renderer;

class GameMenu
{
public:
    GameMenu(Game &game, Renderer &renderer);
    void run();
private:
    Game &_game;
    Renderer &_renderer;
    const int N_OPTIONS = 4;

    void displayMenu();
    void launchGame();
    Option getUserSelection();
};

#endif
