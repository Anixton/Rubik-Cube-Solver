#include <iostream>
#include <vector>
#include "cubeSolve.h"


using namespace std;


int main()
{
    
    // Initialize the cube faces
    vector<char> front = {
        'b', 'g', 'w',
        'w', 'g', 'y',
        'b', 'b', 'y'
    };

    vector<char> back = {
        'y', 'g', 'w',
        'r', 'b', 'y',
        'g', 'w', 'o'
    };

    vector<char> left = {
        'r', 'r', 'o',
        'o', 'r', 'b',
        'g', 'y', 'o'
    };

    vector<char> right = {
        'o', 'w', 'g',
        'r', 'o', 'b',
        'r', 'o', 'r'
    };

    vector<char> up = {
        'b', 'r', 'r',
        'w', 'y', 'g',
        'y', 'y', 'g'
    };

    vector<char> down = {
        'w', 'o', 'b',
        'b', 'w', 'g',
        'y', 'o', 'w'
    };

    // Create a vector to store all cube faces
    vector<vector<char>> cubefaces = { front, back, left, right, up, down };

    cubeSolve solution;
    solution.setCube(cubefaces);
    


}

