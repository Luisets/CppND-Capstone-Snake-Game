#ifndef GAMEMENU_H
#define GAMEMENU_H

#define N_GAME_OPTIONS 4

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

    void displayMenu();
    void launchGame(Difficulty difficulty);
    Option getUserSelection();
};

#endif
