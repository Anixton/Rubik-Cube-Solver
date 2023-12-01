#pragma once
#include <iostream>
#include <vector>


using namespace std;

class cubeSolve
{
private:
	int currentState;
public:
	vector<char> front;  // Green Square
	vector<char> back;   //Blue Square
	vector<char> up;     // Yellow Square
	vector<char> down;   // White Square
	vector<char> right;  //Orange Square
	vector<char> left;   // Red Square


	// Initializes the Cube sides with default colors
	cubeSolve();


	// F and F' Turns
	void frontTurn();
	void reverseFrontTurn();


	// B and B' Turns
	void backTurn();
	void reverseBackTurn();


	// U and U' Turns
	void upTurn();
	void reverseUpTurn();


	// D and D' Turns
	void downTurn();
	void reverseDownTurn();


	// L and L' Turns
	void leftTurn();
	void reverseLeftTurn();


	// R and R' Turns
	void rightTurn();
	void reverseRightTurn();


	// first vector is front
	// second vector is back
	// third vector is left
	// fourth vector is right
	// fifth vector is up
	// sixth vector is down
	void setCube(vector<vector<char>> currentValues); 


	// This function determines the current state of the Rubik's Cube and returns an integer code.
	// Possible return values:
	// -1: No progress
	//  0: White cross achieved
	//  1: White layer completely solved
	//  2: Second layer successfully solved
	//  3: Yellow cross formed
	//  4: Yellow face fully solved
	//  5: Third layer corners correctly positioned
	//  6: Cube completely solved
	//
	// Note: The returned code indicates the current state of cube-solving progress.
	void decideCurrentState();
	

	// Method to solve the white cross on the Rubik's Cube.
	// The algorithm systematically checks and solves the orientation of white edge pieces
	// on the first layer to form a white cross. It considers the colors of adjacent faces
	// to determine the correct moves. The solved cross ensures that each white edge piece is
	// correctly aligned with its adjacent center colors.
	void solveWhiteCross();


	// Method to solve the first layer of a Rubik's Cube by correctly placing white corner pieces.
	// The algorithm systematically checks and applies specific moves based on the current state of the cube.
	// It starts by identifying the correctly placed white corner pieces in the third layer.
	// If a piece is not in the correct position, it applies the corresponding algorithm to move it to the correct place.
	// The process continues until all four white corner pieces are correctly positioned.
	// Additionally, the algorithm handles cases where a white corner piece is in the top layer or in the wrong position,
	// adjusting their placement with specific moves. The method utilizes a rule-based approach rather than brute force.
	void solveFirstLayer();


	// Iterate through the second layer until all pieces are correctly placed and oriented.
	// Check each piece in the second layer, and if a piece has a yellow face,
	// ensure it is correctly positioned; otherwise, adjust its position.
	// Determine the necessary moves based on the specific misalignment and execute the corresponding algorithm.
	// Repeat this process for all sides until all second-layer pieces are correctly placed and oriented.
	void solveSecondLayer();


	// The method employs various move sequences to achieve the yellow cross.
	// Determine the necessary moves based on count of yellow edge pieces
	void solveYellowCross();
	

	// The method employs various move sequences to solve yellow face .
	// Determine the necessary moves based on count of yellow corner pieces
	void solveYellowFace();


	// Position the cube until we have at least 2 correct corners.
	// If there are 2 or more correct corners, perform the corresponding algorithm.
	// If not, rotate the cube until we have 2 correct corners.
	void solveThirdLayerCorners();


	// Check if the cube's third layer edges are already solved.
	// If not, determine the direction to move and perform the necessary algorithms.
	void solveThirdLayerEdges();


	// Function that solves the current problem using decideCurrentState function
	void solveMyCube();


	// Printing Cube faces
	void printFront();
	void printBack();
	void printLeft();
	void printRight();
	void printUp();
	void printDown();
};

