#include <iostream>
using namespace std;

int flag = 0;

struct mystruct
{
	int value;
	mystruct *parent;
	mystruct *left;
	mystruct *right;
};
mystruct *root=NULL;
mystruct *currentLevelNode;
mystruct *storeLeftCurrentLevelNode;

mystruct* createNode(int value)
{
	
	
	mystruct* node=new mystruct;
	node->value = value;
	node->parent = NULL;
	node->left = NULL;
	node->right = NULL;
	return node;
}


void putValueInRightPosition(mystruct *currentNode)
{
	
	while(currentNode->value < currentNode->parent->value)
	{
		swap(currentNode->value,currentNode->parent->value);
		currentNode = currentNode->parent;
		if (currentNode->parent==NULL ) return;
	}
}

void constructingMinHeap()
{
	int value;
	
	cout<<"input value. terminate input will be 0: ";
	while(cin>>value && value)
	{

	mystruct* node = createNode(value);
	if(root==NULL)
	{
		root = node;
		currentLevelNode = root;
		continue;
	}
	
	if(currentLevelNode == root)
	{
		root->left = node;
		node->parent = root;
		currentLevelNode = node;
		storeLeftCurrentLevelNode = currentLevelNode;
		putValueInRightPosition(currentLevelNode);
		continue;
	}
	flag = 0;
	while(currentLevelNode==currentLevelNode->parent->right) 
	{
		
		currentLevelNode = currentLevelNode->parent;
		if(currentLevelNode==root)
		{
			currentLevelNode = storeLeftCurrentLevelNode;
			currentLevelNode->left = node;
			node->parent = currentLevelNode;
			currentLevelNode = node;
			putValueInRightPosition(currentLevelNode);
			storeLeftCurrentLevelNode = currentLevelNode;
			flag =1;
		}
	}
	if(flag) continue;
	
	currentLevelNode = currentLevelNode->parent;
	
	if(currentLevelNode->right == NULL)
	{
		currentLevelNode->right = node;
		node->parent = currentLevelNode;
		currentLevelNode = node;
		putValueInRightPosition(currentLevelNode);
		continue;
	}
	currentLevelNode = currentLevelNode->right;
	while(currentLevelNode->left!=NULL) 
	{
		currentLevelNode = currentLevelNode->left;
	}
	currentLevelNode->left = node;
	node->parent = currentLevelNode;
	currentLevelNode = node;
	putValueInRightPosition(currentLevelNode);
	
  }
	
	
}


void fixTree(mystruct* currentNode)
{
	if(currentNode->left==NULL && currentNode->right==NULL) 
	{
		if(currentNode->parent->left==currentNode) 
		{
			currentNode->parent->left=NULL;
			return;
		}
		else
		{
			currentNode->parent->right=NULL;
			return;
		}
	}
	if(currentNode->left==NULL)
	{
		currentNode->value=currentNode->right->value;
		currentNode->right=NULL;
		return;
	}
	if(currentNode->right==NULL)
	{
		currentNode->value=currentNode->left->value;
		currentNode->left=NULL;
		return;
	}
	if(currentNode->left->value < currentNode->right->value)
	{
		currentNode->value = currentNode->left->value;
		fixTree(currentNode->left);
	}
	else
	{
		currentNode->value = currentNode->right->value;
		fixTree(currentNode->right);
	}
}

void ascendingOrder()
{
	cout<<"output: ";
	mystruct *current=root;
	while(current!=NULL)
	{
		cout<<current->value<<" ";
		if(current->left==NULL && current->right==NULL) 
		{
			cout<<endl;
			return;
		}
		if(current->left==NULL) 
		{
			swap(current->value ,current->right->value);
			fixTree(current->right);
			continue;
		}
		else if(current->right==NULL)
		{
			swap(current->value ,current->left->value);
			fixTree(current->left);
			continue;
		}
		if(current->left->value < current->right->value)
		{
			swap(current->value ,current->left->value);
			fixTree(current->left);
			
		}
		else
		{
			swap(current->value ,current->right->value);
			fixTree(current->right);
		}
	}
	cout<<endl;
}

void inOrder(mystruct* currentNode)
{
	if(currentNode==NULL) 
	{
		cout<<endl;
		return;
	}
	inOrder(currentNode->left);
	cout<<currentNode->value<<" ";
	inOrder(currentNode->right);
}

int main(void)
{
	while(true)
	{
		cout<<"1)input\n2) print ascending order\n3)inorder\n";
		int n;
		cout<<"choose: ";
		cin>>n;
		if(n==1) constructingMinHeap();
		else if(n==2) ascendingOrder();
		else if(n==3) inOrder(root);
		else return 0;
		
	}
}
