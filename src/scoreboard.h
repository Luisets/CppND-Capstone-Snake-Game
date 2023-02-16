#ifndef SCOREBOARD_H
#define SCOREBOARD_H

#include <string>
#include <array>

struct score_entry
{
    char nickname[10];
    unsigned long score;
};

class Scoreboard
{
public:
    Scoreboard(std::string filename);
    ~Scoreboard();
    void displayScoreboard();
    void updateScoreboard(score_entry newScore);
private:
    static constexpr size_t MAX_SCORES = 5;
    std::array<score_entry, MAX_SCORES> _scores;
    size_t _scoresInScoreboard;
    std::string _filename;

    void loadScoreBoardFromFile();
    void saveScoreboard();
    void shiftRightScoreboard(size_t index, score_entry &&score);

};

#endif // SCOREBOARD_H
