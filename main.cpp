
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cassert>

#include <SDL2/SDL.h>

#ifdef MIKE
#include "mike.cpp"
#else
#include "dictionary.cpp"
#endif

int main() {
        SDL_Init(0);

        Dictionary dict;

        const Uint32 start = SDL_GetPerformanceCounter();
        const Data *const d = dict.find(109304797);
        const Uint32 finish = SDL_GetPerformanceCounter();

        std::cout << (finish - start) * 1000.0 / (double)SDL_GetPerformanceFrequency() << "\n";

        assert(d->country == "Swaziland");

        SDL_Quit();
}
