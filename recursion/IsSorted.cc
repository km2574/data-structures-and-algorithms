#include<iostream>
using namespace std;

void InputArr(int n, int arr[])
{
	for (int i = 0; i < n; ++i)
	{
		cin >> arr[i];
	}
}

void OutputArr(int n, int arr[])
{
	for (int i = 0; i < n; ++i)
	{
		cout << arr[i];
	}
}


bool IsSorted(int n, int arr[])
{
	if(n==1) return true;
	if(arr[0]<arr[1] && IsSorted(n-1,arr+1))
	{
		return true;
	}
	else return false;
}



int main()
{
	int n, arr[10];
	cin >> n;
	InputArr(n, arr);

	if(IsSorted(n,arr))
	{
		cout << "Yes"<< endl;
	}
	else cout << "False" << endl;
	OutputArr(n, arr);
	return 0;
}