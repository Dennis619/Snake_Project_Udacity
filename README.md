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

## Functionalities added to the Projcet.
The following modifications where made on the stater code:
1. The following were added to the project: 
    a. Main Menu- is responsible for managing user inputs and changing game setting.
    b. Player - manages the player information by allowing them to enter their name and store their high score
    c. Food - that is an interface of Normal Food class(growth of snake size + 1), Double Growth Food(growth of snake size + 2), Triple Growth Food(growth of snake size + 3) and Poison(kills the snake)
    d. Game difficulty - that manages the start speed of the snake.

## Addressed Rubic Points
### Loops, Functions, I/O
|Criteria Header                                                                                    |Done Header|
|---------------------------------------------------------------------------------------------------|-----------|
|The project demonstrates an understanding of C++ functions and control structures.                 | Yes       |
|The project reads data from a file and process the data, or the program writes data to a file.     | Yes       |

### Object Oriented Programming
|Criteria Header                                                                                    |Done Header|
|---------------------------------------------------------------------------------------------------|-----------|
|One or more classes are added to the project with appropriate access specifiers for class members. | Yes       |
|Class constructors utilize member initialization lists.                                            | Yes       |
|Classes follow an appropriate inheritance hierarchy with virtual and override functions.           | Yes       |

### Memory Management
|Criteria Header                                                                                    |Done Header|
|---------------------------------------------------------------------------------------------------|-----------|
|The project makes use of references in function declarations.                                      | Yes       |
|The project follows the Rule of 5.                                                                 | Yes       |
|The project uses smart pointers instead of raw pointers.                                           | Yes       |

### Concurrency
|Criteria Header                                                                                    |Done Header|
|---------------------------------------------------------------------------------------------------|-----------|
|The project uses multithreading.                                                                   | Yes       |
|A mutex or lock is used in the proj                                                                | Yes       |



## CC Attribution-ShareAlike 4.0 International


Shield: [![CC BY-SA 4.0][cc-by-sa-shield]][cc-by-sa]

This work is licensed under a
[Creative Commons Attribution-ShareAlike 4.0 International License][cc-by-sa].

[![CC BY-SA 4.0][cc-by-sa-image]][cc-by-sa]

[cc-by-sa]: http://creativecommons.org/licenses/by-sa/4.0/
[cc-by-sa-image]: https://licensebuttons.net/l/by-sa/4.0/88x31.png
[cc-by-sa-shield]: https://img.shields.io/badge/License-CC%20BY--SA%204.0-lightgrey.svg
