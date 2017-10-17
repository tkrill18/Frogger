// Names: Chris Giuffrida and Thomas Krill
// Class: Fundamentals of Computing
// Final Project
// File:  game.cpp
// Description:  Contains the implementation of the Game class designed to store attributes for the game environment.

#include "game.h"
#include "gfxnew_mac.h"

using namespace std;

Game::Game(int numLives, int score, int rowsAdvanced, int timeLeft) 
{
   this->numLives = numLives;
   this->score = score;
   this->rowsAdvanced = rowsAdvanced;
   this->timeLeft = timeLeft;
   
   for (int i = 0; i < 5; i++)
   {
      placedHome[i] = false;
   }
}

Game::~Game() { };

int Game::getNumLives()
{return numLives;}

int Game::getTimeLeft()
{return timeLeft;}

bool Game::getPlacedHome(int index)
{return placedHome[index];}

int Game::getScore()
{return score;}

int Game::getRowsAdvanced()
{return rowsAdvanced;}

void Game::setNumLives(int numLives)
{this->numLives = numLives;}

void Game::setTimeLeft(int timeLeft)
{this->timeLeft = timeLeft;}

void Game::setPlacedHome(int index, bool placed)
{placedHome[index] = placed;}

void Game::setScore(int score)
{this->score = score;}

void Game::setRowsAdvanced(int rowsAdvanced)
{this->rowsAdvanced = rowsAdvanced;}

