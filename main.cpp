#include <iostream>
#include <fstream>
#include <string>
#include "./config.h"

std::string getWD(){
    std::string game_dir;
    std::cout << "Plase Enter Game Path: \n";
    std::cin >> game_dir;

    return game_dir;
}

int main(){
    std::string game_dir;
    std::ifstream gamePathFile("./.game_path.txt");
    if(!gamePathFile.is_open()){
        std::cout << "Error: Game Path File Not Opened." << std::endl;
        return 0;
    }
    getline(gamePathFile, game_dir);
    gamePathFile.close();
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
    
    int sv_option;
    std::cout << "Server Options: \n 1. Mihoyo Server\n 2. Bilibili Server\n";
    std::cout << "Select Server: ";
    std::cin >> sv_option;    

    std::ifstream initFile(init_path);
    if(!initFile.is_open()){
        std::cout << "Error: Init File Failed to Open for Read"<<std::endl;
        return 0;
    }
    std::string init_item;
    std::string init_array[6];
    int i=0;
    while(getline(initFile, init_item)){
        init_array[i] = init_item;
        i++;
    }
    initFile.close();

    //Change init file for Mihoyo Server.
        //channel 
        //cps
    if(sv_option==1){
       init_array[1] = guanconf[0];
       init_array[2] = guanconf[1];
    }

    //Change init file for Bilibili Server.
    if(sv_option==2){
       init_array[1] = biliconf[0];
       init_array[2] = biliconf[1];
    }

    std::ofstream newInitFile(init_path);
    if(!newInitFile.is_open()){
        std::cout << "Error: Init File is Failed to open for Update" << std::endl;
    }
    i = 0;
    while(i<size(init_array)){
        newInitFile << init_array[i] <<std::endl;
    }
    newInitFile.close();

}
