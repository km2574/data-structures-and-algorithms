#include<iostream>
using namespace std;
void inputArray(int arr[],int N,int cumSum[])
{
	cin >> arr[0];
	cumSum[0] = arr[0];
    for (int i = 1; i < N; ++i)
    {
    	cin >> arr[i];
    	cumSum[i] = cumSum[i-1] + arr[i];
    }
}

void outputArray(int arr[],int N)
{
	for (int i = 0; i < N; ++i)
	{
		cout << arr[i] << endl;
	}
}


int maxSumSubArray1(int arr[],int N)
{
	int maxSum = 0;
	for (int i = 0; i < N; ++i)
	{
		for (int j = i; j < N; ++j)
		{
			int subArrSum = 0;
			for (int k = i; k <= j ; ++k)
			{
				cout << arr[k] << " ";
				subArrSum = subArrSum + arr[k];
			}
			cout << subArrSum << " \n";
			if (subArrSum > maxSum)
			{
				maxSum = subArrSum;
			}
		}
	}
	return maxSum;
}

int maxSumSubArray2(int arr[],int N,int cumSum[])
{
	int maxSum =0;
	for (int i = 0; i < N; ++i)
	{
		for (int j = i; j < N; ++j)
		{
			int subArrSum = 0;
			subArrSum = cumSum[j] - cumSum[i-1];

			if (subArrSum > maxSum)
			{
				maxSum = subArrSum;
			}
		}

	}
	return maxSum;
}

int main()
{
	int cumSum[20] = {0};
	int N, arr[100];
	cin >> N;
	inputArray(arr,N,cumSum);
	// int nWays = putTheTiles(N);
	cout << maxSumSubArray2(arr,N,cumSum);
	return 0;
}