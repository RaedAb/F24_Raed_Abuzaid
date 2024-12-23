//
//  CollisionHandler.cpp
//  MyGame
//
//  Created by Game on 12/23/24.
//

#include "CollisionHandler.h"

void CollisionHandler::ResolveCollision(Tmt::Unit& movingUnit, const Tmt::Unit& staticUnit, const Tmt::CollisionResult& result)
{
    if (result.type == Tmt::CollisionType::HARD)
    {
        if (result.overlapX < result.overlapY)
        {
            if (movingUnit.GetXCoord() < staticUnit.GetXCoord())
            {
                movingUnit.UpdateXCoord(-result.overlapX);
            }
            else
            {
                movingUnit.UpdateXCoord(result.overlapX);
            }
        }
        else
        {
            if (movingUnit.GetYCoord() < staticUnit.GetYCoord()) {
                float separation = staticUnit.GetYCoord() - (movingUnit.GetYCoord() + movingUnit.GetHeight());
                movingUnit.UpdateYCoord(separation - 1.0f);
            }
            else {
                float separation = (staticUnit.GetYCoord() + staticUnit.GetHeight()) - movingUnit.GetYCoord();
                movingUnit.UpdateYCoord(separation + 1.0f);
            }
        }
    }
}
