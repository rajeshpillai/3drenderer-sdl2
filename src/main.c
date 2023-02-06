#include <stdio.h>
#include <stdint.h>  // uintx_t types
#include <stdbool.h>
#include <SDL2/SDL.h>


bool is_running = false;
SDL_Window* window = NULL;
SDL_Renderer* renderer = NULL;

uint32_t* color_buffer = NULL;
int window_width = 800;
int window_height = 600;

bool initialize_window(void) {
  if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
    fprintf(stderr, "Error initializing SDL.\n");
    return false;
  }

// Create a SDL Window
  window = SDL_CreateWindow(
    NULL,
    SDL_WINDOWPOS_CENTERED,
    SDL_WINDOWPOS_CENTERED,
    window_width,
    window_height,
    SDL_WINDOW_BORDERLESS
  );

   if (NULL == window) {
    fprintf(stderr, "Error creating SDL window.\n");
    return false;
  }

  // Create a SDL renderer
  renderer = SDL_CreateRenderer(window, -1, 0);
  if (!renderer) {
    fprintf(stderr, "Error creating SDL renderef.\n");
    return false;
  }
  return true;
}

void setup(void) {
  // The programmer is responsible for clearing the memory allocated with malloc.
  color_buffer = (uint32_t*) malloc(sizeof(uint32_t) * window_width * window_height);
}

void process_input(void) {
  SDL_Event event;
  SDL_PollEvent(&event);

  switch (event.type) {
    case SDL_QUIT:
      is_running = false;
      break;

    case SDL_KEYDOWN:
      if (event.key.keysym.sym == SDLK_ESCAPE)
        is_running = false;
      break;

  }
}

void update(void) {

}

// Clean up
void destroy_window(void) {
  free(color_buffer);
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();
}

void render(void) {
  SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255 );
  SDL_RenderClear(renderer);
  SDL_RenderPresent(renderer);
}

int main (int argv, char** args) {
  is_running = initialize_window();

  setup();
  while(is_running) {
    process_input();
    update();
    render();
  }

  destroy_window();
  return 0;
} 