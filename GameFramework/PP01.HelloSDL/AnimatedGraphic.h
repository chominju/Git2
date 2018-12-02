#pragma once

#include "SDLGameObject.h"


class AnimatedGraphic : SDLGameObject
{
public:
	AnimatedGraphic(const LoaderParams* pParams, int animSpeed);

	int m_currentFrame;
	int m_animSpeed;
	int m_numFrames;


	void update();
	
};

