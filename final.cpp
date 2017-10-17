// Names: Chris Giuffrida and Thomas Krill
// Class: Fundamentals of Computing
// Final Project
// File: final.cpp 
// Description:  The main driver for the game Frogger.  Includes all necessary functions to operate game that are not in one of the three classes.

#include <iostream>
#include "gfxnew.h"
#include "frog.h"
#include "obstacle.h"
#include <unistd.h>
#include <vector>

using namespace std;

void drawBoard(Game&, string);
void fillObstacleVector(vector<Obstacle>&, int, double, double, double, int, bool, int);
void drawMoveVector(vector<Obstacle>&);
bool isOverlapping(Frog&, vector<Obstacle>&, int);
bool isDead(Frog&, vector<Obstacle>&, int);
void resetGame(Game&);
void resetFrog(Frog&);
bool checkGameOver(Game&, vector<Obstacle>&);
void displaySplashScreen(int);
string getUsername();
void frogMadeIt(Frog&, Game&, vector<Obstacle> &);
void updateTime(Game&, int&, Frog&, vector<Obstacle>&);
void fillFinalFrogs(vector<Frog>&);
void displayFinalFrogs(Game&, vector<Frog>&);
void didWin(Game&);

int main() {

  // Declare variables
	char userInput = 0;
	char garbage = 0;
	bool isPressed = false;
	bool isReleased = false;
	bool frogDead = false;
	int event = 0;
	int sleepCounter = 0;

  // Open Window
	gfx_open(750, 750, "test");

  // Create the game and the player controlled frog
	Game frogger(3, 0, 0, 30);
 	Frog froggy(375, 675, 1, 2, 350, 400, 'U');

  // Create a vector to store the stationary final frogs
 	vector<Frog> finalFrogs;
	fillFinalFrogs(finalFrogs);

  // Declare a vector to store the moving obstacles for each row of the board
 	vector<Obstacle> row2;
 	vector<Obstacle> row3;
 	vector<Obstacle> row4;
 	vector<Obstacle> row5;
 	vector<Obstacle> row6;
 	vector<Obstacle> row7;
 	vector<Obstacle> row8;
 	vector<Obstacle> row9;
 	vector<Obstacle> row10;
 	vector<Obstacle> row11;
 	vector<Obstacle> row12;
 	vector<Obstacle> row13;
 	vector<Obstacle> row14;

  // Fill each of the row vectors with obstalces (w/ unique starting points, velocity, etc)
 	fillObstacleVector(row2, 0, 0, 0, 0, 0, 0, 200);
 	fillObstacleVector(row3, 2, -125, -10, 1, 3, 0, 200);
 	fillObstacleVector(row4, 3, -75, 10, 1, 4, 0, 200);
 	fillObstacleVector(row5, 3, 75, -15, 1, 5, 0, 200);
 	fillObstacleVector(row6, 3, 25, 15, 1, 6, 0, 200);
 	fillObstacleVector(row7, 2, 125, -15, 2, 7, 0, 200);
 	fillObstacleVector(row8, 0, 0, 0, 0, 0, 0, 200);
 	fillObstacleVector(row9, 5, -225, -15, 3, 9, 1, 200);
 	fillObstacleVector(row10, 3, -175, 8, 3, 10, 1, 200);
 	fillObstacleVector(row11, 3, 75, 20, 6, 11, 1, 200);
 	fillObstacleVector(row12, 4, 125, -15, 2, 12, 1, 200);
 	fillObstacleVector(row13, 4, -75, 10, 4, 13, 1, 200);
 	fillObstacleVector(row14, 6, 0, 0, 1, 14, 1, 150);

  // Start game with a welcome screen and username interface
 	displaySplashScreen(1);
 	string username = getUsername();

  // Run program until user presses 'q'
	while(userInput != 'q') {
  		gfx_clear();
  		
    // Check if frog is dead depending on the row of grid he is on
		switch (froggy.getYGrid()) {
			case 2:
				frogDead = isDead(froggy, row2, froggy.getYGrid());
				break;
			case 3:
				frogDead = isDead(froggy, row3, froggy.getYGrid());
				break;
			case 4:
				frogDead = isDead(froggy, row4, froggy.getYGrid());
				break;
			case 5:
				frogDead = isDead(froggy, row5, froggy.getYGrid());	
				break;
			case 6:
				frogDead = isDead(froggy, row6, froggy.getYGrid());
				break;
			case 7:
				frogDead = isDead(froggy, row7, froggy.getYGrid());
				break;
			case 8:
				frogDead = isDead(froggy, row8, froggy.getYGrid());
				break;
			case 9:
				frogDead = isDead(froggy, row9, froggy.getYGrid());
				break;
			case 10:
				frogDead = isDead(froggy, row10, froggy.getYGrid());
				break;
			case 11:
				frogDead = isDead(froggy, row11, froggy.getYGrid());
				break;
			case 12:
				frogDead = isDead(froggy, row12, froggy.getYGrid());
				break;
			case 13:
				frogDead = isDead(froggy, row13, froggy.getYGrid());
				break;
			case 14:
				frogDead = isDead(froggy, row14, froggy.getYGrid());
				if(!(frogDead)) {
					frogMadeIt(froggy, frogger, row14);
				}
				break;
		}

    // Draw and iterate the obstacles for each row and draw frog/background
 		drawMoveVector(row14);
	  drawBoard(frogger, username);
	  gfx_color(255, 255, 255);
	  drawMoveVector(row9);
 		drawMoveVector(row10);
 		drawMoveVector(row11);
 		drawMoveVector(row12);
 		drawMoveVector(row13);
 		froggy.drawFrog();
	  drawMoveVector(row3);	 
		drawMoveVector(row4);
 		drawMoveVector(row5);
 		drawMoveVector(row6);
 		drawMoveVector(row7);

    // Display the correct number of stationary final frogs
 		displayFinalFrogs(frogger, finalFrogs);

    // Update the game's timer
    updateTime(frogger, sleepCounter, froggy, row14);

    // Run the proper sequence of functions if the frog is dead
 		if(frogDead) {
 			gfx_color(255, 0, 0);
			gfx_fill_circle(froggy.getXCenter(), froggy.getYCenter(), 25);
 			resetGame(frogger);
 			usleep(1000000);
 			if(checkGameOver(frogger, row14)) {
 				displaySplashScreen(2);
 			}
 			resetFrog(froggy);
 		}

    // Check to see if the user won the game
 		didWin(frogger);
 		
	  gfx_flush();
	  usleep(100000);
	  int test = gfx_event_waiting();
	  if((event = gfx_event_waiting()) != 0)  {
	   userInput = gfx_wait();
	   if(event == 1) {
	     isPressed = true;
	   }
	   else if(event == 2) {
	     isPressed = false;
	   }
		 if(isPressed) {
		    // Take in user command
		    switch (userInput) {
		      case 'S':
		    	  // Right arrow key
		    	  froggy.moveFrog('R', frogger);
		    	  break;
					case 'Q':
						// Left arrow key
		    	  froggy.moveFrog('L', frogger);
						break;
					case 'R':
						// Up arrow key
		    	  froggy.moveFrog('U',frogger);
						break;
					case 'T':
						// Down arrow key
		    	  froggy.moveFrog('D', frogger);
						break;
				}
			}
  	}
	}
}

// Draw the board game 
void drawBoard(Game &frogger, string username)
{
  // Draw the regions on the board.
  // Blue water
  gfx_color(0, 0, 204);
  gfx_fill_rectangle(0, 100, 750, 250);
  // Blue squares
  gfx_fill_rectangle(50, 50, 50, 50);
  gfx_fill_rectangle(200, 50, 50, 50);
  gfx_fill_rectangle(350, 50, 50, 50);
  gfx_fill_rectangle(500, 50, 50, 50);
  gfx_fill_rectangle(650, 50, 50, 50);
  // Green froggy home
  gfx_color(0, 153, 0);
  gfx_fill_rectangle(0, 40, 750, 10);
  gfx_fill_rectangle(0, 50, 50, 50);
  gfx_fill_rectangle(100, 50, 100, 50);
  gfx_fill_rectangle(250, 50, 100, 50);
  gfx_fill_rectangle(400, 50, 100, 50);
  gfx_fill_rectangle(550, 50, 100, 50);
  gfx_fill_rectangle(700, 50, 50, 50);
  // Purple median #1
  gfx_color(102, 0, 204);
  gfx_fill_rectangle(0, 350, 750, 50); 
  // Purple median #2
  gfx_fill_rectangle(0, 650, 750, 50);
  


  // Display the "Time" 
  gfx_changefont("lucidasans-bold-24");
  gfx_color(255, 255, 0);
  string timeLeft = "TIME LEFT: " + to_string(frogger.getTimeLeft());
  gfx_text(550, 740, timeLeft.c_str());


  // Display the username
  gfx_color(255, 255, 0);
  string userName = "USERNAME: " + username;
  gfx_text(0, 30, userName.c_str());

  // Display the word score
  string scoreString = "SCORE: " + to_string(frogger.getScore());
  const char* p = scoreString.c_str();
  gfx_text(400, 30, p);

  // Display the number of lives
  string livesLeft = "LIVES LEFT: " + to_string(frogger.getNumLives());
  gfx_text(10, 740, livesLeft.c_str());

}

// Place Obstacles inside each row vector at the correct place, velocity, and length
void fillObstacleVector(vector<Obstacle> &currentRow, int numObstacles, double firstPosition, double velocity, double length, int yGrid, bool canRide, int spacing)
{
	double xCenter;

	for (int i = 0; i < numObstacles; i++)
	{
		xCenter = firstPosition + spacing * i;
		currentRow.push_back(Obstacle(xCenter, length, yGrid, xCenter - (length * 50.) / 2, xCenter + (length * 50.) / 2, velocity, canRide));
	}
}

// Move and draw the obstacles for a given row
void drawMoveVector(vector<Obstacle> &currentRow)
{
	for(auto it = currentRow.begin(); it != currentRow.end(); it++) {
		it->drawObstacle();
		it->moveObstacle();
	}
}

// Check to see if the frog's next position is overlapping with an obstacle
bool isOverlapping(Frog &froggy, vector<Obstacle> &currentRow, int yGrid)
{
  // No obstacles in the first row
	if(yGrid == 2) {
		return false;
	} 
  
  // Iterate through obstacles in row and check for overlapping
	for (auto it = currentRow.begin(); it != currentRow.end(); it++) {
		if((froggy.getXRight() > it->getXLeft()) && (froggy.getXLeft() < it->getXRight())) {
			return true;
		}
		else if ((froggy.getXRight() <= it->getXRight()) && (froggy.getXLeft() >= it->getXLeft())) {
			return true;
		}
		else if ((froggy.getXLeft() < it->getXRight()) && (froggy.getXRight() > it->getXLeft())) {
			return true;
		}
	}

	return false;
}

// Check to see if the frog has died
bool isDead(Frog &froggy, vector<Obstacle> &currentRow, int yGrid)
{
	bool frogDead = false;

  // Frog gets hit by a car and dies
	if(yGrid < 9) {
		if(isOverlapping(froggy, currentRow, yGrid)) {
			frogDead = true;
		}
	} 
	// Frog touches the water and dies
	else if (yGrid < 14) {
		if(isOverlapping(froggy, currentRow, yGrid)) {
			frogDead = false;
		}
		else {
			frogDead = true;
		}
	} 
  // Frog does not land on a lillipad and dies
	else if(yGrid < 15) {
		if(isOverlapping(froggy, currentRow, yGrid)) {
			frogDead = true;
		}
	}

	// Frog touches wall
	if((froggy.getXLeft() < 0) || (froggy.getXRight() > 750)) {
		frogDead = true;
	}
	return frogDead;
}

// Reset the game after the frog has lost all lives
void resetGame(Game &frogger)
{
	frogger.setNumLives(frogger.getNumLives() - 1);
	frogger.setTimeLeft(30);
}

// Reset the frog to his starting position at bottom
void resetFrog(Frog &froggy)
{
	froggy.setXCenter(375);
	froggy.setXLeft(350);
	froggy.setYCenter(675);
	froggy.setXRight(400);
	froggy.setYGrid(2);
	froggy.setOrientation('U');
	froggy.drawFrog();
}

// Check to see if the game is over
bool checkGameOver(Game &frogger, vector<Obstacle> &row14)
{
	if(frogger.getNumLives() <= 0) {
		frogger.setNumLives(3);
		for (int i = 0; i < 5; i++)
		{
			frogger.setPlacedHome(i, 0);
		}
		frogger.setScore(0);
		row14.clear();
		fillObstacleVector(row14, 6, 0, 0, 1, 14, 1, 150);
		return true;

	}
	else {
		return false;
	}
}

// Display the starting frogger/game over/you win screen
void displaySplashScreen(int gameCase)
{
	char userInput = '0';
	gfx_clear();
  // Display screen until "s" for start is pressed
	while(userInput != 's') {
		gfx_clear();
		gfx_changefont("lucidasans-bold-24");
	  	gfx_color(0, 255, 0);
      // Display word "Frogger"
	  	gfx_text(325, 250, "FROGGER");

	  	gfx_color(255, 255, 0);
	  	gfx_text(175, 550, "TO START A NEW GAME, PRESS \"S\"");

      // Display "Game Over" or "You Win" if appropriate
	  	if(gameCase == 2) {
	  		gfx_color(255, 0, 0);
	  		gfx_text(312, 375, "GAME OVER");

	  	} else if(gameCase == 3) {
	  		gfx_color(0, 255, 0);
	  		gfx_text(325, 375, "YOU WIN");
	  	}
	  	userInput = gfx_wait();
	}
}

// Get the username from the user at the start
string getUsername()
{
	gfx_clear();
	string username = "";
	int event = 0;
	bool isPressed = false;
	int count = 0;
	char userInput = '0';
	gfx_color(255, 255, 0);
	gfx_changefont("lucidasans-bold-12");
	gfx_text(250, 300, "ENTER USERNAME: ");
  
  // Keep inputting text until user presses enter
	while(userInput != 13) {
		if((event = gfx_event_waiting()) != 0)  {
	    	userInput = gfx_wait();
	    	if(event == 1) {
	    		isPressed = true;
	    	}
	    	else if(event == 2) {
	    		isPressed = false;
	    	}
		    if(isPressed) {
				userInput = gfx_wait();
				if (userInput != 13) {
          // Username must be less than 15 characters
					if(count < 15) {
					username.push_back(userInput);
					count++;
					}
				}
        // Display user name in real time as user types
				string userName = "ENTER USERNAME: " + username;
				gfx_text(250, 300, userName.c_str());
			}
		}
	}
	return username;
}

// If frog made it to the 14th row, change parameters accordingly
void frogMadeIt(Frog &froggy, Game &frogger, vector<Obstacle> &row14)
{
	frogger.setScore(frogger.getScore() + 50 + 10 * frogger.getTimeLeft());

  // Determine which lillipad frog arrived at
	if(froggy.getXRight() < 150) {
		frogger.setPlacedHome(0, 1);
	}
	else if(froggy.getXRight() < 300) {
		frogger.setPlacedHome(1, 1);
	}
	else if(froggy.getXRight() < 450) {
		frogger.setPlacedHome(2, 1);
	}
	else if(froggy.getXRight() < 600) {
		frogger.setPlacedHome(3, 1);
	}
	else {
		frogger.setPlacedHome(4, 1);
	}

  // Add an obstacle on top of lillipad to prevent frog from returning to same one
	row14.push_back(Obstacle(froggy.getXCenter(), 1, 14, froggy.getXLeft(), froggy.getXRight(), 0, 0));

	resetFrog(froggy);
	frogger.setTimeLeft(30);
}

// Update the time displayed in the game
void updateTime(Game& frogger, int &sleepCounter, Frog &froggy, vector<Obstacle> &row14)
{

	int tempTime = 0;

  // Reset time and subtract and life
	if(frogger.getTimeLeft() <= 0) {
		frogger.setNumLives(frogger.getNumLives() - 1);
		tempTime = frogger.getTimeLeft();
		frogger.setTimeLeft(30);
	}

  // Reset time and end game
	if((tempTime <= 0) && (frogger.getNumLives() == 0)) {
		if(checkGameOver(frogger, row14)) {
 				displaySplashScreen(2);
 			}
 			resetFrog(froggy);
	}

  // Display time in seconds
	sleepCounter++;
	if(sleepCounter == 10) {
		sleepCounter = 0;
		frogger.setTimeLeft(frogger.getTimeLeft() - 1);
	}
}

// Generate the 5 final frogs to be displayed
void fillFinalFrogs(vector<Frog> &finalFrogs)
{
	for(int i = 0; i < 5; i++) {
		finalFrogs.push_back(Frog(75 + 150 * i, 75, 1, 14, 50 + 150 * i, 100 + 150 * i, 'D'));
	}
}

// Display the final frogs if the respective lillipad has been reached
void displayFinalFrogs(Game &frogger, vector<Frog> &finalFrogs)
{
	for(int i = 0; i < 5; i++) {
		if(frogger.getPlacedHome(i) == 1) {
			finalFrogs[i].drawFrog();
		}
	}
}

// Check to see if user won the game
void didWin(Game &frogger)
{
	int counter;
	for(int i = 0; i < 5; i++) {
		if(frogger.getPlacedHome(i) == true) {
			counter++;
		}
	}

  // Display the "You Won" screen
	if(counter == 5) {
		displaySplashScreen(3);

		for(int i = 0; i < 5; i++) {
			frogger.setPlacedHome(i, false);
		}
	}

}




