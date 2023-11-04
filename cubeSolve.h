#pragma once
#include <iostream>
#include <vector>


using namespace std;

class cubeSolve
{
private:
	int currentState;
public:
	vector<char> front; // Green Square
	vector<char> back;  //Blue Square
	vector<char> up;   // Yellow Square
	vector<char> down; // White Square
	vector<char> right; //Orange Square
	vector<char> left;  // Red Square
	bool frontSolved;
	bool backSolved;
	bool upSolved;
	bool downSolved;
	bool rightSolved;
	bool leftSolved;
	

	cubeSolve();

	// first vector is front
	// second vector is back
	// third vector is left
	// fourth vector is right
	// fifth vector is up
	// sixth vector is down
	void setCube(vector<vector<char>> currentValues); 
	
	void solveWhiteCross();

	// in solveFirstLayer function
	// we are going to assume its cross is already solved
	void solveFirstLayer();

	// solving the second layer
	// while(correctPieces!=4)
	// {
	//	if there is a piece that doesn't have a yellow face:
	//	
	//  else:
	//		change the position of the incorrect
	//		positioned pieces
	// 
	//  
	//  if (front[1]==front[4] && up[7]!=up[4])
	//  do same for all sides 
	//
	void solveSecondLayer();

	// solving the yellow cross: 
	// default case:
	// F U R U' R' F' Then there is 2 yellow might be one of the cases below
	// 2 yellows across each other:
	// F R U R' U' F'
	// 2 yellows near each other: we should position them top and left and then do:
	// F U R U' R' F'
	void solveYellowCross();
	


	// solving the yellow face
	// there are 3 possible cases:
	// 
	// if there is only yellow cross: left[2]=='y' we need to make this condition true
	// and then do the algorithm:
	// R U R' U R U U R'
	// after that we should have yellow cross + 1 yellow 
	// we should position that yellow to up[6] and do the algorithm again:
	// R U R' U R U U R'
	//
	// if there is yellow cross + 1 yellow: we should position that yellow to 
	// up[6] and do the algorithm:
	// R U R' U R U U R'
	//
	// if there is yellow cross + 2 yellow:
	// left[2]=='y' we need to make this condition true
	// and then do the algorithm:
	// R U R' U R U U R'
	// after this we are at line 48:
	// so when we are designing this we should check if we have 2 yellows
	// and do the operations and then check for 1st and 2nd case scenarios
	// so that we dont write the same code over and over again.
	void solveYellowFace();

	// position the cube until we have at least 2 correct corners:
	// if left[0]== left[4] ++count left[2]==left[4] ++count
	// do same for right
	// if we have more or equal to than 2
	// we can do the algorithm:
	// if not we should do one of the following:
	// 1) U
	// 2) U'
	// 3) U U || U' U'
	// we should move from the case which has more or equal to than 2
	// important part is thge algorithm will change everytime because 
	// position of our correct corners will not be the same
	// 
	// if the correct corners next to each other 
	// we should do the algorithm from other side
	// since in our program we dont have the 
	// function to change the way we look at the cube
	// i will just change the algorithm according to user's need
	// 
	// if the correct corners diagonal to each other
	// we should do the algorithm by taking the correct corner to our left
	// but once again we dont have the function to change the way we look at the cube
	// so i need to change the algorithm
	//
	void solveThirdLayerCorners();
	void solveThirdLayerEdges();

	// Function that decides which state the cube is
	// 
	// -1 if nothing has done
	// 0 if white cross done
	// 1 if white layer solved
	// 2 if second layer solved
	// 3 if yellow cross
	// 4 if yellow face solved
	// 5 if third layer corners solved
	// 6 if cube solved
	// 
	void decideCurrentState();

	// Function that solves the current problem using decideCurrentState function
	void solveMyCube();

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

	// To check if its solved
	bool isSolved();
	bool isColorSolved(vector<char> x);

	bool checkLayer(int a, vector<char> vec);

	void printFront();
	void printBack();
	void printLeft();
	void printRight();
	void printUp();
	void printDown();
};

