#pragma once
#include <iostream>
#include <string>
using namespace std;

class Player
{
private:
    int PlayerID;     // unique identifier for each player
    int Score;        // tracks player's points

public:
    Player();                                   // default constructor
    Player(int id, int score);                  // parameterized constructor
    int getPlayerID() const;                    // getter for PlayerID
    int getScore() const;                       // getter for Score
    void updateScore(int points);               // adds points to score

    friend ostream& operator<<(ostream& os, const Player& player); // overload << operator
    bool operator==(const Player& other);                          // equality based on PlayerID
};

Player::Player() : PlayerID(0), Score(0) {}

Player::Player(int id, int score) : PlayerID(id), Score(score) {}

int Player::getPlayerID() const { return PlayerID; }

int Player::getScore() const { return Score; }

void Player::updateScore(int points) { Score += points; }

ostream& operator<<(ostream& os, const Player& player)
{
    os << "Player ID: " << player.PlayerID << " | Score: " << player.Score;
    return os;
}

bool Player::operator==(const Player& other)
{
    return this->PlayerID == other.PlayerID;
}