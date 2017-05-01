#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

const char X = 'X';  //表示的是一个棋子
const char O = 'O';   //另一个棋子
const char EMPTY = ' ';  //表示棋盘上的空格，是一个空格字符
const char TIE = 'T';   //表示和棋的字符，所有的方格已填满
const char NO_ONE = 'N';  //表示还没有任何一方胜出的字符，但还有空余的空格

void instructions();
char askYesNo(string question);
int askNumber(string question, int high, int low = 0);
char humanpiece();
char opponent(char piece);
void displayBorad(const vector<char>& board);
char winner(const vector<char>& board);
bool isLegal(const vector<char>& board, int move);
int humanMove(const vector<char>& board, char human);
int computerMove(vector<char> board, char computer);
void announceWinner(char winner, char compter, char human);

int main()
{
	int move;
	const int NUM_SQUARES = 9;
	vector<char>board(NUM_SQUARES, EMPTY);
	instructions();
	char human = humanpiece();
	char computer = opponent(human);
	char turn = X;
	displayBorad(board);
	while (winner(board) == NO_ONE)
	{
		if (true == human)
		{
			move = humanMove(board, human);
			board[move] = human;
		}
		else
		{
			move = computerMove(board, computer);
			board[move] = computer;
		}
		displayBorad(board);
		turn = opponent(turn);
	}
	announceWinner(winner(board), computer, human);
	system("pause");
	return 0;
}
//显示游戏指南
void instructions()
{
	cout << "欢迎来到终极人机对决：Tic_Tac_Toe.\n";
	cout << "--在这里是人类的大脑对决计算机的地方\n\n";
	cout << "通过输入0-8之间的数字，来知道你的移动次数\n";
	cout << "对应所需的棋盘的位置，如果所示：\n\n";
	cout << " 0 | 1 | 2\n";
	cout << " ---------\n";
	cout << " 3 | 4 | 5\n";
	cout << " ---------\n";
	cout << " 6 | 7 | 8\n\n";
	cout << "自己做好准备，人类，战斗即将开始.\n\n";
}
char askYesNo(string question)
{
	char response;
	do
	{
		cout << question << "(y/n):";
		cin >> response;
	} while (response != 'y'&& response != 'n');
	return response;
}
int askNumber(string question, int high, int low)
{
	int number;
	do
	{
		cout << question << "(" << low << "-" << high << "):";
		cin >> number;
	} while (number > high || number < low);
	return number;
}
char humanpiece()
{
	char go_first = askYesNo("你需要第一步先移动吗？");
	if (go_first == 'y')
	{
		cout << "\n然后现在你必须先移动.\n";
		return  X;
	}
	else
	{
		cout << "\n那我先走.\n";
		return O;
	}
}
char opponent(char piece)
{
	if (piece == X)
	{
		return O;
	}
	else
	{
		return X;
	}
}
void displayBorad(const vector<char>& board)
{
	cout << "\n\t" << board[0] << " | " << board[1] << " | " << board[2];
	cout << "\n\t" << "---------";
	cout << "\n\t" << board[3] << " | " << board[4] << " | " << board[5];
	cout << "\n\t" << "---------";
	cout << "\n\t" << board[6] << " | " << board[7] << " | " << board[8];
	cout << "\n\n";
}
char winner(const vector<char>& board)
{
	const int WINNING_ROWS[8][3] = { { 0,1,2 }, //所有可能获胜的行数
	{ 3,4,5 },
	{ 6,7,8 },
	{ 0,3,6 },
	{ 1,4,7 },
	{ 2,5,8 },
	{ 0,4,8 },
	{ 2,4,6 } };
	const int TOTAL_ROWS = 8;
	for (int row = 0; row < TOTAL_ROWS; ++row)//如果赢得胜利，那么任何一行都有三个值是相同的，不能为空
	{
		if ((board[WINNING_ROWS[row][0]] != EMPTY) &&
			(board[WINNING_ROWS[row][0]] == board[WINNING_ROWS[row][1]]) &&
			(board[WINNING_ROWS[row][1]] == board[WINNING_ROWS[row][2]]));
		{
			return board[WINNING_ROWS[row][0]];
		}
	}
	//如果没有玩家获胜，但棋盘上没有空余方格，则和棋
	if (count(board.begin(), board.end(), EMPTY) == 0)
		return TIE;
	//如果没有玩家胜出，且没有和棋，那么游戏暂时没有胜利者
	return NO_ONE;
}
inline bool isLegal(const vector<char>& board, int move)  //接受一个棋盘和一招棋作为参数，这招棋合法，返回true
{
	return (board[move] == EMPTY);
}
int humanMove(const vector<char>& board, char human)
{
	int move = askNumber("你将移到哪里？", (board.size() - 1));
	while (!isLegal(move, board))
	{
		cout << "\n那个方格已经被占领了，人类.\n";
		move = askNumber("你将移到哪里？", (board.size() - 1));
	}
	cout << "好的...\n";
	return move;
}
int computerMove(vector<char> board, char computer)
{
	unsigned int move = 0;
	bool found = false;
	//如果电脑下一步棋能够赢得胜利，那就选择这一招棋
	while (!found && move < board.size())
	{
		if (isLegal(move, board))
		{
			board[move] = computer;
			found = winner(board) == computer;
			board[move] = EMPTY;
		}
		if (!found)
		{
			++move;
		}
	}
	if (!found)   //检查人类玩家是否能在下一招棋获胜
	{
		move = 0;
		char human = opponent(computer);
		while (!found && move < board.size())
		{
			if (isLegal(move, board))
			{
				board[move] = human;
				found = winner(board) == human;
				board[move] = EMPTY;
			}
			if (!found)
			{
				++move;
			}
		}
	}
	if (!found)  //顺序循环访问最优棋招的列表，选择第一个合法的棋招
	{
		move = 0;
		unsigned int i = 0;
		const int BEST_MOVES[] = { 4,0,2,6,8,1,3,5,7 };
		while (!found && i < board.size())  //循环访问最好的棋的列表
		{
			move = BEST_MOVES[i];
			if (isLegal(move, board))
			{
				found = true;
			}
			++i;
		}
	}
	cout << "取出方格中的数字" << move << endl;
	return move;
}
void announceWinner(char winner, char computer, char human)
{
	if (winner == computer)
	{
		cout << winner << "取得胜利！\n";
	}
	else if (winner == human)
	{
		cout << winner << "取得胜利！\n";
	}
	else
	{
		cout << "此局为平局！" << endl;
		cout << "祝贺你，你是目前做得最好的.\n";
	}
}