#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

const char X = 'X';  //��ʾ����һ������
const char O = 'O';   //��һ������
const char EMPTY = ' ';  //��ʾ�����ϵĿո���һ���ո��ַ�
const char TIE = 'T';   //��ʾ������ַ������еķ���������
const char NO_ONE = 'N';  //��ʾ��û���κ�һ��ʤ�����ַ��������п���Ŀո�

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
//��ʾ��Ϸָ��
void instructions()
{
	cout << "��ӭ�����ռ��˻��Ծ���Tic_Tac_Toe.\n";
	cout << "--������������Ĵ��ԶԾ�������ĵط�\n\n";
	cout << "ͨ������0-8֮������֣���֪������ƶ�����\n";
	cout << "��Ӧ��������̵�λ�ã������ʾ��\n\n";
	cout << " 0 | 1 | 2\n";
	cout << " ---------\n";
	cout << " 3 | 4 | 5\n";
	cout << " ---------\n";
	cout << " 6 | 7 | 8\n\n";
	cout << "�Լ�����׼�������࣬ս��������ʼ.\n\n";
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
	char go_first = askYesNo("����Ҫ��һ�����ƶ���");
	if (go_first == 'y')
	{
		cout << "\nȻ��������������ƶ�.\n";
		return  X;
	}
	else
	{
		cout << "\n��������.\n";
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
	const int WINNING_ROWS[8][3] = { { 0,1,2 }, //���п��ܻ�ʤ������
	{ 3,4,5 },
	{ 6,7,8 },
	{ 0,3,6 },
	{ 1,4,7 },
	{ 2,5,8 },
	{ 0,4,8 },
	{ 2,4,6 } };
	const int TOTAL_ROWS = 8;
	for (int row = 0; row < TOTAL_ROWS; ++row)//���Ӯ��ʤ������ô�κ�һ�ж�������ֵ����ͬ�ģ�����Ϊ��
	{
		if ((board[WINNING_ROWS[row][0]] != EMPTY) &&
			(board[WINNING_ROWS[row][0]] == board[WINNING_ROWS[row][1]]) &&
			(board[WINNING_ROWS[row][1]] == board[WINNING_ROWS[row][2]]));
		{
			return board[WINNING_ROWS[row][0]];
		}
	}
	//���û����һ�ʤ����������û�п��෽�������
	if (count(board.begin(), board.end(), EMPTY) == 0)
		return TIE;
	//���û�����ʤ������û�к��壬��ô��Ϸ��ʱû��ʤ����
	return NO_ONE;
}
inline bool isLegal(const vector<char>& board, int move)  //����һ�����̺�һ������Ϊ������������Ϸ�������true
{
	return (board[move] == EMPTY);
}
int humanMove(const vector<char>& board, char human)
{
	int move = askNumber("�㽫�Ƶ����", (board.size() - 1));
	while (!isLegal(move, board))
	{
		cout << "\n�Ǹ������Ѿ���ռ���ˣ�����.\n";
		move = askNumber("�㽫�Ƶ����", (board.size() - 1));
	}
	cout << "�õ�...\n";
	return move;
}
int computerMove(vector<char> board, char computer)
{
	unsigned int move = 0;
	bool found = false;
	//���������һ�����ܹ�Ӯ��ʤ�����Ǿ�ѡ����һ����
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
	if (!found)   //�����������Ƿ�������һ�����ʤ
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
	if (!found)  //˳��ѭ�������������е��б�ѡ���һ���Ϸ�������
	{
		move = 0;
		unsigned int i = 0;
		const int BEST_MOVES[] = { 4,0,2,6,8,1,3,5,7 };
		while (!found && i < board.size())  //ѭ��������õ�����б�
		{
			move = BEST_MOVES[i];
			if (isLegal(move, board))
			{
				found = true;
			}
			++i;
		}
	}
	cout << "ȡ�������е�����" << move << endl;
	return move;
}
void announceWinner(char winner, char computer, char human)
{
	if (winner == computer)
	{
		cout << winner << "ȡ��ʤ����\n";
	}
	else if (winner == human)
	{
		cout << winner << "ȡ��ʤ����\n";
	}
	else
	{
		cout << "�˾�Ϊƽ�֣�" << endl;
		cout << "ף���㣬����Ŀǰ������õ�.\n";
	}
}