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
    
    float Unit::GetWidth() const
    {
        return mWidth;
    }
    
    float Unit::GetHeight() const
    {
        return mHeight;
    }
    
    void Unit::SetWidth(float width)
    {
        mWidth = width;
    }
    
    void Unit::SetHeight(float height)
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
    
    void Unit::SetCoords(float x, float y)
    {
        mXCoord = x;
        mYCoord = y;
    }
    
    void Unit::UpdateXCoord(float amount)
    {
        mXCoord += amount;
    }
    
    void Unit::UpdateYCoord(float amount)
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
    
    
    CollisionResult UnitsOverlap(Unit& a, Unit& b)
    {
        float bufferMargin = 1.0f;
        float left_a{ a.mXCoord - bufferMargin };
        float right_a{ a.mXCoord + a.mWidth + bufferMargin };
        float bot_a{ a.mYCoord - bufferMargin };
        float top_a{ a.mYCoord + a.mHeight + bufferMargin };
        
        float left_b{ b.mXCoord - bufferMargin };
        float right_b{ b.mXCoord + b.mWidth + bufferMargin };
        float bot_b{ b.mYCoord - bufferMargin };
        float top_b{ b.mYCoord + b.mHeight + bufferMargin };
        
        bool x_intersection = (left_a < right_b && right_a > left_b);
        bool y_intersection = (bot_a < top_b && top_a > bot_b);
        
        if (!x_intersection || !y_intersection)
        {
            return { CollisionType::NONE, 0.0f, 0.0f };
        }
        
        float overlapX = std::min(right_a, right_b) - std::max(left_a, left_b);
        float overlapY = std::min(top_a, top_b) - std::max(bot_a, bot_b);
        
        if (overlapX > 0.0f && overlapY > 0.0f) {
            if (overlapX > bufferMargin && overlapY > bufferMargin) {
                return { CollisionType::HARD, overlapX, overlapY };
            }
            else
            {
                return { CollisionType::SOFT, overlapX, overlapY };
            }
        }
        
        return { CollisionType::NONE, 0.0f, 0.0f };
    }

}
