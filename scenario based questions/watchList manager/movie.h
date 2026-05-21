#pragma once

#include<iostream>
using namespace std;

class Movie
{
private:
	int MovieID;		// unique identifier
	string MovieName;   // title of the movie
	float Rating;		// IMDb-style rating

public:
	Movie();									// default constructor
	Movie(int id, string name, float rating);	// parameterized constructor
	int getMovieID() const;						// getter for MovieID
	string getMovieName() const;				// getter for MovieName
	float getRating() const;					// getter for Rating

	friend ostream& operator<<(ostream& os, const Movie& movie); // overload << operator
	bool operator==(const Movie& other);						// equality check
};

Movie::Movie() 
	: MovieID(0), MovieName(""), Rating(0.0f) {}
Movie::Movie(int id, string name, float rating) 
	: MovieID(id), MovieName(name), Rating(rating) {}

int Movie::getMovieID() const { return MovieID; }
string Movie::getMovieName() const { return MovieName; }
float Movie::getRating() const { return Rating; }

ostream& operator<<(ostream& os, const Movie& movie)
{
	os << "MovieID: " << movie.MovieID << " | Title: " << movie.MovieName << " | Rating: " << movie.Rating;
	return os;
}

bool Movie::operator==(const Movie& other)
{
	if (other.MovieID <= 0) 
	{
		return this->MovieName == other.MovieName;
	}
	return this->MovieID == other.MovieID;
}