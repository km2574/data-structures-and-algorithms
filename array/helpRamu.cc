#include<iostream>
#include<algorithm>
using namespace std;
int cars , rick;

void takeCostInput(int Cost[])
{
	for (int i = 0; i < 4; ++i)
	{
		cin >> Cost[i];
	}
}
void printArrayRev(int arr[],int n)
{
	for (int i = n-1; i>=0; --i)
	{
		cout << arr[i] << "\n";
	}
	//cout << "\n";
}
void inputArray(int arr[],int n)
{
	for (int i = 0; i < n; ++i)
	{
		cin >> arr[i];
	}
}
void takeNosOfCarsRick(int Carfreq[],int Rickfreq[])
{
	cin >> rick;
	//cout << "rick :"<< rick<< "\n";
	cin >> cars;
	//cout << "cars :"<< cars<< "\n";

	inputArray(Rickfreq,rick);
	inputArray(Carfreq,cars);
}

int minRikshaw(int Rickfreq[],int Cost[])
{
	//cout <<  rick <<" fn called rick \n";
	int ans=0;
	for (int i = 0; i < rick; ++i)
	{
		ans = ans+min(Cost[0]*Rickfreq[i],Cost[1]);
		//cout << " adding min to ricck : \n";
	}
	int rickMinVal = min(ans,Cost[2]);
	//cout <<"rickMinVal :"<< rickMinVal;
	return rickMinVal;
}
int minCab(int Carfreq[],int Cost[])
{
	//cout << " fn called  cars \n";
	int ans= 0;
	for (int i = 0; i < cars; ++i)
	{
		ans = ans+ min(Cost[0]*Carfreq[i],Cost[1]);
		//cout << " adding min to cars : \n";
	}
	int carMinVal = min(Cost[2],ans);
	//cout <<" carMinVal :"<< carMinVal;
	return carMinVal;
}

int tellOptimizedCost(int Cost[],int Carfreq[],int Rickfreq[])
{
	//cout << " fn called \n";
	int ans = minRikshaw(Rickfreq,Cost)+minCab(Carfreq,Cost);
	return min(Cost[3],ans);
}

int main()
{
	int T;
	int Cost[4],Carfreq[10],Rickfreq[10],ans[10];
	cin >> T;
	int copyT = T;
	while(T!=0)
	{
		takeCostInput(Cost);
		takeNosOfCarsRick(Carfreq,Rickfreq);
		ans[T-1] = tellOptimizedCost(Cost,Carfreq,Rickfreq);
		T--;
	}
	printArrayRev(ans,copyT);
}