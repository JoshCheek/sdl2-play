// uhm, tried going through this http://www.aaroncox.net/tutorials/2dtutorials/sdl_gfx.pdf
// but it's for SDL1, so this is mostly me reading the header files and doing my best to translate
// or deviating in whatever way makes sense to me
#include <iostream>
#include <SDL2/SDL.h>
#include "SDL2/SDL2_gfxPrimitives.h"

int main(int argc, char **argv)
{
  if (SDL_Init(SDL_INIT_EVERYTHING) != 0){
    std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
    return 1;
  }

  // window to draw on
  //                                 title,          x, y, width, height
  SDL_Window *win = SDL_CreateWindow("Hello World!", 100, 100, 640, 480, SDL_WINDOW_SHOWN);
  if (win == nullptr){
    std::cout << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
    SDL_Quit();
    return 1;
  }

  // uhm, the thing that draws?
  //                                          -1 means "select first that meets reqs"
  SDL_Renderer *ren = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
  if (ren == nullptr){
    SDL_DestroyWindow(win);
    std::cout << "SDL_CreateRenderer Error: " << SDL_GetError() << std::endl;
    SDL_Quit();
    return 1;
  }

  // "clear" it, w/e that means (why would SDL_CreateRenderer not create me a clean one?)
  SDL_RenderClear(ren);

  // I guess this draws the rectangle on it?
  rectangleRGBA(
    ren,
    0,   0,          // Sint16 x1, Sint16 y1,
    200, 50,         // Sint16 x2, Sint16 y2,
    0, 0xFF, 0, 0xFF // Uint8 r, Uint8 g, Uint8 b, Uint8 a
  );

  rectangleColor(
    ren,
    10,  10,   // Sint16 x1, Sint16 y1,
    190, 40,   // Sint16 x2, Sint16 y2,
    0x888888FF // Uint32 color
  );

  boxColor(
    ren,
    20,  20,   // Sint16 x1, Sint16 y1
    180, 30,   // Sint16 x2, Sint16 y2
    0xFF0088FF // Uint32 color
  );



  // apparently we draw a bunch of shit, then present it at the end
  SDL_RenderPresent(ren);

  // uhm, wait a bit so we can look at it, I guess
  SDL_Delay(2000);

  // cleaning up
  SDL_DestroyRenderer(ren);
  SDL_DestroyWindow(win);
  SDL_Quit();

  //   SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 0, 0,
  //         0));

  // SDL_Surface* screen = SDL_SetVideoMode(WINDOW_WIDTH,
  //                                        WINDOW_HEIGHT, 0,
  //                                        SDL2_HWSURFACE | SDL2_DOUBLEBUF);
  // SDL_WM_SetCaption( WINDOW_TITLE, 0 );
  // SDL_Event event;

  // Filled rectangle (Box)
  // int boxColor(SDL_Surface * dst, Sint16 x1, Sint16 y1,
  //     Sint16 x2, Sint16 y2, Uint32 color);
  // int boxRGBA(SDL_Surface * dst, Sint16 x1, Sint16 y1, Sint16 x2,
  //     Sint16 y2, Uint8 r, Uint8 g, Uint8 b, Uint8 a);

  // bool gameRunning = true;
  // while (gameRunning)
  // {
  //   if (SDL_PollEvent(&event))
  //   {
  //     if (event.type == SDL_QUIT)
  //     {
  //       gameRunning = false;
  //     }
  //   }
  //   SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 0, 0,
  //         0));
  //   pixelRGBA(screen,
  //       10, 15,
  //       255, 255, 255, 255);
  //   lineRGBA(screen,
  //       20, 10,
  //       70, 90,
  //       255, 0, 0, 255);
  //   trigonRGBA(screen,
  //       500, 50,
  //       550, 200,
  //       600, 150,
  //       0, 255, 255, 255);
  //   filledTrigonRGBA(screen,
  //       200, 200,
  //       300, 50,
  //       400, 200,
  //       0, 0, 255, 255);
  //   rectangleRGBA(screen,
  //       -10, 300,
  //       100, 380,
  //       0, 255, 0, 255);
  //   boxRGBA(screen,
  //       210, 76,
  //       325, 300,
  //       255, 0, 0, 150);
  //   ellipseRGBA(screen,
  //       600, 400,
  //       50, 90,
  //       255, 255, 0, 200);
  //   filledEllipseRGBA(screen,
  //       600, 400,
  //       25, 150,
  //       0, 255, 0, 255);
  //   short x[6] = { 350, 275, 300, 325, 350, 400 };
  //   short y[6] = { 325, 325, 390, 390, 375, 300 };
  //   polygonRGBA(screen,
  //       x, y,
  //       6,
  //       255, 255, 255, 155);
  //   short s[5] = { 400, 450, 450, 425, 300 };
  //   short t[5] = { 400, 410, 450, 425, 500};
  //   filledPolygonRGBA(screen,
  //       s, t,
  //       5,
  //       255, 0, 255, 155);
  //   SDL_Flip(screen);
  // }
  return 0;
}
