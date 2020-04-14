#include<iostream>
using namespace std;
int arr[100];
int doMin(int n)
{
	int nCopy = n;
	int i =0;
	while(n%10!=0 && n/10!=0)
	{
		arr[i] = n%10;
		if (arr[i]>=5)
		{
			arr[i]= 9 - arr[i];
		}
		n = n/10;
		i++;
	}
	if (arr[i]==0)
	{
		for (int j = i; j >0 ; --j)
		{
			nCopy = nCopy/10;
		}
		arr[i]=nCopy;
	}
	return i;
}

int main()
{
	int n;
	cin >> n;
	int i = doMin(n);
	for (; i >=0 ; --i)
	{
		cout << arr[i];
	}
}