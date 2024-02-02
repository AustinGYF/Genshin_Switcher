#include <iostream>
#include <fstream> 
#include "./config.h"

std::string getWD(){
    std::string working_dir;
    std::cout << "Plase Enter Game Path: \n";
    std::cin >> working_dir;

    return working_dir;
}

int main(){
    int option;

    std::cout << "Server Options: \n 1. Mihoyo Server\n 2. Bilibili Server\n";
    std::cout << "Select Server: ";
    std::cin >> option;    

    std::string working_dir;
    std::string game_path;
    std::string init_path = working_dir + "config.ini";
    std::ifstream game_path_file("./.game_path.txt");
    getline(game_path_file, game_path);
    
}
