//
//  MovementHandler.h
//  MyGame
//
//  Created by Game on 12/17/24.
//

#include "Tomato.h"
#include "InputHandler.h"

class MovementHandler
{
public:
    MovementHandler() : mVelocityY(-10), mSpeed(5), mGravity(-1) {}
    
    void UpdatePosition(Tmt::Unit& object, const std::set<InputHandler::Direction>& directions)
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
    
    
    void SetGroundObject(std::shared_ptr<Tmt::Unit> object)
    {
        if (mGroundObject == object) return;
        
        mGroundObject = object;
    }
    
    std::shared_ptr<Tmt::Unit> GetGroundObject()
    {
        return mGroundObject;
    }
    
    void SetGrounded(bool grounded) { mIsGrounded = grounded; };
    
private:
    bool mIsJumping{ false };
    bool mIsGrounded;
    float mVelocityY{ 0 };
    int mSpeed{ 0 };
    int mGravity{ 0 };
    std::shared_ptr<Tmt::Unit> mGroundObject{ nullptr };
};
