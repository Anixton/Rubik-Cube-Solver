#include <iostream>
#include <cstdlib>
#include "cubeSolve.h"


cubeSolve::cubeSolve()
{
    for (int i = 0; i < 9; i++)
    {
        front.push_back('g');
        back.push_back('b');
        up.push_back('y');
        down.push_back('w');
        right.push_back('o');
        left.push_back('r');
    }
    currentState = 0;
}

void cubeSolve::frontTurn() {

    vector<char> afterTurn(9);
    afterTurn[0] = front[6];
    afterTurn[1] = front[3];
    afterTurn[2] = front[0];
    afterTurn[3] = front[7];
    afterTurn[4] = front[4];
    afterTurn[5] = front[1];
    afterTurn[6] = front[8];
    afterTurn[7] = front[5];
    afterTurn[8] = front[2];

    char upLeft = up[6];
    char upMiddle = up[7];
    char upRight = up[8];

    up[6] = left[8];
    up[7] = left[5];
    up[8] = left[2];
    left[2] = down[0];
    left[5] = down[1];
    left[8] = down[2];
    down[0] = right[6];
    down[1] = right[3];
    down[2] = right[0];
    right[0] = upLeft;
    right[3] = upMiddle;
    right[6] = upRight;
    
    front = afterTurn;

}

void cubeSolve::reverseFrontTurn() {

    vector<char> afterTurn(9);
    afterTurn[0] = front[2];
    afterTurn[1] = front[5];
    afterTurn[2] = front[8];
    afterTurn[3] = front[1];
    afterTurn[4] = front[4];
    afterTurn[5] = front[7];
    afterTurn[6] = front[0];
    afterTurn[7] = front[3];
    afterTurn[8] = front[6];

    char upLeft = up[6];
    char upMiddle = up[7];
    char upRight = up[8];

    up[6] = right[0];
    up[7] = right[3];
    up[8] = right[6];
    right[0] = down[2];
    right[3] = down[1];
    right[6] = down[0];
    down[0] = left[2];
    down[1] = left[5];
    down[2] = left[8];
    left[2] = upRight;
    left[5] = upMiddle;
    left[8] = upLeft;

    front = afterTurn;
}

void cubeSolve::backTurn() {
    
    vector<char> afterTurn(9);
    afterTurn[0] = back[6];
    afterTurn[1] = back[3];
    afterTurn[2] = back[0];
    afterTurn[3] = back[7];
    afterTurn[4] = back[4];
    afterTurn[5] = back[1];
    afterTurn[6] = back[8];
    afterTurn[7] = back[5];
    afterTurn[8] = back[2];
    
    char upLeft = up[0];
    char upMiddle = up[1];
    char upRight = up[2];

    up[0] = right[2];
    up[1] = right[5];
    up[2] = right[8];
    right[2] = down[8];
    right[5] = down[7];
    right[8] = down[6];
    down[8] = left[6];
    down[7] = left[3];
    down[6] = left[0];
    left[0] = upRight;
    left[3] = upMiddle;
    left[6] = upLeft;

    back = afterTurn;
}

void cubeSolve::reverseBackTurn() {
    
    vector<char> afterTurn(9);
    afterTurn[0] = back[2];
    afterTurn[1] = back[5];
    afterTurn[2] = back[8];
    afterTurn[3] = back[1];
    afterTurn[4] = back[4];
    afterTurn[5] = back[7];
    afterTurn[6] = back[0];
    afterTurn[7] = back[3];
    afterTurn[8] = back[6];

    char upLeft = up[0];
    char upMiddle = up[1];
    char upRight = up[2];

    up[0] = left[6];
    up[1] = left[3];
    up[2] = left[0];
    left[0] = down[6];
    left[3] = down[7];
    left[6] = down[8];
    down[6] = right[8];
    down[7] = right[5];
    down[8] = right[2];
    right[8] = upRight;
    right[5] = upMiddle;
    right[2] = upLeft;

    back = afterTurn;
}

void cubeSolve::upTurn() {
    
    vector<char> afterTurn(9);
    afterTurn[0] = up[6];
    afterTurn[1] = up[3];
    afterTurn[2] = up[0];
    afterTurn[3] = up[7];
    afterTurn[4] = up[4];
    afterTurn[5] = up[1];
    afterTurn[6] = up[8];
    afterTurn[7] = up[5];
    afterTurn[8] = up[2];

    char frontLeft = front[0];
    char frontMiddle = front[1];
    char frontRight = front[2];

    front[0] = right[0];
    front[1] = right[1];
    front[2] = right[2];
    right[0] = back[0];
    right[1] = back[1];
    right[2] = back[2];
    back[0] = left[0];
    back[1] = left[1];
    back[2] = left[2];
    left[0] = frontLeft;
    left[1] = frontMiddle;
    left[2] = frontRight;

    up = afterTurn;
}

void cubeSolve::reverseUpTurn() {
    
    vector<char> afterTurn(9);
    afterTurn[0] = up[2];
    afterTurn[1] = up[5];
    afterTurn[2] = up[8];
    afterTurn[3] = up[1];
    afterTurn[4] = up[4];
    afterTurn[5] = up[7];
    afterTurn[6] = up[0];
    afterTurn[7] = up[3];
    afterTurn[8] = up[6];

    char frontLeft = front[0];
    char frontMiddle = front[1];
    char frontRight = front[2];

    front[0] = left[0];
    front[1] = left[1];
    front[2] = left[2];
    left[0] = back[0];
    left[1] = back[1];
    left[2] = back[2];
    back[0] = right[0];
    back[1] = right[1];
    back[2] = right[2];
    right[0] = frontLeft;
    right[1] = frontMiddle;
    right[2] = frontRight;

    up = afterTurn;
}

void cubeSolve::downTurn() {
    
    vector<char> afterTurn(9);
    afterTurn[0] = down[6];
    afterTurn[1] = down[3];
    afterTurn[2] = down[0];
    afterTurn[3] = down[7];
    afterTurn[4] = down[4];
    afterTurn[5] = down[1];
    afterTurn[6] = down[8];
    afterTurn[7] = down[5];
    afterTurn[8] = down[2];

    char frontLeft = front[6];
    char frontMiddle = front[7];
    char frontRight = front[8];

    front[6] = left[6];
    front[7] = left[7];
    front[8] = left[8];
    left[6] = back[6];
    left[7] = back[7];
    left[8] = back[8];
    back[6] = right[6];
    back[7] = right[7];
    back[8] = right[8];
    right[6] = frontLeft;
    right[7] = frontMiddle;
    right[8] = frontRight;

    down = afterTurn;
}

void cubeSolve::reverseDownTurn() {
   
    vector<char> afterTurn(9);
    afterTurn[0] = down[2];
    afterTurn[1] = down[5];
    afterTurn[2] = down[8];
    afterTurn[3] = down[1];
    afterTurn[4] = down[4];
    afterTurn[5] = down[7];
    afterTurn[6] = down[0];
    afterTurn[7] = down[3];
    afterTurn[8] = down[6];

    char frontLeft = front[6];
    char frontMiddle = front[7];
    char frontRight = front[8];

    front[6] = right[6];
    front[7] = right[7];
    front[8] = right[8];
    right[6] = back[6];
    right[7] = back[7];
    right[8] = back[8];
    back[6] = left[6];
    back[7] = left[7];
    back[8] = left[8];
    left[6] = frontLeft;
    left[7] = frontMiddle;
    left[8] = frontRight;

    down = afterTurn;
}

void cubeSolve::leftTurn() {
    
    vector<char> afterTurn(9);
    afterTurn[0] = left[6];
    afterTurn[1] = left[3];
    afterTurn[2] = left[0];
    afterTurn[3] = left[7];
    afterTurn[4] = left[4];
    afterTurn[5] = left[1];
    afterTurn[6] = left[8];
    afterTurn[7] = left[5];
    afterTurn[8] = left[2];

    char frontLeft = front[0];
    char frontMiddle = front[3];
    char frontRight = front[6];

    front[0] = up[0];
    front[3] = up[3];
    front[6] = up[6];
    up[6] = back[2];
    up[3] = back[5];
    up[0] = back[8];
    back[2] = down[6];
    back[5] = down[3];
    back[8] = down[0];
    down[0] = frontLeft;
    down[3] = frontMiddle;
    down[6] = frontRight;

    left = afterTurn;
}

void cubeSolve::reverseLeftTurn() {
    
    vector<char> afterTurn(9);
    afterTurn[0] = left[2];
    afterTurn[1] = left[5];
    afterTurn[2] = left[8];
    afterTurn[3] = left[1];
    afterTurn[4] = left[4];
    afterTurn[5] = left[7];
    afterTurn[6] = left[0];
    afterTurn[7] = left[3];
    afterTurn[8] = left[6];

    char frontLeft = front[0];
    char frontMiddle = front[3];
    char frontRight = front[6];

    front[0] = down[0];
    front[3] = down[3];
    front[6] = down[6];
    down[0] = back[8];
    down[3] = back[5];
    down[6] = back[2];
    back[2] = up[6];
    back[5] = up[3];
    back[8] = up[0];
    up[0] = frontLeft;
    up[3] = frontMiddle;
    up[6] = frontRight;

    left = afterTurn;
}

void cubeSolve::rightTurn() {
    
    vector<char> afterTurn(9);
    afterTurn[0] = right[6];
    afterTurn[1] = right[3];
    afterTurn[2] = right[0];
    afterTurn[3] = right[7];
    afterTurn[4] = right[4];
    afterTurn[5] = right[1];
    afterTurn[6] = right[8];
    afterTurn[7] = right[5];
    afterTurn[8] = right[2];

    char frontLeft = front[2];
    char frontMiddle = front[5];
    char frontRight = front[8];

    front[2] = down[2];
    front[5] = down[5];
    front[8] = down[8];
    down[2] = back[6];
    down[5] = back[3];
    down[8] = back[0];
    back[6] = up[2];
    back[3] = up[5];
    back[0] = up[8];
    up[2] = frontLeft;
    up[5] = frontMiddle;
    up[8] = frontRight;

    right = afterTurn;
}

void cubeSolve::reverseRightTurn() {
    
    vector<char> afterTurn(9);
    afterTurn[0] = right[2];
    afterTurn[1] = right[5];
    afterTurn[2] = right[8];
    afterTurn[3] = right[1];
    afterTurn[4] = right[4];
    afterTurn[5] = right[7];
    afterTurn[6] = right[0];
    afterTurn[7] = right[3];
    afterTurn[8] = right[6];

    char frontLeft = front[2];
    char frontMiddle = front[5];
    char frontRight = front[8];

    front[2] = up[2];
    front[5] = up[5];
    front[8] = up[8];
    up[2] = back[6];
    up[5] = back[3];
    up[8] = back[0];
    back[0] = down[8];
    back[3] = down[5];
    back[6] = down[2];
    down[2] = frontLeft;
    down[5] = frontMiddle;
    down[8] = frontRight;

    right = afterTurn;
}

bool cubeSolve::checkLayer(int a, vector<char> vec)
{
    char target = vec[4];
    if (vec[3 * (3 - a)] == target && vec[3 * (3 - a) + 1] == target && vec[3 * (3 - 1) + 2] == target)
    {
        return true;
    }
    return false;
}

void cubeSolve::decideCurrentState()
{
    if (down[1] != 'w' || down[3] != 'w' ||
        down[5] != 'w' || down[7] != 'w')
    {
        currentState = -1;
        return;
    }

    if (front[7] != front[4] || back[7] != back[4] ||
        left[7] != left[4] || right[7] != right[4])
    {
        currentState = -1;
        return;
    }

    currentState = 0;

    for (int i = 0; i < 9; i++)
    {
        if (down[i] != down[4])
        {
            return;
        }
    }
    
    for (int j = 6; j < 9; j++)
    {
        if (front[j] != front[4])
        {
            return;
        }

        if (left[j] != left[4])
        {
            return;
        }

        if (right[j] != right[4])
        {
            return;
        }

        if (back[j] != back[4])
        {
            return;
        }
    }

    currentState = 1;

    for (int secondLayerVariable = 3; secondLayerVariable < 6; secondLayerVariable++)
    {
        if (front[secondLayerVariable] != front[4])
        {
            return;
        }

        if (left[secondLayerVariable] != left[4])
        {
            return;
        }

        if (right[secondLayerVariable] != right[4])
        {
            return;
        }

        if (back[secondLayerVariable] != back[4])
        {
            return;
        }
    }

    currentState = 2;

    if (up[1] == up[4] && up[3] == up[4] && up[5] == up[4] && up[7] == up[4])
    {
        currentState = 3;
    }

    else
    {
        return;
    }


    if (up[0] == up[4] && up[2] == up[4] && up[6] == up[4] && up[8] == up[4])
    {
        currentState = 4;
    }

    else
    {
        return;
    }

    if (front[0] == front[4] && front[2] == front[4] && left[0] == left[4] && left[2] == left[4] &&
        back[0] == back[4] && back[2] == back[4] && right[0] == right[4] && right[2] == right[4])
    {
        currentState = 5;
    }

    else
    {
        return;
    }

    if (front[1] == front[4] && left[1] == left[4] && back[1] == back[4] && right[1] == right[4])
    {
        currentState = 6;
    }

    else
    {
        return;
    }
    
    

}

void cubeSolve::solveYellowCross()
{
    cout << "Solving the Yellow Cross:"<<endl;
    cout << "-----------------------------" << endl;

    int yellowCount = 0;

    if (up[1] == 'y')
    {
        yellowCount++;
    }
    if (up[3] == 'y')
    {
        yellowCount++;
    }
    if (up[5] == 'y')
    {
        yellowCount++;
    }
    if (up[7] == 'y')
    {
        yellowCount++;
    }

    if (yellowCount == 4)
    {
        cout << "Yellow Cross Already Solved!" << endl;
        cout << "-----------------------------" << endl;
        return;
    }

    if (yellowCount < 2)
    {
        cout << "F  U  R  U'  R'  F'" << endl;
        frontTurn();
        upTurn();
        rightTurn();
        reverseUpTurn();
        reverseRightTurn();
        reverseFrontTurn();
    }

    if (up[3] == 'y' && up[5] == 'y')
    {
        cout << "F  R  U  R'  U'  F'" << endl;
        frontTurn();
        rightTurn();
        upTurn();
        reverseRightTurn();
        reverseUpTurn();
        reverseFrontTurn();
        cout << "Second Layer Solved!" << endl;
        cout << "-----------------------------" << endl;
        return;
    }
    if (up[1] == 'y' && up[7] == 'y')
    {
        cout << "U F  R  U  R'  U'  F'" << endl;
        upTurn();
        frontTurn();
        rightTurn();
        upTurn();
        reverseRightTurn();
        reverseUpTurn();
        reverseFrontTurn();
        cout << "Second Layer Solved!" << endl;
        cout << "-----------------------------" << endl;
        return;
    }
    if (up[1] == 'y' && up[3] == 'y')
    {
        cout << "F  U  R  U'  R'  F'" << endl;
        frontTurn();
        upTurn();
        rightTurn();
        reverseUpTurn();
        reverseRightTurn();
        reverseFrontTurn();
        cout << "Yellow Cross Solved!" << endl;
        cout << "-----------------------------" << endl;
        return;
    }
    if (up[1] == 'y' && up[5] == 'y')
    {
        cout << "U' F  U  R  U'  R'  F'" << endl;
        reverseUpTurn();
        frontTurn();
        upTurn();
        rightTurn();
        reverseUpTurn();
        reverseRightTurn();
        reverseFrontTurn();
        cout << "Second Layer Solved!" << endl;
        cout << "-----------------------------" << endl;
        return;
    }
    if (up[3] == 'y' && up[7] == 'y')
    {
        cout << "U F  U  R  U'  R'  F'" << endl;
        upTurn();
        frontTurn();
        upTurn();
        rightTurn();
        reverseUpTurn();
        reverseRightTurn();
        reverseFrontTurn();
        cout << "Second Layer Solved!" << endl;
        cout << "-----------------------------" << endl;
        return;
    }
    if (up[5] == 'y' && up[7] == 'w')
    {
        // do F  U  R  U'  R'  F' from back
        cout << "B U L U' L' B'" << endl;
        backTurn();
        upTurn();
        leftTurn();
        reverseUpTurn();
        reverseLeftTurn();
        reverseBackTurn();
        cout << "Second Layer Solved!" << endl;
        cout << "-----------------------------" << endl;
        return;
    }
    
    cout << "U U F  U  R  U'  R'  F'" << endl;
    upTurn();
    upTurn();
    frontTurn();
    upTurn();
    rightTurn();
    reverseUpTurn();
    reverseRightTurn();
    reverseFrontTurn();
    cout << "Yellow Cross Solved!" << endl;
    cout << "-----------------------------" << endl;
    return;
}

void cubeSolve::solveYellowFace()
{
    int yellCount = 0;
    if (up[0] == 'y')
    {
        yellCount++;
    }
    if (up[2] == 'y')
    {
        yellCount++;
    }
    if (up[6] == 'y')
    {
        yellCount++;
    }
    if (up[8] == 'y')
    {
        yellCount++;
    }
    while (yellCount != 4)
    {
        if (yellCount == 2)
        {
            if (left[2] != 'y')
            {
                if (front[2] == 'y')
                {
                    cout << "U ";
                    upTurn();
                }
                else if (back[2] == 'y')
                {
                    cout << "U' ";
                    reverseUpTurn();
                }
                else
                {
                    cout << "U U ";
                    upTurn();
                    upTurn();
                }
            }
            cout << "R U R' U R U U R'" << endl;
            rightTurn();
            upTurn();
            reverseRightTurn();
            upTurn();
            rightTurn();
            upTurn();
            upTurn();
            reverseRightTurn();

            yellCount = 0;
        }

        if (yellCount == 1)
        {
            if (up[6] != 'y')
            {
                if (up[0] == 'y')
                {
                    reverseUpTurn();
                    cout << "U' ";
                }
                else if (up[8] == 'y')
                {
                    upTurn();
                    cout << "U ";
                }
                else
                {
                    upTurn();
                    upTurn();
                    cout << "U U ";
                }
            }
            cout << "R U R' U R U U R'" << endl;
            rightTurn();
            upTurn();
            reverseRightTurn();
            upTurn();
            rightTurn();
            upTurn();
            upTurn();
            reverseRightTurn();
        }

        if (yellCount == 0)
        {
            if (left[2] != 'y')
            {
                if (front[2] == 'y')
                {
                    cout << "U ";
                    upTurn();
                }
                else if (back[2] == 'y')
                {
                    cout << "U' ";
                    reverseUpTurn();
                }
                else
                {
                    cout << "U U ";
                    upTurn();
                    upTurn();
                }
            }
            cout << "R U R' U R U U R'" << endl;
            rightTurn();
            upTurn();
            reverseRightTurn();
            upTurn();
            rightTurn();
            upTurn();
            upTurn();
            reverseRightTurn();
        }

        yellCount = 0;

        if (up[0] == 'y')
        {
            yellCount++;
        }
        if (up[2] == 'y')
        {
            yellCount++;
        }
        if (up[6] == 'y')
        {
            yellCount++;
        }
        if (up[8] == 'y')
        {
            yellCount++;
        }
    }

    cout << endl;
    cout << "Yellow face solved!" << endl;
}
    
void cubeSolve::solveThirdLayerCorners()
{
    int count = 0;
    if (left[0] == left[4])
    {
        count++;
    }
    if (left[2] == left[4])
    {
        count++;
    }
    if (right[0] == right[4])
    {
        count++;
    }
    if (right[2] == right[4])
    {
        count++;
    }
    while (count != 4)
    {
        if (count >= 2)
        {
            // solve using algos
            // check front back left right for near 2 correct blocks
            // reverse front and back
            // reverse left and right
            if (front[0] == front[4] && front[2] == front[4])
            {
                cout << "L' B L' F F L B' L' F F L L U'";
                reverseLeftTurn();
                backTurn();
                reverseLeftTurn();
                frontTurn();
                frontTurn();
                leftTurn();
                reverseBackTurn();
                reverseLeftTurn();
                frontTurn();
                frontTurn();
                leftTurn();
                leftTurn();
                reverseUpTurn();
            }
            else if (back[0] == back[4] && back[2] == back[4])
            {
                cout << "R' F R' B B R F' R' B B R R U'";
                reverseRightTurn();
                frontTurn();
                reverseRightTurn();
                backTurn();
                backTurn();
                rightTurn();
                reverseFrontTurn();
                reverseRightTurn();
                backTurn();
                backTurn();
                rightTurn();
                rightTurn();
                reverseUpTurn();
            }
            else if (left[0] == left[4] && left[2] == left[4])
            {
                cout << "B' R B' L L B R' B' L L B B U'";
                reverseBackTurn();
                rightTurn();
                reverseBackTurn();
                leftTurn();
                leftTurn();
                backTurn();
                reverseRightTurn();
                reverseBackTurn();
                leftTurn();
                leftTurn();
                backTurn();
                backTurn();
                reverseUpTurn();
            }
            else if (right[0] == right[4] && right[2] == right[4])
            {
                cout << "F' L F' R R F L' F' R R F F U'";
                reverseFrontTurn();
                leftTurn();
                reverseFrontTurn();
                rightTurn();
                rightTurn();
                frontTurn();
                reverseLeftTurn();
                reverseFrontTurn();
                rightTurn();
                rightTurn();
                frontTurn();
                frontTurn();
                reverseUpTurn();
            }
            // we should check for diagnols after near blocks
            else if ((front[0] == front[4] && back[0] == back[4]) ||
                (front[2] == front[4] && back[2] == back[4]))
            {
                cout << "R' F R' B B R F' R' B B R R U'";
                reverseRightTurn();
                frontTurn();
                reverseRightTurn();
                backTurn();
                backTurn();
                rightTurn();
                reverseFrontTurn();
                reverseRightTurn();
                backTurn();
                backTurn();
                rightTurn();
                rightTurn();
                reverseUpTurn();

            }
            else if ((left[0] == left[4] && right[0] == right[4]) ||
                (left[2] == left[4] && right[2] == right[4]))
            {
                cout << "F' L F' R R F L' F' R R F F U'";
                reverseFrontTurn();
                leftTurn();
                reverseFrontTurn();
                rightTurn();
                rightTurn();
                frontTurn();
                reverseLeftTurn();
                reverseFrontTurn();
                rightTurn();
                rightTurn();
                frontTurn();
                frontTurn();
                reverseUpTurn();
            }
            else
            {
                cout << "ERROR: YOU SHOULDN'T BE HERE!" << endl;
            }
        }
        else
        {
            upTurn(); 
            count = 0;
            if (left[0] == left[4])
            {
                count++;
            }
            if (left[2] == left[4])
            {
                count++;
            }
            if (right[0] == right[4])
            {
                count++;
            }
            if (right[2] == right[4])
            {
                count++;
            }
            if (count >= 2)
            {
                cout << "U ";
                continue;
            }
            upTurn();
            count = 0;
            if (left[0] == left[4])
            {
                count++;
            }
            if (left[2] == left[4])
            {
                count++;
            }
            if (right[0] == right[4])
            {
                count++;
            }
            if (right[2] == right[4])
            {
                count++;
            }
            if (count >= 2)
            {
                cout << "U U ";
                continue;
            }
            upTurn();
            count = 0;
            if (left[0] == left[4])
            {
                count++;
            }
            if (left[2] == left[4])
            {
                count++;
            }
            if (right[0] == right[4])
            {
                count++;
            }
            if (right[2] == right[4])
            {
                count++;
            }
            if (count >= 2)
            {
                cout << "U' ";
                continue;
            }
            cout << "Line 775 You shouldn't be here" << endl;
        }
        count = 0;
        if (left[0] == left[4])
        {
            count++;
        }
        if (left[2] == left[4])
        {
            count++;
        }
        if (right[0] == right[4])
        {
            count++;
        }
        if (right[2] == right[4])
        {
            count++;
        }
    }
    cout << "Third Layer's Corners are solved !" << endl;
}

void cubeSolve::solveThirdLayerEdges()
{
    // check if its already solved
    // if not solved :
    // we should decide which direction to move
    // 
    if (front[1] == front[4] && left[1] == left[4]
        && right[1] == right[4] && back[1] == back[4])
    {
        cout << "Cube is solved siuuuuuuuu!" << endl;
        return;
    }
    int correctEdgeCount = 0;
    if (front[1] == front[4])
    {
        correctEdgeCount++;
    }
    if (left[1] == left[4])
    {
        correctEdgeCount++;
    }
    if (right[1] == right[4])
    {
        correctEdgeCount++;
    }
    if (back[1] == back[4])
    {
        correctEdgeCount++;
    }
    while (correctEdgeCount != 4)
    {
        if (front[1] == front[4])
        {
            // doing the algo from behind
            // if clockwise
            // B B U R L' B B R' L U B B
            // 
            // if counter clockwise
            // B B U' R L' B B R' L U' B B

            if (left[1] == back[4])
            {
                cout << "B B U R L' B B R' L U B B";
                backTurn();
                backTurn();
                upTurn();
                rightTurn();
                reverseLeftTurn();
                backTurn();
                backTurn();
                reverseRightTurn();
                leftTurn();
                upTurn();
                backTurn();
                backTurn();
            }
            else
            {
                cout << "B B U' R L' B B R' L U' B B";
                backTurn();
                backTurn();
                reverseUpTurn();
                rightTurn();
                reverseLeftTurn();
                backTurn();
                backTurn();
                reverseRightTurn();
                leftTurn();
                reverseUpTurn();
                backTurn();
                reverseBackTurn();
            }

        }
        else if (back[1] == back[4])
        {
            // if clockwise
            // F F U L R' F F L' R U F F
            // 
            // if counter clockwise
            // F F U' L R' F F L' R U' F F

            if (front[4] == right[1]) // do clockwise
            {
                cout << "F F U L R' F F L' R U F F";
                frontTurn();
                frontTurn();
                upTurn();
                leftTurn();
                reverseRightTurn();
                frontTurn();
                frontTurn();
                reverseLeftTurn();
                rightTurn();
                upTurn();
                frontTurn();
                frontTurn();
            }
            else
            {
                cout << "F F U' L R' F F L' R U' F F";
                frontTurn();
                frontTurn();
                reverseUpTurn();
                leftTurn();
                reverseRightTurn();
                frontTurn();
                frontTurn();
                reverseLeftTurn();
                rightTurn();
                reverseUpTurn();
                frontTurn();
                frontTurn();
            }
        }
        else if (left[1] == left[4])
        {
            // if clockwise
            // R R U F B' R R F' B U R R
            // 
            // if counter clockwise
            // R R U' F B' R R F' B U' R R

            if (right[1] == front[4])
            {
                cout << "R R U F B' R R F' B U R R";
                rightTurn();
                rightTurn();
                upTurn();
                frontTurn();
                reverseBackTurn();
                rightTurn();
                rightTurn();
                reverseFrontTurn();
                backTurn();
                upTurn();
                rightTurn();
                rightTurn();
            }
            else
            {
                cout << "R R U' F B' R R F' B U' R R";
                rightTurn();
                rightTurn();
                reverseUpTurn();
                frontTurn();
                reverseBackTurn();
                rightTurn();
                rightTurn();
                reverseFrontTurn();
                backTurn();
                reverseUpTurn();
                rightTurn();
                rightTurn();
            }
        }
        else if (right[1] == right[4])
        {
            // if clockwise
            // L L U B F' L L B' F U L L
            // if counter clockwise
            // L L U' B F' L L B' F U' L L

            if (front[1] == left[4])
            {
                cout << "L L U B F' L L B' F U L L";
                leftTurn();
                leftTurn();
                upTurn();
                backTurn();
                reverseFrontTurn();
                leftTurn();
                leftTurn();
                reverseBackTurn();
                frontTurn();
                upTurn();
                leftTurn();
                leftTurn();
            }
            else
            {
                cout << "L L U' B F' L L B' F U' L L";
                leftTurn();
                leftTurn();
                reverseUpTurn();
                backTurn();
                reverseFrontTurn();
                leftTurn();
                leftTurn();
                reverseBackTurn();
                frontTurn();
                reverseUpTurn();
                leftTurn();
                leftTurn();
            }
        }
        else
        {
            // doesnt matter if you do clockwise or 
            // counter clockwise 
            cout << "F F U L R' F F L' R U F F";
            frontTurn();
            frontTurn();
            upTurn();
            leftTurn();
            reverseRightTurn();
            frontTurn();
            frontTurn();
            reverseLeftTurn();
            rightTurn();
            upTurn();
            frontTurn();
            frontTurn();

        }
        correctEdgeCount = 0;
        if (front[1] == front[4])
        {
            correctEdgeCount++;
        }
        if (left[1] == left[4])
        {
            correctEdgeCount++;
        }
        if (right[1] == right[4])
        {
            correctEdgeCount++;
        }
        if (back[1] == back[4])
        {
            correctEdgeCount++;
        }
    }
    cout << endl;
    cout << "Cube is Solved!";
    
}

void cubeSolve::solveSecondLayer()
{
    int correctPieces = 0;

    if (front[5] == front[4] && right[3] == right[4])
    {
        correctPieces++;
    }
    
    if (front[3] == front[4] && left[5] == left[4])
    {
        correctPieces++;
    }

    if (back[5] == back[4] && left[3] == left[4])
    {
        correctPieces++;
    }

    if (back[3] == back[4] && right[5] == right[4])
    {
        correctPieces++;
    }

    while (correctPieces != 4)
    {
        if (front[1] == front[4] && up[7] != up[4])
        {
            // decide to move left or right
            if (up[7] == left[4])//left  U' L' U L U F U' F'
            {
                cout << "U' L' U L U F U' F'" << endl;
                reverseUpTurn();
                reverseLeftTurn();
                upTurn();
                leftTurn();
                upTurn();
                frontTurn();
                reverseUpTurn();
                reverseFrontTurn();
            }
            else if (up[7] == right[4])// right U R U' R' U' F' U F
            {
                cout << "U R U' R' U' F' U F" << endl;
                upTurn();
                rightTurn();
                reverseUpTurn();
                reverseRightTurn();
                reverseUpTurn();
                reverseFrontTurn();
                upTurn();
                frontTurn();
            }
            else
            {
                cout << "ERROR 1189 YOU SHOULDN'T BE HERE" << endl;
            }
            correctPieces++;
        }

        else if (back[1] == back[4] && up[1] != up[4])
        {
            // decide to move left or right
            if (up[1] == right[4]) // left: U' L' U L U F U' F' from back
            {
                // U' R' U R U B' U' B'
                cout << "U' R' U R U B U' B'"<<endl;
                reverseUpTurn();
                reverseRightTurn();
                upTurn();
                rightTurn();
                upTurn();
                backTurn();
                reverseUpTurn();
                reverseBackTurn();
            }
            else if (up[1] == left[4]) // right: U R U' R' U' F' U F from back
            {
                // U L U' L' U' B' U B
                cout << "U L U' L' U' B' U B" << endl;
                upTurn();
                leftTurn();
                reverseUpTurn();
                reverseLeftTurn();
                reverseUpTurn();
                reverseBackTurn();
                upTurn();
                backTurn();
            }
            else
            {
                cout << "ERROR 1241 YOU SHOULDN'T BE HERE" << endl;
            }
            correctPieces++;
        }

        else if (left[1] == left[4] && up[3] != up[4])
        {
            // decide to move left or right
            if (up[3] == back[4]) // left: U' L' U L U F U' F' from left
            {
                // U' B' U B U L U' L
                cout << "U' B' U B U L U' L'" << endl;
                reverseUpTurn();
                reverseBackTurn();
                upTurn();
                backTurn();
                upTurn();
                leftTurn();
                reverseUpTurn();
                reverseLeftTurn();
            }
            else if (up[3] == front[4]) // right: U R U' R' U' F' U F from left
            {
                // U F U' F' U' L' U L
                cout << "U F U' F' U' L' U L" << endl;
                upTurn();
                frontTurn();
                reverseUpTurn();
                reverseFrontTurn();
                reverseUpTurn();
                reverseLeftTurn();
                upTurn();
                leftTurn();
            }
            else
            {
                cout << "ERROR 1277 YOU SHOULDN'T BE HERE" << endl;
            }
            correctPieces++;
        }

        else if (right[1] == right[4] && up[5] != up[4])
        {
            // decide to move left or right
            if (up[5] == front[4]) // left: U' L' U L U F U' F' from right
            {
                // U' F' U F U R U' R'
                cout << "U' F' U F U R U' R'" << endl;
                reverseUpTurn();
                reverseFrontTurn();
                upTurn();
                frontTurn();
                upTurn();
                rightTurn();
                reverseUpTurn();
                reverseRightTurn();
            }
            else if (up[5] == back[4]) // right: U R U' R' U' F' U F from right
            {
                // U B U' B' U' R' U R
                cout << "U B U' B' U' R' U R" << endl;
                upTurn();
                backTurn();
                reverseUpTurn();
                reverseBackTurn();
                reverseUpTurn();
                reverseRightTurn();
                upTurn();
                rightTurn();
            }
            else
            {
                cout << "ERROR 1313 YOU SHOULDN'T BE HERE" << endl;
            }
            correctPieces++;
        }

        else
        {
            // check if there is 
            // "correct piece in wrong position"
            // make turns to do upper conditions correct if possible
            // if not there is/are piece(s) in the wrong position
            if (left[1] == front[4] && up[3] != up[4])
            {
                cout << "U' ";
                reverseUpTurn();
            }

            else if (back[1] == left[4] && up[1] != up[4])
            {
                cout << "U' ";
                reverseUpTurn();
            }

            else if (right[1] == back[4] && up[5] != up[4])
            {
                cout << "U' ";
                reverseUpTurn();
            }

            else if (front[1] == right[4] && up[7] != up[4])
            {
                cout << "U' ";
                reverseUpTurn();
            }

            else if (left[1] == back[4] && up[3] != up[4])
            {
                cout << "U ";
                upTurn();
            }

            else if (back[1] == right[4] && up[1] != up[4])
            {
                cout << "U ";
                upTurn();
            }

            else if (right[1] == front[4] && up[5] != up[4])
            {
                cout << "U ";
                upTurn();
            }
            
            else if (front[1] == left[4] && up[7] != up[4])
            {
                cout << "U ";
                upTurn();
            }

            else if(left[1]==right[4] && up[3]!=up[4])
            {
                cout << "U U ";
                upTurn();
                upTurn();
            }

            else if (back[1] == front[4] && up[1] != up[4])
            {
                cout << "U U ";
                upTurn();
                upTurn();
            }

            else if (right[1] == left[4] && up[5] != up[4])
            {
                cout << "U U ";
                upTurn();
                upTurn();
            }

            else if (front[1] == back[4] && up[7] != up[4])
            {
                cout << "U U ";
                upTurn();
                upTurn();
            }

            else
            {
                // we need to get the wrong positioned piece out of its place
                // we have to check every corner
                
                if (front[5] != up[4] && right[3] != up[4]
                    && !(front[5] == front[4] && right[3] == right[4]))
                {
                    // do the algo
                    // front-> saða parçayý koyma algoritmasý
                    // U R U' R' U' F' U F
                    cout << "U R U' R' U' F' U F" << endl;
                    upTurn();
                    rightTurn();
                    reverseUpTurn();
                    reverseRightTurn();
                    reverseUpTurn();
                    reverseFrontTurn();
                    upTurn();
                    frontTurn();
                }

                else if (front[3] != up[4] && left[5] != up[4]
                    && !(front[3] == front[4] && left[5] == left[4]))
                {
                    // do the algo
                    // front-> sola parçayý koyma algoritmasý
                    // U' L' U L U F U' F'
                    cout << "U' L' U L U F U' F'" << endl;
                    reverseUpTurn();
                    reverseLeftTurn();
                    upTurn();
                    leftTurn();
                    upTurn();
                    frontTurn();
                    reverseUpTurn();
                    reverseFrontTurn();
                }
                // after this we will check from back

                else if (back[3] != up[4] && right[5] != up[4]
                    && !(back[3] == back[4] && right[5] == right[4]))
                {
                    // do the algo
                    // back-> sola parçayý koyma algoritmasý
                    // algorithm bellow has issue
                    cout << "U' R' U R U B U' B'" << endl;
                    reverseUpTurn();
                    reverseRightTurn();
                    upTurn();
                    rightTurn();
                    upTurn();
                    backTurn();
                    reverseUpTurn();
                    reverseBackTurn();
                }

                else if (back[5] != up[4] && left[3] != up[4]
                    && !(back[5] == back[4] && left[3] == left[4]))
                {
                    // do the algo
                    // back-> saða parçayý koyma algoritmasý
                    cout << "U L U' L' U' B' U B" << endl;
                    upTurn();
                    leftTurn();
                    reverseUpTurn();
                    reverseLeftTurn();
                    reverseUpTurn();
                    reverseBackTurn();
                    upTurn();
                    backTurn();
                }
                
                else
                {
                    cout << "Error: 1474 you shouldn't be here!" << endl;
                }
            }
        }

    }

    cout << endl;
    cout << "Second Layer Solved!" << endl;
}

void cubeSolve::solveFirstLayer()
{
    /* in order to place corner piece correctly
     the white side should be on the third layer
     and should'nt be on top*/

     // if(right[0]=='w' && up[8]==front[4] && front[2]==left[4])
     // do this algorithm for all sides
     // if(left[2]=='w' && up[6]==front[4] && front[0]==right[4])
     // do this algorithm for all sides

     // now we need to figure out how to place other corner pieces
     // to third layer correctly
     // possbile wrong places where the corner pieces can be:
     // 1) in wrong corner facing one of the front,back,left,right sides
     // 2) in wrong corner facing downward
     // 3) it may be in third layer but looking in wrong corner ->solved
     // 
     // 4) in up side of the cube
     // 4: put the white face on top of the empty corner and 
     // do: R U' R OR L' U L' (according to its place)
     //
     // 
     // add 4 boolean values 
     // isTopLeftSolved,isTopRightSolved,isBottomLeftSolved,isBottomRightSolved
     // if there is white face in the bottom but wrongly placed, do this
     // R U R'
     //


    int whiteCornerCount = 0;
    bool isTopLeftSolved = false;
    bool isTopRightSolved = false;
    bool isBottomLeftSolved = false;
    bool isBottomRightSolved = false;


    if (down[0] == down[4] && front[6] == front[4] && left[8] == left[4])
    {
        ++whiteCornerCount;
        isTopLeftSolved = true;
    }

    if (down[2] == down[4] && front[8] == front[4] && right[6] == right[4])
    {
        ++whiteCornerCount;
        isTopRightSolved = true;
    }

    if (down[6] == down[4] && left[6] == left[4] && back[8] == back[4])
    {
        ++whiteCornerCount;
        isBottomLeftSolved = true;
    }

    if (down[8] == down[4] && right[8] == right[4] && back[6] == back[4])
    {
        ++whiteCornerCount;
        isBottomRightSolved = true;
    }

    while (whiteCornerCount < 4)
    {
        // 1 left directions
        if (right[0] == 'w' && up[8] == front[4] && front[2] == left[4])
        {
            // L' U L
            reverseLeftTurn();
            upTurn();
            leftTurn();
            cout << "L' U L" << endl;
            ++whiteCornerCount;
            isTopLeftSolved = true;
        }

        else if (back[0] == 'w' && up[2] == right[4] && right[2] == front[4])
        {
            // F' U F
            reverseFrontTurn();
            upTurn();
            frontTurn();
            cout << "F' U F" << endl;
            ++whiteCornerCount;
            isTopRightSolved = true;
        }

        else if (left[0] == 'w' && up[0] == back[4] && back[2] == right[4])
        {
            // R' U R
            reverseRightTurn();
            upTurn();
            rightTurn();
            cout << "R' U R" << endl;
            ++whiteCornerCount;
            isBottomRightSolved = true;
        }

        else if (front[0] == 'w' && up[6] == left[4] && left[2] == back[4])
        {
            // B' U B
            reverseBackTurn();
            upTurn();
            backTurn();
            cout << "B' U B" << endl;
            ++whiteCornerCount;
            isBottomLeftSolved = true;
        }
        
        // 1 right directions
        else if (left[2] == 'w' && up[6] == front[4] && front[0] == right[4])
        {
            // R U' R'
            rightTurn();
            reverseUpTurn();
            reverseRightTurn();
            cout << "R U' R'" << endl;
            ++whiteCornerCount;
            isTopRightSolved = true;
        }

        else if (back[2] == 'w' && up[0] == left[4] && left[0] == front[4])
        {
            // F U' F'
            frontTurn();
            reverseUpTurn();
            reverseFrontTurn();
            cout << "F U' F'" << endl;
            ++whiteCornerCount;
            isTopLeftSolved = true;
        }

        else if (right[2] == 'w' && up[2] == back[4] && back[0] == left[4])
        {
            // L U' L'
            leftTurn();
            reverseUpTurn();
            reverseLeftTurn();
            cout << "L U' L'" << endl;
            ++whiteCornerCount;
            isBottomLeftSolved = true;
        }

        else if (front[2] == 'w' && up[8] == right[4] && right[0] == back[4])
        {
            // B U' B'
            backTurn();
            reverseUpTurn();
            reverseBackTurn();
            cout << "B U' B'" << endl;
            ++whiteCornerCount;
            isBottomRightSolved = true;
        }
        //2 step l-r directions
        // if we couldn't do any algorithms above and still have white side
        // in third layer we should do move U or U'
        // i'm thinking of an algorithm which turn U and checks the ifs above
        // if no correct piece then backtrack and turn U' check again
        // if no correct piece again then do U U and check
        // if still no correct piece then there is error.

        else
        {
            upTurn();
            // U case
            // 1 left directions
            if (right[0] == 'w' && up[8] == front[4] && front[2] == left[4])
            {
                // L' U L
                reverseLeftTurn();
                upTurn();
                leftTurn();
                cout << "U L' U L" << endl;
                ++whiteCornerCount;
                isTopLeftSolved = true;
                continue;
            }

            else if (back[0] == 'w' && up[2] == right[4] && right[2] == front[4])
            {
                // F' U F
                reverseFrontTurn();
                upTurn();
                frontTurn();
                cout << "U F' U F" << endl;
                ++whiteCornerCount;
                isTopRightSolved = true;
                continue;
            }

            else if (left[0] == 'w' && up[0] == back[4] && back[2] == right[4])
            {
                // R' U R
                reverseRightTurn();
                upTurn();
                rightTurn();
                cout << "U R' U R" << endl;
                ++whiteCornerCount;
                isBottomRightSolved = true;
                continue;
            }

            else if (front[0] == 'w' && up[6] == left[4] && left[2] == back[4])
            {
                // B' U B
                reverseBackTurn();
                upTurn();
                backTurn();
                cout << "U B' U B" << endl;
                ++whiteCornerCount;
                isBottomLeftSolved = true;
                continue;
            }

            // 1 right directions
            else if (left[2] == 'w' && up[6] == front[4] && front[0] == right[4])
            {
                // R U' R'
                rightTurn();
                reverseUpTurn();
                reverseRightTurn();
                cout << "U R U' R'" << endl;
                ++whiteCornerCount;
                isTopRightSolved = true;
                continue;
            }

            else if (back[2] == 'w' && up[0] == left[4] && left[0] == front[4])
            {
                // F U' F'
                frontTurn();
                reverseUpTurn();
                reverseFrontTurn();
                cout << "U F U' F'" << endl;
                ++whiteCornerCount;
                isTopLeftSolved = true;
                continue;
            }

            else if (right[2] == 'w' && up[2] == back[4] && back[0] == left[4])
            {
                // L U' L'
                leftTurn();
                reverseUpTurn();
                reverseLeftTurn();
                cout << "U L U' L'" << endl;
                ++whiteCornerCount;
                isBottomLeftSolved = true;
                continue;
            }

            else if (front[2] == 'w' && up[8] == right[4] && right[0] == back[4])
            {
                // B U' B'
                backTurn();
                reverseUpTurn();
                reverseBackTurn();
                cout << "U B U' B'" << endl;
                ++whiteCornerCount;
                isBottomRightSolved = true;
                continue;
            }

            reverseUpTurn();
            reverseUpTurn();
            // U' case
            // 
            // 1 left directions
            if (right[0] == 'w' && up[8] == front[4] && front[2] == left[4])
            {
                // L' U L
                reverseLeftTurn();
                upTurn();
                leftTurn();
                cout << "U' L' U L" << endl;
                ++whiteCornerCount;
                isTopLeftSolved = true;
                continue;
            }

            else if (back[0] == 'w' && up[2] == right[4] && right[2] == front[4])
            {
                // F' U F
                reverseFrontTurn();
                upTurn();
                frontTurn();
                cout << "U' F' U F" << endl;
                ++whiteCornerCount;
                isTopRightSolved = true;
                continue;
            }

            else if (left[0] == 'w' && up[0] == back[4] && back[2] == right[4])
            {
                // R' U R
                reverseRightTurn();
                upTurn();
                rightTurn();
                cout << "U' R' U R" << endl;
                ++whiteCornerCount;
                isBottomRightSolved = true;
                continue;
            }

            else if (front[0] == 'w' && up[6] == left[4] && left[2] == back[4])
            {
                // B' U B
                reverseBackTurn();
                upTurn();
                backTurn();
                cout << "U' B' U B" << endl;
                ++whiteCornerCount;
                isBottomLeftSolved = true;
                continue;
            }

            // 1 right directions
            else if (left[2] == 'w' && up[6] == front[4] && front[0] == right[4])
            {
                // R U' R'
                rightTurn();
                reverseUpTurn();
                reverseRightTurn();
                cout << "U' R U' R'" << endl;
                ++whiteCornerCount;
                isTopRightSolved = true;
                continue;
            }

            else if (back[2] == 'w' && up[0] == left[4] && left[0] == front[4])
            {
                // F U' F'
                frontTurn();
                reverseUpTurn();
                reverseFrontTurn();
                cout << "U' F U' F'" << endl;
                ++whiteCornerCount;
                isTopLeftSolved = true;
                continue;
            }

            else if (right[2] == 'w' && up[2] == back[4] && back[0] == left[4])
            {
                // L U' L'
                leftTurn();
                reverseUpTurn();
                reverseLeftTurn();
                cout << "U' L U' L'" << endl;
                ++whiteCornerCount;
                isBottomLeftSolved = true;
                continue;
            }

            else if (front[2] == 'w' && up[8] == right[4] && right[0] == back[4])
            {
                // B U' B'
                backTurn();
                reverseUpTurn();
                reverseBackTurn();
                cout << "U' B U' B'" << endl;
                ++whiteCornerCount;
                isBottomRightSolved = true;
                continue;
            }

            // U' U' case
            reverseUpTurn();
            // 1 left directions
            if (right[0] == 'w' && up[8] == front[4] && front[2] == left[4])
            {
                // L' U L
                reverseLeftTurn();
                upTurn();
                leftTurn();
                cout << "U' U' L' U L" << endl;
                ++whiteCornerCount;
                isTopLeftSolved = true;
                continue;
            }

            else if (back[0] == 'w' && up[2] == right[4] && right[2] == front[4])
            {
                // F' U F
                reverseFrontTurn();
                upTurn();
                frontTurn();
                cout << "U' U' F' U F" << endl;
                ++whiteCornerCount;
                isTopRightSolved = true;
                continue;
            }

            else if (left[0] == 'w' && up[0] == back[4] && back[2] == right[4])
            {
                // R' U R
                reverseRightTurn();
                upTurn();
                rightTurn();
                cout << "U' U' R' U R" << endl;
                ++whiteCornerCount;
                isBottomRightSolved = true;
                continue;
            }

            else if (front[0] == 'w' && up[6] == left[4] && left[2] == back[4])
            {
                // B' U B
                reverseBackTurn();
                upTurn();
                backTurn();
                cout << "U' U' B' U B" << endl;
                ++whiteCornerCount;
                isBottomLeftSolved = true;
                continue;
            }

            // 1 right directions
            else if (left[2] == 'w' && up[6] == front[4] && front[0] == right[4])
            {
                // R U' R'
                rightTurn();
                reverseUpTurn();
                reverseRightTurn();
                cout << "U' U' R U' R'" << endl;
                ++whiteCornerCount;
                isTopRightSolved = true;
                continue;
            }

            else if (back[2] == 'w' && up[0] == left[4] && left[0] == front[4])
            {
                // F U' F'
                frontTurn();
                reverseUpTurn();
                reverseFrontTurn();
                cout << "U' U' F U' F'" << endl;
                ++whiteCornerCount;
                isTopLeftSolved = true;
                continue;
            }

            else if (right[2] == 'w' && up[2] == back[4] && back[0] == left[4])
            {
                // L U' L'
                leftTurn();
                reverseUpTurn();
                reverseLeftTurn();
                cout << "U' U' L U' L'" << endl;
                ++whiteCornerCount;
                isBottomLeftSolved = true;
                continue;
            }

            else if (front[2] == 'w' && up[8] == right[4] && right[0] == back[4])
            {
                // B U' B'
                backTurn();
                reverseUpTurn();
                reverseBackTurn();
                cout << "U' U' B U' B'" << endl;
                ++whiteCornerCount;
                isBottomRightSolved = true;
                continue;
            }

            // we considered every case that includes third layer white piece
            // but what to do if there is no white piece in the third layer?
            // 
            // in up side of the cube
            // put the white face on top of the empty corner and 
            // do: R U' R OR L' U L' (according to its place)
            // TopLeft: R U R'
            // TopRight: L' U' L
            // BottomLeft: L' U L
            // BottomRight: R U' R'
            else
            {
                upTurn();
                upTurn();

                if (up[0] == 'w' && !isTopRightSolved)
                {
                    cout << "R U R'" << endl;
                    rightTurn();
                    upTurn();
                    reverseRightTurn();
                }

                else if (up[2] == 'w' && !isTopLeftSolved)
                {
                    cout << "L' U' L" << endl;
                    reverseLeftTurn();
                    reverseUpTurn();
                    leftTurn();
                }

                else if (up[6] == 'w' && !isTopLeftSolved)
                {
                    cout << "L' U L" << endl;
                    reverseLeftTurn();
                    upTurn();
                    leftTurn();
                }

                else if (up[8] == 'w' && !isTopRightSolved)
                {
                    cout << "R U' R'" << endl;
                    rightTurn();
                    reverseUpTurn();
                    reverseRightTurn();
                }

                else if (up[8] == 'w' && !isBottomLeftSolved)
                {
                    // L U L'
                    cout << "L U L'" << endl;
                    leftTurn();
                    upTurn();
                    reverseLeftTurn();
                }

                else if (up[6] == 'w' && !isBottomRightSolved)
                {
                    // R' U' R
                    cout << "R' U' R" << endl;
                    reverseRightTurn();
                    reverseUpTurn();
                    rightTurn();
                }

                else if (up[2] == 'w' && !isBottomRightSolved)
                {
                    //R' U R
                    cout << "R' U R" << endl;
                    reverseRightTurn();
                    upTurn();
                    rightTurn();
                }

                else if (up[0] == 'w' && !isBottomLeftSolved)
                {
                    // L U' L'
                    cout << "L U' L'" << endl;
                    leftTurn();
                    reverseUpTurn();
                    reverseLeftTurn();
                }

                // else if(front[6]=='w')
                // {
                //    L' U L
                // }
                //
                // else if(front[8]=='w')
                // {
                //      R U' R'
                // }
                // 
                // do above functions for all 4 sides
                //

                else if (front[6] == 'w')
                {
                    cout << "L' U L" << endl;
                    reverseLeftTurn();
                    upTurn();
                    leftTurn();
                }

                else if (front[8] == 'w')
                {
                    cout << "R U' R'" << endl;
                    rightTurn();
                    reverseUpTurn();
                    reverseRightTurn();
                }

                else if (back[6] == 'w')
                {
                    cout << "R' U R" << endl;
                    reverseRightTurn();
                    upTurn();
                    rightTurn();
                }

                else if (back[8] == 'w')
                {
                    cout << "L U' L'" << endl;
                    leftTurn();
                    reverseUpTurn();
                    reverseLeftTurn();
                }

                else if (left[6] == 'w')
                {
                    cout << "B' U B" << endl;
                    reverseBackTurn();
                    upTurn();
                    backTurn();
                }

                else if (left[8] == 'w')
                {
                    cout << "F U' F'" << endl;
                    frontTurn();
                    reverseUpTurn();
                    reverseFrontTurn();
                }

                else if (right[6] == 'w')
                {
                    cout << "F' U F" << endl;
                    reverseFrontTurn();
                    upTurn();
                    frontTurn();
                }
                
                else if (right[8] == 'w')
                {
                    cout << "B U' B'" << endl;
                    backTurn();
                    reverseUpTurn();
                    reverseBackTurn();
                }

                else if (down[0] == 'w' && !isTopLeftSolved)
                {
                    cout << "L' U' L" << endl;
                    reverseLeftTurn();
                    reverseUpTurn();
                    leftTurn();
                }

                else if (down[2] == 'w' && !isTopRightSolved)
                {
                    cout << "R U R'" << endl;
                    rightTurn();
                    upTurn();
                    reverseRightTurn();
                }

                else if (down[6] == 'w' && !isBottomLeftSolved)
                {
                    cout << "L U L'" << endl;
                    leftTurn();
                    upTurn();
                    reverseLeftTurn();
                }

                else if (down[8] == 'w' && !isBottomRightSolved)
                {
                    cout << "R' U' R" << endl;
                    reverseRightTurn();
                    reverseUpTurn();
                    rightTurn();
                }

                else
                {
                    cout << "U" << endl;
                    upTurn();
                }
            }
        }
    }
    cout << endl;
    cout << "First Layer Solved !" << endl;
}

void cubeSolve::solveWhiteCross()
{
    // variable initialization
    int correctWhiteEdgePieceCount = 0;
    bool isLeftEdgeSolved = false;
    bool isRightEdgeSolved = false;
    bool isTopEdgeSolved = false;
    bool isBottomEdgeSolved = false;

    if (down[1] == 'w' && front[7] == front[4])
    {
        isTopEdgeSolved = true;
        correctWhiteEdgePieceCount++;
    }

    if (down[3] == 'w' && left[7] == left[4])
    {
        isLeftEdgeSolved = true;
        correctWhiteEdgePieceCount++;
    }

    if (down[5] == 'w' && right[7] == right[4])
    {
        isRightEdgeSolved = true;
        correctWhiteEdgePieceCount++;
    }

    if (down[7] == 'w' && back[7] == back[4])
    {
        isBottomEdgeSolved = true;
        correctWhiteEdgePieceCount++;
    }

    if (down[1] == 'w' && front[7] != front[4])
    {
        cout << "F F" << endl;
        frontTurn();
        frontTurn();
    }

    if (down[5] == 'w' && right[7] != right[4])
    {
        cout << "R R" << endl;
        rightTurn();
        rightTurn();
    }

    if (down[7] == 'w' && back[7] != back[4])
    {
        cout << "B B" << endl;
        backTurn();
        backTurn();
    }

    if (down[3] == 'w' && left[7] != left[4])
    {
        cout << "L L" << endl;
        leftTurn();
        leftTurn();
    }


    while (correctWhiteEdgePieceCount != 4)
    {
        if (up[1] == 'w')
        {
            const char current = back[1];

            switch (current)
            {
                case 'b':
                    cout << "B B"<<endl;
                    backTurn();
                    backTurn();
                    isBottomEdgeSolved = true;
                    break;
                case 'r':
                    cout << "U' L L" << endl;
                    reverseUpTurn();
                    leftTurn();
                    leftTurn();
                    isLeftEdgeSolved = true;
                    break;
                case 'o':
                    cout << "U R R" << endl;
                    upTurn();
                    rightTurn();
                    rightTurn();
                    isRightEdgeSolved = true;
                    break;
                case 'g':
                    cout << "U U F F" << endl;
                    upTurn();
                    upTurn();
                    frontTurn();
                    frontTurn();
                    isTopEdgeSolved = true;
                    break;
                default:
                    cout << "ERROR:2216" << endl;
                    break;
            }
            correctWhiteEdgePieceCount++;
        }

        else if (up[3] == 'w')
        {
            const char current = left[1];
            switch (current)
            {
                case 'b':
                    cout << "U B B" << endl;
                    upTurn();
                    backTurn();
                    backTurn();
                    isBottomEdgeSolved = true;
                    break;

                case 'r':
                    cout << "L L" << endl;
                    leftTurn();
                    leftTurn();
                    isLeftEdgeSolved = true;
                    break;

                case 'o':
                    cout << "U U R R" << endl;
                    upTurn();
                    upTurn();
                    rightTurn();
                    rightTurn();
                    isRightEdgeSolved = true;
                    break;

                case 'g':
                    cout << "U' F F" << endl;
                    reverseUpTurn();
                    frontTurn();
                    frontTurn();
                    isTopEdgeSolved = true;
                    break;

                default:
                    cout << "ERROR:2257" << endl;
                    break;
            }
            correctWhiteEdgePieceCount++;
        }

        else if (up[5] == 'w')
        {
            const char current = right[1];
            switch (current)
            {
                case 'b':
                    cout << "U' B B" << endl;
                    reverseUpTurn();
                    backTurn();
                    backTurn();
                    isBottomEdgeSolved = true;
                    break;

                case 'r':
                    cout << "U U L L" << endl;
                    upTurn();
                    upTurn();
                    leftTurn();
                    leftTurn();
                    isLeftEdgeSolved = true;
                    break;

                case 'o':
                    cout << "R R" << endl;
                    rightTurn();
                    rightTurn();
                    isRightEdgeSolved = true;
                    break;

                case 'g':
                    cout << "U F F" << endl;
                    upTurn();
                    frontTurn();
                    frontTurn();
                    isTopEdgeSolved = true;
                    break;

                default:
                    cout << "ERROR:2296" << endl;
                    break;
            }
            correctWhiteEdgePieceCount++;
        }

        else if (up[7] == 'w')
        {
            const char current = front[1];
            switch (current)
            {
                case 'b':
                    cout << "U U B B" << endl;
                    upTurn();
                    upTurn();
                    backTurn();
                    backTurn();
                    isBottomEdgeSolved = true;
                    break;

                case 'r':
                    cout << "U L L" << endl;
                    upTurn();
                    leftTurn();
                    leftTurn();
                    isLeftEdgeSolved = true;
                    break;

                case 'o':
                    cout << "U' R R" << endl;
                    reverseUpTurn();
                    rightTurn();
                    rightTurn();
                    isRightEdgeSolved = true;
                    break;

                case 'g':
                    cout << "F F" << endl;
                    frontTurn();
                    frontTurn();
                    isTopEdgeSolved = true;
                    break;

                default:
                    cout << "ERROR:2336" << endl;
                    break;
            }
            correctWhiteEdgePieceCount++;
        }

        // adding cases for second layer pieces
        else if (front[3] == 'w')
        {
            const char current = left[5];
            switch (current)
            {
                case 'b':
                    cout << "D L D'" << endl;
                    downTurn();
                    leftTurn();
                    reverseDownTurn();
                    isBottomEdgeSolved = true;
                    break;
                case 'r':
                    cout << "L" << endl;
                    leftTurn();
                    isLeftEdgeSolved = true;
                    break;
                case 'o':
                    cout << "D D L D' D'" << endl;
                    downTurn();
                    downTurn();
                    leftTurn();
                    reverseDownTurn();
                    reverseDownTurn();
                    isRightEdgeSolved = true;
                    break;
                case 'g':
                    cout << "D' L D" << endl;
                    reverseDownTurn();
                    leftTurn();
                    downTurn();
                    isTopEdgeSolved = true;
                    break;
                default:
                    cout << "ERROR:2376" << endl;
                    break;
            }
            correctWhiteEdgePieceCount++;
        }

        else if (front[5] == 'w')
        {
            const char current = right[3];
            switch (current)
            {
                case 'b':
                    cout << "D' R' D" << endl;
                    reverseDownTurn();
                    reverseRightTurn();
                    downTurn();
                    isBottomEdgeSolved = true;
                    break;
                case 'r':
                    cout << "D D R' D D" << endl;
                    downTurn();
                    downTurn();
                    reverseRightTurn();
                    downTurn();
                    downTurn();
                    isLeftEdgeSolved = true;
                    break;
                case 'o':
                    cout << "R'" << endl;
                    reverseRightTurn();
                    isRightEdgeSolved = true;
                    break;
                case 'g':
                    cout << "D R' D'" << endl;
                    downTurn();
                    reverseRightTurn();
                    reverseDownTurn();
                    isTopEdgeSolved = true;
                    break;
                default:
                    cout << "ERROR:2412" << endl;
                    break;
            }
            correctWhiteEdgePieceCount++;
        }

        else if (back[3] == 'w')
        {
            const char current = right[5];
            switch (current)
            {
                case 'b':
                    cout << "D' R D" << endl;
                    reverseDownTurn();
                    rightTurn();
                    downTurn();
                    isBottomEdgeSolved = true;
                    break;

                case 'r':
                    cout << "D' D' R D D" << endl;
                    reverseDownTurn();
                    reverseDownTurn();
                    rightTurn();
                    downTurn();
                    downTurn();
                    isLeftEdgeSolved = true;
                    break;

                case 'o':
                    cout << "R" << endl;
                    rightTurn();
                    isRightEdgeSolved = true;
                    break;

                case 'g':
                    cout << "D R D'" << endl;
                    downTurn();
                    rightTurn();
                    reverseDownTurn();
                    isTopEdgeSolved = true;
                    break;

                default:
                    cout << "ERROR:2452" << endl;
                    break;
            }
            correctWhiteEdgePieceCount++;
        }

        else if (back[5] == 'w')
        {
            const char current = left[3];
            switch (current)
            {
                case 'b':
                    cout << "D L' D'" << endl;
                    downTurn();
                    reverseLeftTurn();
                    reverseDownTurn();
                    isBottomEdgeSolved = true;
                    break;
                case 'r':
                    cout << "L'" << endl;
                    reverseLeftTurn();
                    isLeftEdgeSolved = true;
                    break;
                case 'o':
                    cout << "D D L' D' D'" << endl;
                    downTurn();
                    downTurn();
                    reverseLeftTurn();
                    reverseDownTurn();
                    reverseDownTurn();
                    isRightEdgeSolved = true;
                    break;
                case 'g':
                    cout << "D' L' D" << endl;
                    reverseDownTurn();
                    reverseLeftTurn();
                    downTurn();
                    isTopEdgeSolved = true;
                    break;
                default:
                    cout << "ERROR:2488" << endl;
                    break;
            }
            correctWhiteEdgePieceCount++;
        }

        else if (left[3] == 'w')
        {
            const char current = back[5];
            switch (current)
            {
                case 'b':
                    cout << "B" << endl;
                    backTurn();
                    isBottomEdgeSolved = true;
                    break;

                case 'r':
                    cout << "D' B D" << endl;
                    reverseDownTurn();
                    backTurn();
                    downTurn();
                    isLeftEdgeSolved = true;
                    break;

                case 'o':
                    cout << "D  B  D'" << endl;
                    downTurn();
                    backTurn();
                    reverseDownTurn();
                    isRightEdgeSolved = true;
                    break;

                case 'g':
                    cout << "D' D' B D D" << endl;
                    reverseDownTurn();
                    reverseDownTurn();
                    backTurn();
                    downTurn();
                    downTurn();
                    isTopEdgeSolved = true;
                    break;

                default:
                    cout << "ERROR:2528" << endl;
                    break;
            }
            correctWhiteEdgePieceCount++;
        }

        else if (left[5] == 'w')
        {
            const char current = front[3];
            switch (current)
            {
                case 'b':
                    cout << "D D L' D' D'" << endl;
                    downTurn();
                    downTurn();
                    reverseLeftTurn();
                    reverseDownTurn();
                    reverseDownTurn();
                    isBottomEdgeSolved = true;
                    break;

                case 'r':
                    cout << "D F' D'" << endl;
                    downTurn();
                    reverseFrontTurn();
                    reverseDownTurn();
                    isLeftEdgeSolved = true;
                    break;

                case 'o':
                    cout << "D' F' D" << endl;
                    reverseDownTurn();
                    reverseFrontTurn();
                    downTurn();
                    isRightEdgeSolved = true;
                    break;

                case 'g':
                    cout << "F'" << endl;
                    reverseFrontTurn();
                    isTopEdgeSolved = true;
                    break;

                default:
                    cout << "ERROR:2568" << endl;
                    break;
            }
            correctWhiteEdgePieceCount++;
        }

        else if (right[3] == 'w')
        {
            const char current = front[5];
            switch (current)
            {
                case 'b':
                    cout << "D' D' F D D" << endl;
                    reverseDownTurn();
                    reverseDownTurn();
                    frontTurn();
                    downTurn();
                    downTurn();
                    isBottomEdgeSolved = true;
                    break;

                case 'r':
                    cout << "D F D'" << endl;
                    downTurn();
                    frontTurn();
                    reverseDownTurn();
                    isLeftEdgeSolved = true;
                    break;

                case 'o':
                    cout << "D' F D" << endl;
                    reverseDownTurn();
                    frontTurn();
                    downTurn();
                    isRightEdgeSolved = true;
                    break;

                case 'g':
                    cout << "F" << endl;
                    frontTurn();
                    isTopEdgeSolved = true;
                    break;

                default:
                    cout << "ERROR:2606" << endl;
                    break;
            }
            correctWhiteEdgePieceCount++;
        }

        else if (right[5] == 'w')
        {
            const char current = back[3];
            switch (current)
            {
                case 'b':
                    cout << "B'" << endl;
                    reverseBackTurn();
                    isBottomEdgeSolved = true;
                    break;

                case 'r':
                    cout << "D' B' D" << endl;
                    reverseDownTurn();
                    reverseBackTurn();
                    downTurn();
                    isLeftEdgeSolved = true;
                    break;

                case 'o':
                    cout << "D B' D'" << endl;
                    downTurn();
                    reverseBackTurn();
                    reverseDownTurn();
                    isRightEdgeSolved = true;
                    break;

                case 'g':
                    cout << "D D B' D D" << endl;
                    downTurn();
                    downTurn();
                    reverseBackTurn();
                    downTurn();
                    downTurn();
                    isTopEdgeSolved = true;
                    break;

                default:
                    cout << "ERROR:2648" << endl;
                    break;
            }
            correctWhiteEdgePieceCount++;
        }

        // Cases for first, third layered pieces
        // after the turn i must place the white piece here otherwise infinite loop
        else if (front[1] == 'w')
        {
            if (!isTopEdgeSolved)
            {
                if (up[7] == left[4])
                {
                    cout << "F'" << endl;
                    reverseFrontTurn();
                }
                else
                {
                    cout << "F" << endl;
                    frontTurn();
                }

            }
            
            else if (!isRightEdgeSolved)
            {
                cout << "U'" << endl;
                reverseUpTurn();
                if (up[5] == front[4])
                {
                    cout << "R'" << endl;
                    reverseRightTurn();
                }
                else
                {
                    cout << "R" << endl;
                    rightTurn();
                }
            }

            else if (!isLeftEdgeSolved)
            {
                cout << "U" << endl;
                upTurn();
                if (!isLeftEdgeSolved)
                {
                    if (up[3] == front[4])
                    {
                        cout << "L" << endl;
                        leftTurn();
                    }
                    else
                    {
                        cout << "L'" << endl;
                        reverseLeftTurn();
                    }
                }
            }

            else if (!isBottomEdgeSolved)
            {
                cout << "U U" << endl;
                upTurn();
                upTurn();
                if (up[1] == left[4])
                {
                    cout << "B" << endl;
                    backTurn();
                }
                else
                {
                    cout << "B'" << endl;
                    reverseBackTurn();
                }
            }

            else
            {
                cout << "ERROR: else if (front[1] == 'w')" << endl;
            }
        }

        else if (front[7] == 'w')
        {
            if (down[1] == left[4])
            {
                cout << "F" << endl;
                frontTurn();
            }
            else
            {
                cout << "F'" << endl;
                reverseFrontTurn();
            }
        }

        else if (back[1] == 'w')
        {
            if (!isBottomEdgeSolved)
            {
                if (up[1] == left[4])
                {
                    cout << "B" << endl;
                    backTurn();
                }
                else
                {
                    cout << "B'" << endl;
                    reverseBackTurn();
                }
            }
            
            else if (!isLeftEdgeSolved)
            {
                cout << "U'" << endl;
                reverseUpTurn();
                if (up[3] == front[4])
                {
                    cout << "L" << endl;
                    leftTurn();
                }
                else
                {
                    cout << "L'" << endl;
                    reverseLeftTurn();
                }
            }

            else if (!isRightEdgeSolved)
            {
                cout << "U" << endl;
                upTurn();
                if (!isRightEdgeSolved)
                {
                    if (up[5] == front[4])
                    {
                        cout << "R'" << endl;
                        reverseRightTurn();
                    }
                    else
                    {
                        cout << "R" << endl;
                        rightTurn();
                    }
                }
            }

            else if (!isTopEdgeSolved)
            {
                cout << "U U" << endl;
                upTurn();
                upTurn();
                if (up[7] == left[4])
                {
                    cout << "F'" << endl;
                    reverseFrontTurn();
                }
                else
                {
                    cout << "F" << endl;
                    frontTurn();
                }
            }

            else
            {
                cout << "ERROR: else if (back[1] == 'w') " << endl;
            }
        }

        else if (back[7] == 'w')
        {
            if (down[7] == left[4])
            {
                cout << "B'" << endl;
                reverseBackTurn();
            }
            else
            {
                cout << "B" << endl;
                backTurn();
            }
        }

        else if (left[1] == 'w')
        {
            if (!isLeftEdgeSolved)
            {
                if (up[3] == front[4])
                {
                    cout << "L" << endl;
                    leftTurn();
                }
                else
                {
                    cout << "L'" << endl;
                    reverseLeftTurn();
                }
            }

            else if (!isTopEdgeSolved)
            {
                cout << "U'" << endl;
                reverseUpTurn();
                if (up[7] == left[4])
                {
                    cout << "F'" << endl;
                    reverseFrontTurn();
                }
                else
                {
                    cout << "F" << endl;
                    frontTurn();
                }
            }

            else if (!isBottomEdgeSolved)
            {
                cout << "U" << endl;
                upTurn();
                if (up[1] == left[4])
                {
                    cout << "B" << endl;
                    backTurn();
                }
                else
                {
                    cout << "B'" << endl;
                    reverseBackTurn();
                }
            }

            else if (!isRightEdgeSolved)
            {
                cout << "U U" << endl;
                upTurn();
                upTurn();
                if (up[5] == front[4])
                {
                    cout << "R'" << endl;
                    reverseRightTurn();
                }
                else
                {
                    cout << "R" << endl;
                    rightTurn();
                }
            }

            else
            {
                cout << "ERROR: else if (left[1] == 'w')" << endl;
            }
        }

        else if (left[7] == 'w')
        {
            if (down[3] == front[4])
            {
                cout << "L'" << endl;
                reverseLeftTurn();
            }
            else
            {
                cout << "L" << endl;
                leftTurn();
            }
        }

        else if (right[1] == 'w')
        {
            if (!isRightEdgeSolved)
            {
                if (up[5] == front[4])
                {
                    cout << "R'" << endl;
                    reverseRightTurn();
                }
                else
                {
                    cout << "R" << endl;
                    rightTurn();
                }
            }

            else if (!isTopEdgeSolved)
            {
                cout << "U" << endl;
                upTurn();
                if (up[7] == left[4])
                {
                    cout << "F'" << endl;
                    reverseFrontTurn();
                }
                else
                {
                    cout << "F" << endl;
                    frontTurn();
                }
            }

            else if (!isBottomEdgeSolved)
            {
                cout << "U'" << endl;
                reverseUpTurn();
                if (up[1] == left[4])
                {
                    cout << "B" << endl;
                    backTurn();
                }
                else
                {
                    cout << "B'" << endl;
                    reverseBackTurn();
                }
            }

            else if (!isLeftEdgeSolved)
            {
                cout << "U U" << endl;
                upTurn();
                upTurn();
                if (up[3] == front[4])
                {
                    cout << "L" << endl;
                    leftTurn();
                }
                else
                {
                    cout << "L'" << endl;
                    reverseLeftTurn();
                }
            }

            else
            {
                cout << "ERROR: else if (right[1] == 'w') " << endl;
            }
        }

        else if (right[7] == 'w')
        {
            if (down[5] == front[4])
            {
                cout << "R" << endl;
                rightTurn();
            }
            else
            {
                cout << "R'" << endl;
                reverseRightTurn();
            }
        }

        correctWhiteEdgePieceCount = 0;

        if (down[1] == 'w' && front[7] == front[4])
        {
            isTopEdgeSolved = true;
            correctWhiteEdgePieceCount++;
        }

        if (down[3] == 'w' && left[7] == left[4])
        {
            isLeftEdgeSolved = true;
            correctWhiteEdgePieceCount++;
        }

        if (down[5] == 'w' && right[7] == right[4])
        {
            isRightEdgeSolved = true;
            correctWhiteEdgePieceCount++;
        }

        if (down[7] == 'w' && back[7] == back[4])
        {
            isBottomEdgeSolved = true;
            correctWhiteEdgePieceCount++;
        }
    }

    cout << endl;
    cout << "White Cross Solved!" << endl;
}

void cubeSolve::setCube(vector<vector<char>> currentValues)
{
    // check if there are any wrong information
    for (int firstIndex = 0; firstIndex < 6; firstIndex++)
    {
        for (int secondIndex = 0; secondIndex < 6; secondIndex++)
        {
            char currentColor = currentValues[firstIndex][secondIndex];
            
            if (currentColor == 'g' || currentColor == 'b' ||
                currentColor == 'o' || currentColor == 'r' ||
                currentColor == 'w' || currentColor == 'y')
            {
                continue;
            }

            else
            {
                cout << "There is an error in input!" << endl;
                exit(EXIT_FAILURE);
            }
        }
    }

    for (int i = 0; i < 9; i++)
    {
        front[i] = currentValues[0][i];
    }

    for (int i = 0; i < 9; i++)
    {
        back[i] = currentValues[1][i];
    }

    for (int i = 0; i < 9; i++)
    {
        left[i] = currentValues[2][i];
    }

    for (int i = 0; i < 9; i++)
    {
        right[i] = currentValues[3][i];
    }

    for (int i = 0; i < 9; i++)
    {
        up[i] = currentValues[4][i];
    }

    for (int i = 0; i < 9; i++)
    {
        down[i] = currentValues[5][i];
    }

}

void cubeSolve::printFront()
{
    cout << "-------------------" << endl;
    cout << "Printing Front Face" << endl;
    for (int i = 0; i < 9; i++)
    {
        cout << front[i] << " ";
        if (i % 3 == 2)
        {
            cout << endl;
        }
    }
    cout << "-------------------" << endl;
}

void cubeSolve::printBack()
{
    cout << "-------------------" << endl;
    cout << "Printing Back Face" << endl;
    for (int i = 0; i < 9; i++)
    {
        cout << back[i] << " ";
        if (i % 3 == 2)
        {
            cout << endl;
        }
    }
    cout << "-------------------" << endl;
}

void cubeSolve::printLeft()
{
    cout << "-------------------" << endl;
    cout << "Printing Left Face" << endl;
    for (int i = 0; i < 9; i++)
    {
        cout << left[i] << " ";
        if (i % 3 == 2)
        {
            cout << endl;
        }
    }
    cout << "-------------------" << endl;
}

void cubeSolve::printRight()
{
    cout << "-------------------" << endl;
    cout << "Printing Right Face" << endl;
    for (int i = 0; i < 9; i++)
    {
        cout << right[i] << " ";
        if (i % 3 == 2)
        {
            cout << endl;
        }
    }
    cout << "-------------------" << endl;
}

void cubeSolve::printUp()
{
    cout << "-------------------" << endl;
    cout << "Printing Up Face" << endl;
    for (int i = 0; i < 9; i++)
    {
        cout << up[i] << " ";
        if (i % 3 == 2)
        {
            cout << endl;
        }
    }
    cout << "-------------------" << endl;
}

void cubeSolve::printDown()
{
    cout << "-------------------" << endl;
    cout << "Printing Down Face" << endl;
    for (int i = 0; i < 9; i++)
    {
        cout << down[i] << " ";
        if (i % 3 == 2)
        {
            cout << endl;
        }
    }
    cout << "-------------------" << endl;
}

void cubeSolve::solveMyCube() {

    decideCurrentState();

    while (currentState < 6) {
        switch (currentState) {
        case -1:
            solveWhiteCross();
            break;
        case 0:
            solveFirstLayer();
            break;
        case 1:
            solveSecondLayer();
            break;
        case 2:
            solveYellowCross();
            break;
        case 3:
            solveYellowFace();
            break;
        case 4:
            solveThirdLayerCorners();
            break;
        case 5:
            solveThirdLayerEdges();
            break;
        default:
            cout << "You shouldn't be here in function solveMyCube" << endl;
            break;
        }

        decideCurrentState();  // Update the currentState after each step
    }

    cout << "Cube is solved" << endl;
}
