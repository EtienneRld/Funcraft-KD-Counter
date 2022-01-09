#pragma once

#include <vector>

struct PLAYER {
    std::string name, last_death, last_kill;

    unsigned int kills = 0, deaths = 0;
};

inline std::vector<PLAYER> player_list;
