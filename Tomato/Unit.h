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
    class TOMATO_API Unit
    {
    public:
        Unit(const std::string& fileName, float xCoord, float yCoord, bool visible);
        
    private:
        Image mImage;
        float mXCoord{ 0.0 };
        float mYCoord{ 0.0 };
        bool visible{ true };
    };
}


#endif /* Unit_h */
