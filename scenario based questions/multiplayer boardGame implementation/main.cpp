
/*
    scenario:
    Imagine you are tasked with designing the backend system of a multiplayer digital board 
    game (similar to Ludo or Monopoly). In this game, players take turns in a circular 
    manner—once the last player finishes their turn, the first player plays again. To 
    efficiently manage this rotation of turns, you must implement the system using a circular
    linked list where every node represents a player. Each node will store the following 
    details:
•	PlayerID (a unique integer for identifying each player)
•	Score (an integer keeping track of the player’s points during the game)

The game system must support the following operations:
1.	Add a new player → Insert a player into the circular list. The game can start with any 
    number of players, but new players can also join mid-game.
2.	Remove a player if they quit → Delete their node from the circular linked list. This 
    operation is tricky because the circular structure must remain intact (e.g., if the 
    current player quits, the turn should move seamlessly to the next one).
3.	Move to the next player’s turn → Shift control to the next node in the circle, 
    simulating how the game rotates turns.
4.	Skip a player → Sometimes a penalty is applied (e.g., missing a turn). The system should 
    be able to skip a player’s turn and continue the cycle.
5.	End game when only one player remains → As the game progresses, players may leave. The 
    system should automatically detect when only one node remains in the list, declare that 
    player as the winner, and terminate the game loop.

*/

// implementation of Linked List is not included in the solution,download the required 
// linkedlist header file from the implementation section in order to compile the code, 
// it is prelinked in required file 
#include "gameTurnManager.h"
#include "player.h"
#include <iostream>
using namespace std;

void showGameMenu()
{
    cout << endl << "=== Multiplayer Game Dashboard ===" << endl
        << "1. Register/Add Player" << endl
        << "2. Player Quits Game (Remove)" << endl
        << "3. Complete Turn (Move to Next)" << endl
        << "4. Apply Missed-Turn Penalty (Skip Next)" << endl
        << "5. Show Turn Queue Details" << endl
        << "6. Exit Game Session" << endl;
}

int main()
{
    GameTurnManager session;
    int choice;

    session.addPlayer(Player(101, 0));
    session.addPlayer(Player(102, 0));
    session.addPlayer(Player(103, 0));

    cout << "Game started with standard baseline players: 101, 102, 103." << endl;
    session.displayActiveTurn();

    do {
        if (session.checkWinCondition())
            break;

        showGameMenu();
        cout << "Enter your choice: ";
        cin >> choice;
        cin.clear();
        cin.ignore(100, '\n');

        switch (choice)
        {
        case 1:
        {
            int id, initialScore;
            cout << "Enter Unique Player ID: ";
            cin >> id;
            cout << "Enter Starting Score (default 0): ";
            cin >> initialScore;
            cin.clear();
            cin.ignore(100, '\n');

            session.addPlayer(Player(id, initialScore));
            cout << "Player successfully injected into live game rotation!" << endl;
            break;
        }
        case 2:
        {
            int id;
            cout << "Enter ID of the player who wants to leave: ";
            cin >> id;
            cin.clear();
            cin.ignore(100, '\n');

            session.removePlayer(id);
            break;
        }
        case 3:
            cout << "Shifting control mechanics..." << endl;
            session.moveToNextTurn();
            break;
        case 4:
            session.skipPlayer();
            break;
        case 5:
            cout << endl << "--- Active Rotational Queue ---" << endl;
            session.displayAllPlayers();
            break;
        case 6:
            cout << "Terminating program!" << endl;
            break;
        default:
            cout << "Invalid input." << endl;
        }
    } while (choice != 6);

    return 0;
}