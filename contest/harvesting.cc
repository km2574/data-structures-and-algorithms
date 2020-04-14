#include<iostream>
#include<cstdlib>
using namespace std;
int n;
void inputArray(int arr[],int n)
{
	for (int i = 0; i < n; ++i)
	{
		cin >> arr[i];
	}
}

int rightMaxIndex(int arr[], int curIndex)
{
	int maxIndex = curIndex;
	for (int i = curIndex+1; i < n; ++i)
	{
		if (arr[maxIndex]<arr[i])
		{
			maxIndex = i;
			if (arr[maxIndex] > arr[maxIndex+1] && maxIndex+1< n)
			{
				return maxIndex;
			}
		}
	}
	return curIndex;
}

int leftMaxIndex(int arr[], int curIndex)
{
	int maxIndex = curIndex;
	for (int i = curIndex-1; i >=0; --i)
	{
		if (arr[maxIndex]<arr[i])
		{
			maxIndex = i;
			if (arr[maxIndex] > arr[maxIndex-1] && maxIndex-1>=0)
			{
				return maxIndex;
			}
		}
	}
	return curIndex;
}


int waterSaved(int arr[],int n)
{
	
	int ans = 0;
	for (int i = 1; i < n-1; ++i)
	{
		int rightMax = rightMaxIndex(arr,i);
		int leftMax = leftMaxIndex(arr,i);
		int height = min(arr[rightMax],arr[leftMax]);
		if (leftMax!=i && rightMax!=i)
		{
			ans = ans + height - arr[i];
		}
	}
	return ans;
}


int main()
{
	int arr[20];
	cin >> n;
	inputArray(arr,n);
	cout << waterSaved(arr,n);

}