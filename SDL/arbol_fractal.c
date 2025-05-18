#include <SDL2/SDL.h>
#include <math.h>
#include <stdint.h>

static SDL_Window* window = NULL;
static SDL_Renderer* renderer = NULL;

// Conversión de grados a radianes
double deg2rad(double deg) {
    return deg * M_PI / 180.0;
}

// Establecer color según la profundidad
void set_color_by_depth(int depth) {
    if (depth % 3 == 0)
        SDL_SetRenderDrawColor(renderer, 34, 139, 34, SDL_ALPHA_OPAQUE);     // verde
    else if (depth % 3 == 1)
        SDL_SetRenderDrawColor(renderer, 139, 69, 19, SDL_ALPHA_OPAQUE);     // marrón
    else
        SDL_SetRenderDrawColor(renderer, 255, 215, 0, SDL_ALPHA_OPAQUE);     // amarillo
}

// Dibuja el árbol recursivamente
void tree(double x1, double y1, double length, double angle, int depth) {
    if (depth == 0) return;

    double rad = deg2rad(angle);
    double x2 = x1 + length * cos(rad);
    double y2 = y1 - length * sin(rad);  // menos porque Y crece hacia abajo en pantalla

    set_color_by_depth(depth);
    SDL_RenderDrawLine(renderer, (int)x1, (int)y1, (int)x2, (int)y2);

    tree(x2, y2, length * 0.7, angle - 25, depth - 1); // rama izquierda
    tree(x2, y2, length * 0.7, angle + 25, depth - 1); // rama derecha
}

int main(int argc, char* argv[]) {
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        SDL_Log("No se pudo inicializar SDL: %s", SDL_GetError());
        return 1;
    }

    if (SDL_CreateWindowAndRenderer(640, 480, 0, &window, &renderer) != 0) {
        SDL_Log("Error creando ventana o renderer: %s", SDL_GetError());
        SDL_Quit();
        return 1;
    }

    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "0");
    SDL_RenderSetLogicalSize(renderer, 640, 480);

    for (int depth = 1; depth <= 8; depth++) {
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE); // fondo negro
        SDL_RenderClear(renderer);

        tree(320, 400, 100, 90, depth);  // posición base y orientación vertical

        SDL_RenderPresent(renderer);
        SDL_Delay(500);  // 500 ms por frame
    }

    SDL_Delay(2000); // Espera antes de cerrar

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}


