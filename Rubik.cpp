#include <iostream>
#include <vector>
#include "cubeSolve.h"


using namespace std;


int main()
{
    
    // Initialize the cube faces
    vector<char> front = {
        'b', 'y', 'w',
        'b', 'g', 'w',
        'w', 'r', 'y'
    };

    vector<char> back = {
        'o', 'w', 'g',
        'r', 'b', 'y',
        'r', 'g', 'o'
    };

    vector<char> left = {
        'y', 'o', 'o',
        'b', 'r', 'o',
        'w', 'y', 'b'
    };

    vector<char> right = {
        'r', 'y', 'g',
        'r', 'o', 'b',
        'r', 'b', 'w'
    };

    vector<char> up = {
        'r', 'g', 'y',
        'w', 'y', 'o',
        'y', 'g', 'b'
    };

    vector<char> down = {
        'o', 'g', 'b',
        'r', 'w', 'w',
        'g', 'o', 'g'
    };

    // Create a vector to store all cube faces
    vector<vector<char>> cubefaces = { front, back, left, right, up, down };

    cubeSolve solution;
    solution.setCube(cubefaces);
    solution.solveWhiteCross();
    cout << endl;
    solution.solveFirstLayer();

}

