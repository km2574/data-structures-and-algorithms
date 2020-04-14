#include<iostream>
#include<queue>
using namespace std;
template<typename T>

//push=> O(n) && pop => O(1)
/*class Stack1{
private:
	queue<T> q1, q2;
	int curr_size;
public:
	Stack1()
	{
		curr_size = 0;
	}
	void push(T x)
	{
		//q2 always empty
		q2.push(x);
		curr_size++;
		// empty q1 to q2
		while(!q1.empty())
		{
			q2.push(q1.front());
			q1.pop();
		}
		//to maintain the defenition we will empty q2, so swap q1 and q2
		queue<T> q = q2;
		q2 = q1;
		q1 = q;
	}
	void pop()
	{
		if(q1.empty()) return;
		q1.pop();
		curr_size--;
	}
	T top()
	{
		if(q1.empty()) return -1;
		return q1.front();
	}

	int size()
	{
		return curr_size;
	}

};*/

//push=>O(1) and pop=>O(n)
class Stack2{
	queue<T> q1, q2;
	int curr_size;
public:
	Stack2()
	{
		curr_size = 0;
	}
	//push operation O(1)
	void push(T x)
	{
		q1.push(x);
		curr_size++;
	}
	//pop operation O(n)
	void pop()
	{
		if(q1.empty()) return;
		while(q1.size()>1)
		{
			q2.push(q1.front());
			q1.pop();
		}
		q1.pop();
		curr_size--;
		// to maintain the definition we will empty q2,so will swap q1 n q2

		queue<T> q = q2;
		q1 = q2;
		q2 = q;
	}

	T top()
	{
		if(q1.empty()) return -1;
		return q1.back();
	}

	int size()
	{
		return curr_size;
	}

};

int main()
{
	Stack2<char> s;

	for (int i = 65; i < 71; ++i)
	{
		s.push(i);
	}

	cout << s.size() << endl;

	//cout << s.top()<< endl;
	s.pop();
	s.push(98);
	while(s.size() != 0)
	{
		cout << s.top() << endl;
		s.pop();
	}
}