#pragma once
#include "Tomato.h"

class CollisionHandler
{
public:
    static void ResolveCollision(Tmt::Unit& movingUnit, const Tmt::Unit& staticUnit, const Tmt::CollisionResult& result);
};
