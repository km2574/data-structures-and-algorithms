#include<iostream>
using namespace std;

void inputArray(int array[],int n)
{
	for (int i = 0; i < n; ++i)
	{
		cin >> array[i];
	}
}

int findPivote(int array[],int n)
{
	int be = 0, en = n-1;
	int mid = be+en/2;
	while(be<=en){
		mid = be+en/2;
		if (array[mid]<array[mid-1])
		{
			return mid-1;
		}
		else if(array[mid]>array[mid+1]){
			return mid;
		}
		else if(array[mid]> array[en])
		{
			be = mid+1;
		}
		else{
			en = mid-1;
		}
	}
}
int main()
{
	int array[100],n;
	cin >> n;
	inputArray(array,n);
	cout << findPivote(array,n);
	return 0;
}