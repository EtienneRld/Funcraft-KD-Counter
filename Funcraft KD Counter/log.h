#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <thread>
#include <Windows.h>
#include <io.h>
#include <fcntl.h>
#include <vector>

void read_log(std::string path);
void check_line(std::string line);
bool in_list(std::string name);
int find_all_char(std::string line, const char* character);
int get_player_index(std::string name);