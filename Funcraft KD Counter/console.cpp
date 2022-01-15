#include <iostream>
#include <iomanip>
#include "player.h"

void update_console()
{
    if (!player_list.empty()) {
        system("cls");

        std::cout << "Appuyez sur [F4] dans la console pour réinitialiser le compteur et les joueurs trouvés\n\n";

        std::cout << "Nombre de joueurs trouvés: " << player_list.size() << "\n\n";
        std::cout << "-------------------------\n";

        for (unsigned int i = 0; i < player_list.size(); i++) {
            std::cout << "Pseudo: \033[90m" << player_list.at(i).name << " \033[0m\n";

            std::string color = (player_list.at(i).ratio >= 1.f) ? "\033[32m" : "\033[33m";

            std::cout << "Ratio: " << color << std::setprecision(3) << player_list.at(i).ratio << "\033[0m\n";
            std::cout << "Kills: \033[94m" << player_list.at(i).kills << "\033[0m\n";
            std::cout << "Morts: \033[91m" << player_list.at(i).deaths << "\033[0m\n";
            
            std::cout << "-------------------------\n";
        }
    }
    return;
}
