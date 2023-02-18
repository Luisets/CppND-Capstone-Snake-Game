# CPPND: Capstone Snake Game Example

This is a starter repo for the Capstone project in the [Udacity C++ Nanodegree Program](https://www.udacity.com/course/c-plus-plus-nanodegree--nd213). The code for this repo was inspired by [this](https://codereview.stackexchange.com/questions/212296/snake-game-in-c-with-sdl) excellent StackOverflow post and set of responses.

<img src="snake_game.gif"/>

The Capstone Project gives you a chance to integrate what you've learned throughout this program. This project will become an important part of your portfolio to share with current and future colleagues and employers.

In this project, you can build your own C++ application or extend this Snake game, following the principles you have learned throughout this Nanodegree Program. This project will demonstrate that you can independently create applications using a wide range of C++ features.

## Dependencies for Running Locally
* cmake >= 3.7
  * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1 (Linux, Mac), 3.81 (Windows)
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* SDL2 >= 2.0
  * All installation instructions can be found [here](https://wiki.libsdl.org/Installation)
  >Note that for Linux, an `apt` or `apt-get` installation is preferred to building from source. 
* gcc/g++ >= 5.4
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same deal as make - [install Xcode command line tools](https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)

## Basic Build Instructions

1. Clone this repo.
2. Make a build directory in the top level directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run it: `./SnakeGame`.

## New Features
1. At startup a menu is prompted with the available game options.
2. Game now have two difficulty levels. an easy level without obstacles and a normal mode that has an obstacle in the middle of the screen.
3. Game has a scoreboard to record the top 5 scores along with the player's nick. This scoreboard can be displayed with option 3 in the option menu. A new score is saved if it's greater than one of the scores in the scoreboard.
4. To make the game fair, at starting the game the snake is not moving until the player press an arrow and moves in that direction.

### File structure
* controller.h and controller.cpp: Contains the definition and implementation of class Controller.
This class is responsible of managing the user inputs in the game screen.
* drawableObject.h: Contains the definion of an abstract class that all drawable objects should inherit.
* enums.h: Contains all the enums used in the project
* game.h and game.cpp: Contains the definition and implementation of class Game. This class is in charge of managing the game behaivior. Update the game state, updating the screen.
* gamemenu.h and gamemenu.cpp: Contains the definition and implementation of class MenuGame. This class is the entry point of the program. It display the different options to use and let the user select one of them.
* obstacle.h and obstacle.cpp: Contains the definition and implementation of class Obstacle. This drawableclass encapsulate the information of obstacles in the game and how to draw them in the screen using a renderer object.
* renderer.h and renderer.cpp: Contains the definition and implementation of class Renderer. This  class manage the behaiviour of the game screen (clean, add new objects in the screen).
* scoreboard.h and scoreboard.cpp: Contains the definition and implementation of class ScoreBoard. This class manages the load, updating and display of the game best scores.
* snake.h and snake.cpp: Contains the definition and implementation of class Snake. It contains the snake head and body information. How the snake should move and check if the snake has chrashed.

## Rubric Points
* Loops, Functions, I/O
  1. *The project demonstrates an understanding of C++ functions and control structures:*  
  The project uses three different control strucures. std::array to store and sort the scores in the scoreboard, std::vector to store and loop through reference points of the objects in the screen, and std::pair to encapsulate the height and width of a block in the screen.   Also the code is organized into functions.
  2. *The project reads data from a file and process the data, or the program writes data to a file:*
  The project reads and writes a file to load and save the best scores. This can be found in Scoreboard class definition. loadScoreBoardFromFile (read file) and saveScoreboard (writte file).
3. *The project accepts user input and processes the input:*
  The project accept two different user inputs:
    * First. option inputs to select what the program will do (play game, show scores or exit). This can be found in GameMenu class definition. getUserSelection
    * Second. Nick of a user when a new score will be recorded in the scoreboard.
    This can be found in ScoreBoard class. getUserNickname
    * Third. Arrow inputs to change the direction of the snake.
    This can be found in Controller class definition. handleInput
* Object Oriented Programming
  1. *The project uses Object Oriented Programming techniques:* 
  The project is organized into different classes to hold data and permorm tasks.
  2. *Classes use appropriate access specifiers for class members:*
  All classes have their attributes and methods defined as public or private explicitly.
  3. *Class constructors utilize member initialization lists:*
  All classes constructures utilize memember initialization list if needed
  4. *Classes follow an appropriate inheritance hierarchy:*
  Abstract class DrawableObject is defined with vitual function draw(Renderer &renderer) and its inheritors implement this function with override explicitly
  5. *Derived class functions override virtual base class functions:*
  All classes that will be showing in game inherit from DrawableObject and define draw(Renderer &renderer)
* Memory Management
  1. *The project makes use of references in function declarations.*
  Methods that requires an object as a parameter are defined as reference.

## CC Attribution-ShareAlike 4.0 International


Shield: [![CC BY-SA 4.0][cc-by-sa-shield]][cc-by-sa]

This work is licensed under a
[Creative Commons Attribution-ShareAlike 4.0 International License][cc-by-sa].

[![CC BY-SA 4.0][cc-by-sa-image]][cc-by-sa]

[cc-by-sa]: http://creativecommons.org/licenses/by-sa/4.0/
[cc-by-sa-image]: https://licensebuttons.net/l/by-sa/4.0/88x31.png
[cc-by-sa-shield]: https://img.shields.io/badge/License-CC%20BY--SA%204.0-lightgrey.svg
