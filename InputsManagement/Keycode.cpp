#include "Keycode.h"

#include <unordered_map>

const std::pmr::unordered_map<int, SDL_Keycode> MAP = {
    { 0, SDLK_a },
    { 1, SDLK_b },
    { 2, SDLK_c },
    { 3, SDLK_d },
    { 4, SDLK_e },
    { 5, SDLK_f },
    { 6, SDLK_g },
    { 7, SDLK_h },
    { 8, SDLK_i },
    { 9, SDLK_j },
    { 10, SDLK_k },
    { 11, SDLK_l },
    { 12, SDLK_m },
    { 13, SDLK_n },
    { 14, SDLK_o },
    { 15, SDLK_p },
    { 16, SDLK_q },
    { 17, SDLK_r },
    { 18, SDLK_s },
    { 19, SDLK_t },
    { 20, SDLK_u },
    { 21, SDLK_v },
    { 22, SDLK_w },
    { 23, SDLK_x },
    { 24, SDLK_y },
    { 25, SDLK_z },
    { 26, SDLK_0 },
    { 27, SDLK_1 },
    { 28, SDLK_2 },
    { 29, SDLK_3 },
    { 30, SDLK_4 },
    { 31, SDLK_5 },
    { 32, SDLK_6 },
    { 33, SDLK_7 },
    { 34, SDLK_8 },
    { 35, SDLK_9 },
    { 50, SDLK_TAB },
    { 51, SDLK_ESCAPE },
    { 52, SDLK_RETURN },
    { 53, SDLK_LSHIFT },
    { 54, SDLK_RSHIFT },
    { 55, SDLK_BACKSPACE }
};

SDL_Keycode Keycode::ToSdl(const int key)
{
    if (MAP.contains(key))
    {
        return MAP.at(key);
    }

    return SDLK_UNKNOWN;
}
