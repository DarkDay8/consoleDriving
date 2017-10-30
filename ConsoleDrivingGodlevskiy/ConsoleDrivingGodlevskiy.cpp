#include "ConsoleDrivingGodlevskiy.h"

int main()
{
	const int MAXLINE = 30;
	system("mode con cols=70 lines=30");
	srand(time(0));
	Game game(MAXLINE);
	game.startGame();
}


