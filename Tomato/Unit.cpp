//
//  Unit.cpp
//  Tomato
//
//  Created by Game on 12/11/24.
//

#include "pch.h"
#include "Unit.h"

namespace Tmt
{
    Unit::Unit(const std::string& fileName, float xCoord, float yCoord, int width, int height, bool visible)
    : mImage(fileName), mXCoord(xCoord), mYCoord(yCoord), mWidth(width), mHeight(height), mIsVisible(visible)
    {
    }
    
    int Unit::GetWidth() const
    {
        return mWidth;
    }
    
    int Unit::GetHeight() const
    {
        return mHeight;
    }
    
    void Unit::SetWidth(int width)
    {
        mWidth = width;
    }
    
    void Unit::SetHeight(int height)
    {
        mHeight = height;
    }
    
    float Unit::GetXCoord() const
    {
        return mXCoord;
    }
    
    float Unit::GetYCoord() const
    {
        return mYCoord;
    }
    
    void Unit::SetCoords(int x, int y)
    {
        mXCoord = x;
        mYCoord = y;
    }
    
    void Unit::UpdateXCoord(int amount)
    {
        mXCoord += amount;
    }
    
    void Unit::UpdateYCoord(int amount)
    {
        mYCoord += amount;
    }
    
    void Unit::SetVisibility(bool visibility)
    {
        mIsVisible = visibility;
    }
    
    bool Unit::IsVisible() const
    {
        return mIsVisible;
    }
    
    CollisionResult UnitsOverlap(const Unit& a, const Unit& b)
    {
        float left_a{ a.mXCoord };
        float right_a{ a.mXCoord + a.mWidth };
        float bot_a{ a.mYCoord };
        float top_a{ a.mYCoord + a.mHeight };
        
        float left_b{ b.mXCoord };
        float right_b{ b.mXCoord + b.mWidth };
        float bot_b{ b.mYCoord };
        float top_b{ b.mYCoord + b.mHeight };
        
        bool x_intersection = (left_a < right_b && right_a > left_b);
        
        bool y_intersection = (bot_a < top_b && top_a > bot_b);
        
        if (!x_intersection || !y_intersection) {
            return { false, 0.0f, 0.0f };
        }
        
        float overlapX = std::min(right_a, right_b) - std::max(left_a, left_b);
        float overlapY = std::min(top_a, top_b) - std::max(bot_a, bot_b);
        
        return { true, overlapX, overlapY };
    }

}
