#include <bits/stdc++.h>
using namespace std;
struct mystruct 
{
	int value;
	mystruct *left;
	mystruct *right;
	
};
mystruct *root=NULL;

mystruct* createNode(int value)
{
	
	
	mystruct* node=new mystruct;
	node->value = value;
	node->left = NULL;
	node->right = NULL;
	return node;
}

void add()
{
	int value;
	
	cout<<"input value. terminate input will be 0: ";
	while(cin>>value && value)
	{

	mystruct* node = createNode(value);
	if(root==NULL)
	{
		root =node;
		continue;
	}
	mystruct *currentNode = root;
	while(true)
	{
		if(value<=currentNode->value)
		{
			if(currentNode->left==NULL)
			{
				currentNode->left=node;
				break;
			}
			currentNode = currentNode->left;
		}
		else
		{
			if(currentNode->right==NULL)
				{
					currentNode->right=node;
					break;
				}
			currentNode = currentNode->right;
		}
	}	
  }
	
	
}

void inOrder(mystruct* currentNode)
{
	if(currentNode==NULL) return;
	inOrder(currentNode->left);
	cout<<currentNode->value<<" ";
	inOrder(currentNode->right);
}

void postOrder(mystruct* currentNode)
{
	if(currentNode==NULL) return;
	postOrder(currentNode->left);
	
	postOrder(currentNode->right);
	cout<<currentNode->value<<" ";
}

void preOrder(mystruct* currentNode)
{
	if(currentNode==NULL) return;
	cout<<currentNode->value<<" ";
	preOrder(currentNode->left);
	
	preOrder(currentNode->right);
	
}

void search()
{
	int element;
	cout<<"input value: ";
	cin>>element;
	mystruct* currentNode=root;
	while(true)
	{
		if(currentNode==NULL)
		{
			cout<<element<<" does not exist!"<<endl;
			return;
		}
		else if(currentNode->value==element)
		{
			cout<<element<<" do exist"<<endl;
			return;
		}
		else if(element<currentNode->value)  currentNode=currentNode->left;
	
		else  currentNode=currentNode->right;
		
	}
}

mystruct* searchForDelete(int value)
{
	
	if(root->value==value) return root;
	mystruct* currentNode=NULL;
	mystruct* temp=root;
	if(root->left!=NULL && value<root->value) currentNode=root->left;
	else if(root->right!=NULL) currentNode=root->right; 
	
	while(true)
	{
		if(currentNode==NULL)
		{
			cout<<value<<" does not exist!"<<endl;
			return NULL;
		}
		else if(currentNode->value==value)
		{
			cout<<value<<" deleted"<<endl;
			return temp;
		}
		else if(value<currentNode->value) 
		{
			 temp = currentNode;
			 currentNode=currentNode->left;
		}
	
		else  
		{
			temp = currentNode;
			currentNode=currentNode->right;
		}
		
	}
}
void deleteNode()
{
	int value;
	cout<<"value: "; 
	cin>>value;
	mystruct* previousNodeToBeDelete = searchForDelete(value);
	if(previousNodeToBeDelete==NULL) 
	{
		cout<<"so node can not be deleted\n";
		return;
	}
	if(value==root->value)
	{
		 if(root->left==NULL && root->right==NULL) root=NULL;
		 else if(root->left==NULL) root=root->right;
		 else if(root->right==NULL) root=root->left;
		 else
		 {
		 	mystruct* temp = root->right;
		 	if(temp->left==NULL && temp->right==NULL)
		 	{
		 		root->value=temp->value;
		 		root->right=NULL;
		 	}
		 	else if(temp->left==NULL)
		 	{
		 		root->value=temp->value;
		 		root->right=temp->right;
		 	}
		 	else
		 	{
			 	while(temp->left->left!=NULL) temp=temp->left;
			 	root->value = temp->left->value;
			 	temp->left=NULL;
		 	}
		 	
		 }
	}
	else
	{
		mystruct* nodeToBeDelete;
		
		if(value < previousNodeToBeDelete->value) nodeToBeDelete = previousNodeToBeDelete->left;
		
		if(value>previousNodeToBeDelete->value) nodeToBeDelete = previousNodeToBeDelete->right;
		
		if(nodeToBeDelete->left==NULL && nodeToBeDelete->right==NULL) 
		{
			if(value< previousNodeToBeDelete->value) previousNodeToBeDelete->left = NULL;
			else previousNodeToBeDelete->right = NULL; 
		}
		else if(nodeToBeDelete->left==NULL)
		{
			if(value< previousNodeToBeDelete->value) previousNodeToBeDelete->left = nodeToBeDelete->right;
			else previousNodeToBeDelete->right = nodeToBeDelete->right;
		}
		else if(nodeToBeDelete->right==NULL)
		{
			if(value< previousNodeToBeDelete->value) previousNodeToBeDelete->left = nodeToBeDelete->left;
			else previousNodeToBeDelete->right = nodeToBeDelete->left;
		}
		else
		{
			mystruct* temp = nodeToBeDelete->right;
			if(temp->left==NULL && temp->right==NULL)
		 	{
		 		nodeToBeDelete->value=temp->value;
		 		nodeToBeDelete->right=NULL;
		 	}
		 	else if(temp->left==NULL)
		 	{
		 		nodeToBeDelete->value=temp->value;
		 		nodeToBeDelete->right=temp->right;
		 	}
		 	else
		 	{
			 	while(temp->left->left!=NULL) temp=temp->left;
			 	nodeToBeDelete->value = temp->left->value;
			 	temp->left=NULL;
		 	}
		}
		
	}
}

int main(void)
{
	while(true)
	{
		cout<<"what do u want to do: "<<endl;
		cout<<"1) add element\n";
		cout<<"2) in order travers\n";
		cout<<"3) post order travers\n";
		cout<<"4) pre order travers\n";
		cout<<"5) search element\n";
		cout<<"6) delete"<<endl;
		int n;
		cin>>n;
		switch(n)
		{
			case 1: add();
			break;
			case 2: 
			{
				inOrder(root);
				cout<<endl;
			}
			break;
			case 3: 
			{
				postOrder(root);
				cout<<endl;
			}
			break;
			case 4: 
			{
				preOrder(root);
				cout<<endl;
			}
			break;
			case 5: search();
			break;
			case 6: deleteNode();
			break;
		}
	}
	return 0;

}

