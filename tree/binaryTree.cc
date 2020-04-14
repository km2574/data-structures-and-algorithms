#include<bits/stdc++.h>
using namespace std;

class node{
public:
	int data;
	node* left;
	node* right;
	node(int d)
	{
		data = d;
		left = NULL;
		right = NULL;
	}
};

node* buildTreePre()
{
	int d;
	cin >> d;

	if(d==-1) return NULL;

	node* root = new node(d);

	root->left = buildTreePre();
	root->right = buildTreePre();

	return root;
}

void print(node* root)
{
	if(root == NULL) return;

	cout << root->data;
	print(root->left);
	print(root->right);
}

void printInorder(node* root)
{
	if(root == NULL) return;

	printInorder(root->left);
	cout << root->data <<" ";
	printInorder(root->right);
}

void printPostOrder(node* root)
{
	if(root == NULL) return;

	printPostOrder(root->left);
	printPostOrder(root->right);
	cout << root->data << " ";
}
/*void inputarr(int arr[],int n)
{
	for (int i = 0; i < n; ++i)
	{
		cin >> arr[i];
	}
}*/

int height(node* root)
{
	if(root == NULL) return 0;

	int ls = height(root->left);
	int rs = height(root->right);

	return max(ls,rs) + 1;
}

void printKthOrder(node* root,int k)
{
	if(root == NULL) return;
	if(k==1){
		cout << root->data << " ";
		return;
	}
	printKthOrder(root->left,k-1);
	printKthOrder(root->right,k-1);
	return;
}

void printAllLevel(node* root)
{
	int H= height(root);
	for (int i = 0; i <= H; ++i)
	{
		printKthOrder(root,i);
		cout << endl;
	}
}


void bfs(node* root)
{
	queue<node*> q;
	q.push(root);
	q.push(NULL);
	while(!q.empty())
	{
		node* temp = q.front();
		if(temp==NULL)
		{
			cout << endl;
			q.pop();
			if(!q.empty())
			{
				q.push(NULL);
			}
		}
		else{
			cout << temp->data << " ";
			q.pop();
			if (temp->left)
			{
				q.push(temp->left);
			}
			if (temp->right)
			{
				q.push(temp->right);
			}
		}
	}
	return;
}


//count of number of nodes
int count(node* root)
{
	if(root == NULL) return 0;
	return 1+ count(root->left) + count(root->right);
}


//sum of all the nodes
int sum(node* root)
{
	if(root == NULL) return 0;
	return root->data+sum(root->left)+sum(root->right);
}

//number of edges => O(n^2)
int diameter(node* root)
{
	if(root == NULL) return 0;

	int lHeigth = height(root->left);
	int RHeigth = height(root->right);

	int op1 = lHeigth + RHeigth;
	int op2 = diameter(root->left);
	int op3 = diameter(root->right);
	return max(op1,max(op2,op3));

}

class PairHB{
public:
	int height;
	bool balanced;
};

PairHB IsHeightBalanced(node* root)
{
	PairHB p;
	if(root == NULL){
		p.height = 0;
		p.balanced = true;
		return p;
	}

	PairHB left = IsHeightBalanced(root->left);
	PairHB right = IsHeightBalanced(root->right);

	p.height = max(left.height,right.height)+1;
	if(abs(left.height-right.height)<=1 && left.balanced && right.balanced)
	{
		p.balanced = true;
	}
	else p.balanced = false;

	return p;
}

//numbe of edges == diameter  of order O(N)
class Pair{
public:
	int height;
	int diameter;
};

Pair fast_dia(node* root)
{
	Pair p;

	if(root == NULL){
		p.height = p.diameter = 0;
		return p;
	}

	Pair left = fast_dia(root->left);
	Pair right = fast_dia(root->right);

	p.height = max(left.height,right.height) + 1;
	p.diameter = max(left.height+right.height,max(left.diameter,right.diameter));
	// cout << p.height << " " << p.diameter << " ok \n";
	return p;
}

//Replce each node by sum of their child node
int replaceSum(node* root)
{
	//if no nodes are present
	if (root == NULL)
	{
		return 0;
	}
	// if it is a leaf node
	if (root->left == NULL && root->right == NULL)
	{
		return root->data;
	}

	int leftSum = replaceSum(root->left);
	int rightSum = replaceSum(root->right);

	int temp = root->data;
	//in current root store its child sum
	root->data = leftSum+rightSum;

	//to previous call return all of its nodes
	return temp +root->data;
}


node* buildBalancedTree(int *arr, int be,int en)
{
	if(be>en) return NULL;
	int mid = (be+en)/2;
	node* root = new node(arr[mid]);
	root->left = buildBalancedTree(arr,be,mid-1);
	root->right = buildBalancedTree(arr,mid+1,en);

	return root;
}

node* createTreeTravel(int *in,int *pre,int s,int e)
{
	static int i = 0;
	if(s>e) return NULL;

	node* root = new node(pre[i]);
	int index = -1;
	for (int j = s; j<=e ; ++j)
	{
		if (in[j]==pre[i])
		{
			index = j;
			break;
		}
	}
	i++;
	root->left = createTreeTravel(in,pre,s,index-1);
	root->right = createTreeTravel(in,pre,index+1,e);
	return root;

}

int main()
{
	//int arr[] = {12,15,82,75,96,65,73,54};
	// int n = sizeof(arr)/sizeof(int);
	//node* root = buildTreePre();
	//cout << height(root) << endl;
	// cout << count(root) << endl;
	// cout << sum(root) << endl;
	//printKthOrder(root,3);
	//printAllLevel(root);
	//bfs(root);

	// cout << endl << diameter(root) << endl;

	//cout << fast_dia(root).height << " height \n";
	// cout << fast_dia(root).diameter << " dia";
	//replaceSum(root);
	/*bfs(root);
	if (IsHeightBalanced(root).balanced)
	{
		cout << "true \n";
	}else cout << "false \n";
	*/
	//node* root = buildBalancedTree(arr,0,n-1);
	int in[] = {3,2,8,4,1,6,7,5};
	int pre[] = {1,2,3,4,8,5,6,7};
	int n = sizeof(in)/sizeof(int);
	node* root = createTreeTravel(in,pre,0,n-1);
	bfs(root);
	return 0;
}