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
    solution.solveThirdLayerEdges();

    // -1 if nothing has done
    // 0 if white cross done
    // 1 if white layer solved
    // 2 if second layer solved
}

