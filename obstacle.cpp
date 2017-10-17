// Names: Chris Giuffrida and Thomas Krill
// Class: Fundamentals of Computing
// Final Project
// File:  obstacle.cpp
// Description:  Contains the implementation of the Obstacle class designed to store attributes for the obstacles the frog must avoid.

#include "obstacle.h"
#include "gfxnew_mac.h"
#include <iostream>

using namespace std;

Obstacle::Obstacle()
{
	this->xCenter = 0;
	this->length = 0;
	this->yGrid = 0;
	this->xLeft = 0;
	this->xRight = 0;
	this->velocity = 0;
	this->canRide = 0;
}

Obstacle::Obstacle(double xCenter, int length, int yGrid, double xLeft, double xRight, double velocity, bool canRide)
{
	this->xCenter = xCenter;
	this->length = length;
	this->yGrid = yGrid;
	this->xLeft = xLeft;
	this->xRight = xRight;
	this->velocity = velocity;
	this->canRide = canRide;

}

Obstacle::~Obstacle() { }

double Obstacle::getXCenter()
{return xCenter;}

int Obstacle::getLength()
{return length;}

int Obstacle::getYGrid()
{return yGrid;}

double Obstacle::getXLeft()
{return xLeft;}

double Obstacle::getXRight()
{return xRight;}

double Obstacle::getVelocity()
{return velocity;}

bool Obstacle::getCanRide()
{return canRide;}

void Obstacle::setXCenter(double xCenter)
{this->xCenter = xCenter;}

void Obstacle::setLength(int length)
{this->length = length;}

void Obstacle::setYGrid(int yGrid)
{this->yGrid = yGrid;}

void Obstacle::setXLeft(double xLeft)
{this->xLeft = xLeft;}

void Obstacle::setXRight(double xRight)
{this->xRight = xRight;}

void Obstacle::setVelocity(double velocity)
{this->velocity = velocity;}

void Obstacle::setCanRide(bool canRide)
{this->canRide = canRide;}


// Draw each obstacle
void Obstacle::drawObstacle()
{
  // Set the color based on the row the obstacle is in
	if(yGrid == 3) {
		gfx_color(255, 255, 0);
	}
	else if (yGrid == 4) {
		gfx_color(0, 204, 0);
	}
	else if (yGrid == 5) {
		gfx_color(255, 0, 255);	
	}
	else if (yGrid == 6) {
		gfx_color(102, 204, 0);
	}
	else if (yGrid == 7) {
		gfx_color(160, 160, 160);
	}
	else if ((yGrid == 9) || (yGrid == 12)) {
		gfx_color(255, 0, 0);	
	}
	else if ((yGrid == 10) || (yGrid == 11) || (yGrid == 13)) {
		gfx_color(102, 51, 0);	
	} 
  // Physically draw obstacle
	gfx_fill_rectangle(xLeft, 750 - yGrid * 50, length * 50, 50);
}

// Move obstacle to next position using velocity value
void Obstacle::moveObstacle()
{
  // Update parameters using velocity
	xCenter += velocity;
	xLeft += velocity;
	xRight += velocity;

  // Once the frog moves a certain distance off screen, reset him to other side
	if(velocity < 0) {
		if(xCenter <= -250) {
			xCenter = 750 + ((length * 50.) / 2); 
			xLeft = 750;
			xRight = 750 + length * 50;
		}
	} 
	else {
		if(xCenter >= 1000) {
			xCenter = 0 - ((length * 50.) /2);
			xLeft = 0 - length * 50;
			xRight = 0;
		}
	}

}

