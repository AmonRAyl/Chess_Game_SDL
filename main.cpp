#include <cstdlib>//borrar mas adelante
#include "Button.h"

const char WHITE_ROOK = 'R';
const char WHITE_PAWN = 'P';
const char WHITE_HORSE = 'H';
const char WHITE_BISHOP = 'B';
const char WHITE_QUEEN = 'Q';
const char WHITE_KING = 'K';

const char BLACK_ROOK = 'r';
const char BLACK_PAWN = 'p';
const char BLACK_HORSE = 'h';
const char BLACK_BISHOP = 'b';
const char BLACK_QUEEN = 'q';
const char BLACK_KING = 'k';

bool WHITE_CASTLE_LEFT = true;
bool WHITE_CASTLE_RIGHT = true;
bool WHITE_CASTLE_KING = true;

bool BLACK_CASTLE_LEFT = true;
bool BLACK_CASTLE_RIGHT = true;
bool BLACK_CASTLE_KING = true;

char BLACK_EN_PASSANT;
char WHITE_EN_PASSANT;

const char EMPTY_SQUARE = -2;
const char VERTICAL_LINE = -70;
const char HORIZONTAL_LINE = -51;

const char WHITE_PLAYER = 1;
const char BLACK_PLAYER = 2;

const int SCREEN_H = 640;
const int SCREEN_W = 640;

int StartUP_menu()
{
	int input;
start:
	system("CLS");
	std::cout << "   SIMPLE CHESS   " << std::endl;
	std::cout << std::endl;
	std::cout << "  1) Start P vs P Game (2 players)" << std::endl;
	std::cout << "  2) Start P vs IA Game (1 players/Work in progress currently unavailable)" << std::endl;
	std::cout << "  3) Basic Rules" << std::endl;
	std::cout << "  4) Exit Game" << std::endl;
	std::cout << std::endl;
	std::cout << "  Select Option(1-4): ";
	std::cin >> input;
	while (!std::cin.good() || input < 1 || input>4)
	{
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		system("CLS");
		std::cout << "   SIMPLE CHESS   " << std::endl;
		std::cout << std::endl;
		std::cout << "  1) Start P vs P Game (2 players)" << std::endl;
		std::cout << "  2) Start P vs IA Game (1 players/Work in progress currently unavailable)" << std::endl;
		std::cout << "  3) Basic Rules" << std::endl;
		std::cout << "  4) Exit Game" << std::endl;
		std::cout << std::endl;
		std::cout << "  Select Option(1-4): ";
		std::cin >> input;
	}
	switch (input)
	{
	case 1:
		break;
	case 2:
		std::cout << "NOT READY YET .... , select any other option" << std::endl;
		system("pause");
		goto start;
	case 3:
		system("CLS");
		std::cout << "White Player (UPERCASE)--> P,Q,K,R,B,H" << std::endl;
		std::cout << "BLACK Player (LOWERCASE)--> p,q,k,r,b,h" << std::endl;
		std::cout << std::endl;
		std::cout << "Pieces List/ Movement:" << std::endl;
		std::cout << std::endl;
		std::cout << " - PAWN (P/p) --> Moves one square at a time, it can only move forward, it can only capture enemy pieces diagonally (one square to the left/Right and one up),if it has not moved yet they can start by moving two squares forward, it can do an en passant capture this happens when the opponent pawn does a double move start then if you have a pawn that could have killed the enemy pawn if it had moved only one square then you can still caputre it, if it reaches the final square on the board you can promote it to whatever piece you want." << std::endl;
		std::cout << std::endl;
		std::cout << " - Rook (R/r) --> Moves vertically and horizontally the amount of squares you want without passing through any pieces." << std::endl;
		std::cout << std::endl;
		std::cout << " - Horse (H/h) --> Moves in an L shape, two squares horizontally and one vertically or two squares vertically and one square horizontally." << std::endl;
		std::cout << std::endl;
		std::cout << " - Bishop (B/b) --> Moves Diagonally the amount of squares you want without passing through any pieces." << std::endl;
		std::cout << std::endl;
		std::cout << " - Queen (Q/q) --> Moves like a rook and a bishop, it can move diagonally/vertically/horizontally the amount of squares you want without passing through any pieces" << std::endl;
		std::cout << std::endl;
		std::cout << " - King (K/k) --> Can only move one square in any direction, you can castle the king queen side or king side, this means that if there are no pieces between your king and either of your rooks you can move yout king two squares in the direction you are castling and put the rook on that side next to the king(if you castled king side then your king will go from e1 to g1 and the rook will gor from h1 to f1), this can only be done if neither the king and rook that you are using to castle have moved that game and if your king isn't in check." << std::endl;
		std::cout << std::endl;
		std::cout << "Basic Knowledge:" << std::endl;
		std::cout << std::endl;
		std::cout << "Check --> Your King is being attacked by an enemy piece you must move your king to a safe spot or kill the atacker or interpose the attack with another piece." << std::endl;
		std::cout << "Checkmate --> Your King is being attacked and you can't do anything to protect him, you lost the game." << std::endl;
		std::cout << "Stalemate --> The player that has to make a move can't move any of his pieces, it is a tie." << std::endl;
		system("pause");
		goto start;
	case 4:
		return 4;
	}
	return 0;
}
void Create_Grid(char Grid[][8])
{
	//Create Empty Board
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			Grid[i][j] = EMPTY_SQUARE;
		}
	}
	//Setup Pieces
	for (int i = 0; i < 8; i++)
	{
		Grid[1][i] = BLACK_PAWN;
		Grid[6][i] = WHITE_PAWN;
	}
	Grid[0][0] = BLACK_ROOK;
	Grid[0][1] = BLACK_HORSE;
	Grid[0][2] = BLACK_BISHOP;
	Grid[0][3] = BLACK_QUEEN;
	Grid[0][4] = BLACK_KING;
	Grid[0][5] = BLACK_BISHOP;
	Grid[0][6] = BLACK_HORSE;
	Grid[0][7] = BLACK_ROOK;

	Grid[7][0] = WHITE_ROOK;
	Grid[7][1] = WHITE_HORSE;
	Grid[7][2] = WHITE_BISHOP;
	Grid[7][3] = WHITE_QUEEN;
	Grid[7][4] = WHITE_KING;
	Grid[7][5] = WHITE_BISHOP;
	Grid[7][6] = WHITE_HORSE;
	Grid[7][7] = WHITE_ROOK;
}
void Display_Grid(char Grid[][8])
{
	system("CLS");
	std::cout << "    ";
	for (int j = 0; j < 8; j++)
		std::cout << (char)(j + 97) << " ";
	std::cout << std::endl;
	std::cout << "   ";
	for (int i = 0; i < 16; i++)
		std::cout << HORIZONTAL_LINE;
	std::cout << std::endl;
	for (int i = 0; i < 8; i++)
	{
		std::cout << (8 - i) << " " << VERTICAL_LINE << " ";
		for (int j = 0; j < 8; j++)
		{
			std::cout << Grid[i][j] << " ";
		}
		std::cout << std::endl;
	}
}
bool Check_Start(char Grid[][8], char x, char y, char player)
{
	char pos = Grid[x][y];

	//Check piece existence
	if (pos == EMPTY_SQUARE)
	{
		return false;
	}

	//Check if it is your piece
	if (player == WHITE_PLAYER)
	{
		if (pos != WHITE_BISHOP && pos != WHITE_HORSE && pos != WHITE_ROOK && pos != WHITE_KING && pos != WHITE_QUEEN && pos != WHITE_PAWN)
			return false;
	}
	else
	{
		if (pos != BLACK_BISHOP && pos != BLACK_HORSE && pos != BLACK_ROOK && pos != BLACK_KING && pos != BLACK_QUEEN && pos != BLACK_PAWN)
			return false;
	}
	//Returns false if the starting position is wrong
	return true;
}
bool Player_In_Check(char Grid[][8], char player)
{
	int s, t, x, y;
	if (player == BLACK_PLAYER)
	{
		for (int p = 0; p < 8; p++)
		{
			for (int m = 0; m < 8; m++)
			{
				if (Grid[p][m] == BLACK_BISHOP || Grid[p][m] == BLACK_QUEEN)
				{
					//Look on all directions
					//Search TOP Left x-- y--
					s = m - 1;
					t = p - 1;
					while (t >= 0 && s >= 0)
					{
						if (Grid[t][s] != EMPTY_SQUARE && Grid[t][s] != WHITE_KING)
							break;
						else if (Grid[t][s] == WHITE_KING)
							return true;
						s--;
						t--;
					}
					//Search BOTTOM Right x++ y++
					s = m + 1;
					t = p + 1;
					while (t < 8 && s < 8)
					{
						if (Grid[t][s] != EMPTY_SQUARE && Grid[t][s] != WHITE_KING)
							break;
						else if (Grid[t][s] == WHITE_KING)
							return true;
						s++;
						t++;
					}
					//Search BOTTOM Left x++ y--
					s = m - 1;
					t = p + 1;
					while (s >= 0 && t < 8)
					{
						if (Grid[t][s] != EMPTY_SQUARE && Grid[t][s] != WHITE_KING)
							break;
						else if (Grid[t][s] == WHITE_KING)
							return true;
						s--;
						t++;
					}
					//Search top Right x-- y++
					s = m + 1;
					t = p - 1;
					while (s < 8 && t >= 0)
					{
						if (Grid[t][s] != EMPTY_SQUARE && Grid[t][s] != WHITE_KING)
							break;
						else if (Grid[t][s] == WHITE_KING)
							return true;
						s++;
						t--;
					}
				}
				if (Grid[p][m] == BLACK_ROOK || Grid[p][m] == BLACK_QUEEN)
				{
					//Look Right
					for (int t = m + 1; t < 8; t++)
					{
						if (Grid[p][t] != EMPTY_SQUARE && Grid[p][t] != WHITE_KING)
							break;
						else if (Grid[p][t] == WHITE_KING)
							return true;
					}
					//Look Left
					for (int t = m - 1; t >= 0; t--)
					{
						if (Grid[p][t] != EMPTY_SQUARE && Grid[p][t] != WHITE_KING)
							break;
						else if (Grid[p][t] == WHITE_KING)
							return true;
					}
					//Look Up
					for (int t = p + 1; t < 8; t++)
					{
						if (Grid[t][m] != EMPTY_SQUARE && Grid[t][m] != WHITE_KING)
							break;
						else if (Grid[t][m] == WHITE_KING)
							return true;
					}
					//Look Down
					for (int t = p - 1; t >= 0; t--)
					{
						if (Grid[t][m] != EMPTY_SQUARE && Grid[t][m] != WHITE_KING)
							break;
						else if (Grid[t][m] == WHITE_KING)
							return true;
					}
				}
				if (Grid[p][m] == BLACK_HORSE)
				{
					if (p + 2 < 8 && m + 1 < 8 && Grid[p + 2][m + 1] == WHITE_KING)
						return true;
					if (p + 2 < 8 && m - 1 >= 0 && Grid[p + 2][m - 1] == WHITE_KING)
						return true;
					if (p - 2 >= 0 && m + 1 < 8 && Grid[p - 2][m + 1] == WHITE_KING)
						return true;
					if (p - 2 >= 0 && m - 1 >= 0 && Grid[p - 2][m - 1] == WHITE_KING)
						return true;
					if (p + 1 < 8 && m + 2 < 8 && Grid[p + 1][m + 2] == WHITE_KING)
						return true;
					if (p + 1 < 8 && m - 2 >= 0 && Grid[p + 1][m - 2] == WHITE_KING)
						return true;
					if (p - 1 >= 0 && m + 2 < 8 && Grid[p - 1][m + 2] == WHITE_KING)
						return true;
					if (p - 1 >= 0 && m - 2 >= 0 && Grid[p - 1][m - 2] == WHITE_KING)
						return true;
				}
				else if (Grid[p][m] == BLACK_PAWN)
				{
					if (m + 1 < 8 && p + 1 < 8 && Grid[p + 1][m + 1] == WHITE_KING)
						return true;
					if (m - 1 > 0 && p + 1 < 8 && Grid[p + 1][m - 1] == WHITE_KING)
						return true;
				}
			}
		}
	}
	else if (player == WHITE_PLAYER)
	{
		for (int p = 0; p < 8; p++)
		{
			for (int m = 0; m < 8; m++)
			{
				if (Grid[p][m] == WHITE_BISHOP || Grid[p][m] == WHITE_QUEEN)
				{
					//Look on all directions
					//Search TOP Left x-- y--
					s = m - 1;
					t = p - 1;
					while (t >= 0 && s >= 0)
					{
						if (Grid[t][s] != EMPTY_SQUARE && Grid[t][s] != BLACK_KING)
							break;
						else if (Grid[t][s] == BLACK_KING)
							return true;
						s--;
						t--;
					}
					//Search BOTTOM Right x++ y++
					s = m + 1;
					t = p + 1;
					while (t < 8 && s < 8)
					{
						if (Grid[t][s] != EMPTY_SQUARE && Grid[t][s] != BLACK_KING)
							break;
						else if (Grid[t][s] == BLACK_KING)
							return true;
						s++;
						t++;
					}
					//Search BOTTOM Left x++ y--
					s = m - 1;
					t = p + 1;
					while (s >= 0 && t < 8)
					{
						if (Grid[t][s] != EMPTY_SQUARE && Grid[t][s] != BLACK_KING)
							break;
						else if (Grid[t][s] == BLACK_KING)
							return true;
						s--;
						t++;
					}
					//Search top Right x-- y++
					s = m + 1;
					t = p - 1;
					while (s < 8 && t >= 0)
					{
						if (Grid[t][s] != EMPTY_SQUARE && Grid[t][s] != BLACK_KING)
							break;
						else if (Grid[t][s] == BLACK_KING)
							return true;
						s++;
						t--;
					}
				}
				if (Grid[p][m] == WHITE_ROOK || Grid[p][m] == WHITE_QUEEN)
				{
					//Look Right
					for (int t = m + 1; t < 8; t++)
					{
						if (Grid[p][t] != EMPTY_SQUARE && Grid[p][t] != BLACK_KING)
							break;
						else if (Grid[p][t] == BLACK_KING)
							return true;
					}
					//Look Left
					for (int t = m - 1; t >= 0; t--)
					{
						if (Grid[p][t] != EMPTY_SQUARE && Grid[p][t] != BLACK_KING)
							break;
						else if (Grid[p][t] == BLACK_KING)
							return true;
					}
					//Look Up
					for (int t = p + 1; t < 8; t++)
					{
						if (Grid[t][m] != EMPTY_SQUARE && Grid[t][m] != BLACK_KING)
							break;
						else if (Grid[t][m] == BLACK_KING)
							return true;
					}
					//Look Down
					for (int t = p - 1; t >= 0; t--)
					{
						if (Grid[t][m] != EMPTY_SQUARE && Grid[t][m] != BLACK_KING)
							break;
						else if (Grid[t][m] == BLACK_KING)
							return true;
					}
				}
				if (Grid[p][m] == WHITE_HORSE)
				{
					if (p + 2 < 8 && m + 1 < 8 && Grid[p + 2][m + 1] == BLACK_KING)
						return true;
					if (p + 2 < 8 && m - 1 >= 0 && Grid[p + 2][m - 1] == BLACK_KING)
						return true;
					if (p - 2 >= 0 && m + 1 < 8 && Grid[p - 2][m + 1] == BLACK_KING)
						return true;
					if (p - 2 >= 0 && m - 1 >= 0 && Grid[p - 2][m - 1] == BLACK_KING)
						return true;
					if (p + 1 < 8 && m + 2 < 8 && Grid[p + 1][m + 2] == BLACK_KING)
						return true;
					if (p + 1 < 8 && m - 2 >= 0 && Grid[p + 1][m - 2] == BLACK_KING)
						return true;
					if (p - 1 >= 0 && m + 2 < 8 && Grid[p - 1][m + 2] == BLACK_KING)
						return true;
					if (p - 1 >= 0 && m - 2 >= 0 && Grid[p - 1][m - 2] == BLACK_KING)
						return true;
				}
				else if (Grid[p][m] == WHITE_PAWN)
				{
					if (m + 1 < 8 && p - 1 > 0 && Grid[p - 1][m + 1] == BLACK_KING)
						return true;
					if (m - 1 > 0 && p - 1 > 0 && Grid[p - 1][m - 1] == BLACK_KING)
						return true;
				}
			}
		}
	}
	//Check that both kings are not in contact

	//First locate the kings
	for (s = 0; s < 8; s++)
		for (t = 0; t < 8; t++)
			if (Grid[s][t] == BLACK_KING)
				goto fd;
fd:

	for (x = 0; x < 8; x++)
		for (y = 0; y < 8; y++)
			if (Grid[x][y] == WHITE_KING)
				goto fd2;
fd2:
	//Then we check if they are close
	if (abs(x - s) <= 1 && abs(y - t) <= 1)
		return true;
	return false;
}
bool Check_ADVANCED(char Grid[][8], char x, char y, char j, char z, char player, Button* pieces[])
{
	char piece = Grid[x][y];
	char dest = Grid[j][z];
	bool Castle_Left = false;
	bool Castle_Right = false;
	bool King_Move = false;
	bool check = false;
	char en_passant = 'z';
	char aux, aux_piece;
	int m;
	//Basic movement and Captures
	switch (piece)
	{
	case WHITE_PAWN:
	case BLACK_PAWN:
		//Check backwards movement
		if (piece == WHITE_PAWN && j > x)
			return false;
		else if (piece == BLACK_PAWN && x > j)
			return false;
		//Check posible double move if first time moving pawn
		if (abs(x - j) == 2 && abs(y - z) == 0)
		{
			if (player == WHITE_PLAYER && x == 6)
			{
				en_passant = y;
				goto CHECK_CHECK;
			}
			else if (player == BLACK_PLAYER && x == 1)
			{
				en_passant = y;
				goto CHECK_CHECK;
			}
		}
		//Check en passant
		if (dest == EMPTY_SQUARE && abs(y - z) == 1 && abs(x - j) == 1 && ((player == WHITE_PLAYER && Grid[j + 1][z] == BLACK_PAWN && BLACK_EN_PASSANT == z) || (player == BLACK_PLAYER && Grid[j - 1][z] == WHITE_PAWN && WHITE_EN_PASSANT == z)))
		{
			en_passant = 'k';
			goto CHECK_CHECK;
		}
		//Check that the move is not further than one square and if it goes diagonally there is not an empty square and can t kill enemies just walking forward
		if (abs(y - z) > 1 || abs(x - j) > 1 || ((y != z) && (dest == EMPTY_SQUARE)) || ((y == z) && (dest != EMPTY_SQUARE)))
			return false;
		//Can t capture going horizontally
		if (y - z != 0 && x - j == 0)
			return false;
		//check promote
		if (j == 0 || j == 7)
		{
			std::cout << "What do you want to promote to?" << std::endl;
			std::cout << "Queen (Q/q) Bishop (B/b) Horse (H/h) Rook (R/r)" << std::endl;
			std::cin >> piece;
			bool white_promote = (player == WHITE_PLAYER && (piece == WHITE_HORSE || piece == WHITE_BISHOP || piece == WHITE_QUEEN || piece == WHITE_ROOK));
			bool black_promote = (player == BLACK_PLAYER && (piece == BLACK_HORSE || piece == BLACK_BISHOP || piece == BLACK_QUEEN || piece == BLACK_ROOK));
			bool result = !(white_promote ^ black_promote);
			while (!std::cin.good() || result)
			{
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				system("CLS");
				Display_Grid(Grid);
				std::cout << "What do you want to promote to?" << std::endl;
				std::cout << "Queen (Q/q) Bishop (B/b) Horse (H/h) Rook (R/r)" << std::endl;
				std::cout << "Insert Correct data" << std::endl;
				std::cin >> piece;
				white_promote = (player == WHITE_PLAYER && (piece == WHITE_HORSE || piece == WHITE_BISHOP || piece == WHITE_QUEEN || piece == WHITE_ROOK));
				black_promote = (player == BLACK_PLAYER && (piece == BLACK_HORSE || piece == BLACK_BISHOP || piece == BLACK_QUEEN || piece == BLACK_ROOK));
				result = !(white_promote ^ black_promote);
			}
			Grid[x][y] = piece;
		}
		break;
	case WHITE_HORSE:
	case BLACK_HORSE:
		//Basic movement
		if (abs(x - j) == 2 && abs(y - z) == 1)
			goto CHECK_CHECK;
		if (abs(y - z) == 2 && abs(x - j) == 1)
			goto CHECK_CHECK;
		return false;
	case WHITE_QUEEN:
	case BLACK_QUEEN:
	case WHITE_ROOK:
	case BLACK_ROOK:
		//Check Vertical movement
		if (x == j && y != z)
		{
			y < z ? aux = y : aux = z;
			for (int t = 1; t < abs(y - z); t++)
				if (Grid[x][t + aux] != EMPTY_SQUARE)
					return false;
			if (piece == BLACK_ROOK || piece == WHITE_ROOK)
			{
				if (y == 7) Castle_Right = true;
				if (y == 0) Castle_Left = true;
			}
			goto CHECK_CHECK;
		}
		//Check Horizontal movement
		if (z == y && x != j)
		{
			x < j ? aux = x : aux = j;
			for (int t = 1; t < abs(x - j); t++)
				if (Grid[t + aux][y] != EMPTY_SQUARE)
					return false;
			if (piece == BLACK_ROOK || piece == WHITE_ROOK)
			{
				if (y == 7) Castle_Right = true;
				if (y == 0) Castle_Left = true;
			}
			goto CHECK_CHECK;
		}
		if (piece == BLACK_ROOK || piece == WHITE_ROOK)
			return false;
	case WHITE_BISHOP:
	case BLACK_BISHOP:
		//Check diagonal movement
		if (abs(x - j) != abs(y - z) || abs(x - j) == 0)
			return false;
		//Search TOP Left x-- y--
		if (x > j && y > z)
		{
			m = y - 1;
			for (int t = x - 1; t > j; t--)
			{
				if (Grid[t][m] != EMPTY_SQUARE)
					return false;
				m--;
			}
		}
		//Search BOTTOM Right x++ y++
		else if (x < j && y < z)
		{
			m = y + 1;
			for (int t = x + 1; t < j; t++)
			{
				if (Grid[t][m] != EMPTY_SQUARE)
					return false;
				m++;
			}
		}
		//Search BOTTOM Left x++ y--
		else if (x < j && y>z)
		{
			m = y - 1;
			for (int t = x + 1; t < j; t++)
			{
				if (Grid[t][m] != EMPTY_SQUARE)
					return false;
				m--;
			}
		}
		//Search top Right x-- y++
		else
		{
			m = y + 1;
			for (int t = x - 1; t > j; t--)
			{
				if (Grid[t][m] != EMPTY_SQUARE)
					return false;
				m++;
			}
		}
		goto CHECK_CHECK;
		break;
	case WHITE_KING:
	case BLACK_KING:
		//Basic movement
		if (abs(j - x) > 1 || abs(y - z) > 2 || (abs(y - z) > 1 && y != 4))
			return false;
		//Castle
		if (abs(y - z) == 2 && abs(j - x) == 0 && (x == 0 || x == 7) && y == 4)
		{
			if (player == WHITE_PLAYER && WHITE_CASTLE_KING == true && (WHITE_CASTLE_LEFT == true || WHITE_CASTLE_RIGHT == true))
			{
				if (z == 6)//Castle right
				{
					if (Grid[x][5] != EMPTY_SQUARE || Grid[x][6] != EMPTY_SQUARE || WHITE_CASTLE_RIGHT == false)
						return false;
					Grid[x][5] = WHITE_KING;
					Grid[x][7] = EMPTY_SQUARE;
					check = Player_In_Check(Grid, player % 2 + 1);
					if (check == true)
						return false;
					Grid[x][6] = WHITE_KING;
					check = Player_In_Check(Grid, player % 2 + 1);
					if (check == true)
						return false;
					for (int i = 0; i < 32; i++)
					{
						if (pieces[i]->Getpiece() == WHITE_ROOK)
						{
							int xx, yy;
							pieces[i]->Getposition(&xx, &yy);
							if (xx == (7) * 80 && yy == x * 80)
							{
								pieces[i]->Setposition(5 * 80, x * 80);
								break;
							}
						}
					}
					Grid[x][5] = WHITE_ROOK;

					King_Move = true;
					goto CHECK_CHECK;
				}
				if (z == 2)
				{
					if (Grid[x][3] != EMPTY_SQUARE || Grid[x][2] != EMPTY_SQUARE || Grid[x][1] != EMPTY_SQUARE || WHITE_CASTLE_LEFT == false)
						return false;
					Grid[x][3] = WHITE_KING;
					Grid[x][0] = EMPTY_SQUARE;
					check = Player_In_Check(Grid, player % 2 + 1);
					if (check == true)
						return false;
					Grid[x][2] = WHITE_KING;
					check = Player_In_Check(Grid, player % 2 + 1);
					if (check == true)
						return false;
					for (int i = 0; i < 32; i++)
					{
						if (pieces[i]->Getpiece() == WHITE_ROOK)
						{
							int xx, yy;
							pieces[i]->Getposition(&xx, &yy);
							if (xx == 0 && yy == x * 80)
							{
								pieces[i]->Setposition(3 * 80, x * 80);
								break;
							}
						}
					}
					Grid[x][3] = WHITE_ROOK;
					King_Move = true;
					goto CHECK_CHECK;
				}
			}
			if (player == BLACK_PLAYER && BLACK_CASTLE_KING == true && (BLACK_CASTLE_LEFT == true || BLACK_CASTLE_RIGHT == true))
			{
				if (z == 6)//Castle right
				{
					if (Grid[x][5] != EMPTY_SQUARE || Grid[x][6] != EMPTY_SQUARE || BLACK_CASTLE_RIGHT == false)
						return false;
					Grid[x][5] = BLACK_KING;
					Grid[x][7] = EMPTY_SQUARE;
					check = Player_In_Check(Grid, player % 2 + 1);
					if (check == true)
						return false;
					Grid[x][6] = BLACK_KING;
					check = Player_In_Check(Grid, player % 2 + 1);
					if (check == true)
						return false;
					for (int i = 0; i < 32; i++)
					{
						if (pieces[i]->Getpiece() == BLACK_ROOK)
						{
							int xx, yy;
							pieces[i]->Getposition(&xx, &yy);
							if (xx == (7) * 80 && yy == x * 80)
							{
								pieces[i]->Setposition(5 * 80,x*80);
								break;
							}
						}
					}
					Grid[x][5] = BLACK_ROOK;

					King_Move = true;
					goto CHECK_CHECK;
				}
				if (z == 2)
				{
					if (Grid[x][3] != EMPTY_SQUARE || Grid[x][2] != EMPTY_SQUARE || Grid[x][1] != EMPTY_SQUARE || BLACK_CASTLE_LEFT == false)
						return false;

					Grid[x][3] = BLACK_KING;
					Grid[x][0] = EMPTY_SQUARE;
					check = Player_In_Check(Grid, player % 2 + 1);
					if (check == true)
						return false;
					Grid[x][2] = BLACK_KING;
					check = Player_In_Check(Grid, player % 2 + 1);
					if (check == true)
						return false;
					for (int i = 0; i < 32; i++)
					{
						if (pieces[i]->Getpiece() == BLACK_ROOK)
						{
							int xx, yy;
							pieces[i]->Getposition(&xx, &yy);
							if (xx == 0 && yy == x * 80)
							{
								pieces[i]->Setposition(3*80, x * 80);
								break;
							}
						}
					}
					Grid[x][3] = BLACK_ROOK;
					King_Move = true;
					goto CHECK_CHECK;
				}
			}
			return false;
		}
		King_Move = true;
		break;
	}
CHECK_CHECK:
	//We simulate the move on the actual Grid but if the move is not posible we goto restore and we change the grid again.
	Grid[x][y] = EMPTY_SQUARE;
	aux_piece = Grid[j][z];
	Grid[j][z] = piece;
	if (player == WHITE_PLAYER)
	{
		//An en passant capture is being tested
		if (en_passant == 'k') Grid[j + 1][z] = EMPTY_SQUARE;

		check = Player_In_Check(Grid, player % 2 + 1);
		if (check == true)
		{
			if (en_passant == 'k') Grid[j + 1][z] = BLACK_PAWN;
			goto restore;
		}
		//If en passant is possible kill pawn visually
		if (en_passant == 'k')
		{
			for (int i = 0; i < 32; i++)
			{
				if (pieces[i]->Getpiece() == BLACK_PAWN)
				{
					int xx, yy;
					pieces[i]->Getposition(&xx, &yy);
					if (yy == (j + 1)*80 && xx == z*80)
					{
						pieces[i]->Setdead();
						break;
					}
				}
			}
		}

		//update castle variables
		if (WHITE_CASTLE_KING == true) WHITE_CASTLE_KING = !King_Move;
		if (WHITE_CASTLE_LEFT == true) WHITE_CASTLE_LEFT = !Castle_Left;
		if (WHITE_CASTLE_RIGHT == true) WHITE_CASTLE_RIGHT = !Castle_Right;
		//update en passant column
		if (en_passant != 'z' && en_passant != 'k') WHITE_EN_PASSANT = en_passant;
		BLACK_EN_PASSANT = 'z';
	}
	if (player == BLACK_PLAYER)
	{
		//An en passant capture is being tested
		if (en_passant == 'k') Grid[j - 1][z] = EMPTY_SQUARE;
		
		check = Player_In_Check(Grid, player % 2 + 1);
		if (check == true)
		{
			if (en_passant == 'k') Grid[j - 1][z] = WHITE_PAWN;
			goto restore;
		}
		//If en passant is possible kill pawn visually
		if (en_passant == 'k')
		{
			for (int i = 0; i < 32; i++)
			{
				if (pieces[i]->Getpiece() == WHITE_PAWN)
				{
					int xx, yy;
					pieces[i]->Getposition(&xx, &yy);
					if (yy == (j + 1) * 80 && xx == z * 80)
					{
						pieces[i]->Setdead();
						break;
					}
				}
			}
		}
		//update castle variables
		if (BLACK_CASTLE_KING == true) BLACK_CASTLE_KING = !King_Move;
		if (BLACK_CASTLE_LEFT == true) BLACK_CASTLE_LEFT = !Castle_Left;
		if (BLACK_CASTLE_RIGHT == true) BLACK_CASTLE_RIGHT = !Castle_Right;
		//update en passant column
		if (en_passant != 'z' && en_passant != 'k') BLACK_EN_PASSANT = en_passant;
		WHITE_EN_PASSANT = 'z';
	}
	//returns false if the move is not possible
	return true;
restore:
	Grid[x][y] = Grid[j][z];
	Grid[j][z] = aux_piece;
	return false;
}
bool Check_END(char Grid[][8], char x, char y, char j, char z, char player,Button* pieces[])
{
	char pos = Grid[j][z];

	//Check if destination is empty
	if (pos == EMPTY_SQUARE)
	{
		return Check_ADVANCED(Grid, x, y, j, z, player,pieces);
	}

	//Check if destination is one of your pieces
	if (player == WHITE_PLAYER)
	{
		if (pos == WHITE_BISHOP || pos == WHITE_HORSE || pos == WHITE_ROOK || pos == WHITE_KING || pos == WHITE_QUEEN || pos == WHITE_PAWN)
			return false;
	}
	else
	{
		if (pos == BLACK_BISHOP || pos == BLACK_HORSE || pos == BLACK_ROOK || pos == BLACK_KING || pos == BLACK_QUEEN || pos == BLACK_PAWN)
			return false;
	}
	return Check_ADVANCED(Grid, x, y, j, z, player,pieces);
}
bool Check_Tie(char Grid[][8], char player)
{
	char piece, aux, obj1, obj2;
	//Check all the pieces of the player until one can move
	if (Player_In_Check(Grid, player) == true)
	{
		return false;
	}
	if (player == BLACK_PLAYER)
	{
		for (int x = 0; x < 8; x++)
		{
			for (int y = 0; y < 8; y++)
			{
				piece = Grid[x][y];
				if (piece == WHITE_PAWN)
				{
					//check normal movement then  finally check if en passant is posible
					if (Grid[x - 1][y] == EMPTY_SQUARE)
					{
						Grid[x][y] = EMPTY_SQUARE;
						Grid[x - 1][y] = piece;
						if (Player_In_Check(Grid, player) == false)
						{
							Grid[x - 1][y] = EMPTY_SQUARE;
							Grid[x][y] = piece;
							return false;
						}
						Grid[x - 1][y] = EMPTY_SQUARE;
						Grid[x][y] = piece;
					}
					//check capture right + en passant right
					if (y + 1 < 8)
					{
						obj1 = Grid[x - 1][y + 1];
						if (obj1 == BLACK_PAWN || obj1 == BLACK_ROOK || obj1 == BLACK_HORSE || obj1 == BLACK_BISHOP || obj1 == BLACK_QUEEN)
						{
							Grid[x - 1][y + 1] = piece;
							Grid[x][y] = EMPTY_SQUARE;
							if (Player_In_Check(Grid, player) == false)
							{
								Grid[x][y] = piece;
								Grid[x - 1][y + 1] = obj1;
								return false;
							}
							Grid[x][y] = piece;
							Grid[x - 1][y + 1] = obj1;
						}
						//check en passant
						if (obj1 == EMPTY_SQUARE && x == 3 && (Grid[x][y + 1] == BLACK_PAWN && BLACK_EN_PASSANT == y + 1))
						{
							aux = Grid[x][y + 1];
							Grid[x - 1][y + 1] = piece;
							Grid[x][y] = EMPTY_SQUARE;
							Grid[x][y + 1] = EMPTY_SQUARE;
							if (Player_In_Check(Grid, player) == false)
							{
								Grid[x - 1][y + 1] = EMPTY_SQUARE;
								Grid[x][y] = piece;
								Grid[x][y + 1] = aux;
								return false;
							}
							Grid[x - 1][y + 1] = EMPTY_SQUARE;
							Grid[x][y] = piece;
							Grid[x][y + 1] = aux;
						}
					}
					//check capture left + en passant left
					if (y - 1 >= 0)
					{
						obj2 = Grid[x - 1][y - 1];
						if (obj2 == BLACK_PAWN || obj2 == BLACK_ROOK || obj2 == BLACK_HORSE || obj2 == BLACK_BISHOP || obj2 == BLACK_QUEEN)
						{
							Grid[x - 1][y - 1] = piece;
							Grid[x][y] = EMPTY_SQUARE;
							if (Player_In_Check(Grid, player) == false)
							{
								Grid[x][y] = piece;
								Grid[x - 1][y - 1] = obj2;
								return false;
							}
							Grid[x][y] = piece;
							Grid[x - 1][y - 1] = obj2;
						}
						//check en passant
						if (obj2 == EMPTY_SQUARE && x == 3 && (Grid[x][y - 1] == BLACK_PAWN && BLACK_EN_PASSANT == y - 1))
						{
							aux = Grid[x][y - 1];
							Grid[x - 1][y - 1] = piece;
							Grid[x][y] = EMPTY_SQUARE;
							Grid[x][y - 1] = EMPTY_SQUARE;
							if (Player_In_Check(Grid, player) == false)
							{
								Grid[x - 1][y - 1] = EMPTY_SQUARE;
								Grid[x][y] = piece;
								Grid[x][y - 1] = aux;
								return false;
							}
							Grid[x - 1][y - 1] = EMPTY_SQUARE;
							Grid[x][y] = piece;
							Grid[x][y - 1] = aux;
						}
					}
				}
				if (piece == WHITE_HORSE)
				{
					//Check all its moves until one can be done
					if (x + 2 < 8 && y + 1 < 8)
					{
						obj1 = Grid[x + 2][y + 1];
						if (obj1 == EMPTY_SQUARE || obj1 == BLACK_PAWN || obj1 == BLACK_ROOK || obj1 == BLACK_HORSE || obj1 == BLACK_BISHOP || obj1 == BLACK_QUEEN)
						{
							Grid[x + 2][y + 1] = piece;
							Grid[x][y] = EMPTY_SQUARE;
							if (Player_In_Check(Grid, player) == false)
							{
								Grid[x + 2][y + 1] = obj1;
								Grid[x][y] = piece;
								return false;
							}
							Grid[x + 2][y + 1] = obj1;
							Grid[x][y] = piece;
						}
					}
					if (x + 2 < 8 && y - 1 >= 0)
					{
						obj1 = Grid[x + 2][y - 1];
						if (obj1 == EMPTY_SQUARE || obj1 == BLACK_PAWN || obj1 == BLACK_ROOK || obj1 == BLACK_HORSE || obj1 == BLACK_BISHOP || obj1 == BLACK_QUEEN)
						{
							Grid[x + 2][y - 1] = piece;
							Grid[x][y] = EMPTY_SQUARE;
							if (Player_In_Check(Grid, player) == false)
							{
								Grid[x + 2][y - 1] = obj1;
								Grid[x][y] = piece;
								return false;
							}
							Grid[x + 2][y - 1] = obj1;
							Grid[x][y] = piece;
						}
					}
					if (x - 2 >= 0 && y + 1 < 8)
					{
						obj1 = Grid[x - 2][y + 1];
						if (obj1 == EMPTY_SQUARE || obj1 == BLACK_PAWN || obj1 == BLACK_ROOK || obj1 == BLACK_HORSE || obj1 == BLACK_BISHOP || obj1 == BLACK_QUEEN)
						{
							Grid[x - 2][y + 1] = piece;
							Grid[x][y] = EMPTY_SQUARE;
							if (Player_In_Check(Grid, player) == false)
							{
								Grid[x - 2][y + 1] = obj1;
								Grid[x][y] = piece;
								return false;
							}
							Grid[x - 2][y + 1] = obj1;
							Grid[x][y] = piece;
						}
					}
					if (x - 2 >= 0 && y - 1 >= 0)
					{
						obj1 = Grid[x - 2][y - 1];
						if (obj1 == EMPTY_SQUARE || obj1 == BLACK_PAWN || obj1 == BLACK_ROOK || obj1 == BLACK_HORSE || obj1 == BLACK_BISHOP || obj1 == BLACK_QUEEN)
						{
							Grid[x - 2][y - 1] = piece;
							Grid[x][y] = EMPTY_SQUARE;
							if (Player_In_Check(Grid, player) == false)
							{
								Grid[x - 2][y - 1] = obj1;
								Grid[x][y] = piece;
								return false;
							}
							Grid[x - 2][y - 1] = obj1;
							Grid[x][y] = piece;
						}
					}
					if (x + 1 < 8 && y + 2 < 8)
					{
						obj1 = Grid[x + 1][y + 2];
						if (obj1 == EMPTY_SQUARE || obj1 == BLACK_PAWN || obj1 == BLACK_ROOK || obj1 == BLACK_HORSE || obj1 == BLACK_BISHOP || obj1 == BLACK_QUEEN)
						{
							Grid[x + 1][y + 2] = piece;
							Grid[x][y] = EMPTY_SQUARE;
							if (Player_In_Check(Grid, player) == false)
							{
								Grid[x + 1][y + 2] = obj1;
								Grid[x][y] = piece;
								return false;
							}
							Grid[x + 1][y + 2] = obj1;
							Grid[x][y] = piece;
						}
					}
					if (x + 1 < 8 && y - 2 >= 0)
					{
						obj1 = Grid[x + 1][y - 2];
						if (obj1 == EMPTY_SQUARE || obj1 == BLACK_PAWN || obj1 == BLACK_ROOK || obj1 == BLACK_HORSE || obj1 == BLACK_BISHOP || obj1 == BLACK_QUEEN)
						{
							Grid[x + 1][y - 2] = piece;
							Grid[x][y] = EMPTY_SQUARE;
							if (Player_In_Check(Grid, player) == false)
							{
								Grid[x + 1][y - 2] = obj1;
								Grid[x][y] = piece;
								return false;
							}
							Grid[x + 1][y - 2] = obj1;
							Grid[x][y] = piece;
						}
					}
					if (x - 1 >= 0 && y + 2 < 8)
					{
						obj1 = Grid[x - 1][y + 2];
						if (obj1 == EMPTY_SQUARE || obj1 == BLACK_PAWN || obj1 == BLACK_ROOK || obj1 == BLACK_HORSE || obj1 == BLACK_BISHOP || obj1 == BLACK_QUEEN)
						{
							Grid[x - 1][y + 2] = piece;
							Grid[x][y] = EMPTY_SQUARE;
							if (Player_In_Check(Grid, player) == false)
							{
								Grid[x - 1][y + 2] = obj1;
								Grid[x][y] = piece;
								return false;
							}
							Grid[x - 1][y + 2] = obj1;
							Grid[x][y] = piece;
						}
					}
					if (x - 1 >= 0 && y - 2 >= 0)
					{
						obj1 = Grid[x - 1][y - 2];
						if (obj1 == EMPTY_SQUARE || obj1 == BLACK_PAWN || obj1 == BLACK_ROOK || obj1 == BLACK_HORSE || obj1 == BLACK_BISHOP || obj1 == BLACK_QUEEN)
						{
							Grid[x - 1][y - 2] = piece;
							Grid[x][y] = EMPTY_SQUARE;
							if (Player_In_Check(Grid, player) == false)
							{
								Grid[x - 1][y - 2] = obj1;
								Grid[x][y] = piece;
								return false;
							}
							Grid[x - 1][y - 2] = obj1;
							Grid[x][y] = piece;
						}
					}
				}
				if (piece == WHITE_BISHOP || piece == WHITE_QUEEN || piece == WHITE_KING)
				{
					//Check one square diagonal distance if any of these is allowed stop looking
					if (x + 1 < 8 && y + 1 < 8)
					{
						obj1 = Grid[x + 1][y + 1];
						if (obj1 == EMPTY_SQUARE || obj1 == BLACK_PAWN || obj1 == BLACK_ROOK || obj1 == BLACK_HORSE || obj1 == BLACK_BISHOP || obj1 == BLACK_QUEEN)
						{
							Grid[x + 1][y + 1] = piece;
							Grid[x][y] = EMPTY_SQUARE;
							if (Player_In_Check(Grid, player) == false)
							{
								Grid[x + 1][y + 1] = obj1;
								Grid[x][y] = piece;
								return false;
							}
							Grid[x + 1][y + 1] = obj1;
							Grid[x][y] = piece;
						}
					}
					if (x + 1 < 8 && y - 1 >= 0)
					{
						obj1 = Grid[x + 1][y - 1];
						if (obj1 == EMPTY_SQUARE || obj1 == BLACK_PAWN || obj1 == BLACK_ROOK || obj1 == BLACK_HORSE || obj1 == BLACK_BISHOP || obj1 == BLACK_QUEEN)
						{
							Grid[x + 1][y - 1] = piece;
							Grid[x][y] = EMPTY_SQUARE;
							if (Player_In_Check(Grid, player) == false)
							{
								Grid[x + 1][y - 1] = obj1;
								Grid[x][y] = piece;
								return false;
							}
							Grid[x + 1][y - 1] = obj1;
							Grid[x][y] = piece;
						}
					}
					if (x - 1 >= 0 && y + 1 < 8)
					{
						obj1 = Grid[x - 1][y + 1];
						if (obj1 == EMPTY_SQUARE || obj1 == BLACK_PAWN || obj1 == BLACK_ROOK || obj1 == BLACK_HORSE || obj1 == BLACK_BISHOP || obj1 == BLACK_QUEEN)
						{
							Grid[x - 1][y + 1] = piece;
							Grid[x][y] = EMPTY_SQUARE;
							if (Player_In_Check(Grid, player) == false)
							{
								Grid[x - 1][y + 1] = obj1;
								Grid[x][y] = piece;
								return false;
							}
							Grid[x - 1][y + 1] = obj1;
							Grid[x][y] = piece;
						}
					}
					if (x - 1 >= 0 && y - 1 >= 0)
					{
						obj1 = Grid[x - 1][y - 1];
						if (obj1 == EMPTY_SQUARE || obj1 == BLACK_PAWN || obj1 == BLACK_ROOK || obj1 == BLACK_HORSE || obj1 == BLACK_BISHOP || obj1 == BLACK_QUEEN)
						{
							Grid[x - 1][y - 1] = piece;
							Grid[x][y] = EMPTY_SQUARE;
							if (Player_In_Check(Grid, player) == false)
							{
								Grid[x - 1][y - 1] = obj1;
								Grid[x][y] = piece;
								return false;
							}
							Grid[x - 1][y - 1] = obj1;
							Grid[x][y] = piece;
						}
					}
				}
				if (piece == WHITE_ROOK || piece == WHITE_QUEEN || piece == WHITE_KING)
				{
					//Check one square distance both vertically and horizontally if the move is allowed stop looking
					if (y + 1 < 8)
					{
						obj1 = Grid[x][y + 1];
						if (obj1 == EMPTY_SQUARE || obj1 == BLACK_PAWN || obj1 == BLACK_ROOK || obj1 == BLACK_HORSE || obj1 == BLACK_BISHOP || obj1 == BLACK_QUEEN)
						{
							Grid[x][y] = EMPTY_SQUARE;
							Grid[x][y + 1] = piece;
							if (Player_In_Check(Grid, player) == false)
							{
								Grid[x][y] = piece;
								Grid[x][y + 1] = obj1;
								return false;
							}
							Grid[x][y] = piece;
							Grid[x][y + 1] = obj1;
						}
					}
					if (y - 1 >= 0)
					{
						obj1 = Grid[x][y - 1];
						if (obj1 == EMPTY_SQUARE || obj1 == BLACK_PAWN || obj1 == BLACK_ROOK || obj1 == BLACK_HORSE || obj1 == BLACK_BISHOP || obj1 == BLACK_QUEEN)
						{
							Grid[x][y] = EMPTY_SQUARE;
							Grid[x][y - 1] = piece;
							if (Player_In_Check(Grid, player) == false)
							{
								Grid[x][y] = piece;
								Grid[x][y - 1] = obj1;
								return false;
							}
							Grid[x][y] = piece;
							Grid[x][y - 1] = obj1;
						}
					}
					if (x + 1 < 8)
					{
						obj1 = Grid[x + 1][y];
						if (obj1 == EMPTY_SQUARE || obj1 == BLACK_PAWN || obj1 == BLACK_ROOK || obj1 == BLACK_HORSE || obj1 == BLACK_BISHOP || obj1 == BLACK_QUEEN)
						{
							Grid[x][y] = EMPTY_SQUARE;
							Grid[x + 1][y] = piece;
							if (Player_In_Check(Grid, player) == false)
							{
								Grid[x][y] = piece;
								Grid[x + 1][y] = obj1;
								return false;
							}
							Grid[x][y] = piece;
							Grid[x + 1][y] = obj1;
						}
					}
					if (x - 1 >= 0)
					{
						obj1 = Grid[x - 1][y];
						if (obj1 == EMPTY_SQUARE || obj1 == BLACK_PAWN || obj1 == BLACK_ROOK || obj1 == BLACK_HORSE || obj1 == BLACK_BISHOP || obj1 == BLACK_QUEEN)
						{
							Grid[x][y] = EMPTY_SQUARE;
							Grid[x - 1][y] = piece;
							if (Player_In_Check(Grid, player) == false)
							{
								Grid[x][y] = piece;
								Grid[x - 1][y] = obj1;
								return false;
							}
							Grid[x][y] = piece;
							Grid[x - 1][y] = obj1;
						}
					}
				}
			}
		}
	}
	else
	{
		for (int x = 0; x < 8; x++)
		{
			for (int y = 0; y < 8; y++)
			{
				piece = Grid[x][y];
				if (piece == BLACK_PAWN)
				{
					//check normal movement then  finally check if en passant is posible
					if (Grid[x + 1][y] == EMPTY_SQUARE)
					{
						Grid[x][y] = EMPTY_SQUARE;
						Grid[x + 1][y] = piece;
						if (Player_In_Check(Grid, player) == false)
						{
							Grid[x + 1][y] = EMPTY_SQUARE;
							Grid[x][y] = piece;
							return false;
						}
						Grid[x + 1][y] = EMPTY_SQUARE;
						Grid[x][y] = piece;
					}
					//check capture right + en passant right
					if (y + 1 < 8)
					{
						obj1 = Grid[x + 1][y + 1];
						if (obj1 == WHITE_PAWN || obj1 == WHITE_ROOK || obj1 == WHITE_HORSE || obj1 == WHITE_BISHOP || obj1 == WHITE_QUEEN)
						{
							Grid[x + 1][y + 1] = piece;
							Grid[x][y] = EMPTY_SQUARE;
							if (Player_In_Check(Grid, player) == false)
							{
								Grid[x][y] = piece;
								Grid[x + 1][y + 1] = obj1;
								return false;
							}
							Grid[x][y] = piece;
							Grid[x + 1][y + 1] = obj1;
						}
						//check en passant
						if (obj1 == EMPTY_SQUARE && x == 4 && (Grid[x][y + 1] == WHITE_PAWN && WHITE_EN_PASSANT == y + 1))
						{
							aux = Grid[x][y + 1];
							Grid[x + 1][y + 1] = piece;
							Grid[x][y] = EMPTY_SQUARE;
							Grid[x][y + 1] = EMPTY_SQUARE;
							if (Player_In_Check(Grid, player) == false)
							{
								Grid[x + 1][y + 1] = EMPTY_SQUARE;
								Grid[x][y] = piece;
								Grid[x][y + 1] = aux;
								return false;
							}
							Grid[x + 1][y + 1] = EMPTY_SQUARE;
							Grid[x][y] = piece;
							Grid[x][y + 1] = aux;
						}
					}
					//check capture left + en passant left
					if (y - 1 > 0)
					{
						obj2 = Grid[x + 1][y - 1];
						if (obj2 == WHITE_PAWN || obj1 == WHITE_ROOK || obj1 == WHITE_HORSE || obj1 == WHITE_BISHOP || obj1 == WHITE_QUEEN)
						{
							Grid[x + 1][y - 1] = piece;
							Grid[x][y] = EMPTY_SQUARE;
							if (Player_In_Check(Grid, player) == false)
							{
								Grid[x][y] = piece;
								Grid[x + 1][y - 1] = obj2;
								return false;
							}
							Grid[x][y] = piece;
							Grid[x + 1][y - 1] = obj2;
						}
						//check en passant
						if (obj2 == EMPTY_SQUARE && x == 4 && (Grid[x][y - 1] == WHITE_PAWN && WHITE_EN_PASSANT == y - 1))
						{
							aux = Grid[x][y - 1];
							Grid[x + 1][y - 1] = piece;
							Grid[x][y] = EMPTY_SQUARE;
							Grid[x][y - 1] = EMPTY_SQUARE;
							if (Player_In_Check(Grid, player) == false)
							{
								Grid[x + 1][y - 1] = EMPTY_SQUARE;
								Grid[x][y] = piece;
								Grid[x][y - 1] = aux;
								return false;
							}
							Grid[x + 1][y - 1] = EMPTY_SQUARE;
							Grid[x][y] = piece;
							Grid[x][y - 1] = aux;
						}
					}
				}
				if (piece == BLACK_HORSE)
				{
					if (x + 2 < 8 && y + 1 < 8)
					{
						obj1 = Grid[x + 2][y + 1];
						if (obj1 == EMPTY_SQUARE || obj1 == WHITE_PAWN || obj1 == WHITE_ROOK || obj1 == WHITE_HORSE || obj1 == WHITE_BISHOP || obj1 == WHITE_QUEEN)
						{
							Grid[x + 2][y + 1] = piece;
							Grid[x][y] = EMPTY_SQUARE;
							if (Player_In_Check(Grid, player) == false)
							{
								Grid[x + 2][y + 1] = obj1;
								Grid[x][y] = piece;
								return false;
							}
							Grid[x + 2][y + 1] = obj1;
							Grid[x][y] = piece;
						}
					}
					if (x + 2 < 8 && y - 1 >= 0)
					{
						obj1 = Grid[x + 2][y - 1];
						if (obj1 == EMPTY_SQUARE || obj1 == WHITE_PAWN || obj1 == WHITE_ROOK || obj1 == WHITE_HORSE || obj1 == WHITE_BISHOP || obj1 == WHITE_QUEEN)
						{
							Grid[x + 2][y - 1] = piece;
							Grid[x][y] = EMPTY_SQUARE;
							if (Player_In_Check(Grid, player) == false)
							{
								Grid[x + 2][y - 1] = obj1;
								Grid[x][y] = piece;
								return false;
							}
							Grid[x + 2][y - 1] = obj1;
							Grid[x][y] = piece;
						}
					}
					if (x - 2 >= 0 && y + 1 < 8)
					{
						obj1 = Grid[x - 2][y + 1];
						if (obj1 == EMPTY_SQUARE || obj1 == WHITE_PAWN || obj1 == WHITE_ROOK || obj1 == WHITE_HORSE || obj1 == WHITE_BISHOP || obj1 == WHITE_QUEEN)
						{
							Grid[x - 2][y + 1] = piece;
							Grid[x][y] = EMPTY_SQUARE;
							if (Player_In_Check(Grid, player) == false)
							{
								Grid[x - 2][y + 1] = obj1;
								Grid[x][y] = piece;
								return false;
							}
							Grid[x - 2][y + 1] = obj1;
							Grid[x][y] = piece;
						}
					}
					if (x - 2 >= 0 && y - 1 >= 0)
					{
						obj1 = Grid[x - 2][y - 1];
						if (obj1 == EMPTY_SQUARE || obj1 == WHITE_PAWN || obj1 == WHITE_ROOK || obj1 == WHITE_HORSE || obj1 == WHITE_BISHOP || obj1 == WHITE_QUEEN)
						{
							Grid[x - 2][y - 1] = piece;
							Grid[x][y] = EMPTY_SQUARE;
							if (Player_In_Check(Grid, player) == false)
							{
								Grid[x - 2][y - 1] = obj1;
								Grid[x][y] = piece;
								return false;
							}
							Grid[x - 2][y - 1] = obj1;
							Grid[x][y] = piece;
						}
					}
					if (x + 1 < 8 && y + 2 < 8)
					{
						obj1 = Grid[x + 1][y + 2];
						if (obj1 == EMPTY_SQUARE || obj1 == WHITE_PAWN || obj1 == WHITE_ROOK || obj1 == WHITE_HORSE || obj1 == WHITE_BISHOP || obj1 == WHITE_QUEEN)
						{
							Grid[x + 1][y + 2] = piece;
							Grid[x][y] = EMPTY_SQUARE;
							if (Player_In_Check(Grid, player) == false)
							{
								Grid[x + 1][y + 2] = obj1;
								Grid[x][y] = piece;
								return false;
							}
							Grid[x + 1][y + 2] = obj1;
							Grid[x][y] = piece;
						}
					}
					if (x + 1 < 8 && y - 2 >= 0)
					{
						obj1 = Grid[x + 1][y - 2];
						if (obj1 == EMPTY_SQUARE || obj1 == WHITE_PAWN || obj1 == WHITE_ROOK || obj1 == WHITE_HORSE || obj1 == WHITE_BISHOP || obj1 == WHITE_QUEEN)
						{
							Grid[x + 1][y - 2] = piece;
							Grid[x][y] = EMPTY_SQUARE;
							if (Player_In_Check(Grid, player) == false)
							{
								Grid[x + 1][y - 2] = obj1;
								Grid[x][y] = piece;
								return false;
							}
							Grid[x + 1][y - 2] = obj1;
							Grid[x][y] = piece;
						}
					}
					if (x - 1 >= 0 && y + 2 < 8)
					{
						obj1 = Grid[x - 1][y + 2];
						if (obj1 == EMPTY_SQUARE || obj1 == WHITE_PAWN || obj1 == WHITE_ROOK || obj1 == WHITE_HORSE || obj1 == WHITE_BISHOP || obj1 == WHITE_QUEEN)
						{
							Grid[x - 1][y + 2] = piece;
							Grid[x][y] = EMPTY_SQUARE;
							if (Player_In_Check(Grid, player) == false)
							{
								Grid[x - 1][y + 2] = obj1;
								Grid[x][y] = piece;
								return false;
							}
							Grid[x - 1][y + 2] = obj1;
							Grid[x][y] = piece;
						}
					}
					if (x - 1 >= 0 && y - 2 >= 0)
					{
						obj1 = Grid[x - 1][y - 2];
						if (obj1 == EMPTY_SQUARE || obj1 == WHITE_PAWN || obj1 == WHITE_ROOK || obj1 == WHITE_HORSE || obj1 == WHITE_BISHOP || obj1 == WHITE_QUEEN)
						{
							Grid[x - 1][y - 2] = piece;
							Grid[x][y] = EMPTY_SQUARE;
							if (Player_In_Check(Grid, player) == false)
							{
								Grid[x - 1][y - 2] = obj1;
								Grid[x][y] = piece;
								return false;
							}
							Grid[x - 1][y - 2] = obj1;
							Grid[x][y] = piece;
						}
					}
				}
				if (piece == BLACK_BISHOP || piece == BLACK_QUEEN || piece == BLACK_KING)
				{
					//Check one square diagonal distance if any of these is allowed stop looking
					if (x + 1 < 8 && y + 1 < 8)
					{
						obj1 = Grid[x + 1][y + 1];
						if (obj1 == EMPTY_SQUARE || obj1 == WHITE_PAWN || obj1 == WHITE_ROOK || obj1 == WHITE_HORSE || obj1 == WHITE_BISHOP || obj1 == WHITE_QUEEN)
						{
							Grid[x + 1][y + 1] = piece;
							Grid[x][y] = EMPTY_SQUARE;
							if (Player_In_Check(Grid, player) == false)
							{
								Grid[x + 1][y + 1] = obj1;
								Grid[x][y] = piece;
								return false;
							}
							Grid[x + 1][y + 1] = obj1;
							Grid[x][y] = piece;
						}
					}
					if (x + 1 < 8 && y - 1 >= 0)
					{
						obj1 = Grid[x + 1][y - 1];
						if (obj1 == EMPTY_SQUARE || obj1 == WHITE_PAWN || obj1 == WHITE_ROOK || obj1 == WHITE_HORSE || obj1 == WHITE_BISHOP || obj1 == WHITE_QUEEN)
						{
							Grid[x + 1][y - 1] = piece;
							Grid[x][y] = EMPTY_SQUARE;
							if (Player_In_Check(Grid, player) == false)
							{
								Grid[x + 1][y - 1] = obj1;
								Grid[x][y] = piece;
								return false;
							}
							Grid[x + 1][y - 1] = obj1;
							Grid[x][y] = piece;
						}
					}
					if (x - 1 >= 0 && y + 1 < 8)
					{
						obj1 = Grid[x - 1][y + 1];
						if (obj1 == EMPTY_SQUARE || obj1 == WHITE_PAWN || obj1 == WHITE_ROOK || obj1 == WHITE_HORSE || obj1 == WHITE_BISHOP || obj1 == WHITE_QUEEN)
						{
							Grid[x - 1][y + 1] = piece;
							Grid[x][y] = EMPTY_SQUARE;
							if (Player_In_Check(Grid, player) == false)
							{
								Grid[x - 1][y + 1] = obj1;
								Grid[x][y] = piece;
								return false;
							}
							Grid[x - 1][y + 1] = obj1;
							Grid[x][y] = piece;
						}
					}
					if (x - 1 >= 0 && y - 1 >= 0)
					{
						obj1 = Grid[x - 1][y - 1];
						if (obj1 == EMPTY_SQUARE || obj1 == WHITE_PAWN || obj1 == WHITE_ROOK || obj1 == WHITE_HORSE || obj1 == WHITE_BISHOP || obj1 == WHITE_QUEEN)
						{
							Grid[x - 1][y - 1] = piece;
							Grid[x][y] = EMPTY_SQUARE;
							if (Player_In_Check(Grid, player) == false)
							{
								Grid[x - 1][y - 1] = obj1;
								Grid[x][y] = piece;
								return false;
							}
							Grid[x - 1][y - 1] = obj1;
							Grid[x][y] = piece;
						}
					}
				}
				if (piece == BLACK_ROOK || piece == BLACK_QUEEN || piece == BLACK_KING)
				{
					//Check one square distance both vertically and horizontally if the move is allowed stop looking
					if (y + 1 < 8)
					{
						obj1 = Grid[x][y + 1];
						if (obj1 == EMPTY_SQUARE || obj1 == WHITE_PAWN || obj1 == WHITE_ROOK || obj1 == WHITE_HORSE || obj1 == WHITE_BISHOP || obj1 == WHITE_QUEEN)
						{
							Grid[x][y] = EMPTY_SQUARE;
							Grid[x][y + 1] = piece;
							if (Player_In_Check(Grid, player) == false)
							{
								Grid[x][y] = piece;
								Grid[x][y + 1] = obj1;
								return false;
							}
							Grid[x][y] = piece;
							Grid[x][y + 1] = obj1;
						}
					}
					if (y - 1 >= 0)
					{
						obj1 = Grid[x][y - 1];
						if (obj1 == EMPTY_SQUARE || obj1 == WHITE_PAWN || obj1 == WHITE_ROOK || obj1 == WHITE_HORSE || obj1 == WHITE_BISHOP || obj1 == WHITE_QUEEN)
						{
							Grid[x][y] = EMPTY_SQUARE;
							Grid[x][y - 1] = piece;
							if (Player_In_Check(Grid, player) == false)
							{
								Grid[x][y] = piece;
								Grid[x][y - 1] = obj1;
								return false;
							}
							Grid[x][y] = piece;
							Grid[x][y - 1] = obj1;
						}
					}
					if (x + 1 < 8)
					{
						obj1 = Grid[x + 1][y];
						if (obj1 == EMPTY_SQUARE || obj1 == WHITE_PAWN || obj1 == WHITE_ROOK || obj1 == WHITE_HORSE || obj1 == WHITE_BISHOP || obj1 == WHITE_QUEEN)
						{
							Grid[x][y] = EMPTY_SQUARE;
							Grid[x + 1][y] = piece;
							if (Player_In_Check(Grid, player) == false)
							{
								Grid[x][y] = piece;
								Grid[x + 1][y] = obj1;
								return false;
							}
							Grid[x][y] = piece;
							Grid[x + 1][y] = obj1;
						}
					}
					if (x - 1 >= 0)
					{
						obj1 = Grid[x - 1][y];
						if (obj1 == EMPTY_SQUARE || obj1 == WHITE_PAWN || obj1 == WHITE_ROOK || obj1 == WHITE_HORSE || obj1 == WHITE_BISHOP || obj1 == WHITE_QUEEN)
						{
							Grid[x][y] = EMPTY_SQUARE;
							Grid[x - 1][y] = piece;
							if (Player_In_Check(Grid, player) == false)
							{
								Grid[x][y] = piece;
								Grid[x - 1][y] = obj1;
								return false;
							}
							Grid[x][y] = piece;
							Grid[x - 1][y] = obj1;
						}
					}
				}
			}
		}
	}
	return true;
}
bool Check_Win(char Grid[][8], char player)
{
	if (Player_In_Check(Grid, player) == true)
	{
		if (player == BLACK_PLAYER) std::cout << "White player (UPERCASE/ALL CAPS) is in CHECK! " << std::endl;
		else std::cout << "Black player (LOWER CASE) is in CHECK! " << std::endl;

		//Anlaisis Checkmate
		//look all king moves and all the other pieces moves to see if they can cover the check
		int x, y, s, t;
		char pos, prev;
		if (player == WHITE_PLAYER)
		{
			//First locate the king
			for (x = 0; x < 8; x++)
				for (y = 0; y < 8; y++)
					if (Grid[x][y] == BLACK_KING)
						goto found;
		found:
			//Check King moves
			if (x + 1 < 8)
			{
				pos = Grid[x + 1][y];
				if (pos != BLACK_BISHOP && pos != BLACK_HORSE && pos != BLACK_ROOK && pos != BLACK_QUEEN && pos != BLACK_PAWN)
				{
					Grid[x + 1][y] = BLACK_KING;
					Grid[x][y] = EMPTY_SQUARE;
					if (Player_In_Check(Grid, player) == false)
					{
						Grid[x + 1][y] = pos;
						Grid[x][y] = BLACK_KING;
						return false;
					}
					Grid[x + 1][y] = pos;
					Grid[x][y] = BLACK_KING;
				}
			}
			if (x + 1 < 8 && y - 1 >= 0)
			{
				pos = Grid[x + 1][y - 1];
				if (pos != BLACK_BISHOP && pos != BLACK_HORSE && pos != BLACK_ROOK && pos != BLACK_QUEEN && pos != BLACK_PAWN)
				{
					Grid[x + 1][y - 1] = BLACK_KING;
					Grid[x][y] = EMPTY_SQUARE;
					if (Player_In_Check(Grid, player) == false)
					{
						Grid[x + 1][y - 1] = pos;
						Grid[x][y] = BLACK_KING;
						return false;
					}
					Grid[x + 1][y - 1] = pos;
					Grid[x][y] = BLACK_KING;
				}
			}
			if (x + 1 < 8 && y + 1 < 8)
			{
				pos = Grid[x + 1][y + 1];
				if (pos != BLACK_BISHOP && pos != BLACK_HORSE && pos != BLACK_ROOK && pos != BLACK_QUEEN && pos != BLACK_PAWN)
				{
					Grid[x + 1][y + 1] = BLACK_KING;
					Grid[x][y] = EMPTY_SQUARE;
					if (Player_In_Check(Grid, player) == false)
					{
						Grid[x + 1][y + 1] = pos;
						Grid[x][y] = BLACK_KING;
						return false;
					}
					Grid[x + 1][y + 1] = pos;
					Grid[x][y] = BLACK_KING;
				}
			}
			if (y + 1 < 8)
			{
				pos = Grid[x][y + 1];
				if (pos != BLACK_BISHOP && pos != BLACK_HORSE && pos != BLACK_ROOK && pos != BLACK_QUEEN && pos != BLACK_PAWN)
				{
					Grid[x][y + 1] = BLACK_KING;
					Grid[x][y] = EMPTY_SQUARE;
					if (Player_In_Check(Grid, player) == false)
					{
						Grid[x][y + 1] = pos;
						Grid[x][y] = BLACK_KING;
						return false;
					}
					Grid[x][y + 1] = pos;
					Grid[x][y] = BLACK_KING;
				}
			}
			if (y - 1 >= 0)
			{
				pos = Grid[x][y - 1];
				if (pos != BLACK_BISHOP && pos != BLACK_HORSE && pos != BLACK_ROOK && pos != BLACK_QUEEN && pos != BLACK_PAWN)
				{
					Grid[x][y - 1] = BLACK_KING;
					Grid[x][y] = EMPTY_SQUARE;
					if (Player_In_Check(Grid, player) == false)
					{
						Grid[x][y - 1] = pos;
						Grid[x][y] = BLACK_KING;
						return false;
					}
					Grid[x][y - 1] = pos;
					Grid[x][y] = BLACK_KING;
				}
			}
			if (x - 1 >= 0)
			{
				pos = Grid[x - 1][y];
				if (pos != BLACK_BISHOP && pos != BLACK_HORSE && pos != BLACK_ROOK && pos != BLACK_QUEEN && pos != BLACK_PAWN)
				{
					Grid[x - 1][y] = BLACK_KING;
					Grid[x][y] = EMPTY_SQUARE;
					if (Player_In_Check(Grid, player) == false)
					{
						Grid[x - 1][y] = pos;
						Grid[x][y] = BLACK_KING;
						return false;
					}
					Grid[x - 1][y] = pos;
					Grid[x][y] = BLACK_KING;
				}
			}
			if (x - 1 >= 0 && y - 1 >= 0)
			{
				pos = Grid[x - 1][y - 1];
				if (pos != BLACK_BISHOP && pos != BLACK_HORSE && pos != BLACK_ROOK && pos != BLACK_QUEEN && pos != BLACK_PAWN)
				{
					Grid[x - 1][y - 1] = BLACK_KING;
					Grid[x][y] = EMPTY_SQUARE;
					if (Player_In_Check(Grid, player) == false)
					{
						Grid[x - 1][y - 1] = pos;
						Grid[x][y] = BLACK_KING;
						return false;
					}
					Grid[x - 1][y - 1] = pos;
					Grid[x][y] = BLACK_KING;
				}
			}
			if (x - 1 >= 0 && y + 1 < 8)
			{
				pos = Grid[x - 1][y + 1];
				if (pos != BLACK_BISHOP && pos != BLACK_HORSE && pos != BLACK_ROOK && pos != BLACK_QUEEN && pos != BLACK_PAWN)
				{
					Grid[x - 1][y + 1] = BLACK_KING;
					Grid[x][y] = EMPTY_SQUARE;
					if (Player_In_Check(Grid, player) == false)
					{
						Grid[x - 1][y + 1] = pos;
						Grid[x][y] = BLACK_KING;
						return false;
					}
					Grid[x - 1][y + 1] = pos;
					Grid[x][y] = BLACK_KING;
				}
			}
			//Check the movement of the other pieces
			for (int j = 0; j < 8; j++)
			{
				for (int q = 0; q < 8; q++)
				{
					if (Grid[j][q] != EMPTY_SQUARE)
					{
						if (Grid[j][q] == BLACK_PAWN)
						{
							//Forward Pawn Move (haven t checked if double starting move works)
							if (j + 1 < 8 && Grid[j + 1][q] == EMPTY_SQUARE)
							{
								Grid[j + 1][q] = BLACK_PAWN;
								Grid[j][q] = EMPTY_SQUARE;
								if (Player_In_Check(Grid, player) == false)
								{
									Grid[j + 1][q] = EMPTY_SQUARE;
									Grid[j][q] = BLACK_PAWN;
									return false;
								}
								Grid[j + 1][q] = EMPTY_SQUARE;
								Grid[j][q] = BLACK_PAWN;
							}
							//Capture left
							if (j + 1 < 8 && q - 1 >= 0)
							{
								pos = Grid[j + 1][q - 1];
								if (pos == WHITE_BISHOP || pos == WHITE_HORSE || pos == WHITE_QUEEN || pos == WHITE_PAWN)
								{
									Grid[j + 1][q - 1] = BLACK_PAWN;
									Grid[j][q] = EMPTY_SQUARE;
									if (Player_In_Check(Grid, player) == false)
									{
										Grid[j + 1][q - 1] = pos;
										Grid[j][q] = BLACK_PAWN;
										return false;
									}
									Grid[j + 1][q - 1] = pos;
									Grid[j][q] = BLACK_PAWN;
								}
							}
							//Capture right
							if (j + 1 < 8 && q + 1 < 8)
							{
								pos = Grid[j + 1][q + 1];
								if (pos == WHITE_BISHOP || pos == WHITE_HORSE || pos == WHITE_QUEEN || pos == WHITE_PAWN)
								{
									Grid[j + 1][q + 1] = BLACK_PAWN;
									Grid[j][q] = EMPTY_SQUARE;
									if (Player_In_Check(Grid, player) == false)
									{
										Grid[j + 1][q + 1] = pos;
										Grid[j][q] = BLACK_PAWN;
										return false;
									}
									Grid[j + 1][q + 1] = pos;
									Grid[j][q] = BLACK_PAWN;
								}
							}

						}
						else if (Grid[j][q] == BLACK_HORSE)
						{
							if (j + 2 < 8 && q + 1 < 8)
							{
								pos = Grid[j + 2][q + 1];
								if (pos != BLACK_BISHOP && pos != BLACK_HORSE && pos != BLACK_ROOK && pos != BLACK_QUEEN && pos != BLACK_PAWN && pos != BLACK_KING)
								{
									Grid[j + 2][q + 1] = BLACK_HORSE;
									Grid[j][q] = EMPTY_SQUARE;
									if (Player_In_Check(Grid, player) == false)
									{
										Grid[j + 2][q + 1] = pos;
										Grid[j][q] = BLACK_HORSE;
										return false;
									}
									Grid[j + 2][q + 1] = pos;
									Grid[j][q] = BLACK_HORSE;
								}
							}
							if (j + 2 < 8 && q - 1 >= 0)
							{
								pos = Grid[j + 2][q - 1];
								if (pos != BLACK_BISHOP && pos != BLACK_HORSE && pos != BLACK_ROOK && pos != BLACK_QUEEN && pos != BLACK_PAWN && pos != BLACK_KING)
								{
									Grid[j + 2][q - 1] = BLACK_HORSE;
									Grid[j][q] = EMPTY_SQUARE;
									if (Player_In_Check(Grid, player) == false)
									{
										Grid[j + 2][q - 1] = pos;
										Grid[j][q] = BLACK_PAWN;
										return false;
									}
									Grid[j + 2][q - 1] = pos;
									Grid[j][q] = BLACK_PAWN;
								}
							}
							if (j - 2 >= 0 && q + 1 < 8)
							{
								pos = Grid[j - 2][q + 1];
								if (pos != BLACK_BISHOP && pos != BLACK_HORSE && pos != BLACK_ROOK && pos != BLACK_QUEEN && pos != BLACK_PAWN && pos != BLACK_KING)
								{
									Grid[j - 2][q + 1] = BLACK_HORSE;
									Grid[j][q] = EMPTY_SQUARE;
									if (Player_In_Check(Grid, player) == false)
									{
										Grid[j - 2][q + 1] = pos;
										Grid[j][q] = BLACK_HORSE;
										return false;
									}
									Grid[j - 2][q + 1] = pos;
									Grid[j][q] = BLACK_HORSE;
								}
							}
							if (j - 2 >= 0 && q - 1 >= 0)
							{
								pos = Grid[j - 2][q - 1];
								if (pos != BLACK_BISHOP && pos != BLACK_HORSE && pos != BLACK_ROOK && pos != BLACK_QUEEN && pos != BLACK_PAWN && pos != BLACK_KING)
								{
									Grid[j - 2][q - 1] = BLACK_HORSE;
									Grid[j][q] = EMPTY_SQUARE;
									if (Player_In_Check(Grid, player) == false)
									{
										Grid[j - 2][q - 1] = pos;
										Grid[j][q] = BLACK_HORSE;
										return false;
									}
									Grid[j - 2][q - 1] = pos;
									Grid[j][q] = BLACK_HORSE;
								}
							}
							if (j + 1 < 8 && q + 2 < 8)
							{
								pos = Grid[j + 1][q + 2];
								if (pos != BLACK_BISHOP && pos != BLACK_HORSE && pos != BLACK_ROOK && pos != BLACK_QUEEN && pos != BLACK_PAWN && pos != BLACK_KING)
								{
									Grid[j + 1][q + 2] = BLACK_HORSE;
									Grid[j][q] = EMPTY_SQUARE;
									if (Player_In_Check(Grid, player) == false)
									{
										Grid[j + 1][q + 2] = pos;
										Grid[j][q] = BLACK_HORSE;
										return false;
									}
									Grid[j + 1][q + 2] = pos;
									Grid[j][q] = BLACK_HORSE;
								}
							}
							if (j + 1 < 8 && q - 2 >= 0)
							{
								pos = Grid[j + 1][q - 2];
								if (pos != BLACK_BISHOP && pos != BLACK_HORSE && pos != BLACK_ROOK && pos != BLACK_QUEEN && pos != BLACK_PAWN && pos != BLACK_KING)
								{
									Grid[j + 1][q - 2] = BLACK_HORSE;
									Grid[j][q] = EMPTY_SQUARE;
									if (Player_In_Check(Grid, player) == false)
									{
										Grid[j + 1][q - 2] = pos;
										Grid[j][q] = BLACK_HORSE;
										return false;
									}
									Grid[j + 1][q - 2] = pos;
									Grid[j][q] = BLACK_HORSE;
								}
							}
							if (j - 1 >= 0 && q + 2 < 8)
							{
								pos = Grid[j - 1][q + 2];
								if (pos != BLACK_BISHOP && pos != BLACK_HORSE && pos != BLACK_ROOK && pos != BLACK_QUEEN && pos != BLACK_PAWN && pos != BLACK_KING)
								{
									Grid[j - 1][q + 2] = BLACK_HORSE;
									Grid[j][q] = EMPTY_SQUARE;
									if (Player_In_Check(Grid, player) == false)
									{
										Grid[j - 1][q + 2] = pos;
										Grid[j][q] = BLACK_HORSE;
										return false;
									}
									Grid[j - 1][q + 2] = pos;
									Grid[j][q] = BLACK_HORSE;
								}
							}
							if (j - 1 >= 0 && q - 2 >= 0)
							{
								pos = Grid[j - 1][q - 2];
								if (pos != BLACK_BISHOP && pos != BLACK_HORSE && pos != BLACK_ROOK && pos != BLACK_QUEEN && pos != BLACK_PAWN && pos != BLACK_KING)
								{
									Grid[j - 1][q - 2] = BLACK_HORSE;
									Grid[j][q] = EMPTY_SQUARE;
									if (Player_In_Check(Grid, player) == false)
									{
										Grid[j - 1][q - 2] = pos;
										Grid[j][q] = BLACK_HORSE;
										return false;
									}
									Grid[j - 1][q - 2] = pos;
									Grid[j][q] = BLACK_HORSE;
								}
							}
						}
						else if (Grid[j][q] == BLACK_BISHOP || Grid[j][q] == BLACK_QUEEN)
						{
							//Look on all directions
							//Search TOP Left x-- y--
							s = q - 1;
							t = j - 1;
							if (t >= 0 && s >= 0)
							{
								while (t >= 0 && s >= 0)
								{
									pos = Grid[t][s];
									prev = Grid[j][q];
									if (pos != EMPTY_SQUARE && ((abs(t - x) != abs(s - y)) && x != t && y != s))
										break;
									else if ((pos == EMPTY_SQUARE || pos == WHITE_BISHOP || pos == WHITE_HORSE || pos == WHITE_QUEEN || pos == WHITE_PAWN) && ((abs(t - x) == abs(s - y)) || x == t || y == s))
									{
										Grid[t][s] = Grid[j][q];
										Grid[j][q] = EMPTY_SQUARE;
										if (Player_In_Check(Grid, player) == false)
										{
											Grid[t][s] = pos;
											Grid[j][q] = prev;
											return false;
										}
										Grid[t][s] = pos;
										Grid[j][q] = prev;
									}
									s--;
									t--;
								}
							}
							//Search BOTTOM Right x++ y++
							s = q + 1;
							t = j + 1;
							if (t < 8 && s < 8)
							{
								while (t < 8 && s < 8)
								{
									pos = Grid[t][s];
									prev = Grid[j][q];
									if (pos != EMPTY_SQUARE && ((abs(t - x) != abs(s - y)) || x == t || y == s))
										break;
									else if ((pos == EMPTY_SQUARE || pos == WHITE_BISHOP || pos == WHITE_HORSE || pos == WHITE_QUEEN || pos == WHITE_PAWN) && ((abs(t - x) == abs(s - y)) || x == t || y == s))
									{
										Grid[t][s] = Grid[j][q];
										Grid[j][q] = EMPTY_SQUARE;
										if (Player_In_Check(Grid, player) == false)
										{
											Grid[t][s] = pos;
											Grid[j][q] = prev;
											return false;
										}
										Grid[t][s] = pos;
										Grid[j][q] = prev;
									}
									else break;
									s++;
									t++;
								}
							}
							//Search BOTTOM Left x++ y--
							s = q - 1;
							t = j + 1;
							if (s >= 0 && t < 8)
							{
								while (s >= 0 && t < 8)
								{
									pos = Grid[t][s];
									prev = Grid[j][q];
									if (pos != EMPTY_SQUARE && ((abs(t - x) != abs(s - y)) || x == t || y == s))
										break;
									else if ((pos == EMPTY_SQUARE || pos == WHITE_BISHOP || pos == WHITE_HORSE || pos == WHITE_QUEEN || pos == WHITE_PAWN) && ((abs(t - x) == abs(s - y)) || x == t || y == s))
									{
										Grid[t][s] = Grid[j][q];
										Grid[j][q] = EMPTY_SQUARE;
										if (Player_In_Check(Grid, player) == false)
										{
											Grid[t][s] = pos;
											Grid[j][q] = prev;
											return false;
										}
										Grid[t][s] = pos;
										Grid[j][q] = prev;
									}
									else break;
									s--;
									t++;
								}
							}
							//Search top Right x-- y++
							s = q + 1;
							t = j - 1;
							if (s < 8 && t >= 0)
							{
								while (s < 8 && t >= 0)
								{
									pos = Grid[t][s];
									prev = Grid[j][q];
									if (pos != EMPTY_SQUARE && ((abs(t - x) != abs(s - y)) || x == t || y == s))
										break;
									else if ((pos == EMPTY_SQUARE || pos == WHITE_BISHOP || pos == WHITE_HORSE || pos == WHITE_QUEEN || pos == WHITE_PAWN) && ((abs(t - x) == abs(s - y)) || x == t || y == s))
									{
										Grid[t][s] = Grid[j][q];
										Grid[j][q] = EMPTY_SQUARE;
										if (Player_In_Check(Grid, player) == false)
										{
											Grid[t][s] = pos;
											Grid[j][q] = prev;
											return false;
										}
										Grid[t][s] = pos;
										Grid[j][q] = prev;
									}
									else break;
									s++;
									t--;
								}
							}
						}
						if (Grid[j][q] == BLACK_ROOK || Grid[j][q] == BLACK_QUEEN)
						{
							//Look Right
							for (int t = q + 1; t < 8; t++)
							{
								pos = Grid[j][t];
								prev = Grid[j][q];
								if (pos != EMPTY_SQUARE && ((abs(j - x) != abs(t - y)) || x == j || y == t))
									break;
								else if ((pos == EMPTY_SQUARE || pos == WHITE_BISHOP || pos == WHITE_HORSE || pos == WHITE_QUEEN || pos == WHITE_PAWN) && ((abs(j - x) != abs(t - y)) || x == j || y == t))
								{
									Grid[j][t] = Grid[j][q];
									Grid[j][q] = EMPTY_SQUARE;
									if (Player_In_Check(Grid, player) == false)
									{
										Grid[j][t] = pos;
										Grid[j][q] = prev;
										return false;
									}
									Grid[j][t] = pos;
									Grid[j][q] = prev;
								}
								else break;
							}
							//Look Left
							for (int t = q - 1; t >= 0; t--)
							{
								pos = Grid[j][t];
								prev = Grid[j][q];
								if (pos != EMPTY_SQUARE && ((abs(j - x) != abs(t - y)) || x == j || y == t))
									break;
								else if ((pos == EMPTY_SQUARE || pos == WHITE_BISHOP || pos == WHITE_HORSE || pos == WHITE_QUEEN || pos == WHITE_PAWN) && ((abs(j - x) != abs(t - y)) || x == j || y == t))
								{
									Grid[j][t] = Grid[j][q];
									Grid[j][q] = EMPTY_SQUARE;
									if (Player_In_Check(Grid, player) == false)
									{
										Grid[j][t] = pos;
										Grid[j][q] = prev;
										return false;
									}
									Grid[j][t] = pos;
									Grid[j][q] = prev;
								}
								else break;
							}
							//Look Up
							for (int t = j + 1; t < 8; t++)
							{
								pos = Grid[t][q];
								prev = Grid[j][q];
								if (pos != EMPTY_SQUARE && ((abs(j - x) != abs(t - y)) || x == t || y == q))
									break;
								else if ((pos == EMPTY_SQUARE || pos == WHITE_BISHOP || pos == WHITE_HORSE || pos == WHITE_QUEEN || pos == WHITE_PAWN) && ((abs(j - x) != abs(t - y)) || x == t || y == q))
								{
									Grid[t][q] = Grid[j][q];
									Grid[j][q] = EMPTY_SQUARE;
									if (Player_In_Check(Grid, player) == false)
									{
										Grid[t][q] = pos;
										Grid[j][q] = prev;
										return false;
									}
									Grid[t][q] = pos;
									Grid[j][q] = prev;
								}
								else break;
							}
							//Look Down
							for (int t = j - 1; t >= 0; t--)
							{
								pos = Grid[t][q];
								prev = Grid[j][q];
								if (pos != EMPTY_SQUARE && ((abs(j - x) != abs(t - y)) || x == t || y == q))
									break;
								else if ((pos == EMPTY_SQUARE || pos == WHITE_BISHOP || pos == WHITE_HORSE || pos == WHITE_QUEEN || pos == WHITE_PAWN) && ((abs(j - x) != abs(t - y)) || x == t || y == q))
								{
									Grid[t][q] = Grid[j][q];
									Grid[j][q] = EMPTY_SQUARE;
									if (Player_In_Check(Grid, player) == false)
									{
										Grid[t][q] = pos;
										Grid[j][q] = prev;
										return false;
									}
									Grid[t][q] = pos;
									Grid[j][q] = prev;
								}
								else break;
							}
						}
					}
				}
			}
		}
		else if (player == BLACK_PLAYER)
		{
			for (x = 7; x >= 0; x--)
				for (y = 0; y < 8; y++)
					if (Grid[x][y] == WHITE_KING)
						goto found2;
		found2:
			//Check King moves
			if (x + 1 < 8)
			{
				pos = Grid[x + 1][y];
				if (pos != WHITE_BISHOP && pos != WHITE_HORSE && pos != WHITE_ROOK && pos != WHITE_QUEEN && pos != WHITE_PAWN)
				{
					Grid[x + 1][y] = WHITE_KING;
					Grid[x][y] = EMPTY_SQUARE;
					if (Player_In_Check(Grid, player) == false)
					{
						Grid[x + 1][y] = pos;
						Grid[x][y] = WHITE_KING;
						return false;
					}
					Grid[x + 1][y] = pos;
					Grid[x][y] = WHITE_KING;
				}
			}
			if (x + 1 < 8 && y - 1 >= 0)
			{
				pos = Grid[x + 1][y - 1];
				if (pos != WHITE_BISHOP && pos != WHITE_HORSE && pos != WHITE_ROOK && pos != WHITE_QUEEN && pos != WHITE_PAWN)
				{
					Grid[x + 1][y - 1] = WHITE_KING;
					Grid[x][y] = EMPTY_SQUARE;
					if (Player_In_Check(Grid, player) == false)
					{
						Grid[x + 1][y - 1] = pos;
						Grid[x][y] = WHITE_KING;
						return false;
					}
					Grid[x + 1][y - 1] = pos;
					Grid[x][y] = WHITE_KING;
				}
			}
			if (x + 1 < 8 && y + 1 < 8)
			{
				pos = Grid[x + 1][y + 1];
				if (pos != WHITE_BISHOP && pos != WHITE_HORSE && pos != WHITE_ROOK && pos != WHITE_QUEEN && pos != WHITE_PAWN)
				{
					Grid[x + 1][y + 1] = WHITE_KING;
					Grid[x][y] = EMPTY_SQUARE;
					if (Player_In_Check(Grid, player) == false)
					{
						Grid[x + 1][y + 1] = pos;
						Grid[x][y] = WHITE_KING;
						return false;
					}
					Grid[x + 1][y + 1] = pos;
					Grid[x][y] = WHITE_KING;
				}
			}
			if (y + 1 < 8)
			{
				pos = Grid[x][y + 1];
				if (pos != WHITE_BISHOP && pos != WHITE_HORSE && pos != WHITE_ROOK && pos != WHITE_QUEEN && pos != WHITE_PAWN)
				{
					Grid[x][y + 1] = WHITE_KING;
					Grid[x][y] = EMPTY_SQUARE;
					if (Player_In_Check(Grid, player) == false)
					{
						Grid[x][y + 1] = pos;
						Grid[x][y] = WHITE_KING;
						return false;
					}
					Grid[x][y + 1] = pos;
					Grid[x][y] = WHITE_KING;
				}
			}
			if (y - 1 >= 0)
			{
				pos = Grid[x][y - 1];
				if (pos != WHITE_BISHOP && pos != WHITE_HORSE && pos != WHITE_ROOK && pos != WHITE_QUEEN && pos != WHITE_PAWN)
				{
					Grid[x][y - 1] = WHITE_KING;
					Grid[x][y] = EMPTY_SQUARE;
					if (Player_In_Check(Grid, player) == false)
					{
						Grid[x][y - 1] = pos;
						Grid[x][y] = WHITE_KING;
						return false;
					}
					Grid[x][y - 1] = pos;
					Grid[x][y] = WHITE_KING;
				}
			}
			if (x - 1 >= 0)
			{
				pos = Grid[x - 1][y];
				if (pos != WHITE_BISHOP && pos != WHITE_HORSE && pos != WHITE_ROOK && pos != WHITE_QUEEN && pos != WHITE_PAWN)
				{
					Grid[x - 1][y] = WHITE_KING;
					Grid[x][y] = EMPTY_SQUARE;
					if (Player_In_Check(Grid, player) == false)
					{
						Grid[x - 1][y] = pos;
						Grid[x][y] = WHITE_KING;
						return false;
					}
					Grid[x - 1][y] = pos;
					Grid[x][y] = WHITE_KING;
				}
			}
			if (x - 1 >= 0 && y - 1 >= 0)
			{
				pos = Grid[x - 1][y - 1];
				if (pos != WHITE_BISHOP && pos != WHITE_HORSE && pos != WHITE_ROOK && pos != WHITE_QUEEN && pos != WHITE_PAWN)
				{
					Grid[x - 1][y - 1] = WHITE_KING;
					Grid[x][y] = EMPTY_SQUARE;
					if (Player_In_Check(Grid, player) == false)
					{
						Grid[x - 1][y - 1] = pos;
						Grid[x][y] = WHITE_KING;
						return false;
					}
					Grid[x - 1][y - 1] = pos;
					Grid[x][y] = WHITE_KING;
				}
			}
			if (x - 1 >= 0 && y + 1 < 8)
			{
				pos = Grid[x - 1][y + 1];
				if (pos != WHITE_BISHOP && pos != WHITE_HORSE && pos != WHITE_ROOK && pos != WHITE_QUEEN && pos != WHITE_PAWN)
				{
					Grid[x - 1][y + 1] = WHITE_KING;
					Grid[x][y] = EMPTY_SQUARE;
					if (Player_In_Check(Grid, player) == false)
					{
						Grid[x - 1][y + 1] = pos;
						Grid[x][y] = WHITE_KING;
						return false;
					}
					Grid[x - 1][y + 1] = pos;
					Grid[x][y] = WHITE_KING;
				}
			}
			//Check the movement of the other pieces
			for (int j = 0; j < 8; j++)
			{
				for (int q = 0; q < 8; q++)
				{
					if (Grid[j][q] != EMPTY_SQUARE)
					{
						if (Grid[j][q] == WHITE_PAWN)
						{
							//Forward Pawn Move (haven t checked if double starting move works)
							if (j + 1 < 8 && Grid[j + 1][q] == EMPTY_SQUARE)
							{
								Grid[j + 1][q] = WHITE_PAWN;
								Grid[j][q] = EMPTY_SQUARE;
								if (Player_In_Check(Grid, player) == false)
								{
									Grid[j + 1][q] = EMPTY_SQUARE;
									Grid[j][q] = WHITE_PAWN;
									return false;
								}
								Grid[j + 1][q] = EMPTY_SQUARE;
								Grid[j][q] = WHITE_PAWN;
							}
							//Capture left
							if (j + 1 < 8 && q - 1 >= 0)
							{
								pos = Grid[j + 1][q - 1];
								if (pos == BLACK_BISHOP || pos == BLACK_HORSE || pos == BLACK_QUEEN || pos == BLACK_PAWN)
								{
									Grid[j + 1][q - 1] = WHITE_PAWN;
									Grid[j][q] = EMPTY_SQUARE;
									if (Player_In_Check(Grid, player) == false)
									{
										Grid[j + 1][q - 1] = pos;
										Grid[j][q] = WHITE_PAWN;
										return false;
									}
									Grid[j + 1][q - 1] = pos;
									Grid[j][q] = WHITE_PAWN;
								}
							}
							//Capture right
							if (j + 1 < 8 && q + 1 < 8)
							{
								pos = Grid[j + 1][q + 1];
								if (pos == BLACK_BISHOP || pos == BLACK_HORSE || pos == BLACK_QUEEN || pos == BLACK_PAWN)
								{
									Grid[j + 1][q + 1] = WHITE_PAWN;
									Grid[j][q] = EMPTY_SQUARE;
									if (Player_In_Check(Grid, player) == false)
									{
										Grid[j + 1][q + 1] = pos;
										Grid[j][q] = WHITE_PAWN;
										return false;
									}
									Grid[j + 1][q + 1] = pos;
									Grid[j][q] = WHITE_PAWN;
								}
							}
						}
						else if (Grid[j][q] == WHITE_HORSE)
						{
							if (j + 2 < 8 && q + 1 < 8)
							{
								pos = Grid[j + 2][q + 1];
								if (pos != WHITE_BISHOP && pos != WHITE_HORSE && pos != WHITE_ROOK && pos != WHITE_QUEEN && pos != WHITE_PAWN && pos != WHITE_KING)
								{
									Grid[j + 2][q + 1] = WHITE_HORSE;
									Grid[j][q] = EMPTY_SQUARE;
									if (Player_In_Check(Grid, player) == false)
									{
										Grid[j + 2][q + 1] = pos;
										Grid[j][q] = WHITE_HORSE;
										return false;
									}
									Grid[j + 2][q + 1] = pos;
									Grid[j][q] = WHITE_HORSE;
								}
							}
							if (j + 2 < 8 && q - 1 >= 0)
							{
								pos = Grid[j + 2][q - 1];
								if (pos != WHITE_BISHOP && pos != WHITE_HORSE && pos != WHITE_ROOK && pos != WHITE_QUEEN && pos != WHITE_PAWN && pos != WHITE_KING)
								{
									Grid[j + 2][q - 1] = WHITE_HORSE;
									Grid[j][q] = EMPTY_SQUARE;
									if (Player_In_Check(Grid, player) == false)
									{
										Grid[j + 2][q - 1] = pos;
										Grid[j][q] = WHITE_PAWN;
										return false;
									}
									Grid[j + 2][q - 1] = pos;
									Grid[j][q] = WHITE_PAWN;
								}
							}
							if (j - 2 >= 0 && q + 1 < 8)
							{
								pos = Grid[j - 2][q + 1];
								if (pos != WHITE_BISHOP && pos != WHITE_HORSE && pos != WHITE_ROOK && pos != WHITE_QUEEN && pos != WHITE_PAWN && pos != WHITE_KING)
								{
									Grid[j - 2][q + 1] = WHITE_HORSE;
									Grid[j][q] = EMPTY_SQUARE;
									if (Player_In_Check(Grid, player) == false)
									{
										Grid[j - 2][q + 1] = pos;
										Grid[j][q] = WHITE_HORSE;
										return false;
									}
									Grid[j - 2][q + 1] = pos;
									Grid[j][q] = WHITE_HORSE;
								}
							}
							if (j - 2 >= 0 && q - 1 >= 0)
							{
								pos = Grid[j - 2][q - 1];
								if (pos != WHITE_BISHOP && pos != WHITE_HORSE && pos != WHITE_ROOK && pos != WHITE_QUEEN && pos != WHITE_PAWN && pos != WHITE_KING)
								{
									Grid[j - 2][q - 1] = WHITE_HORSE;
									Grid[j][q] = EMPTY_SQUARE;
									if (Player_In_Check(Grid, player) == false)
									{
										Grid[j - 2][q - 1] = pos;
										Grid[j][q] = WHITE_HORSE;
										return false;
									}
									Grid[j - 2][q - 1] = pos;
									Grid[j][q] = WHITE_HORSE;
								}
							}
							if (j + 1 < 8 && q + 2 < 8)
							{
								pos = Grid[j + 1][q + 2];
								if (pos != WHITE_BISHOP && pos != WHITE_HORSE && pos != WHITE_ROOK && pos != WHITE_QUEEN && pos != WHITE_PAWN && pos != WHITE_KING)
								{
									Grid[j + 1][q + 2] = WHITE_HORSE;
									Grid[j][q] = EMPTY_SQUARE;
									if (Player_In_Check(Grid, player) == false)
									{
										Grid[j + 1][q + 2] = pos;
										Grid[j][q] = WHITE_HORSE;
										return false;
									}
									Grid[j + 1][q + 2] = pos;
									Grid[j][q] = WHITE_HORSE;
								}
							}
							if (j + 1 < 8 && q - 2 >= 0)
							{
								pos = Grid[j + 1][q - 2];
								if (pos != WHITE_BISHOP && pos != WHITE_HORSE && pos != WHITE_ROOK && pos != WHITE_QUEEN && pos != WHITE_PAWN && pos != WHITE_KING)
								{
									Grid[j + 1][q - 2] = WHITE_HORSE;
									Grid[j][q] = EMPTY_SQUARE;
									if (Player_In_Check(Grid, player) == false)
									{
										Grid[j + 1][q - 2] = pos;
										Grid[j][q] = WHITE_HORSE;
										return false;
									}
									Grid[j + 1][q - 2] = pos;
									Grid[j][q] = WHITE_HORSE;
								}
							}
							if (j - 1 >= 0 && q + 2 < 8)
							{
								pos = Grid[j - 1][q + 2];
								if (pos != WHITE_BISHOP && pos != WHITE_HORSE && pos != WHITE_ROOK && pos != WHITE_QUEEN && pos != WHITE_PAWN && pos != WHITE_KING)
								{
									Grid[j - 1][q + 2] = WHITE_HORSE;
									Grid[j][q] = EMPTY_SQUARE;
									if (Player_In_Check(Grid, player) == false)
									{
										Grid[j - 1][q + 2] = pos;
										Grid[j][q] = WHITE_HORSE;
										return false;
									}
									Grid[j - 1][q + 2] = pos;
									Grid[j][q] = WHITE_HORSE;
								}
							}
							if (j - 1 >= 0 && q - 2 >= 0)
							{
								pos = Grid[j - 1][q - 2];
								if (pos != WHITE_BISHOP && pos != WHITE_HORSE && pos != WHITE_ROOK && pos != WHITE_QUEEN && pos != WHITE_PAWN && pos != WHITE_KING)
								{
									Grid[j - 1][q - 2] = WHITE_HORSE;
									Grid[j][q] = EMPTY_SQUARE;
									if (Player_In_Check(Grid, player) == false)
									{
										Grid[j - 1][q - 2] = pos;
										Grid[j][q] = WHITE_HORSE;
										return false;
									}
									Grid[j - 1][q - 2] = pos;
									Grid[j][q] = WHITE_HORSE;
								}
							}
						}
						else if (Grid[j][q] == WHITE_BISHOP || Grid[j][q] == WHITE_QUEEN)
						{
							//Look on all directions
							//Search TOP Left x-- y--
							s = q - 1;
							t = j - 1;
							if (t >= 0 && s >= 0)
							{
								while (t >= 0 && s >= 0)
								{
									pos = Grid[t][s];
									prev = Grid[j][q];
									if (pos != EMPTY_SQUARE && ((abs(t - x) != abs(s - y)) && x != t && y != s))
										break;
									else if ((pos == EMPTY_SQUARE || pos == BLACK_BISHOP || pos == BLACK_HORSE || pos == BLACK_QUEEN || pos == BLACK_PAWN) && ((abs(t - x) == abs(s - y)) || x == t || y == s))
									{
										Grid[t][s] = Grid[j][q];
										Grid[j][q] = EMPTY_SQUARE;
										if (Player_In_Check(Grid, player) == false)
										{
											Grid[t][s] = pos;
											Grid[j][q] = prev;
											return false;
										}
										Grid[t][s] = pos;
										Grid[j][q] = prev;
									}
									else break;
									s--;
									t--;
								}
							}
							//Search BOTTOM Right x++ y++
							s = q + 1;
							t = j + 1;
							if (t < 8 && s < 8)
							{
								while (t < 8 && s < 8)
								{
									pos = Grid[t][s];
									prev = Grid[j][q];
									if (pos != EMPTY_SQUARE && ((abs(t - x) != abs(s - y)) || x == t || y == s))
										break;
									else if ((pos == EMPTY_SQUARE || pos == BLACK_BISHOP || pos == BLACK_HORSE || pos == BLACK_QUEEN || pos == BLACK_PAWN) && ((abs(t - x) == abs(s - y)) || x == t || y == s))
									{
										Grid[t][s] = Grid[j][q];
										Grid[j][q] = EMPTY_SQUARE;
										if (Player_In_Check(Grid, player) == false)
										{
											Grid[t][s] = pos;
											Grid[j][q] = prev;
											return false;
										}
										Grid[t][s] = pos;
										Grid[j][q] = prev;
									}
									else break;
									s++;
									t++;
								}
							}
							//Search BOTTOM Left x++ y--
							s = q - 1;
							t = j + 1;
							if (s >= 0 && t < 8)
							{
								while (s >= 0 && t < 8)
								{
									pos = Grid[t][s];
									prev = Grid[j][q];
									if (pos != EMPTY_SQUARE && ((abs(t - x) != abs(s - y)) || x == t || y == s))
										break;
									else if ((pos == EMPTY_SQUARE || pos == BLACK_BISHOP || pos == BLACK_HORSE || pos == BLACK_QUEEN || pos == BLACK_PAWN) && ((abs(t - x) == abs(s - y)) || x == t || y == s))
									{
										Grid[t][s] = Grid[j][q];
										Grid[j][q] = EMPTY_SQUARE;
										if (Player_In_Check(Grid, player) == false)
										{
											Grid[t][s] = pos;
											Grid[j][q] = prev;
											return false;
										}
										Grid[t][s] = pos;
										Grid[j][q] = prev;
									}
									else break;
									s--;
									t++;
								}
							}
							//Search top Right x-- y++
							s = q + 1;
							t = j - 1;
							if (s < 8 && t >= 0)
							{
								while (s < 8 && t >= 0)
								{
									pos = Grid[t][s];
									prev = Grid[j][q];
									if (pos != EMPTY_SQUARE && ((abs(t - x) != abs(s - y)) || x == t || y == s))
										break;
									else if ((pos == EMPTY_SQUARE || pos == BLACK_BISHOP || pos == BLACK_HORSE || pos == BLACK_QUEEN || pos == BLACK_PAWN) && ((abs(t - x) == abs(s - y)) || x == t || y == s))
									{
										Grid[t][s] = Grid[j][q];
										Grid[j][q] = EMPTY_SQUARE;
										if (Player_In_Check(Grid, player) == false)
										{
											Grid[t][s] = pos;
											Grid[j][q] = prev;
											return false;
										}
										Grid[t][s] = pos;
										Grid[j][q] = prev;
									}
									else break;
									s++;
									t--;
								}
							}
						}
						if (Grid[j][q] == WHITE_ROOK || Grid[j][q] == WHITE_QUEEN)
						{
							//Look Right
							for (int t = q + 1; t < 8; t++)
							{
								pos = Grid[j][t];
								prev = Grid[j][q];
								if (pos != EMPTY_SQUARE && ((abs(j - x) != abs(t - y)) || x == j || y == t))
									break;
								else if ((pos == EMPTY_SQUARE || pos == BLACK_BISHOP || pos == BLACK_HORSE || pos == BLACK_QUEEN || pos == BLACK_PAWN) && ((abs(j - x) != abs(t - y)) || x == j || y == t))
								{
									Grid[j][t] = Grid[j][q];
									Grid[j][q] = EMPTY_SQUARE;
									if (Player_In_Check(Grid, player) == false)
									{
										Grid[j][t] = pos;
										Grid[j][q] = prev;
										return false;
									}
									Grid[j][t] = pos;
									Grid[j][q] = prev;
								}
								else break;
							}
							//Look Left
							for (int t = q - 1; t >= 0; t--)
							{
								pos = Grid[j][t];
								prev = Grid[j][q];
								if (pos != EMPTY_SQUARE && ((abs(j - x) != abs(t - y)) || x == j || y == t))
									break;
								else if ((pos == EMPTY_SQUARE || pos == BLACK_BISHOP || pos == BLACK_HORSE || pos == BLACK_QUEEN || pos == BLACK_PAWN) && ((abs(j - x) != abs(t - y)) || x == j || y == t))
								{
									Grid[j][t] = Grid[j][q];
									Grid[j][q] = EMPTY_SQUARE;
									if (Player_In_Check(Grid, player) == false)
									{
										Grid[j][t] = pos;
										Grid[j][q] = prev;
										return false;
									}
									Grid[j][t] = pos;
									Grid[j][q] = prev;
								}
								else break;
							}
							//Look Up
							for (int t = j + 1; t < 8; t++)
							{
								pos = Grid[t][q];
								prev = Grid[j][q];
								if (pos != EMPTY_SQUARE && ((abs(j - x) != abs(t - y)) || x == t || y == q))
									break;
								else if ((pos == EMPTY_SQUARE || pos == BLACK_BISHOP || pos == BLACK_HORSE || pos == BLACK_QUEEN || pos == BLACK_PAWN) && ((abs(j - x) != abs(t - y)) || x == t || y == q))
								{
									Grid[t][q] = Grid[j][q];
									Grid[j][q] = EMPTY_SQUARE;
									if (Player_In_Check(Grid, player) == false)
									{
										Grid[t][q] = pos;
										Grid[j][q] = prev;
										return false;
									}
									Grid[t][q] = pos;
									Grid[j][q] = prev;
								}
								else break;
							}
							//Look Down
							for (int t = j - 1; t >= 0; t--)
							{
								pos = Grid[t][q];
								prev = Grid[j][q];
								if (pos != EMPTY_SQUARE && ((abs(j - x) != abs(t - y)) || x == t || y == q))
									break;
								else if ((pos == EMPTY_SQUARE || pos == BLACK_BISHOP || pos == BLACK_HORSE || pos == BLACK_QUEEN || pos == BLACK_PAWN) && ((abs(j - x) != abs(t - y)) || x == t || y == q))
								{
									Grid[t][q] = Grid[j][q];
									Grid[j][q] = EMPTY_SQUARE;
									if (Player_In_Check(Grid, player) == false)
									{
										Grid[t][q] = pos;
										Grid[j][q] = prev;
										return false;
									}
									Grid[t][q] = pos;
									Grid[j][q] = prev;
								}
								else break;
							}
						}
					}
				}
			}
		}
		return true;
	}
	return false;
}
int main(int argc, char* argv[]) 
{
	
	char player, Grid[8][8];
	bool win, tie;
	int end;

	win = false;
	tie = false;
	player = WHITE_PLAYER;
	end = StartUP_menu();
	
	if (end == 4) return 0;

	Create_Grid(Grid);
	Display_Grid(Grid);
	
	SDL_Window* window = nullptr;

	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		std::cout << "SDL could not be initialized: " <<
			SDL_GetError();
	}
	else {
		std::cout << "SDL video system is ready to go\n";
	}
	
	window = SDL_CreateWindow("CHESS", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_W, SCREEN_H, SDL_WINDOW_SHOWN);
	SDL_Renderer* renderer = nullptr;
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

	SDL_Surface* surface = SDL_LoadBMP("images/board640px.bmp");
	if (surface == NULL)
	{
		printf("Unable to load image %s! SDL Error: %s\n", "images/board640px.bmp", SDL_GetError());
	}

	SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);

	SDL_FreeSurface(surface);

	// Create a board
	SDL_Rect board;
	board.x = 0;
	board.y = 0;
	board.w = 640;
	board.h = 640;
	//Mouse
	SDL_Rect mouse;
	mouse.w = 1;
	mouse.h = 1;
	//Create pieces
	Button* pieces[32];
	//Black pieces
	{
		pieces[0] = new Button(80 * 5, 0, renderer);
		pieces[0]->Setpiece('r');
		pieces[0]->Setposition(0, 0);

		pieces[7] = new Button(80 * 5, 0, renderer);
		pieces[7]->Setpiece('r');
		pieces[7]->Setposition(80 * 7, 0);

		pieces[1] = new Button(80 * 1, 0, renderer);
		pieces[1]->Setpiece('h');
		pieces[1]->Setposition(80, 0);

		pieces[6] = new Button(80 * 1, 0, renderer);
		pieces[6]->Setpiece('h');
		pieces[6]->Setposition(80 * 6, 0);

		pieces[3] = new Button(0, 0, renderer);
		pieces[3]->Setpiece('b');
		pieces[3]->Setposition(80 * 2, 0);

		pieces[5] = new Button(0, 0, renderer);
		pieces[5]->Setpiece('b');
		pieces[5]->Setposition(80 * 5, 0);

		pieces[4] = new Button(80 * 3, 0, renderer);
		pieces[4]->Setpiece('q');
		pieces[4]->Setposition(80 * 3, 0);

		pieces[2] = new Button(80 * 2, 0, renderer);
		pieces[2]->Setpiece('k');
		pieces[2]->Setposition(80 * 4, 0);
	}
	for (int i = 8; i < 16; i++)
	{
		pieces[i] = new Button(80 * 4, 0, renderer);
		pieces[i]->Setpiece('p');
		pieces[i]->Setposition(80 * (i - 8), 80);
	}
	//White pieces
	{
		pieces[16] = new Button(80 * 5, 0, renderer, 'w');
		pieces[16]->Setpiece('R');
		pieces[16]->Setposition(0, 80 * 7);

		pieces[17] = new Button(80 * 5, 0, renderer, 'w');
		pieces[17]->Setpiece('R');
		pieces[17]->Setposition(80 * 7, 80 * 7);

		pieces[18] = new Button(80 * 1, 0, renderer, 'w');
		pieces[18]->Setpiece('H');
		pieces[18]->Setposition(80, 80 * 7);

		pieces[19] = new Button(80 * 1, 0, renderer, 'w');
		pieces[19]->Setpiece('H');
		pieces[19]->Setposition(80 * 6, 80 * 7);

		pieces[20] = new Button(0, 0, renderer, 'w');
		pieces[20]->Setpiece('B');
		pieces[20]->Setposition(80 * 2, 80 * 7);

		pieces[21] = new Button(0, 0, renderer, 'w');
		pieces[21]->Setpiece('B');
		pieces[21]->Setposition(80 * 5, 80 * 7);

		pieces[22] = new Button(80 * 3, 0, renderer, 'w');
		pieces[22]->Setpiece('Q');
		pieces[22]->Setposition(80 * 3, 80 * 7);

		pieces[23] = new Button(80 * 2, 0, renderer, 'w');
		pieces[23]->Setpiece('K');
		pieces[23]->Setposition(80 * 4, 80 * 7);
	}
	for (int i = 24; i < 32; i++)
	{
		pieces[i] = new Button(80 * 4, 0, renderer, 'w');
		pieces[i]->Setpiece('P');
		pieces[i]->Setposition(80 * (i - 24), 80 * 6);
	}

	// Infinite loop for our application
	bool gameIsRunning = true;
	int pieceSelected = -1;
	bool cont = false;
	bool checkclick = false;
	SDL_Event event;
	int mouseX, mouseY, x, y, First_X, First_Y,posx, posy, i, j;
	char piece;
	//First iteration draw

	//Draw Board
	SDL_RenderCopy(renderer, texture, NULL, &board);
	//Draw pieces
	for (int i = 0; i < 32; i++)
		pieces[i]->draw(renderer);

	// Finally show what we've drawn
	SDL_RenderPresent(renderer);

	// Main application loop
	while (!win && !tie && gameIsRunning)
	{
		SDL_GetMouseState(&mouseX, &mouseY);
		mouse.x = mouseX;
		mouse.y = mouseY;
		
		cont = false;
		// Event loop
		while (SDL_PollEvent(&event))
		{
			// Handle each event
			if (event.type == SDL_QUIT)
			{
				gameIsRunning = false;
			}
			if (event.type == SDL_MOUSEBUTTONDOWN)
			{
				if (event.button.button == SDL_BUTTON_LEFT)
				{
					checkclick = true;
					std::cout << "Left click down" << std::endl;
				}
			}
		}
		if (checkclick == true) 
		{
			x = (mouseY / 80) % 10;
			y = (mouseX / 80) % 10;
			if (pieceSelected == -1 && Check_Start(Grid, x, y, player))
			{
				if (player == WHITE_PLAYER)
					std::cout << "----White to move(UPERCASE)----" << std::endl;
				else std::cout << "----Black to move(lowercase)----" << std::endl;

				std::cout << "Choose the piece you want to move:  " << std::endl;

					for (int i = 0; i < 32; i++)
					{
						if (pieces[i]->collision(mouse) == SDL_TRUE)
						{
							std::cout << "Piece detected :" << pieces[i]->Getpiece() << std::endl;
							SDL_Texture* t = pieces[i]->Getstexture();
							pieces[i]->Settexture(t);
							pieceSelected = i;
							break;
						}
					}
					First_X = x;
					First_Y = y;
			}
			else
			{
				if (First_X == x && First_Y == y)
				{
					SDL_Texture* t = pieces[pieceSelected]->Getauxtexture();
					pieces[pieceSelected]->Settexture(t);
					pieceSelected = -1;
				}
				else if (pieceSelected != -1 && Check_END(Grid,First_X,First_Y,x,y,player,pieces))
				{
					piece = pieces[pieceSelected]->Getpiece();
					posx = mouseX;
					posy = mouseY;
					i = -1;
					j = -1;
					while (posx > 0)
					{
						posx = posx - 80;
						i++;
					}
					while (posy > 0)
					{
						posy = posy - 80;
						j++;
					}
					pieces[pieceSelected]->Setposition(80 * i, 80 * j);
					for (int z = 0; z < 32; z++)
					{
						pieces[z]->Getposition(&posx, &posy);
						if (posx == 80 * i && posy == 80 * j && z != pieceSelected)
							pieces[z]->Setdead();
					}
					SDL_Texture* t = pieces[pieceSelected]->Getauxtexture();
					pieces[pieceSelected]->Settexture(t);
					//Provisional Promotion Change Of Texture
					if (player == WHITE_PLAYER && piece==WHITE_PAWN && (Grid[x][y] == WHITE_BISHOP || Grid[x][y] == WHITE_HORSE || Grid[x][y] == WHITE_ROOK || Grid[x][y] == WHITE_QUEEN))
					{
						int px, py,aux;
						piece = Grid[x][y];
						piece == 'H' ? aux = 1 : (piece == 'Q' ? aux = 3 : (piece == 'R' ? aux = 5 : (piece == 'B' ? aux == 2 : aux = 7)));
						pieces[pieceSelected]->Getposition(&px, &py);
						pieces[pieceSelected] = new Button(80 * aux, 0, renderer,'w');
						pieces[pieceSelected]->Setpiece(piece);
						pieces[pieceSelected]->Setposition(px, py);
					}
					if (player == BLACK_PLAYER && piece == BLACK_PAWN && (Grid[x][y] == BLACK_BISHOP || Grid[x][y] == BLACK_HORSE || Grid[x][y] == BLACK_ROOK || Grid[x][y] == BLACK_QUEEN))
					{
						int px, py, aux;
						piece = Grid[x][y];
						piece == 'h' ? aux = 1 : (piece == 'q' ? aux = 3 : (piece == 'r' ? aux = 5 : (piece == 'b' ? aux == 2 : aux = 7)));
						pieces[pieceSelected]->Getposition(&px, &py);
						pieces[pieceSelected] = new Button(80 * aux, 0, renderer);
						pieces[pieceSelected]->Setpiece(piece);
						pieces[pieceSelected]->Setposition(px, py);
					}
					Grid[x][y] = pieces[pieceSelected]->Getpiece();
					Grid[First_X][First_Y] = EMPTY_SQUARE;
					Display_Grid(Grid);
					pieceSelected = -1;
					cont = true;
				}
			}
			checkclick = false;
		}
		//Draw Board
		SDL_RenderCopy(renderer, texture, NULL, &board);
		//Draw pieces
		for (int i = 0; i < 32; i++)
			pieces[i]->draw(renderer);

		// Finally show what we've drawn
		SDL_RenderPresent(renderer);

		//Player_Choice(Grid, player);
		//Display_Grid(Grid);
		if (cont == true)
		{
			win = Check_Win(Grid, player);
			tie = Check_Tie(Grid, player);
			player = player % 2 + 1;
		}
	}
	Display_Grid(Grid);
	if(gameIsRunning==true)
	{ 
		if (tie == true)
			std::cout << "Tie" << std::endl;
		else
		{
			if (player == WHITE_PLAYER && win == true)
				std::cout << "Black Player WON!!!! CHECKMATE!!!" << std::endl;
			else
				std::cout << "White Player WON!!!! CHECKMATE!!!" << std::endl;
		}
	}	
	system("pause");
	return 0;
}