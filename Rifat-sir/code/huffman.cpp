#include <bits/stdc++.h>
using namespace std;

struct mystruct
{
	char ch;
	int totalCh;
	mystruct *sbNext;
	mystruct *left;
	mystruct *right;
	
};

mystruct *root = NULL;
mystruct *sb = NULL;

mystruct* createNode(char ch,int sum)
{
	mystruct *node = new mystruct;
	node->ch = ch;
	node->totalCh= sum;
	node->sbNext = NULL;
	node->left = NULL;
	node->right = NULL;
	return node;
}

bool swap(mystruct *node1,mystruct *node2)
{
	char ch;
	ch = node1->ch;
	node1->ch = node2->ch;
	node2->ch = ch;
	
	int num;
	num = node1->totalCh;
	node1->totalCh = node2->totalCh;
	node2->totalCh = num;
	
	mystruct *temp;
	temp = node1->left;
	node1->left = node2->left;
	node2->left = temp;
	
	temp = node1->right;
	node1->right = node2->right;
	node2->right = temp;
}

bool check(char ch)
{
	mystruct *current = sb;
	
	while(current != NULL)
	{
		if(current->ch == ch)
		{
			current->totalCh++;
			return false;
		}
		current = current->sbNext;
	}
	if(current == NULL) return true;
}

void sort()
{
	int flag = 0;
	mystruct *current = sb;
	mystruct *temp;
	while(current->sbNext!=NULL && flag<2)
	{
		temp = current->sbNext;
		while(temp!=NULL)
		{
			
			if(current->totalCh >= temp->totalCh) swap(current,temp);
			
			temp = temp->sbNext;
			
		}
		current = current->sbNext;
		flag++;
	}
}

void constructTree()
{
	mystruct *current;
	mystruct *node;
	while(sb->sbNext!=NULL)
	{
		current = sb;
		sort();
		
		node = createNode('\0',current->totalCh+current->sbNext->totalCh);
		node->left = current;
		node->right = current->sbNext;
		
		if(current->sbNext->sbNext!=NULL)
		{
			 node->sbNext = current->sbNext->sbNext;
		}
		
		sb = node;
		current->sbNext->sbNext = NULL;
		current->sbNext = NULL;
	}
	root = sb;
	
}

void print(string s,mystruct *current)
{
	
	if(current ==NULL) return ;
	if(current->ch!='\0') cout<<current->ch<< "     "<<current->totalCh<<"    "<<s<<endl;
	print(s+"0",current->left);
	print(s+"1",current->right);
	
	
}

void decode()
{
	char ch;
	mystruct *current = root;
	cout<<"give encripted message in binary: ";
  ch= getchar();
	cout<<"The message is: ";
	while(ch!='\n')
	{
		
		if(ch=='\n') break;

		if(ch=='0' && current->left!= NULL) 
		{
			current = current->left;
		}
		else if(ch=='1' && current->right!=NULL)
		{
			current= current->right;
		}
		if(current->left==NULL && current->right==NULL)
		{
			cout<< current->ch;
			current = root;
		}
		ch=getchar();
	}
	cout<<endl;	
}

bool encode(mystruct *current,char ch,string s)
{
	if(current->left==NULL && current->right==NULL)
	{
		if(current->ch==ch) 
		{
			cout<<s;
			return false;
		}
		else  return true;
	}
	bool bl = encode(current->left,ch,s+'0');
	if(bl) encode(current->right,ch,s+'1');
	
}

int main(void)
{
	string s;
	cout<<"give a string: ";
	char ch;
	ch = getchar();
	while(ch!='\n')
	{
		s+=ch;
		if(check(ch)) 
		{
		
			mystruct *node = createNode(ch , 1);
			if(sb==NULL) sb = node;
			else
			{
				mystruct *current = sb;
				while(current->sbNext!=NULL) current = current->sbNext;
				current->sbNext = node;
			}
		}
		ch = getchar();
	}

	constructTree();
	
	while(true)
	{
	   cout<<"1)print table\n2)decode a message\n3)exit\n";
	   int n;
	   cout<<"choose: ";
	   cin>>n;
	   cout<<endl;
	   if (n==1) 
	   {
	   	  print("code: ",root);
	   	  cout<<"encripted code is: ";
	   	  for(int i=0;i<s.length(); i++) encode(root,s[i],"\0");
	   	  cout<<endl<<endl;
	   }
	   else if(n==2)
	   {
	   	char ch;
	   	ch=getchar();
	   	decode();
	   	cout<<endl;
	   }
	   else return 0;	
	}
}
