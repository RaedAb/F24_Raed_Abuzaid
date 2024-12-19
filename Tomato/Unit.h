//
//  Unit.h
//  Tomato
//
//  Created by Game on 12/11/24.
//

#ifndef Unit_h
#define Unit_h

#include "TomatoUtilities.h"
#include "Image.h"
#include "pch.h"

namespace Tmt
{
    enum class CollisionType { SOFT, HARD, NONE };
    
    struct CollisionResult {
        CollisionType type;
        float overlapX;
        float overlapY;
    };
    
    class TOMATO_API Unit
    {
    public:
        Unit(const std::string& fileName, float xCoord, float yCoord, int width, int height, bool visible = true);
        
        float GetWidth() const;
        float GetHeight() const;
        void SetWidth(float width);
        void SetHeight(float height);
        
        float GetXCoord() const;
        float GetYCoord() const;
        void SetCoords(float x, float y);
        void UpdateXCoord(float amount);
        void UpdateYCoord(float amount);
        
        bool IsVisible() const;
        void SetVisibility(bool visibility);
        
    private:
        Image mImage;
        float mXCoord{ 0.0 };
        float mYCoord{ 0.0 };
        float mWidth{ 0 };
        float mHeight{ 0 };
        bool mIsVisible{ true };
        
        friend CollisionResult TOMATO_API UnitsOverlap(Unit& a, Unit& b);
        friend class Renderer;
    };
    
    CollisionResult TOMATO_API UnitsOverlap(Unit& a, Unit& b);
}


#endif /* Unit_h */
