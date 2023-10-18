#include <iostream>
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
    frontSolved = false;
    backSolved = false;
    upSolved = false;
    downSolved = false;
    rightSolved = false;
    leftSolved = false;
    currentState = 0;
}

void cubeSolve::frontTurn() {
    // Store the values of the up, left, down, and right faces
    vector<char> tempUp = up;
    vector<char> tempLeft = left;
    vector<char> tempDown = down;
    vector<char> tempRight = right;

    // Update the up, left, down, and right faces using loops
    for (int i = 0; i < 3; ++i) {
        up[i + 6] = tempLeft[i + 6];
        left[i + 6] = tempDown[i + 6];
        down[i + 6] = tempRight[i + 6];
        right[i + 6] = tempUp[i + 6];
    }

    // Update the front face using loops
    vector<char> tempFront = front;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            front[i * 3 + j] = tempFront[(2 - j) * 3 + i];
        }
    }
}

void cubeSolve::reverseFrontTurn() {
    // Store the values of the up, left, down, and right faces
    vector<char> tempUp = up;
    vector<char> tempLeft = left;
    vector<char> tempDown = down;
    vector<char> tempRight = right;

    // Update the up, left, down, and right faces to reverse the move using loops
    for (int i = 0; i < 3; ++i) {
        up[i + 6] = tempRight[i + 6];
        left[i + 6] = tempUp[i + 6];
        down[i + 6] = tempLeft[i + 6];
        right[i + 6] = tempDown[i + 6];
    }

    // Update the front face to reverse the move using loops
    vector<char> tempFront = front;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            front[i * 3 + j] = tempFront[j * 3 + (2 - i)];
        }
    }
}

void cubeSolve::backTurn() {
    // Store the values of the up, left, down, and right faces
    vector<char> tempUp = up;
    vector<char> tempLeft = left;
    vector<char> tempDown = down;
    vector<char> tempRight = right;

    // Update the up, left, down, and right faces using loops
    for (int i = 0; i < 3; ++i) {
        up[i] = tempRight[i];
        left[i] = tempUp[i];
        down[i] = tempLeft[i];
        right[i] = tempDown[i];
    }

    // Update the back face using loops
    vector<char> tempBack = back;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            back[i * 3 + j] = tempBack[j * 3 + (2 - i)];
        }
    }
}

void cubeSolve::reverseBackTurn() {
    // Store the values of the up, left, down, and right faces
    vector<char> tempUp = up;
    vector<char> tempLeft = left;
    vector<char> tempDown = down;
    vector<char> tempRight = right;

    // Update the up, left, down, and right faces to reverse the move using loops
    for (int i = 0; i < 3; ++i) {
        up[i] = tempLeft[i];
        left[i] = tempDown[i];
        down[i] = tempRight[i];
        right[i] = tempUp[i];
    }

    // Update the back face to reverse the move using loops
    vector<char> tempBack = back;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            back[i * 3 + j] = tempBack[(2 - j) * 3 + i];
        }
    }
}

void cubeSolve::upTurn() {
    // Store the values of the front, left, back, and right faces
    vector<char> tempFront = front;
    vector<char> tempLeft = left;
    vector<char> tempBack = back;
    vector<char> tempRight = right;

    // Update the front, left, back, and right faces using loops
    for (int i = 0; i < 3; ++i) {
        front[i] = tempRight[i];
        left[i] = tempFront[i];
        back[i] = tempLeft[i];
        right[i] = tempBack[i];
    }

    // Update the up face by rotating it clockwise
    vector<char> tempUp = up;
    up[0] = tempUp[6];
    up[1] = tempUp[3];
    up[2] = tempUp[0];
    up[3] = tempUp[7];
    up[5] = tempUp[1];
    up[6] = tempUp[8];
    up[7] = tempUp[5];
    up[8] = tempUp[2];
}

void cubeSolve::reverseUpTurn() {
    // Store the values of the front, left, back, and right faces
    vector<char> tempFront = front;
    vector<char> tempLeft = left;
    vector<char> tempBack = back;
    vector<char> tempRight = right;

    // Update the front, left, back, and right faces using loops
    for (int i = 0; i < 3; ++i) {
        front[i] = tempLeft[i];
        left[i] = tempBack[i];
        back[i] = tempRight[i];
        right[i] = tempFront[i];
    }

    // Update the up face by rotating it counterclockwise
    vector<char> tempUp = up;
    up[0] = tempUp[2];
    up[1] = tempUp[5];
    up[2] = tempUp[8];
    up[3] = tempUp[1];
    up[5] = tempUp[7];
    up[6] = tempUp[0];
    up[7] = tempUp[3];
    up[8] = tempUp[6];
}

void cubeSolve::downTurn() {
    // Store the values of the front, left, back, and right faces
    vector<char> tempFront = front;
    vector<char> tempLeft = left;
    vector<char> tempBack = back;
    vector<char> tempRight = right;

    // Update the front, left, back, and right faces using loops
    for (int i = 0; i < 3; ++i) {
        front[i + 6] = tempLeft[i + 6];
        left[i + 6] = tempBack[i + 6];
        back[i + 6] = tempRight[i + 6];
        right[i + 6] = tempFront[i + 6];
    }

    // Update the down face by rotating it clockwise
    vector<char> tempDown = down;
    down[0] = tempDown[6];
    down[1] = tempDown[3];
    down[2] = tempDown[0];
    down[3] = tempDown[7];
    down[5] = tempDown[1];
    down[6] = tempDown[8];
    down[7] = tempDown[5];
    down[8] = tempDown[2];
}

void cubeSolve::reverseDownTurn() {
    // Store the values of the front, left, back, and right faces
    vector<char> tempFront = front;
    vector<char> tempLeft = left;
    vector<char> tempBack = back;
    vector<char> tempRight = right;

    // Update the front, left, back, and right faces using loops
    for (int i = 0; i < 3; ++i) {
        front[i + 6] = tempRight[i + 6];
        left[i + 6] = tempFront[i + 6];
        back[i + 6] = tempLeft[i + 6];
        right[i + 6] = tempBack[i + 6];
    }

    // Update the down face by rotating it counterclockwise
    vector<char> tempDown = down;
    down[0] = tempDown[2];
    down[1] = tempDown[5];
    down[2] = tempDown[8];
    down[3] = tempDown[1];
    down[5] = tempDown[7];
    down[6] = tempDown[0];
    down[7] = tempDown[3];
    down[8] = tempDown[6];
}

void cubeSolve::leftTurn() {
    // Store the values of the up, front, down, and back faces
    vector<char> tempUp = up;
    vector<char> tempFront = front;
    vector<char> tempDown = down;
    vector<char> tempBack = back;

    // Update the up, front, down, and back faces using loops
    for (int i = 0; i < 3; ++i) {
        up[i * 3] = tempBack[(2 - i) * 3];
        front[i * 3] = tempUp[i * 3];
        down[i * 3] = tempFront[i * 3];
        back[i * 3] = tempDown[i * 3];
    }

    // Update the left face by rotating it clockwise
    vector<char> tempLeft = left;
    left[0] = tempLeft[6];
    left[1] = tempLeft[3];
    left[2] = tempLeft[0];
    left[3] = tempLeft[7];
    left[5] = tempLeft[1];
    left[6] = tempLeft[8];
    left[7] = tempLeft[5];
    left[8] = tempLeft[2];
}

void cubeSolve::reverseLeftTurn() {
    // Store the values of the up, front, down, and back faces
    vector<char> tempUp = up;
    vector<char> tempFront = front;
    vector<char> tempDown = down;
    vector<char> tempBack = back;

    // Update the up, front, down, and back faces using loops
    for (int i = 0; i < 3; ++i) {
        up[i * 3] = tempFront[i * 3];
        front[i * 3] = tempDown[i * 3];
        down[i * 3] = tempBack[(2 - i) * 3];
        back[i * 3] = tempUp[i * 3];
    }

    // Update the left face by rotating it counterclockwise
    vector<char> tempLeft = left;
    left[0] = tempLeft[2];
    left[1] = tempLeft[5];
    left[2] = tempLeft[8];
    left[3] = tempLeft[1];
    left[5] = tempLeft[7];
    left[6] = tempLeft[0];
    left[7] = tempLeft[3];
    left[8] = tempLeft[6];
}

void cubeSolve::rightTurn() {
    // Store the values of the up, front, down, and back faces
    vector<char> tempUp = up;
    vector<char> tempFront = front;
    vector<char> tempDown = down;
    vector<char> tempBack = back;

    // Update the up, front, down, and back faces using loops
    for (int i = 0; i < 3; ++i) {
        up[i * 3 + 2] = tempFront[i * 3 + 2];
        front[i * 3 + 2] = tempDown[i * 3 + 2];
        down[i * 3 + 2] = tempBack[(2 - i) * 3 + 2];
        back[i * 3 + 2] = tempUp[i * 3 + 2];
    }

    // Update the right face by rotating it clockwise
    vector<char> tempRight = right;
    right[0] = tempRight[6];
    right[1] = tempRight[3];
    right[2] = tempRight[0];
    right[3] = tempRight[7];
    right[5] = tempRight[1];
    right[6] = tempRight[8];
    right[7] = tempRight[5];
    right[8] = tempRight[2];
}

void cubeSolve::reverseRightTurn() {
    // Store the values of the up, front, down, and back faces
    vector<char> tempUp = up;
    vector<char> tempFront = front;
    vector<char> tempDown = down;
    vector<char> tempBack = back;

    // Update the up, front, down, and back faces using loops
    for (int i = 0; i < 3; ++i) {
        up[i * 3 + 2] = tempBack[(2 - i) * 3 + 2];
        front[i * 3 + 2] = tempUp[i * 3 + 2];
        down[i * 3 + 2] = tempFront[i * 3 + 2];
        back[i * 3 + 2] = tempDown[i * 3 + 2];
    }

    // Update the right face by rotating it counterclockwise
    vector<char> tempRight = right;
    right[0] = tempRight[2];
    right[1] = tempRight[5];
    right[2] = tempRight[8];
    right[3] = tempRight[1];
    right[5] = tempRight[7];
    right[6] = tempRight[0];
    right[7] = tempRight[3];
    right[8] = tempRight[6];
}

bool isColorSolved(vector<char> x)
{
    for (int i = 0; i < x.size(); i++)
    {
        if (x.at(i) != x.at(4))
        {
            return false;
        }
    }
    return true;
}

bool cubeSolve::isSolved()
{
    // Check each color if its solved
    if (frontSolved && backSolved && upSolved &&
        downSolved  && leftSolved && rightSolved)
    {
        return true;
    }

    return false;
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
    
    for (int i = 0; i < 9; i++)
    {
        if (down[i] != 'w')
        {
            currentState = 0;
            return;
        }
    }
    if (!(checkLayer(1, front) && checkLayer(1, back) && checkLayer(1, left) && checkLayer(1, right)))
    {
        currentState = 0;
        return;
    }
    currentState = 1;
    if (!(checkLayer(2, front) && checkLayer(2, back) && checkLayer(2, left) && checkLayer(2, right)))
    {
        currentState = 1;
        return;
    }
    currentState = 2;
    if (up[1] == 'y' && up[3] == 'y' && up[5] == 'y' && up[7] == 'y')
    {
        currentState = 3;
    }
    else
    {
        currentState = 2;
        return;
    }
    for (int i = 0; i < 9; i++)
    {
        if (up[i] != 'y')
        {
            currentState = 3;
            return;
        }
    }
    currentState = 4;

    if (!(checkLayer(3, front) && checkLayer(3, back) && checkLayer(3, left) && checkLayer(3, right)))
    {
        currentState = 3;
        return;
    }
    
    currentState = 4;
    return;

}

void cubeSolve::solveYellowCross()
{
    cout << "Solving the second Layer:"<<endl;
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
        cout << "Second Layer Solved!" << endl;
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
    
    cout << "U U F  U  R  U'  R'  F'" << endl;
    upTurn();
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

    if (front[5] == front[4] && left[3] == left[4])
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
                cout << "U' R' U R U B' U' B'"<<endl;
                reverseUpTurn();
                reverseRightTurn();
                upTurn();
                rightTurn();
                upTurn();
                reverseBackTurn();
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
                cout << "U' B' U B U L U' L" << endl;
                reverseUpTurn();
                reverseBackTurn();
                upTurn();
                backTurn();
                upTurn();
                leftTurn();
                reverseUpTurn();
                leftTurn();
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

                else if (back[3] != up[4] && right[6] != up[4]
                    && !(back[3] == back[4] && right[6] == right[4]))
                {
                    // do the algo
                    // back-> sola parçayý koyma algoritmasý
                    cout << "U' R' U R U B' U' B'" << endl;
                    reverseUpTurn();
                    reverseRightTurn();
                    upTurn();
                    rightTurn();
                    upTurn();
                    reverseBackTurn();
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
                //up 4 ifs are for front face we have to convert to all 4 sides
            }
        }
        


    }
    cout << endl;
    cout << "First Layer Solved !" << endl;
}