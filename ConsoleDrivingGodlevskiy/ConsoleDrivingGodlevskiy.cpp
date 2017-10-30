#include "ConsoleDrivingGodlevskiy.h"

int main()
{
	int maxLines = 30;
	system("mode con cols=70 lines=30");
	srand(time(0));
	Game Game(maxLines);
	Game.StartGame();
}


