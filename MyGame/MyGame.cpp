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
#include "Elavator.h"
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
        // Collision with ground objects
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
        
        // reset location if out of bounds
        if (blob.GetYCoord() < 0) {
            blob.SetCoords(100, 100);
        }
        
        // Collision with ground object registered with the movement handler
        Tmt::CollisionResult groundResult = Tmt::UnitsOverlap(blob, *mMovementHandler.GetGroundObject());
        if (groundResult.type == Tmt::CollisionType::HARD)
        {
            mMovementHandler.SetGrounded(true);
            mInputHandler.SetBlocked(true);
            CollisionHandler::ResolveCollision(blob, *mGroundObjects.front(), groundResult);
        } else if (groundResult.type == Tmt::CollisionType::SOFT)
        {
            mMovementHandler.SetGrounded(true);
        } else
        {
            mMovementHandler.SetGrounded(false);
            mMovementHandler.SetGroundObject(mGroundObjects.front());
        }
        
        // Collision with collectibles
        for (auto it = mCollectibles.begin(); it != mCollectibles.end();)
        {
            Tmt::CollisionResult result = Tmt::UnitsOverlap(blob, **it);
            if (result.type == Tmt::CollisionType::SOFT || result.type == Tmt::CollisionType::HARD)
            {
                it = mCollectibles.erase(it);
            }
            else
            {
                ++it;
            }
        }

        
        if (blocked)
        {
            mInputHandler.SetBlocked(false);
        }
        
        Tmt::Renderer::Draw(sky);
        
        for (auto& groundObject : mGroundObjects)
        {
            Tmt::Renderer::Draw(*groundObject);
        }
        
        for (auto& collectible : mCollectibles)
        {
            Tmt::Renderer::Draw(*collectible);
        }
        
        mElevator1.Update();
        mElevator2.Update();
        mElevator3.Update();
        
        Tmt::Renderer::Draw(blob);
        
        if (mCollectibles.empty())
        {
            Tmt::Renderer::Draw(BigStar);
            
            Tmt::CollisionResult result = Tmt::UnitsOverlap(blob, BigStar);
            if (result.type == Tmt::CollisionType::SOFT || result.type == Tmt::CollisionType::HARD)
            {
                Tmt::Renderer::ClearScreen();
                Tmt::Renderer::Draw(WinScreen);
                mInputHandler.SetBlocked(true);
            }
        }
    }
    
private:
    Tmt::Unit blob{ "../MyGame/Assets/Drawing.png", 100, 100, 25, 25 };
    
    Tmt::Unit sky{ "../MyGame/Assets/Sky.png", 0, 0, 800, 600 };
    
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
        std::make_shared<Tmt::Unit>("../MyGame/Assets/LongGrassBlock.png", 0, 380, 75, 25),
        
        std::make_shared<Tmt::Unit>("../MyGame/Assets/GrassBlock.png", 684, 380, 25, 25),
        std::make_shared<Tmt::Unit>("../MyGame/Assets/GrassBlock.png", 592, 380, 25, 25),
        std::make_shared<Tmt::Unit>("../MyGame/Assets/GrassBlock.png", 500, 380, 25, 25),
        std::make_shared<Tmt::Unit>("../MyGame/Assets/GrassBlock.png", 408, 380, 25, 25),
        std::make_shared<Tmt::Unit>("../MyGame/Assets/GrassBlock.png", 316, 380, 25, 25),
        std::make_shared<Tmt::Unit>("../MyGame/Assets/GrassBlock.png", 224, 380, 25, 25),
        std::make_shared<Tmt::Unit>("../MyGame/Assets/GrassBlock.png", 132, 380, 25, 25),
        std::make_shared<Tmt::Unit>("../MyGame/Assets/GrassBlock.png", 132, 380, 25, 25),
        
        std::make_shared<Tmt::Unit>("../MyGame/Assets/LongGrassBlock.png", 734, 350, 75, 25),
        
        /**                               LEVEL 4                                                                                   **/
        std::make_shared<Tmt::Unit>("../MyGame/Assets/LongGrassBlock.png", 105, 500, 75, 25),
        
        std::make_shared<Tmt::Unit>("../MyGame/Assets/GrassBlock.png", 602, 528, 25, 25),
        std::make_shared<Tmt::Unit>("../MyGame/Assets/GrassBlock.png", 418, 528, 25, 25),
        std::make_shared<Tmt::Unit>("../MyGame/Assets/GrassBlock.png", 234, 528, 25, 25),
        
        std::make_shared<Tmt::Unit>("../MyGame/Assets/LongGrassBlock.png", 734, 500, 75, 25),
    };
    
    Elevator mElevator1{ mGroundObjects[17].get(), 100, 1 };
    Elevator mElevator2{ mGroundObjects[18].get(), 100, 1 };
    Elevator mElevator3{ mGroundObjects[28].get(), 550, 0, 1 };
    
    std::list<std::shared_ptr<Tmt::Unit>> mCollectibles = {
        /**                              LEVEL 1                                                                                   **/
        std::make_shared<Tmt::Unit>("../MyGame/Assets/Star.png", 602, 240, 20, 20),
        std::make_shared<Tmt::Unit>("../MyGame/Assets/Star.png", 510, 240, 20, 20),
        std::make_shared<Tmt::Unit>("../MyGame/Assets/Star.png", 418, 240, 20, 20),
        std::make_shared<Tmt::Unit>("../MyGame/Assets/Star.png", 326, 240, 20, 20),
        std::make_shared<Tmt::Unit>("../MyGame/Assets/Star.png", 234, 240, 20, 20),
        std::make_shared<Tmt::Unit>("../MyGame/Assets/Star.png", 142, 240, 20, 20),
        
        /**                               LEVEL 2                                                                                     **/
        // Above stars
        std::make_shared<Tmt::Unit>("../MyGame/Assets/Star.png", 684, 412, 20, 20),
        std::make_shared<Tmt::Unit>("../MyGame/Assets/Star.png", 592, 412, 20, 20),
        std::make_shared<Tmt::Unit>("../MyGame/Assets/Star.png", 500, 412, 20, 20),
        std::make_shared<Tmt::Unit>("../MyGame/Assets/Star.png", 408, 412, 20, 20),
        std::make_shared<Tmt::Unit>("../MyGame/Assets/Star.png", 316, 412, 20, 20),
        std::make_shared<Tmt::Unit>("../MyGame/Assets/Star.png", 224, 412, 20, 20),
        std::make_shared<Tmt::Unit>("../MyGame/Assets/Star.png", 132, 412, 20, 20),
        std::make_shared<Tmt::Unit>("../MyGame/Assets/Star.png", 132, 412, 20, 20),
        // Below Stars
        std::make_shared<Tmt::Unit>("../MyGame/Assets/Star.png", 684, 350, 20, 20),
        std::make_shared<Tmt::Unit>("../MyGame/Assets/Star.png", 592, 350, 20, 20),
        std::make_shared<Tmt::Unit>("../MyGame/Assets/Star.png", 500, 350, 20, 20),
        std::make_shared<Tmt::Unit>("../MyGame/Assets/Star.png", 408, 350, 20, 20),
        std::make_shared<Tmt::Unit>("../MyGame/Assets/Star.png", 316, 350, 20, 20),
        std::make_shared<Tmt::Unit>("../MyGame/Assets/Star.png", 224, 350, 20, 20),
        std::make_shared<Tmt::Unit>("../MyGame/Assets/Star.png", 132, 350, 20, 20),
        std::make_shared<Tmt::Unit>("../MyGame/Assets/Star.png", 132, 350, 20, 20),
        
        /**                               LEVEL 4                                                                                     **/
        std::make_shared<Tmt::Unit>("../MyGame/Assets/Star.png", 602, 560, 20, 20),
        std::make_shared<Tmt::Unit>("../MyGame/Assets/Star.png", 418, 560, 20, 20),
        std::make_shared<Tmt::Unit>("../MyGame/Assets/Star.png", 234, 560, 20, 20),
    };
    
    Tmt::Unit BigStar{ "../MyGame/Assets/Star.png", 734, 532, 50, 50 };
    
    Tmt::Unit WinScreen{ "../MyGame/Assets/WinScreen.png", 0, 0, 800, 600 };
    
    std::list<std::shared_ptr<Tmt::Unit>> mNonCollidables = {
    };
    
    enum class mDirection { LEFT, RIGHT, UP, DOWN, IDLE, BLOCKED };
    std::set<mDirection> mCurrDirections{ mDirection::IDLE };
    
    InputHandler mInputHandler;
    MovementHandler mMovementHandler;
};

TOMATO_GAME_START(MyGameApplication)
