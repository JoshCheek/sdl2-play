// http://www.willusher.io/sdl2%20tutorials/2013/08/17/lesson-1-hello-world/
#include <iostream>
#include <SDL2/SDL.h>
#include "res_path.h"

int main(int argc, char **argv){

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

  // load the image
  // std::string imagePath = getResourcePath("lesson1") + "hello.bmp";
  std::string imagePath = "/Users/josh/code/sdl-tutorial/res/lesson1/hello.bmp"; // didn't feel like spending time figuring out how to fix the res_path thing
  SDL_Surface *bmp = SDL_LoadBMP(imagePath.c_str());
  if (bmp == nullptr){
    SDL_DestroyRenderer(ren);
    SDL_DestroyWindow(win);
    std::cout << "SDL_LoadBMP Error: " << SDL_GetError() << std::endl;
    SDL_Quit();
    return 1;
  }

  // texture can actually be drawn
  SDL_Texture *tex = SDL_CreateTextureFromSurface(ren, bmp);
  SDL_FreeSurface(bmp);
  if (tex == nullptr){
    SDL_DestroyRenderer(ren);
    SDL_DestroyWindow(win);
    std::cout << "SDL_CreateTextureFromSurface Error: " << SDL_GetError() << std::endl;
    SDL_Quit();
    return 1;
  }

  // so draw it
  SDL_RenderClear(ren);
  SDL_RenderCopy(ren, tex, NULL, NULL); // NULLs are the the source and destination rectangles -- apparently this makes it stretch to fill the whole screen
  SDL_RenderPresent(ren);
  SDL_Delay(2000);

  // cleaning up
  // "in a real world program proper error handling and clean up is absolutely required."
  // fuck off
  SDL_DestroyTexture(tex);
  SDL_DestroyRenderer(ren);
  SDL_DestroyWindow(win);
  SDL_Quit();

  return 0;
}
