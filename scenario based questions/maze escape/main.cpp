// note* before compiling this code download and paste the stack-array
// header file in the same directory as this file

#include"Maze.h"

int main()
{
	int rows;
	int columns;
	ifstream inputfile("input.txt");

	if (!inputfile.is_open())
	{
		cout << "File not found!" << endl;
		return 0;
	}

	inputfile >> rows;
	inputfile >> columns;

	Maze game(rows, columns);
	game.loadMaze(inputfile);
	inputfile.close();
	game.displayMaze();
	game.findPath();
	game.displaySolution();

	ofstream outputfile("output.txt");
	game.saveSolution(outputfile);
	outputfile.close();

	return 0;
}
