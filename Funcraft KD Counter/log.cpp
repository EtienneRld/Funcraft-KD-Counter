#include <regex>
#include "log.h"
#include "console.h"
#include "player.h"

std::regex rgx("\\b(?!(?:par|une|est|TNT|vide|mort|chute|suffocation)\\b)\\w{3,16}");
std::string death_args[] = { " est mort.", " a été tué" };
unsigned int death_args_size = 2;

void read_log(std::string path)
{
    std::ifstream log(path, std::ifstream::in);
    std::string line, last_line;
    std::streampos pos;

    std::cout << "\nL'affichage du compteur s'activera quand";
    std::cout << "\nil détectera un événement de mort dans le tchat.";

    log.seekg(-1, std::ios_base::end);

    while (log.good()) {
        last_line = line;

        if (getline(log, line)) {
            if (line != last_line) {
                check_line(line);
            }
            pos = !log.tellg() ? pos += line.size() : pos = log.tellg();
        }
        log.clear();
        log.seekg(pos);
    }
    log.close();
    return;
}

void check_line(std::string line)
{
    if (find_all_char(line, ":") == 3) {
        bool death_event = false;
        
        for (unsigned int i = 0; i < death_args_size; i++) {
            if (line.find(death_args[i]) != std::string::npos) {
                death_event = true;
            }
        }

        if (death_event) {
            line = line.substr(line.find("[CHAT]") + 14);

            std::string::const_iterator start(line.cbegin());
            std::vector<std::string> event_args;
            std::smatch player;

            while (std::regex_search(start, line.cend(), player, rgx)) {
                event_args.push_back(player[0]);
                start = player.suffix().first;
            }
            add_death(event_args[0]);

            for (unsigned int i = 1; i < event_args.size(); i++) {
                add_kill(event_args[i]);
            }
            event_args.clear();
            update_ratio();
            sort_players();
            update_console();
        }
    }
    return;
}

bool in_list(std::string player_name)
{
    if (!player_list.empty()) {
        for (const PLAYER& player : player_list) {
            if (player.name == player_name) {
                return true;
            }
        }
    }
    return false;
}

unsigned int find_all_char(std::string line, const char* character)
{
    unsigned int count = 0;
    size_t pos = line.find(character, 0);

    while (pos != std::string::npos) {
        count++;
        pos = line.find(character, pos + 1);
    }
    return count;
}

int get_player_index(std::string player_name)
{
    if (!player_list.empty()) {
        for (unsigned int i = 0; i < player_list.size(); i++) {
            if (player_list.at(i).name == player_name) {
                return i;
            }
        }
    }
    return -1;
}
