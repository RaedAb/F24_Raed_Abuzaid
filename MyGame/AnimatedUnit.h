//
//  AnimatedUnit.h
//  MyGame
//
//  Created by Game on 12/16/24.
//

// AnimatedUnit.h
#ifndef AnimatedUnit_h
#define AnimatedUnit_h

#include "Tomato.h"
#include <unordered_map>
#include <vector>

class TOMATO_API AnimatedUnit : public Tmt::Unit
{
public:
    AnimatedUnit(const std::string& fileName, float xCoord, float yCoord, int width, int height, bool visible = true);
    
    void AddAnimation(const std::string& animationName, const std::vector<Tmt::Image>& frames);
    std::vector<Tmt::Image>& GetAnimation(const std::string& animationName);
    void SetCurrentAnimation(const std::string& animationName);
    std::vector<Tmt::Image>& GetCurrentAnimation();
    void PlayCurrentAnimation();
    
private:
    std::unordered_map<std::string, std::vector<Tmt::Image>> mAnimations;
    std::string mCurrentAnimationName;
    size_t mCurrentFrameIndex{ 0 };
};

#endif /* AnimatedUnit_h */

