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
        mMovementHandler.SetGroundObject(mGroundObjects.front());
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
            TOMATO_LOG("hard collision detected")
        } else if (groundResult.type == Tmt::CollisionType::SOFT)
        {
            mMovementHandler.SetGrounded(true);
            TOMATO_LOG("soft collision detected")
        } else
        {
            TOMATO_LOG("No collision detected")
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
        
        Tmt::Renderer::Draw(blob);
    }
    
private:
    Tmt::Unit blob{ "../MyGame/Assets/Drawing.png", 100, 200, 100, 100 };
    
    std::list<std::shared_ptr<Tmt::Unit>> mGroundObjects = {
        std::make_shared<Tmt::Unit>("../MyGame/Assets/Ground.png", 0, 0, 800, 100),
        std::make_shared<Tmt::Unit>("../MyGame/Assets/Ground.png", 500, 100, 75, 75),
    };
    
    enum class mDirection { LEFT, RIGHT, UP, DOWN, IDLE, BLOCKED };
    std::set<mDirection> mCurrDirections{ mDirection::IDLE };
    
    InputHandler mInputHandler;
    MovementHandler mMovementHandler;
};

TOMATO_GAME_START(MyGameApplication)
