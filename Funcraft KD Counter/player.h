#pragma once
#include <string>
#include <vector>

struct PLAYER {
    std::string name;
    float ratio = 0;
    unsigned int kills = 0, deaths = 0;
};

inline std::vector<PLAYER> player_list;

void sort_players();
void update_ratio();
void add_kill(std::string player_name);
void add_death(std::string player_name);
