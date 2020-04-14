#include<iostream>
using namespace std;

int pow(int a,int b)
{
	if(b==0) return 1;
	return a*Fpow(a,b-1);
}

int Fpow(int a,int b)
{
	int smallerPow = Fpow(a,b/2);
	smallerPow *= smallerPow;

	if ()
	 {
	 	/* code */
	 } 
}


int main()
{
	int a, b;
	cin >> a >> b;
	cout << pow(a,b);
}