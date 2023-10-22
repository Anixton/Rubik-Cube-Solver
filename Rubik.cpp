#include <iostream>
#include <vector>
#include "cubeSolve.h"


using namespace std;


int main()
{
    
    // Initialize the cube faces
    vector<char> front = {
        'g', 'g', 'g',
        'g', 'g', 'g',
        'g', 'g', 'g'
    };

    vector<char> back = {
        'b', 'b', 'b',
        'b', 'b', 'b',
        'b', 'b', 'b'
    };

    vector<char> left = {
        'r', 'r', 'r',
        'r', 'r', 'r',
        'r', 'r', 'r'
    };

    vector<char> right = {
        'o', 'o', 'o',
        'o', 'o', 'o',
        'o', 'o', 'o'
    };

    vector<char> up = {
        'y', 'y', 'y',
        'y', 'y', 'y',
        'y', 'y', 'y'
    };

    vector<char> down = {
        'w', 'w', 'w',
        'w', 'w', 'w',
        'w', 'w', 'w'
    };

    // Create a vector to store all cube faces
    vector<vector<char>> cubefaces = { front, back, left, right, up, down };

    


}

