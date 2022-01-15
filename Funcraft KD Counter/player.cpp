#include "player.h"
#include "log.h"

void sort_players()
{
    unsigned int i, j;
    PLAYER tmp;

    for (i = 0; i < player_list.size() - 1; i++) {
        for (j = 0; j < player_list.size() - i - 1; j++) {
            if (player_list.at(j).ratio < player_list.at(static_cast<std::vector<PLAYER, std::allocator<PLAYER>>::size_type>(j) + 1).ratio) {
                tmp = player_list.at(j);
                player_list.at(j) = player_list.at(static_cast<std::vector<PLAYER, std::allocator<PLAYER>>::size_type>(j) + 1);
                player_list.at(static_cast<std::vector<PLAYER, std::allocator<PLAYER>>::size_type>(j) + 1) = tmp;
            }
        }
    }
    return;
}

void update_ratio()
{
    float ratio = 0;

    for (unsigned int i = 0; i < player_list.size(); i++) {
        unsigned int kills = player_list.at(i).kills;
        unsigned int deaths = player_list.at(i).deaths;

        ratio = (kills >= 1 && deaths == 0) ? (float)kills :
                (kills == 0 && deaths >= 1) ? 0.f :
                (float)kills / (float)deaths;

        player_list.at(i).ratio = ratio;
    }
    return;
}

void add_kill(std::string player_name)
{
    if (!in_list(player_name)) {
        PLAYER player;
        player.name = player_name;
        player.kills++;

        player_list.push_back(player);
    }
    else {
        player_list.at(get_player_index(player_name)).kills++;
    }
    return;
}

void add_death(std::string player_name)
{
    if (!in_list(player_name)) {
        PLAYER player;
        player.name = player_name;
        player.deaths++;

        player_list.push_back(player);
    } else {
        player_list.at(get_player_index(player_name)).deaths++;
    }
    return;
}