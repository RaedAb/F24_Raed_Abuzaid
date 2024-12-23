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
    MovementHandler();
    
    void UpdatePosition(Tmt::Unit& object, const std::set<InputHandler::Direction>& directions);
    void SetGroundObject(std::shared_ptr<Tmt::Unit> object);
    std::shared_ptr<Tmt::Unit> GetGroundObject();
    void SetGrounded(bool grounded);
    
private:
    bool mIsJumping{ false };
    bool mIsGrounded;
    float mVelocityY{ 0 };
    int mSpeed{ 0 };
    int mGravity{ 0 };
    std::shared_ptr<Tmt::Unit> mGroundObject{ nullptr };
};
