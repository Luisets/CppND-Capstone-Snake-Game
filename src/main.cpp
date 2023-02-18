#include "controller.h"
#include "game.h"
#include "gamemenu.h"
#include "renderer.h"
#include "scoreboard.h"
#include <cstring>
#include <iostream>

// #define SCOREBOARD_PATH "./scoreboard"

int main()
{
  constexpr std::size_t kScreenWidth{640};
  constexpr std::size_t kScreenHeight{640};
  constexpr std::size_t kGridWidth{32};
  constexpr std::size_t kGridHeight{32};

  Renderer renderer(kScreenWidth, kScreenHeight, kGridWidth, kGridHeight);
  Game game(kGridWidth, kGridHeight);
  GameMenu gameMenu(game, renderer);
  gameMenu.run();
  return 0;
}
