//
//  AnimatedUnit.cpp
//  MyGame
//
//  Created by Game on 12/16/24.
//
#include "AnimatedUnit.h"

AnimatedUnit::AnimatedUnit(const std::string& fileName, float xCoord, float yCoord, int width, int height, bool visible)
    : Unit(fileName, xCoord, yCoord, width, height, visible)
{
}

void AnimatedUnit::AddAnimation(const std::string& animationName, const std::vector<Tmt::Image>& frames)
{
    mAnimations[animationName] = frames;
}

std::vector<Tmt::Image>& AnimatedUnit::GetAnimation(const std::string& animationName)
{
    return mAnimations.at(animationName);
}

void AnimatedUnit::SetCurrentAnimation(const std::string& animationName)
{
    mCurrentAnimationName = animationName;
    mCurrentFrameIndex = 0;
}

std::vector<Tmt::Image>& AnimatedUnit::GetCurrentAnimation()
{
    return mAnimations.at(mCurrentAnimationName);
}

void AnimatedUnit::PlayCurrentAnimation()
{
    if (mCurrentAnimationName.empty())
    {
        return;  // No animation set
    }
    
    std::vector<Tmt::Image>& currentAnimation = GetCurrentAnimation();
    
    if (mCurrentFrameIndex < currentAnimation.size())
    {
        Tmt::Renderer::Draw(currentAnimation[mCurrentFrameIndex], GetXCoord(), GetYCoord(), GetWidth(), GetHeight());
        ++mCurrentFrameIndex;
    }
    else
    {
        mCurrentFrameIndex = 0;  // Loop the animation
    }
}
