#include "MyGame.h"

MyGame::MyGame(void)
{
  // init variables
  window   = NULL;
  surface  = NULL;
  renderer = NULL;

  // set the application's status
  active = true;
}

int MyGame::onExecute(void)
{
  if(!onInit()) {
    printf("Initialization Error: %s\n", SDL_GetError());
    return -1;
  }

  SDL_Event event;

  while(active) {
    while(SDL_PollEvent(&event)) {
      onEvent(&event);
    }

    onLoop();
    onRender();
  }

  onCleanup();
  return 0;
}

bool MyGame::onInit(void)
{
  if(SDL_Init(SDL_INIT_VIDEO) < 0) {
    return false;
  }

  window = SDL_CreateWindow("My Game",
                            SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
                            SCREEN_WIDTH, SCREEN_HEIGHT,
                            SDL_WINDOW_SHOWN);
  if(!window) {
    return false;
  }

  renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
  if(!renderer) {
    return false;
  }

  return true;
}

void MyGame::onEvent(SDL_Event *event)
{
  switch(event->type) {
  case SDL_QUIT:
    active = false;
    break;
  }
  return;
}

void MyGame::onLoop(void)
{
  return;
}

void MyGame::onRender(void)
{
  return;
}

void MyGame::onCleanup(void)
{
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();

  return;
}
