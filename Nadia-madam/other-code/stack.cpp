#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
int *arr;
int index=-1,n;
void pop()
{
	if(index==-1)
	{
		cout<<"stack is empty\n";
		return;
	}	

	
	cout<<arr[index]<<endl;
index--;
}
void push()
{

	if(index==n-1)
	{
		cout<<"stack is full"<<endl;
		return;
	}
		index++;
	int item;
	cout<<"input: ";
	
	cin>>item;
	arr[index]=item;
	
}
int main(void)
{
  cout<<"initialize array: ";
  cin>>n;
  arr= new int[n];
	while(true)
	{
			cout<<"1)push\n2)pop\nchoose: ";
			int choose;
			cin>>choose;
			if(choose==1) push();
			else pop();
	}
}
