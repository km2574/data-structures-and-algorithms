#include<iostream>
using namespace std;
#define ll long long int


bool configPossible(ll books[],ll n, ll k,ll ans)
{
    int student = 1;
    ll noOfPagesDone =0;
    for(int i = 0;i < n;i++)
    {
        if(noOfPagesDone+books[i] > ans)
        {
            noOfPagesDone = books[i];
            student++;
            if(student>k)
            {
                return false;
            }
        }
        else{
            noOfPagesDone += books[i];
        }
    }
    return true;
}

ll allocate_books(ll books[],ll n,ll k)
{
	if(n<k) return -1;
    ll total_pages = 0;
    for(int i = 0; i< n;i++)
    {
        total_pages += books[i];
    }
    ll be = books[n-1], en = total_pages;
    int finalAns = be;

    while(be<= en)
    {
        ll mid = (be+en)/2;
        if(configPossible(books,n,k,mid))
        {
            //if true look for kore optikized value
            finalAns = mid;
            en = mid-1;
        }
        else{
            // if that value is not possible look for higher values
            be = mid+1;
        }
    }
    return finalAns;
}


int main()
{
    ll books[100];
    ll n=0,k=0;
    cin >> n >> k;

    for (int i = 0; i < n; ++i)
    {
    	cin >> books[i];
    }
   
    cout << allocate_books(books,n,k);
    return 0;
}