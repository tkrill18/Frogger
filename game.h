// Names: Chris Giuffrida and Thomas Krill
// Class: Fundamentals of Computing
// Final Project
// File:  game.h
// Description:  Contains the interface of the Game class designed to store attributes for the game environment.
using namespace std;

class Game {
  public:
	Game(int, int, int, int);
	~Game();
	int getNumLives();
	int getTimeLeft();
	bool getPlacedHome(int);
	int getScore();
	int getRowsAdvanced();
	void setNumLives(int);
	void setTimeLeft(int);
	void setPlacedHome(int, bool);
	void setScore(int);
	void setRowsAdvanced(int);
  private:
    int numLives;
    int score;
    int rowsAdvanced;
    int timeLeft;
    bool placedHome[5];

};
