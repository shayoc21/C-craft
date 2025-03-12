#include "game.h"

int main(int argc, char** argv)
{
	Game game;
	initGame(&game);
	runGame(&game);
	closeGame(&game);
}
