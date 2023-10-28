#include <iostream>
#include <vector>
#include "cubeSolve.h"


using namespace std;


int main()
{
    
    // Initialize the cube faces
    vector<char> front = {
        'g', 'o', 'o',
        'r', 'g', 'r',
        'r', 'y', 'g'
    };

    vector<char> back = {
        'b', 'y', 'o',
        'r', 'b', 'w',
        'o', 'o', 'b'
    };

    vector<char> left = {
        'y', 'g', 'w',
        'b', 'r', 'b',
        'w', 'b', 'y'
    };

    vector<char> right = {
        'b', 'w', 'r',
        'y', 'o', 'g',
        'r', 'w', 'g'
    };

    vector<char> up = {
        'g', 'g', 'w',
        'w', 'y', 'r',
        'r', 'g', 'y'
    };

    vector<char> down = {
        'b', 'b', 'y',
        'o', 'w', 'o',
        'o', 'y', 'w'
    };

    // Create a vector to store all cube faces
    vector<vector<char>> cubefaces = { front, back, left, right, up, down };

    cubeSolve solution;
    solution.setCube(cubefaces);
    solution.solveWhiteCross();
    cout << endl;
    //solution.solveFirstLayer();

}

