
// implementation of Linked List is not included in the solution,download the required 
// linkedlist header file from the implementation section in order to compile the code, 
// it is prelinked in required file 
#pragma once
#include "linkedListTailPTRonly-doubly.h" 
#include "player.h"
#include <iostream>
using namespace std;

class GameTurnManager
{
private:
    LinkedList<Player> turnCircle;  // generic list reused as a turn sequence
    int playerBudget;               // tracks the total number of active players

public:
    GameTurnManager();              // default constructor
    void addPlayer(Player p);       // inserts a new player into the turn rotation
    void removePlayer(int id);      // handles a player quitting mid-game
    void moveToNextTurn();          // cycles the current player to the end of the line
    void skipPlayer();              // skips the next player in the rotation sequence
    bool checkWinCondition();       // automatically evaluates if only one player remains
    void displayActiveTurn();       // prints who is currently allowed to take their turn
    void displayAllPlayers();       // prints the current queue state
};

GameTurnManager::GameTurnManager()
{
    playerBudget = 0;
}

// Add a new player
void GameTurnManager::addPlayer(Player p)
{
    turnCircle.insertAtTail(p);
    playerBudget++;
}

// Remove a player if they quit
void GameTurnManager::removePlayer(int id)
{
    Player target(id, 0);

    // Attempting to delete using your existing method
    if (turnCircle.deleteByValue(target))
    {
        playerBudget--;
        cout << "Player " << id << " has safely quit the game loop." << endl;
    }
    else
    {
        cout << "Player with ID " << id << " not found in active session." << endl;
    }
}

// Move to the next player's turn
void GameTurnManager::moveToNextTurn()
{
    if (turnCircle.isEmpty()) return;

    // Take the active player from the head and push them to the rear 
    Player finishedPlayer = turnCircle.deleteFromHead();
    turnCircle.insertAtTail(finishedPlayer);

    // Announce the upcoming player's active turn status
    displayActiveTurn();
}

// Skip a player
void GameTurnManager::skipPlayer()
{
    if (playerBudget <= 1)
    {
        cout << "Not enough players to execute a skip penalty." << endl;
        return;
    }

    // Move current player to the back so we can access the next one
    Player activePlayer = turnCircle.deleteFromHead();

    // Pull out the victim (the next player), show they are skipped
    Player skippedPlayer = turnCircle.deleteFromHead();
    cout << "Penalty Applied! Skipping Turn for Player ID: " << skippedPlayer.getPlayerID() << endl;

    // Put them both back in order at the tail of our line
    turnCircle.insertAtTail(skippedPlayer);
    turnCircle.insertAtTail(activePlayer);

    // Announce current state who is next up to bat
    displayActiveTurn();
}

// End game when only one player remains
bool GameTurnManager::checkWinCondition()
{
    if (playerBudget == 1)
    {
        // Cycle to grab the last remaining node object
        Player winner = turnCircle.deleteFromHead();
        cout << "\n====================================" << endl;
        cout << "GAME OVER! Only one player remains." << endl;
        cout << "Winner Details -> " << winner << endl;
        cout << "====================================" << endl;
        return true;
    }
    return false;
}

// Display whose turn it currently is
void GameTurnManager::displayActiveTurn()
{
    if (playerBudget == 0)
    {
        cout << "No players registered in the current match loop." << endl;
        return;
    }

    // Pull the active player from the front to read their data
    Player activePlayer = turnCircle.deleteFromHead();

    cout << "It's currently Player " << activePlayer.getPlayerID() << "'s turn." << endl;
    turnCircle.insertAtHead(activePlayer);
}

// Display all players
void GameTurnManager::displayAllPlayers()
{
    turnCircle.display();
}