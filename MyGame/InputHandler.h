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
    
    void HandleKeyEvent(const Tmt::KeyEvent& event);
    const std::set<Direction>& GetDirections() const;
    bool IsBlocked() const;
    void SetBlocked(bool blocked);
    
private:
    std::set<Direction> mDirections;
    void AddDirection(int key);
    void RemoveDirection(int key);
};


#endif /* InputHandler_h */
