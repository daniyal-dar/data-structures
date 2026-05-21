#pragma once
#include <iostream>
#include <string>
using namespace std;

class Song
{
private:
	int SongID;         // unique identifier
	string SongName;    // title of the song
	float Duration;     // length in minutes

public:
	Song();                                   // default constructor
	Song(int id, string name, float duration); // parameterized constructor
	int getSongID() const;                    // getter for SongID
	string getSongName() const;                // getter for SongName
	float getDuration() const;                 // getter for Duration

	friend ostream& operator<<(ostream& os, const Song& song); // overload << operator
	bool operator==(const Song& other);                        // equality check
};


Song::Song() : SongID(0), SongName(""), Duration(0.0f) {}
Song::Song(int id, string name, float duration) : SongID(id), SongName(name), Duration(duration) {}
int Song::getSongID() const { return SongID; }
string Song::getSongName() const { return SongName; }
float Song::getDuration() const { return Duration; }

ostream& operator<<(ostream& os, const Song& song)
{
	os << "SongID: " << song.SongID << " | Title: " << song.SongName << " | Duration: " << song.Duration << " mins";
	return os;
}

bool Song::operator==(const Song& other)
{
	if (other.SongID <= 0)
	{
		return this->SongName == other.SongName;
	}
	return this->SongID == other.SongID;
}