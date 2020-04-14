#include<iostream>
using namespace std;
class Node{
public:
	int data;
	Node* next = NULL;
	Node(int d)
	{
		data = d;
	}
};

Node* createLL()
{
	Node* head = NULL;
	Node* tail = NULL;
	int x;
	while(1)
	{
		cin >> x;
		Node* newNode = new Node(x);
		if (x==-1)
		{
			return head;
		}
		if(head == NULL)
		{
			head = newNode;
			tail = newNode;
		}
		else
		{
			tail->next = newNode;
			tail = tail->next;
		}
	}
}

void insertAtTail(Node*& head,int data)
{
	Node* newNode = new Node(data);
	if(head == NULL)
	{
		head = newNode;
	}
	Node* tail = head;
	while(tail->next != NULL)
	{
		tail = tail->next;
	}
	tail->next = newNode;
	tail->next->next = head->next->next->next->next;
}

void insertAtHead(Node*& head,int data)
{
	Node* newNode = new Node(data);
	newNode->next = head;
	head = newNode;
}

int lengthLL(Node* head)
{
	if(head == NULL) return 0;
	return 1+lengthLL(head->next);
}

void insertAtKthPos(Node* &head,int data,int k)
{
	Node* newNode= new Node(data);
	if(k== 0 ||head == NULL)
	{
		head = newNode;
	}
	else if(k >= lengthLL(head))
	{
		insertAtTail(head,data);
	}
	else{
		//insert at Kth pos
		Node* temp = head;
		int jump =1;
		while(jump<k)
		{
			temp = temp->next;
			jump +=1;
		}
		newNode->next = temp->next;
		temp -> next =  newNode;
	}
}
void deleteHead(Node* &head)
{
	Node* temp = head;
	head = head->next;
	delete temp;
}


void deleteTail(Node*& head)
{
	Node* prev = NULL;
	Node* temp = head;;
	while(temp->next != NULL)
	{
		prev = temp;
		temp = temp->next;
	}
	delete temp;
	prev->next = NULL;
}
void printLL(Node* head)
{
	while(head!= NULL)
	{
		cout << head->data << "->";
		head = head->next;
	}
	cout << endl;
}

void deleteKthPos(Node* &head,int k)
{
	Node* temp = head;
	int jump =0;
	while(jump<k)
	{
		temp = temp->next;
		jump +=1;
	}
	Node* del = temp->next;
	temp->next = temp->next->next;
	delete del;
}

int searchINllIterative(Node* head,int element)
{
	int pos = 1;

	while(head->next != NULL)
	{
		if(head->data == element)
		{
			return pos;
		}
		head = head->next;
		pos++;
	}
	return -1;
}

int searchRecursive(Node* head,int element,int pos)
{
	if (head->next== NULL) return -1;
	if(head->data == element) return pos;
	searchRecursive(head->next,element,pos+1);
}

Node* reverseLL(Node*& head)
{
	Node* P = NULL;
	Node* C = head;
	Node* N = C->next;
	while(N!= NULL)
	{
		C->next = P;
		P = C;
		C = N;
		N = N->next; 
	}
	C->next = P;
	return C;
}

Node* reverseRecursive(Node* head,Node* P, Node* C, Node* N)
{
	if(N->next == NULL){
		C->next = P;
		N->next = C;
		return N;
	}
	C->next = P;
	reverseRecursive(head,C,N,N->next);
}

Node* midPointLL(Node* head,Node* slow, Node* fast)
{
	if(fast->next == NULL || fast->next->next == NULL) return slow;
	midPointLL(head,slow->next,fast->next->next);
}

Node* KthElementLast(Node* head,int K)
{
	int jump = 1;
	Node* ans = head;
	while(head->next != NULL)
	{
		head = head->next;
		jump++;
		if(jump>K)
		{
			ans = ans->next;
		}
	}
	return ans;
}

Node* mergeLL(Node*& head1, Node*& head2)
{
	if(head1 == NULL){
		return head2;
	}
	if (head2 == NULL)
	{
		return head1;
	}
	Node* newHead;
	if (head1->data > head2->data)
	{
		newHead = head2;
		newHead->next = mergeLL(head1,head2->next);
	}
	else{
		newHead = head1;
		newHead->next= mergeLL(head1->next,head2);
	}

	return newHead;

}

Node* mergeSort(Node*& head)
{
	//Base case
	if(head==NULL || head->next == NULL) return head;

	//break from mid
	Node* mid = midPointLL(head,head,head);
	Node* a = head;
	Node* b = mid->next;
	mid->next = NULL;

	//sort the smaller LL
	a = mergeSort(a);
	b = mergeSort(b);

	//merge the sorted parts
	Node* c = mergeLL(a,b);

	return c;
}

void sortThisAlgo(int arr[],int n)
{
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0;  j< n; ++j)
		{
			if (arr[j]>arr[j+1])
			{
				swap(arr[j],arr[j+1]);
			}
		}
	}
}

bool cycleDetection(Node* head,Node* slow, Node* fast)
{
	if(fast->next == NULL||fast->next->next == NULL) return false;
	if(slow== fast) return true;
	cycleDetection(head,slow->next,fast->next->next);
	if (ans > ans2)
	{
		cycleDetection(head,slow->next,fast->next->next);
	}

}

void breakCycle(Node*& head)
{
	Node* slow = head;
	Node* fast = head;

	while(slow != fast)
	{
		slow = slow->next;
		fast = fast->next->next;
	}
	slow = head;
	Node* prev = fast;
	while(slow != fast)
	{
		slow = slow->next;
		fast = fast->next->next;
		prev = prev->next;
	}
	prev->next = NULL;

}

int main()
{
	//Node* head = createLL();
	/*Node* head = NULL;
	insertAtHead(head,10);
	insertAtHead(head,9);
	insertAtHead(head,8);
	insertAtTail(head,12);
	insertAtHead(head,7);
	insertAtKthPos(head,11,4);
	deleteHead(head);
	deleteTail(head);
	deleteKthPos(head,4);
	cout << searchRecursive(head,9,1);*/
	//printLL(head);
	
	//printLL(reverseLL(head));
	//Node* newHead = reverseRecursive(head,NULL,head,head->next);
	//printLL(newHead);

	//Node* mid = midPointLL(head,head,head);
	//cout << mid->data;

	//Node* Kthelement = KthElementLast(head,4);
	//cout << Kthelement->data;



	/*Node* newHead;
	Node* head1 = createLL();
	Node* head2 = createLL();
	newHead = mergeLL(head1,head2);
	printLL(newHead);*/

	/*Node* head = createLL();
	head = mergeSort(head);
	printLL(head);*/

	Node* head = createLL();
	insertAtTail(head,17);
	//printLL(head);
	/*Node* slow = head;
	Node* fast = head;
	slow = slow->next;
	fast = fast->next->next;
	if (cycleDetection(head,slow,fast))
	{
		cout << "yes \n";
	}
	else cout << "No";*/

	
	breakCycle(head);
	printLL(head);

	return 0;
	
}