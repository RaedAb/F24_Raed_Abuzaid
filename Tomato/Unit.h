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
    struct CollisionResult {
        bool isColliding;
        float overlapX;
        float overlapY;
    };
    
    class TOMATO_API Unit
    {
    public:
        Unit(const std::string& fileName, float xCoord, float yCoord, int width, int height, bool visible = true);
        
        int GetWidth() const;
        int GetHeight() const;
        void SetWidth(int width);
        void SetHeight(int height);
        
        float GetXCoord() const;
        float GetYCoord() const;
        void SetCoords(int x, int y);
        void UpdateXCoord(int amount);
        void UpdateYCoord(int amount);
        
        bool IsVisible() const;
        void SetVisibility(bool visibility);
        
    private:
        Image mImage;
        float mXCoord{ 0.0 };
        float mYCoord{ 0.0 };
        int mWidth{ 0 };
        int mHeight{ 0 };
        bool mIsVisible{ true };
        
        friend CollisionResult TOMATO_API UnitsOverlap(const Unit& a, const Unit& b);
        friend class Renderer;
    };
    
    CollisionResult TOMATO_API UnitsOverlap(const Unit& a, const Unit& b);
}


#endif /* Unit_h */
