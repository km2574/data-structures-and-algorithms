#include<iostream>
#include<algorithm>

using namespace std;

bool myComparator(pair<string,int> p1, pair<string,int> p2)
{
    //if both have same salary
    if(p1.second == p2.second)
    {
        return p1.first<p2.first;
    }

    //if both have different salary
    return p1.second>p2.second;
}


int main()
{
    int thresHold, numberOfPairs;
    cin >> thresHold >> numberOfPairs;
    pair<string,int> empData[100005];


    string empName;
    int salary;

    //input data
    for(int i= 0;i < numberOfPairs;i++)
    {
        cin >> empName;
        cin >> salary;
        empData[i].first = empName;
        empData[i].second = salary;
    }

    sort(empData,empData+numberOfPairs,myComparator);
    
    //output data
    for(int k = 0;k<numberOfPairs;k++)
    {
        if(empData[k].second>= thresHold)
        {
            cout << empData[k].first << " ";
            cout << empData[k].second << "\n";
        }
    }

    return 0;
}