#include <iostream>
#include <vector>
#include "cubeSolve.h"


using namespace std;


int main()
{
    
    // Initialize the cube faces
    vector<char> front = {
        'b', 'w', 'g',
        'r', 'g', 'o',
        'w', 'o', 'o'
    };

    vector<char> back = {
        'o', 'g', 'o',
        'b', 'b', 'g',
        'y', 'w', 'g'
    };

    vector<char> left = {
        'b', 'o', 'y',
        'y', 'r', 'y',
        'w', 'g', 'r'
    };

    vector<char> right = {
        'w', 'b', 'g',
        'y', 'o', 'y',
        'b', 'b', 'r'
    };

    vector<char> up = {
        'y', 'r', 'y',
        'g', 'y', 'r',
        'r', 'r', 'o'
    };

    vector<char> down = {
        'b', 'b', 'w',
        'w', 'w', 'w',
        'r', 'o', 'g'
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


}

