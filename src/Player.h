#ifndef PLAYER_H
#define PLAYER_H

#include<string>
#include<mutex>
#include<thread>
using namespace std;

class Player{
    public:
        Player();
        ~Player();

        //copy constructor
        Player (const Player &source);
        Player &operator=(const Player &source);

        //move constructor
        Player (Player &&source);
        Player &operator=(Player &&source);

        //setter
        void SetPlayerName(string name);
        void SetHighScore(int score);

        //getters
        string GetPlayerName()const;
        int GetHighScore()const;
        bool IsPlayerInfoSet()const;

        //create new player with Player name and score information
        void SendNewPlayerToFile(std::string, int);
        void UpdatePlayerInfo(std::string, int);

    private:
        std::string playerName{"Default Name"};
        int high_score{0};
        bool isPlayerInfoSet{false};
        const std::string path = "../src/files/playerInfo.txt";
        std::mutex _mutex;        
};

#endif
