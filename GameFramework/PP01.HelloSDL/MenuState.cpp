﻿#include <iostream>
#include "MenuState.h"
#include "TextureManager.h"
#include "game.h"
#include "MenuButton.h"
#include "PlayState.h"

MenuState* MenuState::s_pInstance = 0;
const std::string MenuState::s_menuID = "MENU";


void MenuState::update()
{
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->update();
	}
}

void MenuState::render()
{
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->draw();
	}
}

bool MenuState::onEnter()
{
	if (!TheTextureManager::Instance()->load("assets/button.png",
		"playbutton", TheGame::Instance()->getRenderer()))
	{
		return false;
	}
	if (!TheTextureManager::Instance()->load("assets/exit.png",
		"exitbutton", TheGame::Instance()->getRenderer()))
	{
		return false;
	}

    if (!TheTextureManager::Instance()->load("assets/sky.png",
        "sky", TheGame::Instance()->getRenderer()))
    {
        return false;
    }

	GameObject* button1 = new MenuButton(
		new LoaderParams(300, 100, 400, 100, "playbutton"),
		s_menuToPlay);

	GameObject* button2 = new MenuButton(
		new LoaderParams(300, 310, 400, 100, "exitbutton"),
		s_exitFromMenu);

    GameObject* background = new SDLGameObject(
        new LoaderParams(0, 0, 960, 640, "sky"));
 

    m_gameObjects.push_back(background);
	m_gameObjects.push_back(button1);
	m_gameObjects.push_back(button2);
   
	std::cout << "entering MenuState\n";
	return true;
}

bool MenuState::onExit()
{
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->clean();
	}
	m_gameObjects.clear();

	return true;
}

void MenuState::s_menuToPlay()
{
	TheGame::Instance()->getStateMachine()->changeState(
		new PlayState());
}

void MenuState::s_exitFromMenu()
{
	TheGame::Instance()->quit();
}