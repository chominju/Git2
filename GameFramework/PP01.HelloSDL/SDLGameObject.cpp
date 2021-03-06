#include "SDLGameObject.h"
#include "LoaderParams.h"
#include "TextureManager.h"
#include "Game.h"

SDLGameObject::SDLGameObject(const LoaderParams* pParams) : GameObject(pParams),
m_position(pParams->getX(), pParams->getY()),
m_velocity(0.0f, 0.0f), m_acceleration(0.0f, 0.0f)
{
	//m_x = pParams->getX();
	//m_y = pParams->getY();
	m_width = pParams->getWidth();
	m_height = pParams->getHeight();

	m_textureID = pParams->getTextureID();
	m_currentRow = 0;
	m_currentFrame = 0;
}

//void SDLGameObject::draw()
//{
//	/*TextureManager::Instance()->drawFrame(m_textureID, m_x, m_y,
//	m_width, m_height, m_currentRow, m_currentFrame,
//	TheGame::Instance()->getRenderer());*/
//
//	TextureManager::Instance()->drawFrame(m_textureID,
//		(int)m_position.getX(), (int)m_position.getY(),
//		m_width, m_height, m_currentRow, m_currentFrame,
//		TheGame::Instance()->getRenderer());
//
//}

void SDLGameObject::draw()
{
	if (m_velocity.getX() > 0)
	{
		TextureManager::Instance()->drawFrame(m_textureID,
			(Uint32)m_position.getX(), (Uint32)m_position.getY(),
			m_width, m_height, m_currentRow, m_currentFrame,
			TheGame::Instance()->getRenderer()/*,
			SDL_FLIP_HORIZONTAL*/);
	}
	else {
		TextureManager::Instance()->drawFrame(m_textureID,
			(Uint32)m_position.getX(), (Uint32)m_position.getY(),
			m_width, m_height, m_currentRow, m_currentFrame,
			TheGame::Instance()->getRenderer());
	}
}


void SDLGameObject::update()
{
	/*m_x += 1;*/
	m_velocity += m_acceleration;
	m_position += m_velocity;

}

void SDLGameObject::clean()
{
}

float SDLGameObject::posX()
{
	return 0.0f;
}

float SDLGameObject::posY()
{
	return 0.0f;
}

