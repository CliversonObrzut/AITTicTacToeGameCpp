#include "stdafx.h"
#include "game.h"
#include "GUI.h"
#include "LinkedList.h"

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

void Game::drawTextForFile(string * screen, string text, int file_x, int file_y)
{
	char * string = new char[text.length()];
	string = &text[0];
	for (int i = 0; i < text.length(); i++)
		screen[file_x][file_y + i] = string[i];
}

void Game::updateRanking()
{
	FileManager fm(stp.getRankingFile());
	string * file = new string[fm.linesCount()];
	file = fm.getContentLines();
	LinkedList scores;
	LinkedList players;
	node np1(0), np2(0), np3(0), np4(0), np5(0), np6(0), np7(0), np8(0), np9(0), np10(0), np11(0);
	string n = ".";
	node nn1(n), nn2(n), nn3(n), nn4(n), nn5(n), nn6(n), nn7(n), nn8(n), nn9(n), nn10(n), nn11(n);

	scores.addToHead(np1);
	scores.addToTail(np2);
	scores.addToTail(np3);
	scores.addToTail(np4);
	scores.addToTail(np5);
	scores.addToTail(np6);
	scores.addToTail(np7);
	scores.addToTail(np8);
	scores.addToTail(np9);
	scores.addToTail(np10);

	players.addToHead(nn1);
	players.addToTail(nn2);
	players.addToTail(nn3);
	players.addToTail(nn4);
	players.addToTail(nn5);
	players.addToTail(nn6);
	players.addToTail(nn7);
	players.addToTail(nn8);
	players.addToTail(nn9);
	players.addToTail(nn10);

	string points[10];
	string names[10];
	int name_x = 13;
	int name_y = 38;
	int point_y = 78;

	node * np = scores.getHead();
	node * nn = players.getHead();
	for (int x = name_x, i=0; x < 23; x++, i++)
	{
		for (int y = name_y, z = point_y, j = 0; j < 4; j++, y++, z++)
		{
			if(j < 3)
				names[i] = names [i] + file[x][y];
			points[i] = points[i] + file[x][z];
		}		
		nn->data4 = names[i];
		np->data1 = stoi(points[i]);
		np = np->ptr;
		nn = nn->ptr;

	}

	updateLinkedListRanking(&scores, &players, &np1, &nn11, &np11, p1);
	updateLinkedListRanking(&scores, &players, &np1, &nn11, &np11, p2);

	int pos = 0;
	np = scores.getHead();
	nn = players.getHead();
	while (np != NULL)
	{
		names[pos] = nn->data4;
		points[pos] = to_string(np->data1);
		if(points[pos].length() < 4)
		{
			while (points[pos].length() < 4)
				points[pos] = "0" + points[pos];
		}
		pos++;
		np = np->ptr;
		nn = nn->ptr;
	}
	for(int i = 0; i < 10; i++)
	{
		drawTextForFile(file, names[i], name_x+i, name_y);
		drawTextForFile(file, points[i], name_x+i, point_y);
	}
	string newContent;
	for (int i = 0; i < fm.linesCount(); i++)
		newContent = newContent + file[i];

	fm.saveData(stp.getRankingFile(), newContent);
}

void Game::updateLinkedListRanking(LinkedList * scores, LinkedList * players, node * n, node * new_nn, node * new_np, Player p)
{
	int pos = 1;
	node * curr = n;
	while (curr != NULL)
	{
		if (curr->data1 < p.getPoints())
		{
			new_np->data1 = p.getPoints();
			new_nn->data4 = p.getName();
			scores->addToPos(*new_np, pos);
			scores->removeTail();
			players->addToPos(*new_nn, pos);
			players->removeTail();
			break;
		}
		pos++;
		curr = curr->ptr;
	}
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
		updateRanking();
		los.displayResult(rs, p1.getName(), stp.getWinnerPoints());
	}
	else
	{
		updatePoints(&p2, &p1);
		updateRanking();
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
		updateRanking();
		lts.displayResult(rs, p1.getName(), stp.getWinnerPoints());
	}
	else
	{
		updatePoints(&p2, &p1);
		updateRanking();
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
		updateRanking();
		lts.displayResult(rs, p1.getName(), stp.getWinnerPoints());
	}
	else
	{
		updatePoints(&p2, &p1);
		updateRanking();
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