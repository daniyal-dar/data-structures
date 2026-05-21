/*
	scenario:
	Imagine you are working as a software developer for a video streaming platform. The 
	company wants you to build a Watchlist Manager so users can organize movies they want to 
	watch.
Since users frequently move forward and backward between movies, you are required to 
implement this system using a Doubly Linked List.
Each node in the list represents a movie and stores the following information:
•	MovieID (integer, unique identifier) 
•	MovieName (string, title of the movie) 
•	Rating (float, IMDb-style rating)

Your program must support the following operations:
1. Add Movie at End
Users should be able to add movies to the end of the watchlist. Each new movie must be 
properly linked in both directions.

2. Remove Movie by Name
Allow users to delete a movie by its name.
The movie may be:
•	At the beginning 
•	In the middle 
•	At the end 

3. Play Next &Play Previous
Users should be able to:
•	Move to the next movie 
•	Move to the previous movie 

4. Reverse Watchlist: Implement a function to reverse the entire watchlist using pointer
	manipulation (not by creating a new list).

5.  Display Watchlist :Print all movies in order showing MovieID , Movie Name Rating.

6.	Implement a function to find the highest-rated movie in the list
*/

// implementation of Linked List is not included in the solution,download the required 
// linkedlist header file from the implementation section in order to compile the code, 
// it is prelinked in required file 
#include "wishListManager.h"


void menu()
{
	cout << "1. Add Movie at End" << endl;
	cout << "2. Remove Movie by Name" << endl;
	cout << "3. Play Next" << endl;
	cout << "4. Play Previous" << endl;
	cout << "5. Reverse Watchlist" << endl;
	cout << "6. Display Watchlist" << endl;
	cout << "7. Find Highest-rated Movie" << endl;
	cout << "8. Exit" << endl;
}

int main()
{
	WatchlistManager manager;
	int choice;
	do {
		menu();
		cout << "Enter your choice: ";
		cin >> choice;
		cin.ignore(100, '\n');

		switch (choice)
		{
		case 1:
		{
			// Code to add movie at end
			int id;
			string name;
			float rating;

			cout << "Enter Movie ID: ";
			cin >> id;
			cin.ignore(100, '\n');

			cout << "Enter Movie Name: ";
			getline(cin, name);

			cout << "Enter Movie Rating: ";
			cin >> rating;
			cin.ignore(100, '\n');

			manager.addMovie(Movie(id, name, rating));
			cout << "Movie added successfully!" << endl;
			break;
		}
		case 2:
		{
			// Code to remove movie by name
			string name;
			cout << "Enter Movie Name to remove: ";
			getline(cin, name);
			manager.removeMovieByName(name);
			break;
		}
		case 3:
			// Code to play next movie
			manager.playNext();
			break;
		case 4:
			// Code to play previous movie
			manager.playPrevious();
			break;
		case 5:
			// Code to reverse watchlist
			manager.reverseWatchlist();
			cout << "Watchlist reversed successfully." << endl;
			break;
		case 6:
			// Code to display watchlist
			cout << "--- Current Watchlist ---" << endl;
			manager.displayWatchlist();
			break;
		case 7:
		{
			// Code to find highest-rated movie
			Movie highest = manager.findHighestRatedMovie();
			if (highest.getMovieID() != 0)
				cout << "Highest Rated Movie Details -> " << highest << endl;
			break;
		}
		case 8:
			cout << "Exiting the program." << endl;
			break;
		default:
			cout << "Invalid input! Try again." << endl;
		}
	} while (choice != 8);

	return 0;
}
