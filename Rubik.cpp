#include <iostream>
#include <vector>
#include "cubeSolve.h"


using namespace std;


int main()
{
    
    // Initialize the cube faces
    vector<char> front = {
        'w', 'b', 'g',
        'g', 'g', 'w',
        'r', 'y', 'w'
    };

    vector<char> back = {
        'w', 'w', 'r',
        'y', 'b', 'r',
        'y', 'g', 'o'
    };

    vector<char> left = {
        'y', 'w', 'r',
        'w', 'r', 'o',
        'y', 'r', 'b'
    };

    vector<char> right = {
        'y', 'o', 'g',
        'o', 'o', 'o',
        'o', 'y', 'g'
    };

    vector<char> up = {
        'b', 'g', 'o',
        'b', 'y', 'b',
        'g', 'r', 'r'
    };

    vector<char> down = {
        'w', 'r', 'b',
        'g', 'w', 'b',
        'b', 'y', 'o'
    };

    // Create a vector to store all cube faces
    vector<vector<char>> cubefaces = { front, back, left, right, up, down };

    cubeSolve solution;
    solution.setCube(cubefaces);
    solution.solveWhiteCross();

}

