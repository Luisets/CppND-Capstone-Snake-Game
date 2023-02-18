#ifndef ENUNS_H
#define ENUNS_H
enum class Option : unsigned int
{
    Play = 1,
    ShowScores = 2,
    Exit = 3,
    TestScoreboard = 4
};

enum class SnakeDirection
{
    kUp,
    kDown,
    kLeft,
    kRight,
    kNone
};

#endif
