#include<iostream>
using namespace std;

void inputMat(char mat[][10],int row, int col)
{
    for(int r = 0;r < row;r++)
    {
        for(int c=0; c<col; c++)
        {
            cin >> mat[r][c];
        }
    }
}
void printMat(char mat[][10],int row, int col)
{
    for(int r = 0;r < row;r++)
    {
        for(int c=0; c<col; c++)
        {
            cout <<  mat[r][c];
        }
    }
}

void spiralFn(char mat[][10],int row,int col)
{
    
}
int main()
{
    char mat[10][10];
    int row, col;
    cin << row << col;
    inputMat(mat,row,col);
    spiralFn(mat,row,col);
    printMat(mat,row,col);
    return 0;

}