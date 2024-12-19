//
//  MyGameApplication.cpp
//  MyGame
//
//  Created by Game on 9/12/24.
//

//#include "MyGameApplication.hpp"
#include "Tomato.h"
#include "InputHandler.h"
#include "MovementHandler.h"
#include "CollisionHandler.h"
#include <iostream>
#include <set>
#include <list>

class MyGameApplication : public Tmt::TomatoApplication
{
    virtual void Initialize() override
    {
        TOMATO_LOG("Starting...");
        
        SetKeyEventHandler([this](const Tmt::KeyEvent& event) { mInputHandler.HandleKeyEvent(event); });
        mMovementHandler.SetGroundObject(mGroundObjects[0]);
    }
    
    virtual void Update() override
    {
        if (!mInputHandler.IsBlocked())
        {
            mMovementHandler.UpdatePosition(blob, mInputHandler.GetDirections());
        }
        
        
        bool blocked = false;
        for (auto& groundObject : mGroundObjects)
        {
            Tmt::CollisionResult result = Tmt::UnitsOverlap(blob, *groundObject);
            if (result.type == Tmt::CollisionType::SOFT || result.type == Tmt::CollisionType::HARD)
            {
                mMovementHandler.SetGroundObject(groundObject);
                mMovementHandler.SetGrounded(true);
                if (result.type == Tmt::CollisionType::HARD)
                {
                    mInputHandler.SetBlocked(true);
                    blocked = true;
                }
                CollisionHandler::ResolveCollision(blob, *groundObject, result);
            }
        }
        
        Tmt::CollisionResult groundResult = Tmt::UnitsOverlap(blob, *mMovementHandler.GetGroundObject());
        if (groundResult.type == Tmt::CollisionType::HARD)
        {
            mMovementHandler.SetGrounded(true);
            mInputHandler.SetBlocked(true);
            CollisionHandler::ResolveCollision(blob, *mGroundObjects.front(), groundResult);
//            TOMATO_LOG("hard collision detected")
        } else if (groundResult.type == Tmt::CollisionType::SOFT)
        {
            mMovementHandler.SetGrounded(true);
//            TOMATO_LOG("soft collision detected")
        } else
        {
//            TOMATO_LOG("No collision detected")
            mMovementHandler.SetGrounded(false);
            mMovementHandler.SetGroundObject(mGroundObjects.front());
        }
        
        if (blocked)
        {
            mInputHandler.SetBlocked(false);
        }
        
        for (auto& groundObject : mGroundObjects)
        {
            Tmt::Renderer::Draw(*groundObject);
        }
        
        if (goingUp) {
            elevator->UpdateYCoord(1);
            counter++;
            if (counter >= 125) {
                goingUp = false;
                counter = 0;
            }
        } else {
            elevator->UpdateYCoord(-1);
            counter++;
            if (counter >= 125) {
                goingUp = true;
                counter = 0;
            }
        }
        
        Tmt::Renderer::Draw(blob);
    }
    
private:
    Tmt::Unit blob{ "../MyGame/Assets/Drawing.png", 100, 100, 25, 25 };
    
    std::vector<std::shared_ptr<Tmt::Unit>> mGroundObjects = {
        /**                              LEVEL 1                                                                                   **/
        std::make_shared<Tmt::Unit>("../MyGame/Assets/LongGround.png", 0, 0, 400, 25),
        std::make_shared<Tmt::Unit>("../MyGame/Assets/LongGround.png", 400, 0, 400, 25),
        
        
        std::make_shared<Tmt::Unit>("../MyGame/Assets/GrassBlock.png", 550, 25, 25, 25),
        std::make_shared<Tmt::Unit>("../MyGame/Assets/GrassBlock.png", 573, 47, 25, 25),
        std::make_shared<Tmt::Unit>("../MyGame/Assets/GrassBlock.png", 596, 70, 25, 25),
        std::make_shared<Tmt::Unit>("../MyGame/Assets/GrassBlock.png", 619, 93, 25, 25),
        std::make_shared<Tmt::Unit>("../MyGame/Assets/GrassBlock.png", 642, 116, 25, 25),
        std::make_shared<Tmt::Unit>("../MyGame/Assets/GrassBlock.png", 665, 139, 25, 25),
        std::make_shared<Tmt::Unit>("../MyGame/Assets/GrassBlock.png", 688, 162, 25, 25),
        std::make_shared<Tmt::Unit>("../MyGame/Assets/GrassBlock.png", 711, 185, 25, 25),
        std::make_shared<Tmt::Unit>("../MyGame/Assets/LongGrassBlock.png", 734, 208, 75, 25),
        
        /**                               LEVEL 2                                                                                     **/
        std::make_shared<Tmt::Unit>("../MyGame/Assets/GrassBlock.png", 602, 208, 25, 25),
        std::make_shared<Tmt::Unit>("../MyGame/Assets/GrassBlock.png", 510, 208, 25, 25),
        std::make_shared<Tmt::Unit>("../MyGame/Assets/GrassBlock.png", 418, 208, 25, 25),
        std::make_shared<Tmt::Unit>("../MyGame/Assets/GrassBlock.png", 326, 208, 25, 25),
        std::make_shared<Tmt::Unit>("../MyGame/Assets/GrassBlock.png", 234, 208, 25, 25),
        std::make_shared<Tmt::Unit>("../MyGame/Assets/GrassBlock.png", 142, 208, 25, 25),
        
        
        std::make_shared<Tmt::Unit>("../MyGame/Assets/LongGrassBlock.png", 0, 208, 75, 25),
        
        /**                               LEVEL 3                                                                                     **/
        std::make_shared<Tmt::Unit>("../MyGame/Assets/GrassBlock.png", 684, 408, 25, 25),
        std::make_shared<Tmt::Unit>("../MyGame/Assets/GrassBlock.png", 592, 408, 25, 25),
        std::make_shared<Tmt::Unit>("../MyGame/Assets/GrassBlock.png", 500, 408, 25, 25),
        std::make_shared<Tmt::Unit>("../MyGame/Assets/GrassBlock.png", 408, 408, 25, 25),
        std::make_shared<Tmt::Unit>("../MyGame/Assets/GrassBlock.png", 316, 408, 25, 25),
        std::make_shared<Tmt::Unit>("../MyGame/Assets/GrassBlock.png", 224, 408, 25, 25),
        std::make_shared<Tmt::Unit>("../MyGame/Assets/GrassBlock.png", 132, 408, 25, 25),
        std::make_shared<Tmt::Unit>("../MyGame/Assets/GrassBlock.png", 132, 408, 25, 25),
//        std::make_shared<Tmt::Unit>("../MyGame/Assets/GrassBlock.png", 40, 408, 25, 25),
        std::make_shared<Tmt::Unit>("../MyGame/Assets/LongGrassBlock.png", 734, 375, 75, 25),
        
    };
    
    Tmt::Unit* elevator = mGroundObjects[17].get();
    bool goingUp{ true };
    int counter{ 0 };
    
    std::list<std::shared_ptr<Tmt::Unit>> mNonCollidables = {
    };
    
    enum class mDirection { LEFT, RIGHT, UP, DOWN, IDLE, BLOCKED };
    std::set<mDirection> mCurrDirections{ mDirection::IDLE };
    
    InputHandler mInputHandler;
    MovementHandler mMovementHandler;
};

TOMATO_GAME_START(MyGameApplication)
