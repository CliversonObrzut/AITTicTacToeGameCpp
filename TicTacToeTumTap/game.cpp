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

int Game::getValidCoordenate(int number_of_options)
{
	int option = 0;
	bool valid = false;
	while (!valid)
	{
		option = _getch();
		if (option >= 48 && option <= 47 + number_of_options)
			valid = true;
	}
	return option-48;
}

void Game::resultUpdates(Board board, int turn)
{
	if (board.getWinner())
	{
		if (turn == 1)
			updatePoints(&p1, &p2);
		else
			updatePoints(&p2, &p1);
		updateRanking();
	}
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

	updateLinkedListRanking(&scores, &players, &nn11, &np11, p1);
	updateLinkedListRanking(&scores, &players, &nn11, &np11, p2);

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

void Game::updateLinkedListRanking(LinkedList * scores, LinkedList * players, node * new_nn, node * new_np, Player p)
{
	int pos = 1;
	int old_pos = 0;
	int new_pos = 0;
	node * curr_p = scores->getHead();
	node * old_nn = NULL;
	node * old_np = NULL;
	while (curr_p != NULL)
	{
		if (curr_p->data1 < p.getPoints())
		{
			new_np->data1 = p.getPoints();
			new_nn->data4 = p.getName();
			scores->addToPos(*new_np, pos);
			players->addToPos(*new_nn, pos);
			new_pos = pos;
			break;
		}
		pos++;
		curr_p = curr_p->ptr;
	}

	pos = 1;
	node * curr_n = players->getHead();
	curr_p = scores->getHead();
	while (curr_n != NULL)
	{
		if (curr_n->data4 == p.getName())
		{
			if (new_pos != pos)
			{
				old_nn = curr_n;
				old_np = curr_p;
				old_pos = pos;
				break;
			}
		}
		pos++;
		curr_n = curr_n->ptr;
		curr_p = curr_p->ptr;
	}

	if(new_pos == 0)
	{
		if(old_pos != 0 && p.getPoints() < old_np->data1)
		{
			scores->remove(*old_np);
			players->remove(*old_nn);
			new_nn->data4 = "ROG";
			new_np->data1 = 1;
			scores->addToTail(*new_np);
			players->addToTail(*new_nn);
		}
	}
	else
	{
		if (old_pos == 0)
		{
			scores->removeTail();
			players->removeTail();
		}
		else
		{
			scores->remove(*old_np);
			players->remove(*old_nn);
		}
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
			p2.setName("PL2");  // Should be CPU but the CPU player engine is not developed yet
			ps.display(stp.getNPlayers());
		}
		else if (option == 50)
		{
			stp.setNPlayers(2);
			p2.setName("PL2");
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
	int turn = 0;
	Board board(stp.getLevel());
	LevelOneScreen los(stp.getLeveOneFile(), stp.getWidth(), stp.getLevelOneHeight(), stp.getLevel(), stp.getNPlayers(), p1, p2);
	ResultScreen rs(stp.getResultFile());

	los.resizeScreen();
	los.display(turn, board);

	int number_of_options = los.getNumberOfOptions();
	turn = defineWhoStart(number_of_options);
	
	int count = 0;
	do
	{		
		los.display(turn, board);
		enterCoordX(&board);
		los.display(turn, board);
		enterCoordY(&board);			
		los.display(turn, board);
		while (_getch() != 13) {}
		if(board.coordIsValid())
		{
			count++;
			board.setBoard(turn);

			if (checkVictory(&board))
			{
				board.setWinner();
				finished = true;
			}
			if (checkTie(&board))
			{
				board.setTie();
				finished = true;
			}
			if (!finished)
			{
				if (turn == 1)
					turn = 2;
				else
					turn = 1;
			}
			if (count == 5)
			{
				finished = true;
				board.setTie();
				//board.setWinner();
			}
		}

		board.setCoordX(-1);
		board.setCoordY(-1);
	} 
	while (!finished);

	resultUpdates(board, turn);
	los.displayResult(rs, board, turn, stp.getWinnerPoints());
		
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
	int turn = 0;
	Board board(stp.getLevel());
	LevelTwoScreen lts(stp.getLevelTwoFile(), stp.getWidth(), stp.getLevelTwoHeight(), stp.getLevel(), stp.getNPlayers(), p1, p2);
	ResultScreen rs(stp.getResultFile());
	
	lts.resizeScreen();
	lts.display(turn, board);

	int number_of_options = lts.getNumberOfOptions();
	turn = defineWhoStart(number_of_options);

	int count = 0;
	do
	{
		lts.display(turn, board);
		enterCoordX(&board);
		lts.display(turn, board);
		enterCoordY(&board);
		lts.display(turn, board);
		while (_getch() != 13) {}
		if (board.coordIsValid())
		{
			count++;
			board.setBoard(turn);

			if (checkVictory(&board))
			{
				board.setWinner();
				finished = true;
			}
			if (checkTie(&board))
			{
				board.setTie();
				finished = true;
			}
			if (!finished)
			{
				if (turn == 1)
					turn = 2;
				else
					turn = 1;
			}
			if (count == 5)
			{
				finished = true;
				//board.setWinner();
				board.setTie();
			}
		}

		board.setCoordX(-1);
		board.setCoordY(-1);
	} 
	while (!finished);

	resultUpdates(board, turn);
	lts.displayResult(rs, board, turn, stp.getWinnerPoints());

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
	int turn = 0;
	Board board(stp.getLevel());
	LevelThreeScreen lts(stp.getLevelThreeFile(), stp.getWidth(), stp.getLevelThreeHeight(), stp.getLevel(), stp.getNPlayers(), p1, p2);
	ResultScreen rs(stp.getResultFile());
	
	lts.resizeScreen();
	lts.display(turn, board);

	int number_of_options = lts.getNumberOfOptions();
	turn = defineWhoStart(number_of_options);

	int count = 0;
	do
	{
		lts.display(turn, board);
		enterCoordX(&board);
		lts.display(turn, board);
		enterCoordY(&board);
		lts.display(turn, board);
		while (_getch() != 13){}
		if (board.coordIsValid())
		{
			count++;
			board.setBoard(turn);

			if (checkVictory(&board))
			{
				board.setWinner();
				finished = true;
			}
			if (checkTie(&board))
			{
				board.setTie();
				finished = true;
			}
			if (!finished)
			{
				if (turn == 1)
					turn = 2;
				else
					turn = 1;
			}
			if (count == 5)
			{
				finished = true;
				//board.setWinner();
				board.setTie();
			}
		}

		board.setCoordX(-1);
		board.setCoordY(-1);
	} 
	while (!finished);

	resultUpdates(board, turn);
	lts.displayResult(rs, board, turn, stp.getWinnerPoints());

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

int Game::defineWhoStart(int numberOfOptions)
{
	while (true)
	{
		int option = getUserOption(numberOfOptions);
		if (option == 49)
			return 1;
		if (option == 50)
			return 2;
		else
			return 0;
	}
}

void Game::enterCoordX(Board * board)
{
	int coordX = getValidCoordenate(stp.getLevel());
	board->setCoordX(coordX);
}

void Game::enterCoordY(Board * board)
{
	int coordY = getValidCoordenate(stp.getLevel());
	board->setCoordY(coordY);
}

bool Game::checkVictory(Board * board)
{
	return false;
}

bool Game::checkTie(Board * board)
{
	return false;
}

