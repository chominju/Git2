#include <iostream>
#include "Fire.h"
#include "InputHandler.h"
#include "Game.h"
#include "GameOverState.h"
#include "PlayState.h"
#include <SDL.h>

//void Enemy::update()
//{
//	GameObject::update();
//	m_y += 1;
//	//m_x += 1;
//	m_currentFrame = int(((SDL_GetTicks() / 100) % 6));
//}
Fire::Fire(const LoaderParams* pParams) : SDLGameObject(pParams)
{
	//p2 = PlayState::Instance()->getObj();
	m_gameObjects = PlayState::Instance()->getObj();
}

void Fire::draw()
{
	if (collision == false)
	{
		SDLGameObject::draw(); // we now use SDLGameObject
		update();
	}
}

void Fire::update()
{
	//	GameObject::update();
	//m_position.setY(m_position.getY());

	m_currentFrame = int(((SDL_GetTicks() / 100) % 1));

	m_position.setX(m_position.getX() - 2);

	if (checkCollision())
	{
		TheGame::Instance()->getStateMachine()->changeState(new GameOverState());
	}

}

void Fire::clean()
{
	SDL_Renderer* getRenderer = Game::Instance()->getRenderer();
	SDL_RenderClear(getRenderer);
}

float Fire::posX()
{
	return 0.0f;
}

float Fire::posY()
{
	return 0.0f;
}

void Fire::handleInput()
{

}


Fire::~Fire()
{
	std::cout << "Fire is finish";
}


bool Fire::checkCollision()
{
	float leftA, leftB;
	float rightA, rightB;
	float topA, topB;
	float bottomA, bottomB;

	/*p2 = dynamic_cast<SDLGameObject*>(m_gameObjects[0]);*/

	leftA = m_position.getX();
	rightA = m_position.getX() + m_width;
	topA = m_position.getY();
	bottomA = m_position.getY()+m_height;

	//leftB = m_gameObjects[0]->posX();
	//rightB = m_gameObjects[0]->posX() + 52;
	//topB = m_gameObjects[0]->posY();
	//bottomB = m_gameObjects[0]->posY() + 64;


	//If any of the sides from A are outside of B

	/*if (bottomA <= m_gameObjects[0]->posY()) { return false; }
	if (topA >= m_gameObjects[0]->posY() + 64) { return false; }
	if (rightA <= m_gameObjects[0]->posX()) { return false; }
	if (leftA >= m_gameObjects[0]->posX() + 52) { return false; }*/
	return false;
}
