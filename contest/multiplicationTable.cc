#include<iostream>
using namespace std;

int findOccurance(long long int n,long long int mat[][20],long long int x)
{
	int count =0;
	for (int i = 1; i <= n ; ++i)
	{
		for (int j = 0; j <= n; ++j)
		{
			mat[i-1][j-1] = i*j;
			if (mat[i-1][j-1]==x)
			{
				count +=1;
			}
		}
	}
	return count;
}
int findOccuranceFast(long long int n,long long int x)
{
	int count =0;
	for (int i = 1; i<= n ; ++i)
	{
		if(x%i==0 && x/i <= n)
		{
			count += 1;
		}
	}
	return count;
}

int main()
{
	long long int n,x;
	cin >> n >> x;
	int ans = findOccuranceFast(n,x);
	cout << ans;
}