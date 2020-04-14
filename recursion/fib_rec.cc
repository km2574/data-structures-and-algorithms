#include<iostream>
using namespace std;

int fibRec(int n)
{
	if(n==0) return 0;
	if(n==1) return 1;
	int ans = fibRec(n-2) + fibRec(n-1);
	return ans;
}


int main()
{
	int n;
	cout << "Enter the nth fibo no you want to know" << endl;
	cin >> n;
	cout << fibRec(n);
}