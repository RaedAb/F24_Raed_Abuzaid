//
//  InputHandler.h
//  MyGame
//
//  Created by Game on 12/17/24.
//

#ifndef InputHandler_h
#define InputHandler_h

#include "Tomato.h"
#include <set>

class InputHandler
{
public:
    enum class Direction { LEFT, RIGHT, UP, DOWN, IDLE, BLOCKED };
    
    void HandleKeyEvent(const Tmt::KeyEvent& event)
    {
        if (event.GetKeyAction() == Tmt::KeyEvent::KeyAction::Release)
        {
            RemoveDirection(event.GetKeyCode());
        }
        else if (event.GetKeyAction() == Tmt::KeyEvent::KeyAction::Press ||
                 event.GetKeyAction() == Tmt::KeyEvent::KeyAction::Repeat)
        {
            AddDirection(event.GetKeyCode());
        }
    }
    
    const std::set<Direction>& GetDirections() const { return mDirections; }
    
    bool IsBlocked() const { return mDirections.count(Direction::BLOCKED); }
    
    void SetBlocked(bool blocked)
    {
        if (blocked) mDirections.insert(Direction::BLOCKED);
        else mDirections.erase(Direction::BLOCKED);
    }
    
private:
    std::set<Direction> mDirections;
    
    void AddDirection(int key) {
        switch (key) {
            case TOMATO_KEY_LEFT: mDirections.insert(Direction::LEFT); break;
            case TOMATO_KEY_RIGHT: mDirections.insert(Direction::RIGHT); break;
            case TOMATO_KEY_UP: mDirections.insert(Direction::UP); break;
            case TOMATO_KEY_DOWN: mDirections.insert(Direction::DOWN); break;
        }
    }
    
    void RemoveDirection(int key) {
        switch (key) {
            case TOMATO_KEY_LEFT: mDirections.erase(Direction::LEFT); break;
            case TOMATO_KEY_RIGHT: mDirections.erase(Direction::RIGHT); break;
            case TOMATO_KEY_UP: mDirections.erase(Direction::UP); break;
            case TOMATO_KEY_DOWN: mDirections.erase(Direction::DOWN); break;
        }
    }
};


#endif /* InputHandler_h */
