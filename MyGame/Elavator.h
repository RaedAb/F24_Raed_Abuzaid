//
//  Elavator.h
//  MyGame
//
//  Created by Game on 12/23/24.
//
#include "Tomato.h"

class Elevator
{
public:
    Elevator(Tmt::Unit* unit, int stepsPerCycle, int speedY = 0, int speedX = 0)
    : mUnit(unit), mStepsPerCycle(stepsPerCycle), mSpeedY(speedY), mSpeedX(speedX) {}
    
    void Update()
    {
        if (mGoingUp)
        {
            mUnit->UpdateYCoord(mSpeedY);
            mUnit->UpdateXCoord(mSpeedX);
            mCounter++;
            if (mCounter >= mStepsPerCycle)
            {
                mGoingUp = false;
                mCounter = 0;
            }
        }
        else
        {
            mUnit->UpdateYCoord(-mSpeedY);
            mUnit->UpdateXCoord(-mSpeedX);
            mCounter++;
            if (mCounter >= mStepsPerCycle)
            {
                mGoingUp = true;
                mCounter = 0;
            }
        }
    }
    
private:
    Tmt::Unit* mUnit;
    int mStepsPerCycle;
    int mCounter{0};
    int mSpeedY;
    int mSpeedX;
    bool mGoingUp{true};
};

