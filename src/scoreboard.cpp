#include "scoreboard.h"
#include <fstream>
#include <iostream>


Scoreboard::Scoreboard(std::string filename)
    : _filename(filename)
    , _scoresInScoreboard(0)
{
    std::fstream fileStream;
    fileStream.open(_filename, std::ios_base::in);
    if (!fileStream.is_open())
    {
        fileStream.open(_filename, std::ios_base::out);
    }
    fileStream.close();
}

Scoreboard::~Scoreboard()
{
}

void Scoreboard::displayScoreboard()
{
    loadScoreBoardFromFile();
    if (_scoresInScoreboard == 0)
    {
        std::cout << "There are not scores to display" << std::endl << std::endl;
        return;
    }
    for(size_t index = 0; index < _scoresInScoreboard; ++index)
    {
        std::cout << index + 1 << ". " << _scores[index].nickname << ": " << _scores[index].score << std::endl;
    }
    std::cout << std::endl;
}

void Scoreboard::updateScoreboard(score_entry newScore)
{
    loadScoreBoardFromFile();
    size_t index;
    for (index = 0; (index < _scoresInScoreboard); ++index)
    {
        if(newScore.score > _scores[index].score)
        {
            break;
        }
    }
    if ((index < MAX_SCORES)
        && (index < _scoresInScoreboard))
    {
        shiftRightScoreboard(index, std::move(newScore));
        _scoresInScoreboard = std::min(_scoresInScoreboard + 1, MAX_SCORES);
        saveScoreboard();
    }
    else if (index < MAX_SCORES)
    {
        _scores[index] = std::move(newScore);
        _scoresInScoreboard = std::min(_scoresInScoreboard + 1, MAX_SCORES);
        saveScoreboard();
    }
}

void Scoreboard::loadScoreBoardFromFile()
{
    std::fstream fileStream;
    score_entry entry;
    std::string line;
    _scoresInScoreboard = 0;
    fileStream.open(_filename, std::ios_base::in);
    if (!fileStream.is_open())
    {
        std::cout << "\tThere was a problem reading the scoreboard!!" << std::endl;
        std::cout << "\tTry again later!!" << std::endl;
        return;
    }
    int count = 0;
    while (fileStream.read(reinterpret_cast<char *>(&entry), sizeof(entry)))
    {
        _scores[count] = std::move(entry);
        ++count;
    }
    _scoresInScoreboard = count;
}

/**
 * Save the current scoreboard in _filename.
*/
void Scoreboard::saveScoreboard()
{
    std::fstream fileStream;
    fileStream.open(_filename, std::ios_base::out | std::ios_base::trunc);

    for(size_t i = 0; i < _scoresInScoreboard; i++)
    {
        fileStream.write(reinterpret_cast<char *>(&_scores[i]), sizeof(score_entry));
    }
    fileStream.close();
}

/*
 *  Shift the array values to the starting at position index and move the value from score to that position in the array.
 *  if the array is full, the last element will be deleted.
 *  i.e. our array is {['Luis', 50], ['Maria', 30], ['Jose', 20], ['Jose', 15], ['Sara', 10]}. index = 1 and score = ['Carlos', 40]
 *  result  {['Luis', 50], ['Carlos', 40], ['Maria', 30], ['Jose', 20], ['Jose', 15]}
*/
void Scoreboard::shiftRightScoreboard(size_t index, score_entry &&score)
{
    size_t i = std::min(_scoresInScoreboard, MAX_SCORES - 1);
    for(i; (i > index); --i)
    {
        _scores[i] = std::move(_scores[i - 1]);
    }
    _scores[i] = score;
}