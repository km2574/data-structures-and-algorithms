#include<iostream>
using namespace std;

float findSqrt(int n,int decimalPlaces)
{
	int s = 0,e = n;
	int mid = (s+e)/2;
	float ans;
	while(s<=e)
	{
		mid=(s+e)/2;
		if (mid*mid==n)
		{
			//got the answer
			return mid;
		}
		else if(mid*mid>n){
			//answer is on left
			e = mid-1;
		}
		else{
			//answer is on right
			s = mid+1;
			ans = mid;
			//cout << mid << endl;

		}
	}
	//dealing with the fractional part
	float increment=0.1;
	for (int i = 0; i < decimalPlaces; ++i)
	{
		//cout << "entered increment \n";
		while(ans*ans<=n)
		{
			//cout << "while \n";
			ans += increment;
			//cout << ans;
		}
		ans -= increment;
		increment = increment/10;
		//cout << "exit increment \n";
	}
	return ans;
}

int main()
{
	int n,decimalPlaces;
	cin >> n >> decimalPlaces;
	cout << findSqrt(n,decimalPlaces);
}