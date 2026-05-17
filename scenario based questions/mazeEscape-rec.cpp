/*
    Imagine a rat placed at the starting point (0,0) of a maze represented as a grid (matrix).
    The maze contains open paths (1) and blocked paths (0). The rat can only move down or right 
    at each step. The goal is to find a path for the rat to reach the destination (n-1, n-1) 
    using recursion. Your task is to implement a recursive function in C++ that explores 
    possible moves, marking the path taken, and backtracking if a dead end is encountered.
    The recursive logic works as follows:
    •	If the current cell is outside the maze boundaries or blocked, return false.
    •	If the current cell is the destination, return true.
    •	Otherwise, move recursively either right or down and check if a path exists.
    •	If a move doesn’t lead to a solution, backtrack by unmarking the current cell and 
        try another path.
    This problem not only demonstrates recursion but also introduces the concept of backtracking, 
    where the algorithm explores possible solutions and undoes steps when they lead to failure.
    Example Input Maze (4×4): 
    1 0 0 0
    1 1 0 1
    0 1 0 0
    1 1 1 1
*/

#include <iostream>
using namespace std;

bool solveMazeRecursive(int maze[][4], int solution[][4], int maxRows, int maxCols, int row = 0, int col = 0);
void printMatrix(int matrix[][4], int maxRows);

int main()
{
    const int rows = 4;
    const int cols = 4;

    int maze[rows][cols] =
    {
        {1, 0, 0, 0},
        {1, 1, 0, 1},
        {0, 1, 0, 0},
        {1, 1, 1, 1}
    };

    int solution[rows][cols] =
    {
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0}
    };

    cout << "Input Maze:" << endl;
    printMatrix(maze, rows);
    cout << "-----------------" << endl;

    if (solveMazeRecursive(maze, solution, rows, cols))
    {
        cout << "Path Found! Output Solution Matrix (1 shows the path):" << endl;
        printMatrix(solution, rows);
    }
    else
        cout << "No valid path exists for this maze." << endl;

    return 0;
}

bool solveMazeRecursive(int maze[][4], int solution[][4], int maxRows, int maxCols, int row, int col) 
{
    // Base Case: Outside boundaries or hit a blocked path (0)
    if (row >= maxRows || col >= maxCols || maze[row][col] == 0)
        return false;

    // Base Case: Reached the destination
    if (row == maxRows - 1 && col == maxCols - 1) 
    {
        solution[row][col] = 1;
        return true;
    }

    solution[row][col] = 1;

    // Recursive Logic: Move Right
    if (solveMazeRecursive(maze, solution, maxRows, maxCols, row, col + 1))
        return true;

    // Recursive Logic: Move Down
    if (solveMazeRecursive(maze, solution, maxRows, maxCols, row + 1, col)) 
        return true;

    // Backtracking: If neither move works, unmark this cell and turn back
    solution[row][col] = 0;
    return false;
}

void printMatrix(int matrix[][4], int maxRows) 
{
    for (int i = 0; i < maxRows; i++) 
    {
        for (int j = 0; j < 4; j++) 
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

