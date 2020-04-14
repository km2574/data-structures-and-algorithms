#include<iostream>
using namespace std;

bool isPrimeOn(int n)
{
	for (int i = 2; i < n; ++i)
	{
		if (n%i==0)
		{
			return false;
		}
	}
	return true;
}

bool isPrimeOnFaster(int n)
{
	for (int i = 2; i <= n/2; ++i)
	{
		if (n%i==0)
		{
			return false;
		}
	}
	return true;
}
 bool isPrimeRootN(int n)
 {
 	if(n<=1)	return false;
 	if (n==2 || n==3)
 	{
 		return true;
 	}
 	for (int i = 2; i*i <= n; ++i)
 	{
 		if (n%i==0)
 		{
 			return false;
 		}
 	}
 	return true;
 }

int main()
{
	int n;
	cin >> n;
	if (isPrimeRootN(n))
	{
		cout << "yes";
	}
	else cout << "NO";
}