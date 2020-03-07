#pragma once
#include <cstdint>
#include <SDL2/SDL.h>

class Renderer
{
public:
	Renderer(uint32_t w, uint32_t h, const char* windowName);
	~Renderer();
	
	void getDim(int32_t* w, int32_t* h);

	void render();

	


private:
	int32_t mWidth, mHeight;
	SDL_Window* mWindow;
	SDL_Renderer* mRenderer;
	SDL_Texture* mFrameTexture;
	uint32_t* mPixels;
};