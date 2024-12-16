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
    Unit::Unit(const std::string& fileName, float xCoord, float yCoord, bool visible)
        : mImage(fileName), mXCoord(xCoord), mYCoord(yCoord), mIsVisible(visible)
    {
    }
    
    int Unit::GetWidth() const
    {
        return mImage.GetWidth();
    }
    
    int Unit::GetHeight() const
    {
        return mImage.GetHeight();
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
    
    bool UnitsOverlap(const Unit& a, const Unit& b)
    {
        float left_a{ a.mXCoord };
        float right_a{ a.mXCoord + a.mImage.GetWidth() };
        float left_b{ b.mXCoord };
        float right_b{ b.mXCoord + b.mImage.GetWidth() };
        
        bool x_intersection{ (left_a <= left_b && left_b <= right_a) ||
            (left_b <= left_a && left_a <= right_b) };
        
        float bot_a{ a.mYCoord };
        float top_a{ a.mYCoord + a.mImage.GetHeight() };
        float bot_b{ b.mYCoord };
        float top_b{ b.mYCoord + b.mImage.GetHeight() };
        
        bool y_intersection{ (bot_a <= bot_b && bot_b <= top_a) ||
            (bot_b <= bot_a && bot_a <= top_b) };
        
        return x_intersection && y_intersection;
    }
}
