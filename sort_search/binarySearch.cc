#include<iostream>
using namespace std;

void inputArray(int array[],int n)
{
    for(int i = 0;i<n;i++)
    {
        cin >> array[i];
        //cout << i <<"th no entered \n";
    }
}
int binarySearch(int array[],int n,int key)
{
    int s = 0;
    int e = n-1;
    int mid = (s+e)/2;
    while(s<=e)
    {
        mid = (s+e)/2;
        if(array[mid]== key){
            //Key found
            return mid;
        }
        else if(array[mid]>key){

            //key is on left
            e = mid-1;
        }
        else{
            //key is on right
            s = mid+1;
        }
    }
    //key not found
    return -1;
}
int lowerBond(int array[],int n,int key)
{
    int s = 0,ans=-1;
    int e = n-1;
    int mid = (s+e)/2;
    while(s<=e)
    {
        mid = (s+e)/2;
        if(array[mid]== key){
            //Key found
            //return mid;
            ans = mid;
            //for lower bond
            e = mid -1;
        }
        else if(array[mid]>key){

            //key is on left
            e = mid-1;
        }
        else{
            //key is on right
            s = mid+1;
        }
    }
    //key not found
    return ans;
}

int upperBond(int array[],int n,int key)
{
    int s = 0,ans=-1;
    int e = n-1;
    int mid = (s+e)/2;
    while(s<=e)
    {
        mid = (s+e)/2;
        if(array[mid]== key){
            //Key found
            //return mid;
            ans = mid;
            //for upper bond
            s = mid+1;
        }
        else if(array[mid]>key){

            //key is on left
            e = mid-1;
        }
        else{
            //key is on right
            s = mid+1;
        }
    }
    //key not found
    return ans;
}


int main()
{
    int array[100],n,key;
    cin >> n >> key;
    inputArray(array,n);
    //cout <<"input done";
    //int ans = binarySearch(array,n,key);
    /*if(ans == -1)
    {
        cout << "--------------Key not present---------------";
    }
    else{
        cout <<"Key location: "<< ans;
    }*/
    cout << "lower :" << lowerBond(array,n,key) << endl;
    cout << "upper :" << upperBond(array,n,key) << endl;
    return 0;
}