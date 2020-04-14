#include<iostream>
using namespace std;
int main()
{
	char arr[50],rot;
	cin >> arr;
	cin >> rot;
	int len = strlen(arr);

	for (int k = len-1; k>=0; --k)
	{
		arr[k+rot] = arr[k];
	}
	
	cout << arr << " moved";

	for (int i = rot-1; i>=0; --i)
	{
		arr[i] = arr[len+i];
		cout << arr[i];
	}
	arr[len] = '\0';
	cout << arr << " rotated";
}