
/*
	scenario:
	Imagine you are hired as a software developer at a music streaming company. The company 
	wants you to design a Playlist Manager that allows users to organize and control their 
	music in a simple way. Since users often want to move back and forth between songs, you 
	have been asked to implement this system using a Doubly Linked List. In this setup, every 
	node will represent a song and store the following information:
•	SongID (an integer for uniquely identifying the song)
•	SongName (a string for the title of the song)
•	Duration (a float representing the length of the song in minutes)

Your program should provide the following features:
7.	Add a new song at the end of the playlist. Users should be able to add unlimited songs, 
	and each one must be linked correctly in both directions.
8.	Delete a song by name if the user wants to remove it from the playlist. This requires 
	careful handling of links because the song could be at the beginning, middle, or end.
9.	Play Next and Play Previous – The user should be able to move forward to the next song or 
	backward to the previous song seamlessly. This simulates pressing the “Next” or “Back” 
	button in real music players.
10.	Shuffle (Reverse) Playlist – Users often like to shuffle their playlists. In this system,
	instead of random shuffling, you must implement a function that reverses the playlist 
	order using the doubly linked list. This requires reassigning all next and previous 
	pointers.
11.	Display the playlist – Show all songs with their ID, Name, and Duration in order.
*/


// implementation of Linked List is not included in the solution,download the required 
// linkedlist header file from the implementation section in order to compile the code, 
// it is prelinked in required file 
#include "playlistManager.h"
#include "song.h"
#include <iostream>
#include <string>
using namespace std;

void showMenu()
{
	cout << endl
		<< "=== Music Playlist Manager ===" << endl
		<< "1. Add Song at End" << endl
		<< "2. Delete Song by Name" << endl
		<< "3. Play Next Song" << endl
		<< "4. Play Previous Song" << endl
		<< "5. Shuffle (Reverse) Playlist" << endl
		<< "6. Display Playlist Details" << endl
		<< "7. Exit Application" << endl;
}

int main()
{
	PlaylistManager manager;
	int choice;

	do {
		showMenu();
		cout << "Enter your choice: ";
		cin >> choice;
		cin.clear();
		cin.ignore(100, '\n');

		switch (choice)
		{
		case 1:
		{
			int id;
			string name;
			float duration;

			cout << "Enter Unique Song ID: ";
			cin >> id;
			cin.clear();
			cin.ignore(100, '\n');

			cout << "Enter Song Title Name: ";
			getline(cin, name);

			cout << "Enter Song Duration (mins): ";
			cin >> duration;
			cin.clear();
			cin.ignore(100, '\n');

			manager.addSong(Song(id, name, duration));
			cout << "Song successfully added to the track listing!" << endl;
			break;
		}
		case 2:
		{
			string name;
			cout << "Enter Song Title to remove: ";
			getline(cin, name);
			manager.removeSongByName(name);
			break;
		}
		case 3:
			manager.playNext();
			break;
		case 4:
			manager.playPrevious();
			break;
		case 5:
			manager.shufflePlaylist();
			cout << "Playlist successfully inverted!" << endl;
			break;
		case 6:
			cout << endl;
			cout << "--- Current Track Queue ---" << endl;
			manager.displayPlaylist();
			break;
		case 7:
			cout << "Program terminating." << endl;
			break;
		default:
			cout << "Invalid input!" << endl;
		}
	} while (choice != 7);

	return 0;
}