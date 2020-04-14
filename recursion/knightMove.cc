#include<iostream>
using namespace std;
const int D = 8;


void printBoard(int board[D][D],int n)
{
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cout << board[i][j] << "\t";
		}
		cout << "\n";
	}
}
bool canPlace(int board[D][D],int n,int nextRow,int nextCol){
	return nextRow >= 0 && nextRow < n &&
			nextCol >= 0 && nextCol < n &&
			board[nextRow][nextCol] == 0; 
}

bool solveKnightMove(int board[D][D],int n,int move_no,int curRow,int curCol)
{
	if(move_no == n*n){
		printBoard(board,n);
		cout << "============================== \n";
		return true;
	}
	static int rowDir[] = {2,1,-1,-2,-2,-1,1,2};
	static int colDir[] = {1,2,2,1,-1,-2,-1,-1};
	for (int curDir = 0; curDir < 8; ++curDir)
	{
		int nextRow = curRow + rowDir[curDir];
		int nextCol = curCol + colDir[curDir];
		if (canPlace(board,n,nextRow,nextCol))
		{
			board[nextRow][nextCol] = move_no + 1;
			bool isSuccessful = solveKnightMove(board,n,move_no+1,nextRow,nextCol);
			//if (isSuccessful) return true;
			board[nextRow][nextCol] = 0;
		}
	}
	return false;
}


int main()
{
	int board[D][D] = {0},n;
	cin >> n;
	board[0][0] = 1;
	solveKnightMove(board,n,1,0,0);
	/*if(solveKnightMove(board,n,1,0,0))
	{
		printBoard(board,n);
	}
	else cout << "Sorry!! Can't visit" << endl;*/
}