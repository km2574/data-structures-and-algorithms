#include<iostream>
using namespace std;

void inputArray(int array[],int n)
{
	for (int i = 0; i < n; ++i)
	{
		cin >> array[i];
	}
}


int findElement(int array[],int n)
{
	
}

int main()
{
	int array[100],n;
	inputArray(array,n);
	findElement(array,n);
	return 0;
}