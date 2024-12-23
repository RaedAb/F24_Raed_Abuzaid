//
//  MovementHandler.cpp
//  MyGame
//
//  Created by Game on 12/23/24.
//

#include "MovementHandler.h"

MovementHandler::MovementHandler() : mVelocityY(-10), mSpeed(5), mGravity(-1) {}

void MovementHandler::UpdatePosition(Tmt::Unit& object, const std::set<InputHandler::Direction>& directions)
{
    for (const auto& direction : directions)
    {
        switch (direction)
        {
            case InputHandler::Direction::LEFT:
                object.UpdateXCoord(-mSpeed);
                break;
                
            case InputHandler::Direction::RIGHT:
                object.UpdateXCoord(mSpeed);
                break;
                
            case InputHandler::Direction::UP:
                if (!mIsJumping)
                {
                    mIsJumping = true;
                    mIsGrounded = false;
                    mVelocityY = 10;
                }
                break;
                
            default:
                break;
        }
    }
    
    if (mIsJumping || !mIsGrounded)
    {
        if (mVelocityY > -10) mVelocityY += mGravity;
    }
    
    if (mIsGrounded)
    {
        mVelocityY = 0;
        mIsJumping = false;
    }
    
    object.UpdateYCoord(mVelocityY);
    
}


void MovementHandler::SetGroundObject(std::shared_ptr<Tmt::Unit> object)
{
    if (mGroundObject == object) return;
    
    mGroundObject = object;
}

std::shared_ptr<Tmt::Unit> MovementHandler::GetGroundObject()
{
    return mGroundObject;
}

void MovementHandler::SetGrounded(bool grounded)
{
    mIsGrounded = grounded;
};

