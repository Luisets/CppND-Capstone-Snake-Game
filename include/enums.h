#ifndef ENUNS_H
#define ENUNS_H
enum class Option : unsigned int
{
    PlayEasyMode = 1,
    PlayHardMode = 2,
    ShowScores = 3,
    Exit = 4,
};

enum class Difficulty : int
{
    Easy = 1,
    Normal = 3
};

enum class SnakeDirection
{
    kUp,
    kDown,
    kLeft,
    kRight,
    kNone
};

enum class BrushColor
{
    SnakeHeadAlive,
    SnakeHeadDead,
    SnakeBody,
    Food,
    BackGround,
    Obstacle
};

#endif
