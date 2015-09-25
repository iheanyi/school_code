#include "SDL/SDL.h"
#include "SDL/SDL_image.h"

int main(int argc, char* args[]) {
SDL_Surface* hello = NULL;
SDL_Surface* screen = NULL;

SDL_Init(SDL_INIT_EVERYTHING);

screen = SDL_SetVideoMode(640, 480, 32, SDL_SWSURFACE);

hello = IMG_Load("preview2.jpg");

SDL_BlitSurface(hello, NULL, screen, NULL);

SDL_Flip(screen);

SDL_Delay(2000);

SDL_FreeSurface(hello);

SDL_Quit();

return 0;



}