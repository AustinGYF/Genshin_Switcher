#include <iostream>
#include <fstream> 
#include "./config.h"

std::string getWD(){
    std::string game_dir;
    std::cout << "Plase Enter Game Path: \n";
    std::cin >> game_dir;

    return game_dir;
}

int main(){
    std::string game_dir;
    std::ifstream game_path_file("./.game_path.txt");
    getline(game_path_file, game_dir);
    game_path_file.close();
    if(game_dir.length()==0){
        std::cout << "No Game Path is Found.\n";
        std::cout << "Set Game Path Now? (yes/no; Defualt no)"<<std::endl;
        std::string set_path_op;
        std::cin >> set_path_op;
        if(set_path_op=="yes"){
            game_dir = getWD();
            std::ofstream game_path_file("./.game_path.txt");
            game_path_file << game_dir;
            game_path_file.close();
        }else{
            return 0;
        }
    }
    std::string init_path = game_dir + "config.ini";
    
    int option;
    std::cout << "Server Options: \n 1. Mihoyo Server\n 2. Bilibili Server\n";
    std::cout << "Select Server: ";
    std::cin >> option;    

    
}
