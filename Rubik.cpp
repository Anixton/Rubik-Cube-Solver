#include <iostream>
#include <vector>
#include "cubeSolve.h"


using namespace std;


int main()
{
    
    // Initialize the cube faces
    vector<char> front = {
        'g', 'y', 'r',
        'o', 'g', 'g',
        'y', 'g', 'g'
    };

    vector<char> back = {
        'r', 'g', 'r',
        'o', 'b', 'y',
        'o', 'b', 'y'
    };

    vector<char> left = {
        'b', 'r', 'o',
        'r', 'r', 'w',
        'r', 'o', 'o'
    };

    vector<char> right = {
        'w', 'y', 'y',
        'r', 'o', 'g',
        'y', 'w', 'w'
    };

    vector<char> up = {
        'w', 'w', 'g',
        'w', 'y', 'o',
        'w', 'b', 'g'
    };

    vector<char> down = {
        'b', 'y', 'o',
        'b', 'w', 'b',
        'b', 'r', 'b'
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
    cout << endl;
    solution.solveYellowCross();
    cout << endl;
    solution.solveYellowFace();
    cout << endl;
    solution.solveThirdLayerCorners();
    cout << endl;


}

