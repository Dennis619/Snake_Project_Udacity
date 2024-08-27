#include "Player.h"
#include "SDL.h"

#include<iostream>
#include<fstream>
#include<sstream>
#include<exception>

//constructor and destructor dfn
Player::Player():playerName("Default Name"), 
    high_score(0) {std::cout <<"Player create " << endl; }

Player::~Player(){ std::cout<<"Player destroyed " << playerName << std::endl;}


//copy Constructor
Player::Player(const Player &source){
    std::cout << "player copied using copy constructor" << std::endl;
    playerName = source.playerName;
    high_score = source.high_score;
}
Player& Player::operator=(const Player &source){
    std::cout << "player copied using copy assignmet constructor" << std::endl;
    if(this == &source)
    return *this;

    playerName = source.playerName;
    high_score = source.high_score;

    return *this;
}

//move constructor
Player::Player (Player &&source){
    std::cout << "player moved using move constructor" << std::endl;
    playerName = std::move(source.playerName);
    high_score = std::move(source.high_score);
}

Player& Player::operator=(Player &&source){
    std::cout << "player moved using move assignmet constructor" << std::endl;
    if(this == &source)
        return *this;

    playerName = std::move(source.playerName);
    high_score = std::move(source.high_score);

    return *this;
}

void Player::SetPlayerName(std::string name){
    playerName = name;
}

void Player::SetHighScore(int score){
   high_score = score;
}

//getters
std::string Player::GetPlayerName()const{return playerName;}
int Player::GetHighScore()const{ return high_score; }
bool Player::IsPlayerInfoSet()const { return isPlayerInfoSet; }; 

//send Player Info to database
void Player::SendNewPlayerToFile(std::string player_name, int score){
    std::ofstream myFile(path, std::ios::trunc);
    try{
    if(myFile.is_open()){
        std::lock_guard <std::mutex> lck(_mutex);
        std::cout << "File opened sending " << player_name << std::endl;
        myFile << "PlayerName: " << player_name << std::endl;
        myFile << "PlayerHighScore: " << score << std::endl;

        //is player information added to true
        Player::isPlayerInfoSet = true;
    }else{
        std::cout << "Unable to open file" <<std::endl;
    }
    } catch( const ofstream::failure &e){
        std::cout << "Error during file openning " << std::endl;
    }

    myFile.close();
};

void Player::UpdatePlayerInfo(std::string player_name, int score){
    bool fileEdited = false;
    std::ifstream myFile(Player::path);
    std::string line, key, value, newFileContent;

    try
    {
        if(myFile.is_open())
        {
            std::cout << "File opened "<< std::endl;
            std::lock_guard <std::mutex> lck(_mutex);

            while(getline(myFile, line))
            {
                std::istringstream linestream(line);
                    linestream >> key >> value;

                    if(key == "PlayerName:" && player_name != "")
                    {
                        //replace is playerName
                        line = "PlayerName: " + player_name;
                        std::cout << "PlayerName updated to " << player_name <<endl; 
                        fileEdited = true;
                    } else if(key == "PlayerHighScore:" && score != -1)
                    {
                        //update if player has a higher score
                        int currentPlayerScore = std::stoi(value);
                        std::cout << "Player current score " << currentPlayerScore << std::endl;
                        if(currentPlayerScore < score){
                            line = "PlayerHighScore: " + std::to_string(score);
                            fileEdited = true;
                            std::cout << "PlayerHighScore updated to " << score <<endl; 
                        }
                    } 
                    newFileContent += line + "\n"; 
                  
            }
        }else{
            std::cout << "File cannot Open!!" << std::endl;
            return;
        }
    }catch( const ifstream::failure &e){
        std::cout << "Error during file openning " << std::endl;
        return;
    }

    myFile.close();

    if(fileEdited)
    {
        std::ofstream outFile;
        try{
        outFile.open(Player::path);
        if(outFile){
            std::lock_guard <std::mutex> lck(_mutex);
            outFile << newFileContent << std::endl;
            outFile.close();
        }else{
            std::cout << "Unable to open output file" <<std::endl;
        }
        } catch( const ofstream::failure &e){
            std::cout << "Error during file openning " << std::endl;
        }
    }
}
