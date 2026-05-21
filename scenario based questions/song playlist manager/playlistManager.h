
// implementation of Linked List is not included in the solution,download the required 
// linkedlist header file from the implementation section in order to compile the code, 
// it is prelinked in required file 
#pragma once
#include "linkedList-doubly.h"
#include "song.h"
#include <iostream>
#include <string>
using namespace std;

class PlaylistManager
{
private:
	LinkedList<Song> playlist;
	int songCount;      // tracks size safely
	int currentSongID;  // tracks playing song without indices

public:
	PlaylistManager();
	void addSong(Song s);
	void removeSongByName(string name);
	void playNext();
	void playPrevious();
	void displayPlaylist();
	void shufflePlaylist();
};

PlaylistManager::PlaylistManager()
{
	songCount = 0;
	currentSongID = -1;
}

// Add song at the end
void PlaylistManager::addSong(Song s)
{
	playlist.insertAtTail(s);
	songCount++;
	if (currentSongID == -1)
	{
		currentSongID = s.getSongID();
	}
}

// Remove song by name
void PlaylistManager::removeSongByName(string name)
{
	Song tempSong(0, name, 0.0f);
	if (playlist.deleteByValue(tempSong))
	{
		songCount--;
		if (songCount == 0)
		{
			currentSongID = -1;
		}
	}
}

// Play Next using treadmill rotation
void PlaylistManager::playNext()
{
	if (playlist.isEmpty())
	{
		cout << "Playlist is empty!" << endl;
		return;
	}

	bool foundCurrent = false;
	int nextSongID = -1;
	string nextSongName = "";

	for (int i = 0; i < songCount; i++)
	{
		Song current = playlist.deleteFromHead();

		if (foundCurrent && nextSongID == -1)
		{
			nextSongID = current.getSongID();
			nextSongName = current.getSongName();
		}

		if (current.getSongID() == currentSongID)
		{
			foundCurrent = true;
		}

		playlist.insertAtTail(current);
	}

	if (nextSongID != -1)
	{
		currentSongID = nextSongID;
		cout << "Now Playing Next Song: " << nextSongName << endl;
	}
	else
	{
		cout << "End of playlist reached. No next song available." << endl;
	}
}

// Play Previous using treadmill rotation
void PlaylistManager::playPrevious()
{
	if (playlist.isEmpty())
	{
		cout << "Playlist is empty!" << endl;
		return;
	}

	int previousSongID = -1;
	string previousSongName = "";
	int targetPrevID = -1;
	string targetPrevName = "";

	for (int i = 0; i < songCount; i++)
	{
		Song current = playlist.deleteFromHead();

		if (current.getSongID() == currentSongID)
		{
			targetPrevID = previousSongID;
			targetPrevName = previousSongName;
		}

		previousSongID = current.getSongID();
		previousSongName = current.getSongName();

		playlist.insertAtTail(current);
	}

	if (targetPrevID != -1)
	{
		currentSongID = targetPrevID;
		cout << "Now Playing Previous Song: " << targetPrevName << endl;
	}
	else
	{
		cout << "Beginning of playlist reached. No previous song available." << endl;
	}
}

void PlaylistManager::displayPlaylist()
{
	playlist.display();
}

void PlaylistManager::shufflePlaylist()
{
	playlist.reverseLL();
}