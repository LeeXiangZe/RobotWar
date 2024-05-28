#include <iostream>
#include <string>
#include <time.h>
using namespace std;

// class Battlefield
// {
// public:
//     int lenX, widthY, steps, robots, coorX, coorY;
//     string robotName, robotType;
//     void input(int lenX, int widthY, int robots, int coorX, int coorY, string robotName, string robotType)
// };

class Robot
{
public:
    int lives, level, coorX, coorY;
    string name;
    virtual void action(int, int)=0;
    virtual ~Robot() {};
};

class MovingRobot : public Robot
{
public:
    void action(int x, int y)
    {
        coorX = x;
        coorY = y;
        cout << "I'm now moving to " << coorX << "," << coorY << endl;
    }
};

class ShootingRobot : public Robot
{
public:
    void action(int x, int y)
    {
        coorX = x;
        coorY = y;
        cout << "I'm now shooting at " << coorX << "," << coorY << endl;
    }
};

class SeeingRobot : virtual public Robot
{
public:
    void action(int x, int y)
    {
        coorX = x;
        coorY = y;
        cout << "I'm now looking at " << coorX << "," << coorY << endl;
    }
};

class SteppingRobot : public Robot
{
public:
    void action(int x, int y)
    {
        coorX = x;
        coorY = y;
        cout << "I'm now stepping at " << coorX << "," << coorY << endl;
    }
};

class RoboCop : public MovingRobot, public ShootingRobot
{
public:
    void move(int x, int y)
    {
        MovingRobot::action(x, y);
    }
    void fire(int x, int y)
    {
        ShootingRobot::action(x, y);
    }  
};

class Terminator : public SeeingRobot, public MovingRobot
{
public:
    void look(int x, int y)
    {
        SeeingRobot::action(x, y);
    }
    void fire(int x, int y)
    {
        MovingRobot::action(x, y);
    }  
};

class TerminatorRoboCop : public ShootingRobot, public SteppingRobot
{
public:
    void fire(int x, int y)
    {
        ShootingRobot::action(x, y);
    }
    void step(int x, int y)
    {
        SteppingRobot::action(x, y);
    }  
};

class BlueThunder : public ShootingRobot
{
public:
    void fire(int x, int y)
    {
        ShootingRobot::action(x, y);
    } 
};

class MadBot : public ShootingRobot
{
public:
    void fire(int x, int y)
    {
        ShootingRobot::action(x, y);
    }  
};

class RoboTank : public ShootingRobot
{
public:
    void fire(int x, int y)
    {
        ShootingRobot::action(x, y);
    }  
};

class UltimateRobot : public MovingRobot, public SteppingRobot, public ShootingRobot
{
public:
    void move(int x, int y)
    {
        MovingRobot::action(x, y);
    }
    void step(int x, int y)
    {
        SteppingRobot::action(x, y);
    }  
    void fire(int x, int y)
    {
        ShootingRobot::action(x, y);
    }  
};

int main()
{
    UltimateRobot Max;
    
    Max.move(3,5);
    Max.fire(4,6);
    Max.step(2,3);  

    return 0;
}