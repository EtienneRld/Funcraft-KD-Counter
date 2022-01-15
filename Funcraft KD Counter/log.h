#pragma once
#include <iostream>
#include <fstream>

void read_log(std::string path);
void check_line(std::string line);
bool in_list(std::string player_name);
unsigned find_all_char(std::string line, const char* character);
int get_player_index(std::string player_name);
