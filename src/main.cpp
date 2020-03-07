#include "log.h"
#include "render.h"

int main(void)
{
	setThreadName("MAIN");
	log(kLog_Info, "CORE", "Intializing...");
	Renderer* myRenderer = new Renderer(1280, 720, "bruh moment");
	
	bool quit = false;
	SDL_Event e;
	while(!quit)
	{
		while(SDL_PollEvent(&e))
		{
			if(e.type == SDL_QUIT)
				quit = true;
		}
	}

	delete myRenderer;
	return 0;
}