#include <string>

#include "log.h"
#include "console.h"
#include "player.h"

//"é = "�"
std::string death_args[3] = { " est mort.", "a été tué par", "a été tué par" };

// Used to read every new line of the log file.
void read_log(std::string path)
{
    std::cout << "\nL'affichage du compteur s'activera quand\n";
    std::cout << "il détectera un événement de mort dans le tchat.";

    std::ifstream log(path, std::ifstream::in);
    std::streampos pos = 0;

    std::string line;
    std::string last_line;

    log.seekg(-1, std::ios_base::end);

    while (log.good())
    {
        last_line = line;

        if (getline(log, line))
        {
            // To show every new line
            //std::cout << "\n" << line;

            if (line != last_line)
            {
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

// Call every time a new line is read by the function read_log().
void check_line(std::string line)
{
    if (find_all_char(line, ":") == 3)
    {
        for (int i = 0; i < 2; i++)
        {
            if (line.find(death_args[i]) != std::string::npos)
            {
                std::size_t start = line.find("[CHAT]") + 14;
                std::string stop;

                if (i == 0)
                {
                    stop = " est ";
                }

                else
                {
                    stop = " a ";
                }

                std::string name = line.substr(start, line.find(stop) - start);

                struct tm newtime;
                time_t now = time(0);
                char buf[80];
                localtime_s(&newtime, &now);
                strftime(buf, sizeof(buf), "%X", &newtime);

                if (!in_list(name))
                {
                    PLAYER player;

                    player.name = name;
                    player.last_death = buf;
                    player.deaths++;

                    player_list.push_back(player);
                }

                else
                {
                    int index = get_player_index(name);

                    if (index == -1)
                    {
                        std::cout << "Error cannot found player by name";
                    }

                    else
                    {
                        player_list.at(index).last_death = buf;
                        player_list.at(index).deaths++;
                    }
                }

                unsigned int i, j;
                PLAYER tmp;

                //afficher les �l�ments du tableau

                for (i = 0; i < player_list.size() - 1; i++)
                {
                    for (j = 0; j < player_list.size() - i - 1; j++)
                    {
                        /* Pour un ordre d�croissant utiliser < */
                        if (player_list.at(j).deaths < player_list.at(static_cast<std::vector<PLAYER, std::allocator<PLAYER>>::size_type>(j) + 1).deaths)
                        {
                            tmp = player_list.at(j);
                            player_list.at(j) = player_list.at(static_cast<std::vector<PLAYER, std::allocator<PLAYER>>::size_type>(j) + 1);
                            player_list.at(static_cast<std::vector<PLAYER, std::allocator<PLAYER>>::size_type>(j) + 1) = tmp;
                        }
                    }
                }

                update_console();
            }
        }
    }

    return;
}

// Check if the player is already in the list to prevent double struct.
bool in_list(std::string name)
{
    if (!player_list.empty())
    {
        for (unsigned int i = 0; i < player_list.size(); i++)
        {
            if (player_list.at(i).name == name)
            {
                return true;
            }
        }
    }


    return false;
}

// Get the index of a struct player by is name, in the vector players.
int get_player_index(std::string name)
{
    if (!player_list.empty())
    {
        for (unsigned int i = 0; i < player_list.size(); i++)
        {
            if (player_list.at(i).name == name)
            {
                return i;
            }
        }
    }

    return -1;
}

// Return the number of characters specified on a line.
int find_all_char(std::string line, const char* character)
{
    int count = 0;

    size_t pos = line.find(character, 0);

    while (pos != std::string::npos)
    {
        count++;

        pos = line.find(character, pos + 1);
    }

    return count;
}