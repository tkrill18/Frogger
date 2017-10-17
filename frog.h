// Names: Chris Giuffrida and Thomas Krill
// Class: Fundamentals of Computing
// Final Project
// File:  frog.h
// Description:  Contains the interface of the Frog class designed to store attributes for the user-controlled frog.

using namespace std;
#include "game.h"

class Frog {
  public:
    Frog(double, double, int, int, double, double, char);
    ~Frog();
    double getXCenter();
    double getYCenter();
    int getLength();
    int getYGrid();
    double getXLeft();
    double getXRight();
    char getOrientation();
    void setXCenter(double);
    void setYCenter(double);
    void setLength(int);
    void setYGrid(int);
    void setXLeft(double);
    void setXRight(double);
    void setOrientation(char);
    void drawFrog();
    void moveFrog(char, Game&);
  private:
    double xCenter;
    double yCenter;
    int length;
    int yGrid;
    double xLeft;
    double xRight;
    char orientation;
};
