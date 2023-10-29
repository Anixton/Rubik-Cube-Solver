#include <iostream>
#include <vector>
#include "cubeSolve.h"


using namespace std;


int main()
{
    
    // Initialize the cube faces
    vector<char> front = {
        'o', 'g', 'r',
        'o', 'g', 'r',
        'r', 'w', 'g'
    };

    vector<char> back = {
        'b', 'o', 'o',
        'b', 'b', 'o',
        'w', 'w', 'y'
    };

    vector<char> left = {
        'b', 'r', 'w',
        'b', 'r', 'y',
        'o', 'w', 'b'
    };

    vector<char> right = {
        'g', 'r', 'y',
        'w', 'o', 'y',
        'w', 'g', 'b'
    };

    vector<char> up = {
        'y', 'g', 'r',
        'y', 'y', 'b',
        'g', 'y', 'y'
    };

    vector<char> down = {
        'w', 'o', 'r',
        'b', 'w', 'r',
        'g', 'g', 'o'
    };

    // Create a vector to store all cube faces
    vector<vector<char>> cubefaces = { front, back, left, right, up, down };

    cubeSolve solution;
    solution.setCube(cubefaces);
    solution.solveWhiteCross();
    cout << endl;
    solution.solveFirstLayer();
    cout << endl;
    solution.solveSecondLayer();

}

