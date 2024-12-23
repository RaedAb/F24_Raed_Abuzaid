//
//  InputHandler.cpp
//  MyGame
//
//  Created by Game on 12/23/24.
//

#include "InputHandler.h"

void InputHandler::HandleKeyEvent(const Tmt::KeyEvent& event)
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

const std::set<InputHandler::Direction>& InputHandler::GetDirections() const
{
    return mDirections;
}

bool InputHandler::IsBlocked() const
{
    return mDirections.count(Direction::BLOCKED);
}

void InputHandler::SetBlocked(bool blocked)
{
    if (blocked) mDirections.insert(Direction::BLOCKED);
    else mDirections.erase(Direction::BLOCKED);
}

void InputHandler::AddDirection(int key)
{
    switch (key) {
        case TOMATO_KEY_LEFT: mDirections.insert(Direction::LEFT); break;
        case TOMATO_KEY_RIGHT: mDirections.insert(Direction::RIGHT); break;
        case TOMATO_KEY_UP: mDirections.insert(Direction::UP); break;
        case TOMATO_KEY_DOWN: mDirections.insert(Direction::DOWN); break;
    }
}

void InputHandler::RemoveDirection(int key)
{
    switch (key) {
        case TOMATO_KEY_LEFT: mDirections.erase(Direction::LEFT); break;
        case TOMATO_KEY_RIGHT: mDirections.erase(Direction::RIGHT); break;
        case TOMATO_KEY_UP: mDirections.erase(Direction::UP); break;
        case TOMATO_KEY_DOWN: mDirections.erase(Direction::DOWN); break;
    }
}

