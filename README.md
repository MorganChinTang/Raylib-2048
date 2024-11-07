# 2048 Game in C++ with Raylib

## Overview

This is a 2048 game built using C++ and the [Raylib](https://www.raylib.com/) graphics library. It features a simple and addictive gameplay where players combine numbered tiles to reach the elusive 2048 tile. The game board is a 4x4 grid, and the gameplay consists of sliding and merging tiles based on user input (up, down, left, right). Every time the tiles combine, a new random tile appears, adding to the challenge.

## Demo
![2048Demo](https://github.com/user-attachments/assets/9916d9e8-01cd-4408-ab52-bf1110b182e1)

## Game Flow

### Setup

1. A 4x4 grid is created.
2. The game begins, and 2 tiles spawn at random positions on the grid.

### Game Loop

1. The player presses an arrow key (up, down, left, or right).
2. All tiles in the direction of the press will move and stack to the side.
3. If two tiles of the same number are adjacent, they combine into a single tile of the next number (e.g., 2 + 2 = 4).
   - Example: `2 2 2` becomes `0 2 4`
4. After a move, a new tile spawns in a random empty position.
5. The game continues until no moves are possible, or the player achieves the 2048 tile!

### Winning Condition

The game ends when the player successfully creates the 2048 tile, or when no more valid moves are possible.

## How to Play

1. Use the arrow keys (Up, Down, Left, Right) to move tiles in the corresponding direction.
2. Tiles with the same number combine when they collide, doubling their value.
3. A new tile will appear in a random empty space after each move.
4. Keep combining tiles and try to reach the 2048 tile.

## Installation

1. Clone or download this repository.
2. Install [Raylib](https://www.raylib.com/), if you haven't already. Follow the installation instructions for your operating system.
3. Compile and run the game using a C++ compiler:
   - For example, on Linux/Mac:
     ```bash
     g++ -o 2048_game main.cpp -lraylib -lm -lpthread -ldl -lrt -lX11
     ./2048_game
     ```
   - On Windows, use the appropriate command for your IDE or compiler setup.

## Credits

- **Game Design & Development**: [Morgan Tang]
- **Graphics**: Raylib library (https://www.raylib.com/)
- **Game Concept**: Inspired by the popular 2048 game.
  
**Tutorials & Resources**:
- [Coding Train's 2048 Challenge](https://thecodingtrain.com/challenges/94-2048) – This tutorial helped in understanding the logic behind the game and implementing the core mechanics.
- [YouTube Video: 2048 Game Implementation](https://youtu.be/p4vk4-xiI8s?si=viWnrmSLEzBJEgvC) – This video was instrumental in the design and implementation of this C++ version of the game.

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

## Contact

If you have any questions, suggestions, or issues, feel free to contact me via [email/other contact method]. 
This project is an assignment for school! We're learning everyday!

Happy gaming! 🎮
