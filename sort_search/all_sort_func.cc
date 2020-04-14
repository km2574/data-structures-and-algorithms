#include<iostream>
using namespace std;
void swap(int *xp, int *yp)  
{  
    int temp = *xp;  
    *xp = *yp;  
    *yp = temp;  
}

void inputArray(int array[],int n)
{
	for (int i = 0; i < n; ++i)
	{		
		cin >> array[i];
	}
}

void outputArray(int array[],int n)
{
	for (int i = 0; i < n; ++i)
	{
		cout << array[i] << " ";
	}
	cout << "\n";
}
void bubbleSortr(int array[],int n)
{
	for (int i = 0; i < n-1; ++i)
	{
		for (int j = 0; j < n-1-i; ++j)
		{
			if (array[j]>array[j+1])
			{
				swap(&array[j],&array[j+1]);
			}
		}
	}
}


void selectionSort(int array[],int n)
{
	for (int i = 0; i < n-1; ++i)
	{
		int minIndex = i;
		for (int j = i-1; j < n ; ++j)
		{
			if (array[minIndex]>array[j])
			{
				minIndex = j;
			}
		}
		swap(&array[minIndex],&array[i]);
		outputArray(array,n);

	}
}


void insertionSort(int array[],int n)
{
	int j,i;
	for (i = 1; i < n ; ++i)
	{
		int number = array[i];
		for (j = i-1; j >= 0 && number < array[j] ; --j)
		{
			array[j+1] = array[j];
		}
		//insert the number
		array[j+1] = number;
	}
}

void waveSort(int array[],int n)
{
	for (int i = 0; i < n; i+=2)
	{
		//check left
		if (i>0 && array[i-i] > array[i])
		{
			swap(array[i-1],array[i]);
		}
		//check right
		if (i<n-1 && array[i+1]>array[i])
		{
			swap(array[i+1],array[i]);
		}
	}
}



int main()
{
	int array[100],n;
	cin >> n;
	inputArray(array,n);
	// bubbleSortr(array,n);
	//selectionSort(array,n);
	//insertionSort(array,n);
	waveSort(array,n);
	outputArray(array,n);
	return 0;
}