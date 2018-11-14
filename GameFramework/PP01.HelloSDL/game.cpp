#include <iostream>
#include "game.h"

bool Game::init(const char* title, int xpos, int ypos,
	int width, int height, bool fullscreen)
{
	if (SDL_Init(SDL_INIT_EVERYTHING) >= 0)
	{
		m_pWindow = SDL_CreateWindow(title, xpos, ypos,
			width, height, /*fullscreen*/SDL_WINDOW_SHOWN);

		if (m_pWindow != 0)
		{
			m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);

			m_bRunning = true;

			SDL_Surface* pTempSurface = SDL_LoadBMP("assets/rider.bmp");
			m_pTexture = SDL_CreateTextureFromSurface(m_pRenderer, pTempSurface);

			SDL_FreeSurface(pTempSurface);

			SDL_QueryTexture(m_pTexture, NULL, NULL,
				&m_sourceRectangle.w, &m_sourceRectangle.h);
		}

	}
	else
	{
		return false;
	}

	return true;
}

void Game::render()
{

	// source => ���� �簢��
	// destination => ��� �簢��

	//�⺻ 

	/*m_destinationRectangle.x = m_sourceRectangle.x = 0;
	m_destinationRectangle.y = m_sourceRectangle.y = 0;
	m_destinationRectangle.w = m_sourceRectangle.w;
	m_destinationRectangle.h = m_sourceRectangle.h;*/

	m_destinationRectangle.x = m_sourceRectangle.x = 0;
	m_destinationRectangle.y = m_sourceRectangle.y = 0;

	//m_sourceRectangle.x = 50;
	//m_sourceRectangle.y = 50;

	m_sourceRectangle.x = 50;
	m_sourceRectangle.y = 50;

	m_destinationRectangle.x = 50;
	m_destinationRectangle.y = 50;



	m_sourceRectangle.w = 30;
	m_sourceRectangle.h = 30;


	m_destinationRectangle.w = m_sourceRectangle.w;
	m_destinationRectangle.h = m_sourceRectangle.h;

	m_destinationRectangle.w = 100;
	//�߰����� 

	/*m_destinationRectangle.w = m_sourceRectangle.w;
	m_destinationRectangle.h = m_sourceRectangle.h;

	m_sourceRectangle.x = 50;
	m_sourceRectangle.y = 50;

	m_destinationRectangle.x = 100;
	m_destinationRectangle.y = 100;


	m_sourceRectangle.w = 50;
	m_sourceRectangle.h = 50;*/



	SDL_RenderClear(m_pRenderer);
	SDL_RenderCopy(m_pRenderer, m_pTexture,
		NULL, &m_destinationRectangle);
	SDL_RenderPresent(m_pRenderer);
}

void Game::update()
{

}

void Game::handleEvents()
{
	SDL_Event event;
	if (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_QUIT:
			m_bRunning = false;
			break;

		default:
			break;
		}
	}
}

void Game::clean()
{
	std::cout << "cleaning game\n";
	SDL_DestroyWindow(m_pWindow);
	SDL_DestroyRenderer(m_pRenderer);
	SDL_Quit();
}
