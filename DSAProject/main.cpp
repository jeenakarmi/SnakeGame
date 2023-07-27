#include <iostream>
#include <SDL.h>
#include <vector>

// window resolution
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

class Snake
{
public:
	static const int SNAKE_WIDTH = 20;
	// constructor
	Snake();
	// renders the body part to screen
	void render();
	// returns bodyRect
	SDL_Rect getBodyRect();
private:
	SDL_Rect bodyRect;
	int xDir, yDir;
};

// initialize SDL and all it's subsystems
bool init();

// initialize all media
bool loadMedia();

// close SDL and subsystems 
void close();

// GLOBAL VARIABLES
SDL_Window* gWindow = NULL;
SDL_Renderer* gRenderer = NULL;

bool init()
{
	bool success{ true };

	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		std::cout << "SDL could not be initialzed! SDL Error: " << SDL_GetError() << '\n';
		success = false;
	}
	else
	{
		// created a window
		gWindow = SDL_CreateWindow("snake", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (gWindow == NULL)
		{
			std::cout << "Window could not be created! SDL Error: " << SDL_GetError() << '\n';
			success = false;
		}
		else
		{
			// created renderer in the window
			gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
			if (gRenderer == NULL)
			{
				std::cout << "Renderer could not be created! SDL Error: " << SDL_GetError() << '\n';
				success = false;
			}
			else
			{
				SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);

				// png loading
			}

		}
	}

	return success;
}

bool loadMedia()
{
	bool success{ true };

	// nothing here

	return success;
}

void close()
{
	SDL_DestroyWindow(gWindow);
	SDL_DestroyRenderer(gRenderer);
	gWindow = NULL;
	gRenderer = NULL;

	// close SDL
	SDL_Quit();
}

int main(int argc, char* argv[])
{
	if (!init())
	{
		std::cout << "Failed to initialize SDL!\n";
	}
	else
	{
		if (!loadMedia())
		{
			std::cout << "Failed to load media!\n";
		}
		else
		{
			bool quit{ false };
			SDL_Event e;

			while (!quit) // main loop / game loop
			{
				while (SDL_PollEvent(&e) != 0) // EVENT LOOP
				{
					if (e.type == SDL_QUIT)
					{
						quit = true;
					}
				}
				// clear renderer
				SDL_SetRenderDrawColor(gRenderer, 0xcc, 0x12, 0xE2, 0xFF);
				SDL_RenderClear(gRenderer);

				// render
				SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
				SDL_Rect renctangle = { 10, 10, 200, 100 };
				SDL_RenderFillRect(gRenderer, &renctangle);

				// show rendered objects
				SDL_RenderPresent(gRenderer);
			}
		}
	}

	close();
	return 0;
}