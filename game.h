#ifndef _GAME
#define _GAME

#include "session.h"
#include "scene.h"
#include "camera.h"

#include <stdlib.h>
#include <stdio.h>

struct Game
{
	GLFWwindow* window;
	Scene scene;
};
typedef struct Game Game;

void initGame(Game* game);
void runGame(Game* game);
void closeGame(Game* game);

#endif


