#include<iostream>
using namespace std;
void inputArray(int arr[],int N)
{
    for (int i = 0; i < N; ++i)
    {
    	cin >> arr[i];
    }
}

void outputArray(int arr[],int N)
{
	for (int i = 0; i < N; ++i)
	{
		cout << arr[i] << endl;
	}
}


void findSubArray(int arr[],int N)
{
	for (int i = 0; i < N; ++i)
	{
		for (int j = i; j < N; ++j)
		{
			for (int k = i; k <= j ; ++k)
			{
				cout << arr[k] << " ";
			}
			cout << endl;
		}
	}
}

int main()
{
	int N, arr[100];
	cin >> N;
	inputArray(arr,N);
	// int nWays = putTheTiles(N);
	findSubArray(arr,N);
	return 0;
}