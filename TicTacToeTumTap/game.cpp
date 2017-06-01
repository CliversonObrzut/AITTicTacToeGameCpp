#include "stdafx.h"
#include "game.h"
#include "GUI.h"

Game::Game()
{

}

void Game::Start()
{
	p1.setName(stp.getPlayerOneName());
	p2.setName(stp.getPlayerTwoName());
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

void Game::updatePoints(Player *pw, Player *pl)
{
	if (pw->getPoints() + stp.getWinnerPoints() > 9999)
		pw->maxPoints();
	else
		pw->addPoints(stp.getWinnerPoints());

	if (pl->getPoints() - stp.getLoserPoints() < 0)
		pl->resetPoints();
	else
		pl->decreasePoints(stp.getLoserPoints());
}

void Game::getWelcomeScreen()
{
	WelcomeScreen ws(stp.getWelcomeFile(), stp.getWidth(), stp.getWelcomeHeight());
	ws.resizeScreen();
	ws.display();
	Sleep(2000);
	getMenuScreen();
}

void Game::getMenuScreen()
{
	bool gameEnd = false;
	MenuScreen ms(stp.getMenuFile(), stp.getWidth(), stp.getMenuHeight());
	while(!gameEnd)
	{
		ms.resizeScreen();
		ms.display();
		int option = getUserOption(ms.getNumberOfOptions());
		if (option == 49)
		{
			if (stp.getLevel() == 3)
				getLevelOneScreen();
			if (stp.getLevel() == 5)
				getLevelTwoScreen();
			if (stp.getLevel() == 7)
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
			exit(1);
	}
}

void Game::getPlayerScreen()
{
	bool menu = false;
	PlayerScreen ps(stp.getPlayerFile(), stp.getWidth(), stp.getPlayerHeight());
	ps.resizeScreen();
	ps.display(stp.getNPlayers());
	while(!menu)
	{
		int option = getUserOption(ps.getNumberOfOptions());
		if (option == 49)
		{
			stp.setNPlayers(1);
			ps.display(stp.getNPlayers());
		}
		else if (option == 50)
		{
			stp.setNPlayers(2);
			ps.display(stp.getNPlayers());
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
	LevelScreen ls(stp.getLevelFile(), stp.getWidth(), stp.getLevelHeight());
	ls.resizeScreen();
	ls.display(stp.getLevel());
	while(!menu)
	{
		int option = getUserOption(ls.getNumberOfOptions());
		if (option == 49)
		{
			stp.setLevel(3);
			ls.display(stp.getLevel());
		}
		else if (option == 50)
		{
			stp.setLevel(5);
			ls.display(stp.getLevel());
		}			
		else if (option == 51)
		{
			stp.setLevel(7);
			ls.display(stp.getLevel());
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
	RulesScreen rs(stp.getRulesFile(), stp.getWidth(), stp.getRulesHeight());
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
	RankingScreen rs(stp.getRankingFile(), stp.getWidth(), stp.getRankingHeight());
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
	LevelOneScreen los(stp.getLeveOneFile(), stp.getWidth(), stp.getLevelOneHeight(), stp.getLevel(), stp.getNPlayers(), p1, p2);
	ResultScreen rs(stp.getResultFile());
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
	{
		updatePoints(&p1, &p2);
		los.displayResult(rs, p1.getName(), stp.getWinnerPoints());
	}
	else
	{
		updatePoints(&p2, &p1);
		los.displayResult(rs, p1.getName(), stp.getWinnerPoints());
	}
		
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
	LevelTwoScreen lts(stp.getLevelTwoFile(), stp.getWidth(), stp.getLevelTwoHeight(), stp.getLevel(), stp.getNPlayers(), p1, p2);
	ResultScreen rs(stp.getResultFile());
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
	{
		updatePoints(&p1, &p2);
		lts.displayResult(rs, p1.getName(), stp.getWinnerPoints());
	}
	else
	{
		updatePoints(&p2, &p1);
		lts.displayResult(rs, p1.getName(), stp.getWinnerPoints());
	}
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
	LevelThreeScreen lts(stp.getLevelThreeFile(), stp.getWidth(), stp.getLevelThreeHeight(), stp.getLevel(), stp.getNPlayers(), p1, p2);
	ResultScreen rs(stp.getResultFile());
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
	{
		updatePoints(&p1, &p2);
		lts.displayResult(rs, p1.getName(), stp.getWinnerPoints());
	}
	else
	{
		updatePoints(&p2, &p1);
		lts.displayResult(rs, p1.getName(), stp.getWinnerPoints());
	}
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