#include<iostream>
#include<stack>
using namespace std;

void printSatck(stack<char> s)
{
	while(!s.empty()){
		cout << s.top();
		s.pop();
	}cout << endl;
}
void transfer(stack<char> &s1, stack<char> &s2)
{
	while(!s2.empty())
	{
		s1.push(s2.top());
		s2.pop();
	}
}

void transferFew(stack<char> &s1, stack<char> &s2,int n)
{
	while(n--)
	{
		s1.push(s2.top());
		s2.pop();
	}
}

void insertAtBottom(stack<char> &s,char temp)
{
	if (s.empty())
	{
		s.push(temp);
		return;
	}

	char temp2 = s.top();
	s.pop();
	insertAtBottom(s,temp);
	s.push(temp2);
}

void reverseRecursive(stack<char> &s)
{
	if (s.empty()) return;
	char temp = s.top();
	s.pop();
	reverseRecursive(s);
	insertAtBottom(s,temp);

}


int main()
{
	stack<char> s;
	for (int i = 65; i < 71; ++i)
	{
		s.push(i);
	}
	printSatck(s);
	//using two stacks
	/*stack<char> s1,s2;
	transfer(s1,s);
	transfer(s2,s1);
	transfer(s,s2);
	printSatck(s);*/

	// using 1 stack
	/*printSatck(s);
	stack<char> s1;
	int count = s.size();
	while(count--)
	{
		//cout << count << endl;
		char temp = s.top();
		s.pop();
		transferFew(s1,s,count);
		s.push(temp);
		transfer(s,s1);
	}
	printSatck(s);*/

	//reverse recursive
	reverseRecursive(s);
	printSatck(s);
}