#include "sfwdraw.h"
#include "GameState.h"
#include "constd.h"
#include <cstdio>

void main()
{
	float SCREEN_WIDTH = 1000, SCREEN_HEIGHT = 800;
	sfw::initContext(SCREEN_WIDTH, SCREEN_HEIGHT);
	unsigned font = sfw::loadTextureMap("./res/tonc_font.png", 16, 6);

	GameState game;

	Splash Splash;
	Splash.init(font);

	Quit quit;
	quit.init(font);

	APP_STATE state = ENTERSPLASH;

	while (sfw::stepContext())
	{
		float dt = sfw::getDeltaTime();

		switch (state)
		{
		case ENTERSPLASH:
			Splash.play();
		case SPLASH:
			Splash.step();
			Splash.draw();
			state = Splash.next();
			break;
		case ENTERGAME:
			game.init(font);
		case GAME:
			game.update(dt);
			game.draw();
			state = game.next();
			break;
		case ENTERQUIT:
			quit.play();
		case QUIT:
			quit.step();
			quit.draw();
			state = quit.next();
			break;
		}
	}
	sfw::termContext();
}