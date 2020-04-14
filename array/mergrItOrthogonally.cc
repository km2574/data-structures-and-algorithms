#include<iostream>
using namespace std;
int ans[100];
void inputArr(int arr[],int n)
{
    for(int i= 0;i<n; i++)
    {
        cin >> arr[i];
    }
}

void printArray(int arr[],int n)
{
    for(int i= 0;i<n; i++)
    {
        cout << arr[i] << " ";
    }
}
void doitThen(int a1[],int a2[],int n1,int n2){
    int h1=0,h2=0;
    int i=0;
    for(;i<n1+n2 && n1-1 >= h1 && n2-1 >= h2;i++)
    {
        if(a1[h1]<=a2[h2])
        {
            ans[i]= a1[h1];
            h1++;
        }
        else{
            ans[i] = a2[h2];
            h2++;
        }
    }
    //cout << i << endl;
    //--i;
    
    if(n1-1 <= h1 && h2<=n2-1){
        for(; h2<n2;h2++)
        {
            ans[i] = a2[h2];
            //cout << "\n" << ans[i];
            i++;
        }
        return;
    }
    
    if(n2-1 <= h2 && h1<=n1-1){
        for(; h1<n1;h1++)
        {
            ans[i] = a1[h1];
            //cout << "\n" << ans[i];
            i++;
        }
        return;
    }

}
int main()
{
    int a1[100],a2[100];
    int n1,n2;
    cin >> n1 >> n2;
    inputArr(a1,n1);
    inputArr(a2,n2);
    doitThen(a1,a2,n1,n2);
    printArray(ans,n1+n2);
}