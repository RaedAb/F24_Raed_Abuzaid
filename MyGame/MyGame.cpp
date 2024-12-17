//
//  MyGameApplication.cpp
//  MyGame
//
//  Created by Game on 9/12/24.
//

//#include "MyGameApplication.hpp"
#include "Tomato.h"
#include "AnimatedUnit.h"
#include <iostream>
#include <set>

class MyGameApplication : public Tmt::TomatoApplication
{
    virtual void Initialize() override
    {
        TOMATO_LOG("Starting...");
        
        SetKeyEventHandler([this](const Tmt::KeyEvent& event) {MyKeysHandler(event); });
    }
    
    virtual void Update() override
    {
        for (auto& direction : mCurrDirections) {
            if (direction == mDirection::LEFT) {
                blob.UpdateXCoord(-3);
            }
            
            if (direction == mDirection::RIGHT) {
                blob.UpdateXCoord(3);
            }
            
            if (direction == mDirection::UP) {
                blob.UpdateYCoord(3);
            }
            
            if (direction == mDirection::DOWN) {
                blob.UpdateYCoord(-3);
            }
        }
        
        Tmt::CollisionResult result = Tmt::UnitsOverlap(blob, wall);
        
        if (result.isColliding) {
            mCurrDirections.insert(mDirection::BLOCKED);
            
            if (result.overlapX < result.overlapY) {
                if (blob.GetXCoord() < wall.GetXCoord()) {
                    blob.UpdateXCoord(-result.overlapX);
                } else {
                    blob.UpdateXCoord(result.overlapX);
                }
            } else {
                if (blob.GetYCoord() < wall.GetYCoord()) {
                    blob.UpdateYCoord(-result.overlapY);
                } else {
                    blob.UpdateYCoord(result.overlapY);
                }
            }
        }
        
        if (mCurrDirections.find(mDirection::BLOCKED) != mCurrDirections.end() && !result.isColliding) {
            mCurrDirections.erase(mDirection::BLOCKED);
        }
        
        Tmt::Renderer::Draw(ground);
        Tmt::Renderer::Draw(wall);
        Tmt::Renderer::Draw(blob);
    }
    
private:
//    Tmt::Unit blob{ "../MyGame/Assets/Drawing.png", 100, 100 };
    Tmt::Unit ground{ "../MyGame/Assets/Ground.png", 0, 0, 800, 100 };
    Tmt::Unit wall{ "../MyGame/Assets/Ground.png", 500, 100, 100, 200 };
    
    AnimatedUnit blob{ "../MyGame/Assets/Drawing.png", 100, 100, 100, 100};
    
    enum class mDirection { LEFT, RIGHT, UP, DOWN, IDLE, BLOCKED };
    std::set<mDirection> mCurrDirections{ mDirection::IDLE };
    
    void MyKeysHandler(const Tmt::KeyEvent& event)
    {
        if (event.GetKeyAction() == Tmt::KeyEvent::KeyAction::Release)
        {
            switch (event.GetKeyCode())
            {
                case TOMATO_KEY_LEFT:
                    mCurrDirections.erase(mDirection::LEFT);
                    break;
                    
                case TOMATO_KEY_RIGHT:
                    mCurrDirections.erase(mDirection::RIGHT);
                    break;
                    
                case TOMATO_KEY_UP:
                    mCurrDirections.erase(mDirection::UP);
                    break;
                    
                case TOMATO_KEY_DOWN:
                    mCurrDirections.erase(mDirection::DOWN);
                    break;
            }
        }
        
        if (mCurrDirections.find(mDirection::BLOCKED) != mCurrDirections.end()) return;
        
        if (event.GetKeyAction() == Tmt::KeyEvent::KeyAction::Press ||
            event.GetKeyAction() == Tmt::KeyEvent::KeyAction::Repeat)
        {
            switch (event.GetKeyCode())
            {
                case TOMATO_KEY_LEFT:
                    mCurrDirections.insert(mDirection::LEFT);
                    break;

                case TOMATO_KEY_RIGHT:
                    mCurrDirections.insert(mDirection::RIGHT);
                    break;
                    
                case TOMATO_KEY_UP:
                    mCurrDirections.insert(mDirection::UP);
                    break;
                    
                case TOMATO_KEY_DOWN:
                    mCurrDirections.insert(mDirection::DOWN);
                    break;
            }
        }
    }
};

TOMATO_GAME_START(MyGameApplication)
