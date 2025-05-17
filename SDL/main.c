#include <stdint.h>        // para uint8_t
#include <SDL2/SDL.h>      // principal header de SDL2

// Punteros globales al contexto SDL
static SDL_Window   *window   = NULL;
static SDL_Renderer *renderer = NULL;

void vg_frame_start(void) {
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
    SDL_RenderClear(renderer);
}

void vg_draw_pixel(int x, int y, uint8_t r, uint8_t g, uint8_t b) {
    SDL_SetRenderDrawColor(renderer, r, g, b, SDL_ALPHA_OPAQUE);
    SDL_RenderDrawPoint(renderer, x, y);
}

void vg_frame_end(void) {
    SDL_RenderPresent(renderer);
}

int main(int argc, char *argv[]) {
    // 1. Inicializar SDL
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        SDL_Log("No se pudo inicializar SDL: %s", SDL_GetError());
        return 1;
    }

    // 2. Crear ventana y renderer lógicos 640×480
    if (SDL_CreateWindowAndRenderer(640, 480, 0, &window, &renderer) != 0) {
        SDL_Log("Error creando ventana o renderer: %s", SDL_GetError());
        SDL_Quit();
        return 1;
    }
    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "0");
    SDL_RenderSetLogicalSize(renderer, 640, 480);

    // 3. Bucle de evento simple que dibuja una cruz y espera 2 s
    vg_frame_start();
    for (int i = 0; i < 640; ++i) {
        vg_draw_pixel(i, 240, 255, 0, 0);
    }
    for (int j = 0; j < 480; ++j) {
        vg_draw_pixel(320, j, 255, 0, 0);
    }
    vg_frame_end();

    SDL_Delay(2000);  // muestra 2 s

    // 4. Limpieza
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}





