# 🎮 DARK-CELL-ESCAPE
### A C-Based Survival Maze Game

> **Not every first project needs to be a calculator. Sometimes, it should be a maze you might not escape.**

The Blind Labyrinth is a terminal-based survival game developed in C, where the player must navigate through an unknown 10×10 maze, avoid randomly placed walls and enemies, manage limited health and energy, and reach the exit before running out of resources.

The catch? You cannot see the entire maze.

Your vision is limited to a small area around your current position, forcing you to explore carefully, remember what you discover, and make decisions without knowing what lies ahead.

## 🧩 The Idea Behind the Project

A first-year programming assignment does not have to end with a calculator, a number-guessing game, or another implementation of Rock-Paper-Scissors.

Those projects are useful for learning the basics, but assignments can also be treated as opportunities to challenge yourself, explore logic, and build something more interesting.

**The Blind Labyrinth was built with that mindset:** take the concepts taught in C programming and combine them into a playable game that requires planning, problem-solving, and resource management.

Because learning programming should not just be about making a program work. It should also be about discovering what you can build with it.

## 🎯 Objective

- Start at the top-left corner of the maze.
- Explore the hidden 10×10 grid using a limited field of vision.
- Avoid walls and enemies while conserving energy and health.
- Find a safe route to the exit at the bottom-right corner.
- Reach the exit before your resources run out.

## 🕹️ How to Play

| Key | Action |
|---|---|
| `W` | Move up |
| `A` | Move left |
| `S` | Move down |
| `D` | Move right |

The game accepts uppercase and lowercase movement keys.

### Map Symbols

| Symbol | Meaning |
|---|---|
| `P` | Your current position |
| `S` | Starting position |
| `X` | Exit |
| `#` | Wall |
| `E` | Enemy |
| `.` | Empty path |
| `?` | Unexplored area |

## ❤️ Survival Rules

- **Health:** You start with 3 health points.
- **Energy:** You start with 25 energy points.
- **Walls:** Attempting to move into a wall consumes energy.
- **Enemies:** Attempting to move into an enemy costs both health and energy.
- **Boundaries:** Attempting to move outside the maze consumes energy.
- **Victory:** Reach `X` to win.
- **Defeat:** Running out of health or energy ends the game.

Every move matters. A wrong decision might cost you more than just a few steps.

## 🔦 The Fog-of-War Mechanic

Unlike a conventional maze where the entire map is visible, The Blind Labyrinth uses two separate 2D character arrays:

- `real_map` stores the actual maze, including walls, enemies, and the exit.
- `print_map` represents what the player can currently see.

A flashlight-style visibility system reveals the player's immediate 3×3 neighborhood. The visible map is reset and updated after each turn, keeping unexplored cells hidden behind `?` symbols.

This makes exploration an important part of the gameplay rather than simply following a path that is already visible.

## ⚙️ Technical Implementation

The project applies several fundamental C programming concepts in a practical setting.

- **Two-dimensional arrays:** Represent the actual maze and the player's visible map.
- **Functions:** Separate movement, map generation, display, and visibility logic into manageable components.
- **Pointers:** Allow functions to update player coordinates, health, and energy.
- **Random number generation:** Place walls and enemies at different positions for each game session.
- **Loops and conditional statements:** Control gameplay, validate movement, and detect collisions.
- **Switch statements:** Process player movement based on keyboard input.
- **Character handling:** Use `toupper()` to accept both uppercase and lowercase inputs.
- **Time-based seeding:** Use `srand(time(NULL))` to vary the random maze layout between runs.

The project is intentionally built with standard C libraries and a terminal interface, keeping the focus on programming logic rather than graphical frameworks.

## 💻 Getting Started

### Prerequisites

- A C compiler, such as GCC.
- A terminal or command prompt.

### Compilation

Save the source code as `main.c`, then run:

```bash
gcc main.c -o blind_labyrinth
```

### Execution

**Linux / macOS**

```bash
./blind_labyrinth
```

**Windows**

```bash
blind_labyrinth.exe
```

Follow the on-screen instructions and use `W`, `A`, `S`, and `D` to navigate.

## 🚀 Possible Future Improvements

The current version provides the foundation for a more advanced survival game. Potential extensions include:

- A guaranteed-solvable maze-generation algorithm.
- A proper game-over screen and replay option.
- Difficulty levels with different health and energy limits.
- A scoring system based on moves, exploration, and resources remaining.
- Smarter enemy behavior instead of static obstacles.
- Improved input validation and handling of invalid commands.
- A larger maze with multiple levels and additional hazards.

These improvements would turn a simple terminal game into a more complete game-engineering project.

## 🎓 Final Note

The purpose of this project was not to build the most complicated game possible. It was to go beyond the bare minimum and use basic programming concepts to create something interactive, challenging, and enjoyable.

A calculator can teach you arithmetic operations. Rock-Paper-Scissors can teach you conditionals.

But a maze with hidden information, limited resources, random obstacles, and multiple interacting functions can challenge you to think about how an entire program behaves as a system.

**The assignment may be compulsory. The effort you put into it is your choice.**

*Explore wisely. Conserve your energy. Trust your logic. And whatever you do, don't take a blind step.*

---

**Project:** DARK-CELL-ESCAPE 
**Language:** C  
**Interface:** Terminal / Command Line  
**Grid Size:** 10 × 10  
**Core Concepts:** Arrays, pointers, functions, randomization, loops, and conditional logic
