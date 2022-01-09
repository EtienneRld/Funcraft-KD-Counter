#include <iostream>
#include <fstream>
#include <string>
#include <thread>
#include <Windows.h>
#include <io.h>
#include <fcntl.h>
#include <vector>
#include <thread>
#include <chrono>

#include "log.h"
#include "player.h"

int main()
{
    SetConsoleOutputCP(CP_UTF8);

    std::cout << "Ce programme est en dÃ©veloppement, si vous trouvez des bugs merci de me contacter\n";
    std::cout << "sur Discord: Etienne#1230 ou sur GitHub: EtienneRld\n";

    char username[256 + 1];
    DWORD size = 256 + 1;
    GetUserNameA(username, &size);

    std::string path_log = "C:/Users/" + std::string(username) + "/AppData/Roaming/.az-client/logs/latest.log";

    std::ifstream log(path_log, std::ios::in);

    if (log.is_open())
    {
        std::cout << "\nLe fichier de log a bien Ã©tÃ© trouvÃ©.\n";
        new std::thread(read_log, "C:/Users/" + std::string(username) + "/AppData/Roaming/.az-client/logs/latest.log");
    }

    else
    {
        std::cout << "Le fichier log du AZ-Launcher n'ayant pas Ã©tÃ© trouvÃ©, veulliez indiquer le chemin complet\n";
        std::cout << "vers le dossier contenant le fichier lastest.log ou vÃ©rifier qu'il existe bien.\n";
        std::cout << "\nExemple -> C:\\Users\\Etienne\\AppData\\Roaming\\.az-client\\logs\\\n";

        bool open = false;

        do
        {
            std::cout << "\n-> ";
            std::cin >> path_log;

            // The last character of the path is not "/" if so, adding one.
            if (path_log.back() != (char)"/")
            {
                path_log.append("\\");
            }

            std::ifstream log(path_log + "latest.log", std::ios::in);

            if (!log.is_open())
            {
                std::cout << "\nLe chemin \"" + path_log + "\" ne contient pas le fichier latest.log ou est invalide.\n";
            }

            else
            {
                new std::thread(read_log, path_log + "latest.log");

                std::cout << "\nLe fichier de log a bien Ã©tÃ© trouvÃ©.\n";

                open = true;

            }
        } while (!open);
    }


    while (true)
    {
        if (GetAsyncKeyState(VK_F4) && GetForegroundWindow() == GetConsoleWindow())
        {
            player_list.clear();

            system("cls");

            std::cout << "L'affichage du compteur se rÃ©activera quand\n";
            std::cout << "il dÃ©tectera un Ã©vÃ©nement de mort dans le tchat.";
        }

        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
}