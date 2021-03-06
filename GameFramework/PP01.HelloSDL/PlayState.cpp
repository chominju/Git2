﻿#include <iostream>
#include <random>
#include <time.h>
#include "PlayState.h"
#include "TextureManager.h"
#include "game.h"
#include "InputHandler.h"
#include "PauseState.h"
#include "Enemy.h"
#include "GameOverState.h"
#include "Fire.h"


PlayState* PlayState::s_pInstance = 0;
const std::string PlayState::s_playID = "PLAY";


void PlayState::update()
{
	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_ESCAPE))
	{
		TheGame::Instance()->getStateMachine()->changeState(
			new PauseState());
	}

	//else if (checkCollision(
	//	dynamic_cast<SDLGameObject*>(m_gameObjects[1]),
	//	dynamic_cast<SDLGameObject*>(m_gameObjects[2])))
	//{
	//	TheGame::Instance()->getStateMachine()->changeState(
	//		new GameOverState());
	//}

	for (int i = 0; i < m_gameObjects.size(); i++) {
		m_gameObjects[i]->update();
	}

	

}

void PlayState::render()
{
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->draw();
	}
}

bool PlayState::onEnter()
{
	srand(time(NULL));

	if (!TheTextureManager::Instance()->load("assets/witch.png",
		"player", TheGame::Instance()->getRenderer())) {
		return false;
	}
	if (!TheTextureManager::Instance()->load("assets/helicopter2.png",
		"helicopter2", TheGame::Instance()->getRenderer())) {
		return false;
	}

	if (!TheTextureManager::Instance()->load("assets/bomb.png",
		"skill", TheGame::Instance()->getRenderer())) {
		return false;
	}

	/*GameObject* player = new Player(
		new LoaderParams(500, 100, 48, 48, "player"));*/

	GameObject* player = new Player(
		new LoaderParams(500, 100, 52, 64, "player"));

	/*GameObject* enemy = new Enemy(
		new LoaderParams(100, 100, 128, 55, "helicopter2"));*/

	
	GameObject* background = new SDLGameObject(
		new LoaderParams(0, 0, 960, 640, "sky"));

	m_gameObjects.push_back(background);
	m_gameObjects.push_back(player);

	//m_gameObjects.push_back(enemy);
	std::cout << "entering PlayState\n";
	return true;
}
bool PlayState::onExit()
{
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->clean();
	}

	TheTextureManager::Instance()->clearFromTextureMap("helicopter");
	m_gameObjects.clear();

	std::cout << "exiting PlayState\n";
	return true;
}

bool PlayState::checkCollision(SDLGameObject * p1, SDLGameObject * p2)
{
	int leftA, leftB;
	int rightA, rightB;
	int topA, topB;
	int bottomA, bottomB;

	leftA = p1->getPosition().getX();
	rightA = p1->getPosition().getX() + p1->getWidth();
	topA = p1->getPosition().getY();
	bottomA = p1->getPosition().getY() + p1->getHeight();

	//Calculate the sides of rect B
	leftB = p2->getPosition().getX();
	rightB = p2->getPosition().getX() + p2->getWidth();
	topB = p2->getPosition().getY();
	bottomB = p2->getPosition().getY() + p2->getHeight();

	//If any of the sides from A are outside of B
	if (bottomA <= topB) { return false; }
	if (topA >= bottomB) { return false; }
	if (rightA <= leftB) { return false; }
	if (leftA >= rightB) { return false; }
	return true;
}

//std::vector<GameObject*> PlayState::getObj()
//{
//	return m_gameObjects;
//}


std::vector<GameObject*> PlayState::getObj()
{
	return m_gameObjects;
}

