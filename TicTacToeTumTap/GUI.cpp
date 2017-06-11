#include "stdafx.h"
#include "GUI.h"
#include "board.h"

// Graphical User Interface constructor
Gui::Gui(string fileName, int screenWidth=0, int screenHeight=0) : FileManager (fileName)
{
	this->screen_width = screenWidth;
	this->screen_height = screenHeight;
}

int Gui::getScreenWidth()
{
	return screen_width;
}

int Gui::getScreenHeight()
{
	return screen_height;
}

void Gui::display()
{
	clrscr();
	cout << getContent();
}

void Gui::clrscr()
{
	system("cls");
}

void Gui::resizeScreen()
{
	string w = to_string(screen_width);
	string h = to_string(screen_height);
	string first = "mode con: cols=";
	string second = " lines=";
	string winSize = first + w + second + h;
	char *resize = new char[winSize.length()];
	resize = &winSize[0];
	system(resize);
}

void Gui::findScreenPosition(int * screenX, int * screenY)
{
	bool done = false;
	string * text = new string[linesCount()];
	text = getContentLines();
	for (int y = 0; y < linesCount(); y++)
	{
		for (int x = 0; x < text[y].length(); x++)
		{
			if (text[y][x] == 'Z')
			{
				*screenX = x;
				*screenY = y;
				done = true;
				break;
			}
		}
		if (done)
			break;
	}
}

void Gui::redrawPlayScreen(Board board, Player p1, Player p2, int turn, bool * first_display, int boardX, int boardY, int textX, int textY)
{
	string * screen = new string[linesCount()];
	screen = getContentLines();
	if (*first_display)
	{
		drawTextInScreen(screen, p1.getName(), textX + 11, textY + 1);
		drawTextInScreen(screen, p2.getName(), textX + 11, textY + 2);
		updateScreen(screen);
		*first_display = false;
	}
	else
	{
		redrawBoard(board, screen, boardX, boardY);
		string spaces = "                                                  ";
		string message = "";
		string value_x;
		string value_y;
		if (board.getCoordX() == -1)
			value_x = "_";
		else
			value_x = to_string(board.getCoordX());
		if (board.getCoordY() == -1)
			value_y = "_";
		else
			value_y = to_string(board.getCoordY());

		string coord_x = "- Enter the board position X: " + value_x;
		string coord_y = "- Enter the board position Y: " + value_y;
		if (value_x != "_" && value_y != "_")
		{
			if (board.coordIsValid())
				message = "- Good play! (Enter)";
			else
				message = "- Position already filled! Try again! (Enter)";
		}
		else
			message = spaces;

		string player_turn = "";
		if (turn == 1)
			player_turn = p1.getName() + "'s turn!     ";
		else
			player_turn = p2.getName() + "'s turn!     ";

		drawTextInScreen(screen, player_turn, textX, textY);
		drawTextInScreen(screen, coord_x, textX, textY + 1);
		drawTextInScreen(screen, coord_y, textX, textY + 2);
		drawTextInScreen(screen, message, textX, textY + 3);
		updateScreen(screen);
	}
}


void Gui::redrawBoard(Board b, string* screen, int boardx, int boardy)
{
	int level = b.getSize();
	char * board = b.getBoard();
	for (int y = boardy, r = 0; r < level; y++, r++)
	{
		for (int x = boardx, c = 0; c < level; c++, x = x + 4)
		{
			screen[y][x] = board[(level*r) + c];
		}
	}
}

void Gui::redrawPlayerScreen(int nPlayer, char selectSymbol, int select_x, int select_y)
{
	string * screen = new string[linesCount()];
	screen = getContentLines();
	if(nPlayer == 1)
	{
		screen[select_y][select_x] = selectSymbol;
		screen[select_y + 1][select_x] = ' ';
	}
	if (nPlayer == 2)
	{
		screen[select_y][select_x] = ' ';
		screen[select_y + 1][select_x] = selectSymbol;
	}	
	updateScreen(screen);
}

void Gui::redrawLevelScreen(int level, char selectSymbol, int select_x, int select_y)
{
	string * screen = new string[linesCount()];
	screen = getContentLines();
	if (level == 3)
	{
		screen[select_y][select_x] = selectSymbol;
		screen[select_y + 1][select_x] = ' ';
		screen[select_y + 2][select_x] = ' ';
	}
	if (level == 5)
	{
		screen[select_y][select_x] = ' ';
		screen[select_y + 1][select_x] = selectSymbol;
		screen[select_y + 2][select_x] = ' ';
	}
	if (level == 7)
	{
		screen[select_y][select_x] = ' ';
		screen[select_y + 1][select_x] = ' ';
		screen[select_y + 2][select_x] = selectSymbol;
	}
	updateScreen(screen);
}

void Gui::drawResultScreen(ResultScreen rs, Board board, string name, int points, int board_x, int board_y)
{
	string * screen = new string[linesCount()];
	screen = getContentLines();

	redrawBoard(board, screen, board_x, board_y);

	string * result_screen = new string[rs.linesCount()];
	result_screen = rs.getContentLines();
	int difference = linesCount() - rs.linesCount();
	for(int i=0; i < rs.linesCount(); i++)
	{
		screen[difference + i] = result_screen[i];
	}
	if(board.getWinner())
	{
		int x = rs.getNameX();
		int y = rs.getNameY();
		if (board.getSize() == 5)
			y++;
		if (board.getSize() == 7)
			y = y + 3;
		drawTextInScreen(screen, name, x, y);
		x = rs.getPointX();
		string point = to_string(points);
		drawTextInScreen(screen, point, x, y);
	}
	if(board.getTie())
	{
		int x = rs.getTextX();
		int y = rs.getTextY();
		if (board.getSize() == 5)
			y++;
		if (board.getSize() == 7)
			y = y + 3;
		string tieMessage = "          It was a tie! No points added or removed!           ";
		drawTextInScreen(screen, tieMessage, x, y);
	}
	updateScreen(screen);
}

void Gui::drawTextInScreen(string * screen, string text, int screen_x, int screen_y)
{
	char * string = new char[text.length()];
	string = &text[0];
	for (int i = 0; i < text.length(); i++)
		screen[screen_y][screen_x + i] = string[i];
}

void Gui::updateScreen(string* screen)
{
	string newContent;
	for (int i = 0; i < linesCount(); i++)
		newContent = newContent + screen[i];
	clrscr();
	cout << newContent;
}



// WelcomeScreen constructor
WelcomeScreen::WelcomeScreen(string fileName, int width, int height) : Gui(fileName, width, height)
{
	
}

// MenuScreen constructor
MenuScreen::MenuScreen(string fileName, int width, int height) : Gui(fileName, width, height)
{
	number_of_options = 6;
}

int MenuScreen::getNumberOfOptions()
{
	return number_of_options;
}

// PlayerScreen constructor
PlayerScreen::PlayerScreen(string fileName, int width, int height) : Gui(fileName, width, height)
{
	number_of_options = 3;
	select_x = 46;
	select_y = 13;
	selectSymbol = '>';
}

int PlayerScreen::getNumberOfOptions()
{
	return number_of_options;
}

void PlayerScreen::display(int nPlayers)
{
	redrawPlayerScreen(nPlayers, selectSymbol, select_x, select_y);
}

int PlayerScreen::getSelectX()
{
	return select_x;
}

int PlayerScreen::getSelectY()
{
	return select_y;
}

char PlayerScreen::getSelectSymbol()
{
	return selectSymbol;
}


// LevelScreen constructor
LevelScreen::LevelScreen(string fileName, int width, int height) : Gui(fileName, width, height)
{
	number_of_options = 4;
	select_x = 46;
	select_y = 13;
	selectSymbol = '>';
}

int LevelScreen::getNumberOfOptions()
{
	return number_of_options;
}

void LevelScreen::display(int level)
{
	redrawLevelScreen(level, selectSymbol, select_x, select_y);
}

int LevelScreen::getSelectX()
{
	return select_x;
}

int LevelScreen::getSelectY()
{
	return select_y;
}

char LevelScreen::getSelectSymbol()
{
	return selectSymbol;
}


// RulesScreen constructor
RulesScreen::RulesScreen(string fileName, int width, int height) : Gui(fileName, width, height)
{
	number_of_options = 1;
}

int RulesScreen::getNumberOfOptions()
{
	return number_of_options;
}

// RankingScreen constructor
RankingScreen::RankingScreen(string fileName, int width, int height) : Gui(fileName, width, height)
{
	number_of_options = 1;
}

int RankingScreen::getNumberOfOptions()
{
	return number_of_options;
}


LevelOneScreen::LevelOneScreen(string fileName, int width, int height, int n_player, Board board, Player p1, Player p2) : Gui(fileName, width, height)
{
	this->p1 = p1;
	this->p2 = p2;
	board_x = 54;
	board_y = 15;
	first_display = true;
	text_x = 43;
	text_y = 22;
	number_of_options = 2;
}

int LevelOneScreen::getNumberOfOptions()
{
	return number_of_options;
}

void LevelOneScreen::display(int turn, Board board)
{
	redrawPlayScreen(board, p1, p2, turn, &first_display, board_x, board_y, text_x, text_y);
}

void LevelOneScreen::displayResult(ResultScreen rs, Board board, int turn, int points)
{
	if(turn == 1)
		drawResultScreen(rs, board, p1.getName(), points, board_x, board_y);
	else
		drawResultScreen(rs, board, p2.getName(), points, board_x, board_y);
}

int LevelOneScreen::getBoardX()
{
	return board_x;
}

int LevelOneScreen::getBoardY()
{
	return board_y;
}

int LevelOneScreen::getTextX()
{
	return text_x;
}

int LevelOneScreen::getTextY()
{
	return text_y;
}

LevelTwoScreen::LevelTwoScreen(string fileName, int width, int height, int n_player, Board board, Player p1, Player p2) : Gui(fileName, width, height)
{
	this->p1 = p1;
	this->p2 = p2;
	board_x = 50;
	board_y = 15;
	first_display = true;
	text_x = 41;
	text_y = 23;
	number_of_options = 2;
}

int LevelTwoScreen::getNumberOfOptions()
{
	return number_of_options;
}

void LevelTwoScreen::display(int turn, Board board)
{
	redrawPlayScreen(board, p1, p2, turn, &first_display, board_x, board_y, text_x, text_y);
}

void LevelTwoScreen::displayResult(ResultScreen rs, Board board, int turn, int points)
{
	if (turn == 1)
		drawResultScreen(rs, board, p1.getName(), points, board_x, board_y);
	else
		drawResultScreen(rs, board, p2.getName(), points, board_x, board_y);
}


int LevelTwoScreen::getBoardX()
{
	return board_x;
}

int LevelTwoScreen::getBoardY()
{
	return board_y;
}

int LevelTwoScreen::getTextX()
{
	return text_x;
}

int LevelTwoScreen::getTextY()
{
	return text_y;
}

LevelThreeScreen::LevelThreeScreen(string fileName, int width, int height, int n_player, Board board, Player p1, Player p2) : Gui(fileName, width, height)
{
	this->p1 = p1;
	this->p2 = p2;
	board_x = 46;
	board_y = 15;
	first_display = true;
	text_x = 37;
	text_y = 25;
	number_of_options = 2;
}

int LevelThreeScreen::getNumberOfOptions()
{
	return number_of_options;
}

void LevelThreeScreen::display(int turn, Board board)
{
	redrawPlayScreen(board, p1, p2, turn, &first_display, board_x, board_y, text_x, text_y);
}

void LevelThreeScreen::displayResult(ResultScreen rs, Board board, int turn, int points)
{
	if (turn == 1)
		drawResultScreen(rs, board, p1.getName(), points, board_x, board_y);
	else
		drawResultScreen(rs, board, p2.getName(), points, board_x, board_y);
}


int LevelThreeScreen::getBoardX()
{
	return board_x;
}

int LevelThreeScreen::getBoardY()
{
	return board_y;
}

int LevelThreeScreen::getTextX()
{
	return text_x;
}

int LevelThreeScreen::getTextY()
{
	return text_y;
}

ResultScreen::ResultScreen(string fileName) : Gui(fileName)
{
	number_of_options = 1;
	name_x = 41;
	name_y =24;
	points_x = 78;
	points_y = 24;
	text_x = 25;
	text_y = 24;
}

int ResultScreen::getNumberOfOptions()
{
	return number_of_options;
}

int ResultScreen::getNameX()
{
	return name_x;
}

int ResultScreen::getNameY()
{
	return name_y;
}

int ResultScreen::getPointX()
{
	return points_x;
}

int ResultScreen::getPointY()
{
	return points_y;
}

int ResultScreen::getTextX()
{
	return text_x;
}

int ResultScreen::getTextY()
{
	return text_y;
}








