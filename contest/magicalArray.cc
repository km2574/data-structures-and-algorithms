#include<iostream>
using namespace std;
void inputArray(long long int arr[],int n)
{
	for (int i = 0; i < n; ++i)
	{
		cin >> arr[i];
	}
}

int magicalSubarrays(long long int arr[],int n)
{
	int ans = n, ansTwo = 0;
	for (int i = 0; i < n; ++i)
	{
		int keyIndex = i;
		for (int j = i+1; j < n; ++j)
		{
			if (arr[keyIndex]==arr[j])
			{
				keyIndex = j;
				ansTwo += 1;
			}
		}
	}
	return ans+ansTwo;
}



int main()
{
	long long int arr[100];
	int n;
	cin >> n;
	inputArray(arr,n);
	cout << magicalSubarrays(arr,n);
	return 0;
}