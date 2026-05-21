// implementation of Linked List is not included in the solution,download the required 
// linkedlist header file from the implementation section in order to compile the code, 
// it is prelinked in required file 

#pragma once
#include "linkedList-doubly.h"
#include "movie.h"
#include <string>
#include <iostream>
using namespace std;

class WatchlistManager
{
private:
    LinkedList<Movie> watchlist;
    int movieCount;
    int currentMovieID;     // Tracks currently playing movie

public:
    WatchlistManager();
    void addMovie(Movie m);
    void removeMovieByName(string name);
    Movie findHighestRatedMovie();
    void playNext();
    void playPrevious();
    void displayWatchlist();
    void reverseWatchlist();
};

WatchlistManager::WatchlistManager()
{
    movieCount = 0;
    currentMovieID = -1; // -1 means no movie is currently playing
}

// Add Movie at End
void WatchlistManager::addMovie(Movie m)
{
    watchlist.insertAtTail(m);
    movieCount++;
    if (currentMovieID == -1)
        currentMovieID = m.getMovieID(); // Set first added movie as playing
}

// Remove Movie by Name
void WatchlistManager::removeMovieByName(string name)
{
    Movie tempMovie(0, name, 0.0f);
    if (watchlist.deleteByValue(tempMovie))
    {
        movieCount--;
        if (movieCount == 0)
            currentMovieID = -1;
    }
}

// Find Highest Rated Movie
Movie WatchlistManager::findHighestRatedMovie()
{
    if (watchlist.isEmpty())
    {
        cout << "Watchlist is empty!" << endl;
        return Movie();
    }

    Movie highestRated = watchlist.deleteFromHead();
    watchlist.insertAtTail(highestRated);

    for (int i = 0; i < movieCount - 1; i++)
    {
        Movie current = watchlist.deleteFromHead();

        if (current.getRating() > highestRated.getRating()) {
            highestRated = current;
        }

        watchlist.insertAtTail(current);
    }

    return highestRated;
}

// Play Next
void WatchlistManager::playNext()
{
    if (watchlist.isEmpty()) 
    {
        cout << "Watchlist is empty!" << endl;
        return;
    }

    bool foundCurrent = false;
    int nextMovieID = -1;
    string nextMovieName = "";

    // Rotate through everything to find who follows our current ID
    for (int i = 0; i < movieCount; i++) 
    {
        Movie current = watchlist.deleteFromHead();

        if (foundCurrent && nextMovieID == -1) 
        {
            nextMovieID = current.getMovieID();
            nextMovieName = current.getMovieName();
        }

        if (current.getMovieID() == currentMovieID)
            foundCurrent = true;

        watchlist.insertAtTail(current);
    }

    if (nextMovieID != -1) 
    {
        currentMovieID = nextMovieID;
        cout << "Now Playing Next Movie: " << nextMovieName << endl;
    }
    else
        cout << "Already at the end of your watchlist. No next movie available." << endl;
}

// Play Previous
void WatchlistManager::playPrevious()
{
    if (watchlist.isEmpty()) 
    {
        cout << "Watchlist is empty!" << endl;
        return;
    }

    int previousMovieID = -1;
    string previousMovieName = "";
    int targetPrevID = -1;
    string targetPrevName = "";

    for (int i = 0; i < movieCount; i++) 
    {
        Movie current = watchlist.deleteFromHead();

        if (current.getMovieID() == currentMovieID) 
        {
            targetPrevID = previousMovieID;
            targetPrevName = previousMovieName;
        }

        previousMovieID = current.getMovieID();
        previousMovieName = current.getMovieName();

        watchlist.insertAtTail(current);
    }

    if (targetPrevID != -1) 
    {
        currentMovieID = targetPrevID;
        cout << "Now Playing Previous Movie: " << targetPrevName << endl;
    }
    else
        cout << "Already at the beginning of your watchlist. No previous movie available." << endl;
}

void WatchlistManager::displayWatchlist() 
{
    watchlist.display();
}

void WatchlistManager::reverseWatchlist() 
{
    watchlist.reverseLL();
}