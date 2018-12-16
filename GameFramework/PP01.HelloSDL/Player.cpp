#include <iostream>
#include "Player.h"
#include "SDLGameObject.h"
#include "InputHandler.h"
#include "Fire.h"

//void Player::load(int x, int y, int width, int height,
//	std::string textureID)
//{
//	GameObject::load(x, y, width, height, textureID);
//	// 이 코드가 의미가 있을까? 이코드가 없었다면, 자동으로 부모 호출?? 
//}

Player::Player(const LoaderParams* pParams) :SDLGameObject(pParams)
{
	speed = 2;
}

void Player::draw()
{
	SDLGameObject::draw(); // we now use SDLGameObject

	for (std::vector<GameObject*>::size_type i = 0;
		i != m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->draw(/*m_pRenderer*/);
	}
}

void Player::update()
{
	/*m_x -= 1;
	m_currentFrame = int(((SDL_GetTicks() / 100) % 6));*/

	//m_currentFrame = int(((SDL_GetTicks() / 100) % 6));
	//m_acceleration.setX(1);
	//SDLGameObject::update();

	delay--;

	printf("%d", delay);

	if (delay <= 0)
	{
		x = 1030;
		y = rand() % 480;

		GameObject* skill = new Fire(
			new LoaderParams(x, y, 48, 48, "skill"));
		m_gameObjects.push_back(skill);
		delay = rand() % 30;
	}


	m_velocity.setX(0);
	m_velocity.setY(0);
	handleInput(); // add our function
	m_currentFrame = int(((SDL_GetTicks() / 100) % 2));
	SDLGameObject::update();

}

void Player::clean()
{

}

float Player::posX()
{
	return m_position.getX();
}

float Player::posY()
{
	return m_position.getY();
}

void Player::handleInput()
{
	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_RIGHT))
	{
		m_currentRow = 0;
		m_velocity.setX(speed);
	}
	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_LEFT))
	{
		m_currentRow = 1;
		m_velocity.setX(-speed);
	}
	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_UP))
	{
		m_velocity.setY(-speed);
	}
	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_DOWN))
	{
		m_velocity.setY(speed);
	}

	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_A))
	{
		speed = 4;
	}
	else
	{
		speed = 2;
	}
}