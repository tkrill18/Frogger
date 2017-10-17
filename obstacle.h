// Names: Chris Giuffrida and Thomas Krill
// Class: Fundamentals of Computing
// Final Project
// File:  obstacle.h
// Description:  Contains the implementation of the Obstacle class designed to store attributes for the obstacles the frog must avoid.

using namespace std;


class Obstacle {
  public:
  	Obstacle();
    Obstacle(double, int, int, double, double, double, bool);
    ~Obstacle();
    double getXCenter();
    int getLength();
    int getYGrid();
    double getXLeft();
    double getXRight();
    double getVelocity();
    bool getCanRide();
    void setXCenter(double);
    void setLength(int);
    void setYGrid(int);
    void setXLeft(double);
    void setXRight(double);
    void setVelocity(double);
    void setCanRide(bool);
    void drawObstacle();
    void moveObstacle();
  private:  
  	double xCenter;
    int length;
    int yGrid;
    double xLeft;
    double xRight;
    double velocity;
    bool canRide;
};
