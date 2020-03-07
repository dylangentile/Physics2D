#include "render.h"

#include "log.h"

#define logCat "RENDER"

Renderer::Renderer(uint32_t w, uint32_t h, const char* windowName)
{
	mWindow = SDL_CreateWindow(windowName, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 
		w, h, SDL_WINDOW_SHOWN | SDL_WINDOW_ALLOW_HIGHDPI);
	if(!mWindow)
		log(kLog_Fatal, logCat, "Failed to create SDL Window: %s", SDL_GetError());

	mRenderer = SDL_CreateRenderer(mWindow, -1, SDL_RENDERER_SOFTWARE);
	if(!mRenderer)
		log(kLog_Fatal, logCat, "Failed to create SDL Renderer: %s", SDL_GetError());

	SDL_GetRendererOutputSize(mRenderer, &mWidth, &mHeight);
		log(kLog_Info, logCat, "Window dim: %dx%d", mWidth, mHeight);

	mFrameTexture = SDL_CreateTexture(mRenderer, SDL_PIXELFORMAT_RGBA8888, 
		SDL_TEXTUREACCESS_STREAMING, mWidth, mHeight);
	if(!mFrameTexture)
		log(kLog_Fatal, logCat, "Failed to create Frame Texture: %s", SDL_GetError());

	mPixels = new uint32_t[mWidth*mHeight];



}

Renderer::~Renderer()
{
	delete[] mPixels;
	SDL_DestroyTexture(mFrameTexture);
	SDL_DestroyRenderer(mRenderer);
	SDL_DestroyWindow(mWindow);
}

void 
Renderer::getDim(int32_t* w, int32_t* h)
{
	*w = mWidth;
	*h = mHeight;
}

void
Renderer::render()
{

}

