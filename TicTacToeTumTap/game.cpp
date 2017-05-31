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
	Sleep(2000);
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
	ps.display(setup.getNPlayers());
	while(!menu)
	{
		int option = getUserOption(ps.getNumberOfOptions());
		if (option == 49)
		{
			setup.setNPlayers(1);
			ps.display(setup.getNPlayers());
		}
		else if (option == 50)
		{
			setup.setNPlayers(2);
			ps.display(setup.getNPlayers());
		}
		else if (option == 51)
			menu = true;
		else
			exit(1);
	}
}

void Game::getLevelScreen()
{
	bool menu = false;
	LevelScreen ls(setup.getLevelFile(), setup.getWidth(), setup.getLevelHeight());
	ls.resizeScreen();
	ls.display(setup.getLevel());
	while(!menu)
	{
		int option = getUserOption(ls.getNumberOfOptions());
		if (option == 49)
		{
			setup.setLevel(3);
			ls.display(setup.getLevel());
		}
		else if (option == 50)
		{
			setup.setLevel(5);
			ls.display(setup.getLevel());
		}			
		else if (option == 51)
		{
			setup.setLevel(7);
			ls.display(setup.getLevel());
		}			
		else if (option == 52)
			menu = true;
		else
			exit(1);
	}
}

void Game::getRulesScreen()
{
	bool menu = false;
	RulesScreen rs(setup.getRulesFile(), setup.getWidth(), setup.getRulesHeight());
	rs.resizeScreen();
	rs.display();
	while (!menu)
	{
		int option = getUserOption(rs.getNumberOfOptions());
		if (option == 49)
			menu = true;
		else
			exit(1);
	}
}

void Game::getRankingScreen()
{
	bool menu = false;
	RankingScreen rs(setup.getRankingFile(), setup.getWidth(), setup.getRankingHeight());
	rs.resizeScreen();
	rs.display();
	while (!menu)
	{
		int option = getUserOption(rs.getNumberOfOptions());
		if (option == 49)
			menu = true;
		else
			exit(1);
	}
}
void Game::getLevelOneScreen()
{
	bool finished = false;
	LevelOneScreen los(setup.getLeveOneFile(), setup.getWidth(), setup.getLevelOneHeight(), setup.getLevel(), setup.getNPlayers(), setup.getPlayerOne(), setup.getPlayerTwo());
	ResultScreen rs(setup.getResultFile());
	los.resizeScreen();
	int turn = 1;
	while(!finished)
	{
		los.display();
		Sleep(2000);
		los.display();
		Sleep(2000);
		finished = true;
	}
	if (turn == 1)
		los.displayResult(rs, setup.getPlayerOne().getName(), setup.getWinnerPoints());
	else
		los.displayResult(rs, setup.getPlayerTwo().getName(), setup.getWinnerPoints());
	bool menu = false;
	while (!menu)
	{
		int option = getUserOption(rs.getNumberOfOptions());
		if (option == 49)
			menu = true;
		else
			exit(1);
	}
}
void Game::getLevelTwoScreen()
{
	bool finished = false;
	LevelTwoScreen lts(setup.getLevelTwoFile(), setup.getWidth(), setup.getLevelTwoHeight(), setup.getLevel(), setup.getNPlayers(), setup.getPlayerOne(), setup.getPlayerTwo());
	ResultScreen rs(setup.getResultFile());
	lts.resizeScreen();
	int turn = 1;
	while(!finished)
	{
		lts.display();
		Sleep(2000);
		lts.display();
		Sleep(3000);
		finished = true;
	}
	if (turn == 1)
		lts.displayResult(rs, setup.getPlayerOne().getName(), setup.getWinnerPoints());
	else
		lts.displayResult(rs, setup.getPlayerTwo().getName(), setup.getWinnerPoints());
	bool menu = false;
	while (!menu)
	{
		int option = getUserOption(rs.getNumberOfOptions());
		if (option == 49)
			menu = true;
		else
			exit(1);
	}
}
void Game::getLevelThreeScreen()
{
	bool finished = false;
	LevelThreeScreen lts(setup.getLevelThreeFile(), setup.getWidth(), setup.getLevelThreeHeight(), setup.getLevel(), setup.getNPlayers(), setup.getPlayerOne(), setup.getPlayerTwo());
	ResultScreen rs(setup.getResultFile());
	lts.resizeScreen();
	int turn = 1;
	while(!finished)
	{
		lts.display();
		Sleep(2000);
		lts.display();
		Sleep(3000);
		finished = true;
	}
	if (turn == 1)
		lts.displayResult(rs, setup.getPlayerOne().getName(), setup.getWinnerPoints());
	else
		lts.displayResult(rs, setup.getPlayerTwo().getName(), setup.getWinnerPoints());
	bool menu = false;
	while (!menu)
	{
		int option = getUserOption(rs.getNumberOfOptions());
		if (option == 49)
			menu = true;
		else
			exit(1);
	}
}