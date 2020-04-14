#include<iostream>
using namespace std;

void mySwap(int *a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
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


void bubbleSort(int arr[],int N)
{

	for (int i = 0; i < N-1; ++i)
	{
		for (int j = 0; j < N-1-i; ++j)
		{
			if(arr[j]>arr[j+1])
			{
				mySwap(&arr[j],&arr[j+1]);
			}

		}

	}
	
}


int findKthElement(int arr[], int N, int K)
{
	bubbleSort(arr,N);
	return arr[K-1];








}

int main()
 {
	int T,N,arr[100],K, ans[100];
	cin >> T;
	for(int i = 0; i < T;i++)
	{
	    cin >> N;
	    inputArray(arr,N);
	    cin >> K;
	    ans[i] = findKthElement(arr,N,K);
	}
	outputArray(ans,T);

	return 0;
}