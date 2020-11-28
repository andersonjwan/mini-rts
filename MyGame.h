#ifndef MY_GAME_H
#define MY_GAME_H

#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>

#define SCREEN_WIDTH  640
#define SCREEN_HEIGHT 480

class MyGame {
 private:
  bool active;

  SDL_Window   *window;
  SDL_Surface  *surface;
  SDL_Renderer *renderer;

 public:
  MyGame(void);

  // method(s)
  int onExecute(void);

  bool onInit(void);
  void onEvent(SDL_Event *);
  void onLoop(void);
  void onRender(void);
  void onCleanup(void);
};

#endif
