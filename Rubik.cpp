#include <iostream>
#include <vector>
#include "cubeSolve.h"

using namespace std;


int main()
{
    
    // Initialize the cube faces
    vector<char> front = {
        'w', 'b', 'w',
        'o', 'g', 'y',
        'y', 'b', 'o'
    };

    vector<char> back = {
        'y', 'g', 'b',
        'g', 'b', 'w',
        'g', 'w', 'r'
    };

    vector<char> left = {
        'r', 'w', 'r',
        'r', 'r', 'g',
        'w', 'y', 'g'
    };

    vector<char> right = {
        'o', 'r', 'b',
        'o', 'o', 'w',
        'b', 'y', 'y'
    };

    vector<char> up = {
        'y', 'r', 'o',
        'b', 'y', 'b',
        'g', 'y', 'g'
    };

    vector<char> down = {
        'o', 'o', 'w',
        'r', 'w', 'g',
        'b', 'o', 'r'
    };

    // Create a vector to store all cube faces
    vector<vector<char>> cubefaces = { front, back, left, right, up, down };

    cubeSolve solution;
    solution.setCube(cubefaces);
    solution.solveMyCube();
    
}

/*
    To Do:
    2) Add necessary comments
    3) Write documentation and explanation of the code using Microsoft Word
    4) Display your project in Resume (Don't forget to update your Resume)
*/




