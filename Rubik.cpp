#include <iostream>
#include <vector>
#include "cubeSolve.h"


using namespace std;


int main()
{
    
    // Initialize the cube faces
    vector<char> front = {
        'g', 'w', 'g',
        'y', 'g', 'o',
        'b', 'w', 'g'
    };

    vector<char> back = {
        'b', 'r', 'y',
        'y', 'b', 'r',
        'g', 'g', 'y'
    };

    vector<char> left = {
        'b', 'r', 'o',
        'w', 'r', 'r',
        'b', 'o', 'w'
    };

    vector<char> right = {
        'y', 'g', 'w',
        'b', 'o', 'b',
        'w', 'o', 'o'
    };

    vector<char> up = {
        'r', 'g', 'o',
        'b', 'y', 'y',
        'w', 'b', 'r'
    };

    vector<char> down = {
        'r', 'o', 'r',
        'g', 'w', 'y',
        'o', 'w', 'y'
    };

    // Create a vector to store all cube faces
    vector<vector<char>> cubefaces = { front, back, left, right, up, down };

    cubeSolve solution;
    solution.setCube(cubefaces);
    solution.solveWhiteCross();
    cout << endl;
    //solution.solveFirstLayer();

}

