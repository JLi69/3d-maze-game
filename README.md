# 3d-maze-game

## About
This is a quick little three dimensional maze game that I made a while back while trying to learn OpenGL.

I learned some basic things about OpenGL such as vertex buffers, matrices, and shaders and I thought it would be fun to create a little game where I tried to use my newly gained knowledge.

In this game, you control a camera that you can move around using the arrow keys and you can collect spinning yellow cubes (these don't really do anything). To complete the maze, you have to find a spinning rainbow cube which will teleport you to another randomly generated maze (all mazes are randomly generated). 

The code isn't very clean (or up to any standard) and the controls are slightly awkward (if you improve the game feel free to fork this) and the game isn't actually that fun but I had a lot of fun programming it and learning how to actually get it to work so I figured that I can share this on GitHub. Anyway, I hope you have fun and enjoy!

## Controls
Left Arrow key = turn camera left

Right Arrow key = turn camera right

Up Arrow key = move forward

Down Arrow key = move backwards

Space key = Jump

## How to compile the Code
To compile the source code, simply run the following commands:
```
cmake -S 3d-maze-game -B 3d-maze-game/build
cd 3d-maze-game/build
make
```

To run the program just type `./3d-maze`.

**IMPORTANT: The folder 'shaders' must be in the same directory as the exectutable for the game to work!**

**IMPORTANT 2: Some necessary depedencies: [GLFW](https://www.glfw.org/), [glad](https://glad.dav1d.de/)**, and [glm](https://github.com/g-truc/glm)

**NOTE: I wrote this targeted towards Linux so there may be some issues on Windows or MacOS. If you figure out a way to compile the source code on these platforms, please fork the project with the necessary adjustments.**

## Screenshots
![Screenshot 1](https://github.com/JLi69/3d-maze-game/blob/main/screenshots/Maze-1.png)

![Screenshot 2](https://github.com/JLi69/3d-maze-game/blob/main/screenshots/Maze-2.png)

![Screenshot 3](https://github.com/JLi69/3d-maze-game/blob/main/screenshots/Maze-3.png)

## Videos
[Gameplay Video](https://www.youtube.com/watch?v=eIESb0ElVV8)

[Code Explanation (TBA)]()
