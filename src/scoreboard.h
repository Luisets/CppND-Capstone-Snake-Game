#ifndef SCOREBOARD_H
#define SCOREBOARD_H

#include <array>
#include <string>

struct score_entry
{
    char nickname[11];
    unsigned long score;
};

class Scoreboard
{
public:
    Scoreboard(std::string filename);
    ~Scoreboard();
    void displayScoreboard();
    void updateScoreboard(unsigned long newScore);

private:
    static constexpr size_t MAX_SCORES = 5;
    static constexpr size_t MAX_NICK_SIZE = 10;
    std::array<score_entry, MAX_SCORES> _scores;
    size_t _scoresInScoreboard;
    std::string _filename;

    void loadScoreBoardFromFile();
    void saveScoreboard();
    void shiftRightScoreboard(size_t index, score_entry &&score);
    void getUserNickname(char *nickname);
};

#endif // SCOREBOARD_H
