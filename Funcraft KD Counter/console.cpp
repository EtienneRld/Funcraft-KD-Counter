#include <iostream>

#include "player.h"

// Call every time a kill / death append to update sur console output.
void update_console()
{
    if (!player_list.empty())
    {
        system("cls");

        std::cout << "Appuyez sur [F4] dans la console pour réinitialiser le compteur et les joueurs trouvés\n\n";

        std::cout << "Nombre de joueurs trouvés: " << player_list.size() << "\n\n";
        std::cout << "-------------------------\n";

        for (int i = 0; i < player_list.size(); i++)
        {
            std::cout << "Pseudo: " << player_list.at(i).name << "\n";
            //std::cout << "Kills: " << players.at(i).kills << "\n";
            std::cout << "Morts: " << player_list.at(i).deaths << " (" << player_list.at(i).last_death << ")\n";
            std::cout << "-------------------------\n";
        }
    }
}
