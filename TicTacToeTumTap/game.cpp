#include "stdafx.h"
#include "game.h"
#include "GUI.h"

Game::Game()
{
	
}

void Game::Start()
{
	getWelcomeScreen();
}

int Game::getUserOption(int number_of_options)
{
	int option = 0;
	bool valid = false;
	while (!valid)
	{
		option = _getch();
		if (option >= 49 && option <= 48+number_of_options)
			valid = true;
	}
	return option;
}

void Game::getWelcomeScreen()
{
	WelcomeScreen ws(setup.getWelcomeFile(), setup.getWidth(), setup.getWelcomeHeight());
	ws.resizeScreen();
	ws.display();
	Sleep(3000);
	ws.clrscr();
	getMenuScreen();
}

void Game::getMenuScreen()
{
	bool gameEnd = false;
	MenuScreen ms(setup.getMenuFile(), setup.getWidth(), setup.getMenuHeight());
	while(!gameEnd)
	{
		ms.resizeScreen();
		ms.display();
		int option = getUserOption(ms.getNumberOfOptions());
		ms.clrscr();
		if (option == 49)
		{
			if (setup.getLevel() == 3)
				getLevelOneScreen();
			if (setup.getLevel() == 5)
				getLevelTwoScreen();
			if (setup.getLevel() == 7)
				getLevelThreeScreen();
		}
		else if (option == 50)
			getPlayerScreen();
		else if (option == 51)
			getLevelScreen();
		else if (option == 52)
			getRulesScreen();
		else if (option == 53)
			getRankingScreen();
		else if (option == 54)
			gameEnd = true;
		else
		{
			cout << "Logic error";
			system("pause");
			exit(1);
		}
	}
}

void Game::getPlayerScreen()
{
	bool menu = false;
	PlayerScreen ps(setup.getPlayerFile(), setup.getWidth(), setup.getPlayerHeight());
	ps.resizeScreen();
	ps.display();
	while(!menu)
	{
		int option = getUserOption(ps.getNumberOfOptions());
		if (option == 49)
			setup.setNPlayers(1);
		else if (option == 50)
			setup.setNPlayers(2);
		else if (option == 51)
			menu = true;
		else
			exit(1);
	}
	ps.clrscr();
}

void Game::getLevelScreen()
{
	bool menu = false;
	LevelScreen ls(setup.getLevelFile(), setup.getWidth(), setup.getLevelHeight());
	ls.resizeScreen();
	ls.display();
	while(!menu)
	{
		int option = getUserOption(ls.getNumberOfOptions());
		if (option == 49)
			setup.setLevel(3);
		else if (option == 50)
			setup.setLevel(5);
		else if (option == 51)
			setup.setLevel(7);
		else if (option == 52)
			menu = true;
		else
			exit(1);
	}
	ls.clrscr();
}

void Game::getRulesScreen()
{
	RulesScreen rs(setup.getRulesFile(), setup.getWidth(), setup.getRulesHeight());
	rs.resizeScreen();
	rs.display();
	Sleep(3000);
	rs.clrscr();
}

void Game::getRankingScreen()
{
	RankingScreen rs(setup.getRankingFile(), setup.getWidth(), setup.getRankingHeight());
	rs.resizeScreen();
	rs.display();
	Sleep(3000);
	rs.clrscr();
}
void Game::getLevelOneScreen()
{
	Board board(setup.getLevel());
	LevelOneScreen los(setup.getLeveOneFile(), setup.getWidth(), setup.getLevelOneHeight());
	los.resizeScreen();
	los.display(board);
	Sleep(3000);
	los.clrscr();

	for (int y = 0; y < setup.getLevel(); y++)
		for (int x = 0; x < setup.getLevel(); x++)
			board.setBoard(x,y,'X');

	los.display(board);
	Sleep(3000);
	los.clrscr();
}
void Game::getLevelTwoScreen()
{
	Board board(setup.getLevel());
	LevelTwoScreen lts(setup.getLevelTwoFile(), setup.getWidth(), setup.getLevelTwoHeight());
	lts.resizeScreen();
	lts.display(board);
	Sleep(3000);
	lts.clrscr();
	for (int y = 0; y < setup.getLevel(); y++)
		for (int x = 0; x < setup.getLevel(); x++)
			board.setBoard(x, y, 'X');
	lts.display(board);
	Sleep(3000);
	lts.clrscr();
}
void Game::getLevelThreeScreen()
{
	Board board(setup.getLevel());
	LevelThreeScreen lts(setup.getLevelThreeFile(), setup.getWidth(), setup.getLevelThreeHeight());
	lts.resizeScreen();
	lts.display(board);
	Sleep(3000);
	lts.clrscr();
	for (int y = 0; y < setup.getLevel(); y++)
		for (int x = 0; x < setup.getLevel(); x++)
			board.setBoard(x, y, 'X');
	lts.resizeScreen();
	lts.display(board);
	Sleep(3000);
	lts.clrscr();
}