#pragma once


#include"stack-array.h"
#include<fstream>
#include<iostream>
using namespace std;


class Maze
{
private:
	int** map;
	int** solutionMatrix;
	int rows;
	int columns;
	Stack<string>path;


public:


	Maze(const int r, const int c) : rows(r), columns(c), path(r* c)
	{
		map = new int* [rows];
		for (int i = 0; i < rows; i++)
			map[i] = new int[columns];

		solutionMatrix = new int* [rows];
		for (int i = 0; i < rows; i++)
			solutionMatrix[i] = new int[columns]();
	}

	~Maze()
	{
		for (int i = 0; i < rows; i++)
			delete[] this->map[i];
		delete[] this->map;

		for (int i = 0; i < rows; i++)
			delete[] this->solutionMatrix[i];
		delete[] this->solutionMatrix;
	}

	void loadMaze(ifstream& obj)
	{
		for (int i = 0; i < this->rows; i++)
		{
			for (int j = 0; j < this->columns; j++)
			{
				if (!(obj >> map[i][j]))
					break;
			}
		}
	}

	void findPath()
	{
		int current_row = 0;
		int current_col = 0;

		markVisited(current_row, current_col); // marking 1st cell of the maze as visited
		solutionMatrix[current_row][current_col] = 1;

		while (current_row != rows - 1 || current_col != columns - 1)
		{
			if (isValid(current_row, current_col + 1)) // move right
			{
				path.push("right");
				current_col++;
				markVisited(current_row, current_col);
				solutionMatrix[current_row][current_col] = 1;
				cout << "moving right..." << endl;
			}
			else if (isValid(current_row - 1, current_col)) // move up
			{
				path.push("up");
				current_row--;
				markVisited(current_row, current_col);
				solutionMatrix[current_row][current_col] = 1;
				cout << "moving top..." << endl;
			}
			else if (isValid(current_row + 1, current_col)) // move down
			{
				path.push("down");
				current_row++;
				markVisited(current_row, current_col);
				solutionMatrix[current_row][current_col] = 1;
				cout << "moving bottom..." << endl;
			}
			else if (isValid(current_row, current_col - 1)) // move left
			{
				path.push("left");
				current_col--;
				markVisited(current_row, current_col);
				solutionMatrix[current_row][current_col] = 1;
				cout << "moving left..." << endl;
			}
			else 
			{
				if (path.isEmpty())
					return;

				solutionMatrix[current_row][current_col] = 0;

				string directionTaken = path.pop();

				if (directionTaken == "right")
				{
					current_col--;
					cout << "reversing Right ..." << endl;
				}
					
				else if (directionTaken == "up")
				{
					current_row++;
					cout << "reversing up ..." << endl;
				}
				else if (directionTaken == "left")
				{
					current_col++;
					cout << "reversing left ..." << endl;
				}

				else if (directionTaken == "down")
				{
					current_row--;
					cout << "reversing Down ..." << endl;
				}

			}
		}
	}

	void displayMaze()
	{
		cout << endl
			<< "Showing maze:" << endl
			<< "Rows:" << rows << endl
			<< "Columns: " << columns << endl
			<< "Map: " << endl;

		for (int i = 0;i < rows;i++)
		{
			for (int j = 0;j < columns;j++)
			{
				cout << map[i][j] << " ";
			}
			cout << endl;
		}

		cout << "Path: ";
		if (path.isEmpty())
			cout << "nothing to show path is empty!" << endl << endl;
		else
			cout << path << endl << endl;
		
	}

	void displaySolution()
	{
		cout << endl
			<< "Showing solution matrix:" << endl
			<< "Rows:" << rows << endl
			<< "Columns: " << columns << endl
			<< "Map: " << endl;

		for (int i = 0;i < rows;i++)
		{
			for (int j = 0;j < columns;j++)
			{
				cout << solutionMatrix[i][j] << " ";
			}
			cout << endl;
		}

		cout << "Path: ";
		if (path.isEmpty())
			cout << "nothing to show path is empty!" << endl << endl;
		else
			cout << path << endl << endl;
	}

	void saveSolution(ofstream& output)
	{
		for (int i = 0; i < rows;i++)
		{
			for (int j = 0;j < columns;j++)
			{
				output << solutionMatrix[i][j] << " ";
			}
			output << endl;
		}
		output << path;
	}

	bool isValid(int r, int c)
	{
		if (r >= 0 && r < rows && c >= 0 && c < columns)
		{
			if (map[r][c] == 1)
			{
				return true;
			}
		}
		return false;
	}

	void markVisited(int r, int c)
	{
		this->map[r][c] = -1;
	}

	int getRows() { return this->rows; }
	int getColumns() { return this->columns; }
};
