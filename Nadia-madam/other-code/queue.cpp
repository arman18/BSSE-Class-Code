#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
int front=0,tail=0,accsValue=0,element;
int *arr;
void enqueue()
{
	if(front==tail && accsValue)
	{
		cout<<"queue is full"<<endl;
		return;
	}
	int item;
	cout<<"value: ";
	cin>>item;
	arr[front]=item;
	front=(front+1)%element;
	accsValue=1;
}
void dequeue()
{
	if(front==tail && accsValue==0)
	{
		cout<<"queue is emti\n";
		return;
	}
	cout<<"element is: "<<arr[tail]<<endl;
	tail=(tail+1)%element;
	accsValue=0;
}
int main(void)
{
 cout<<"how many element: ";

 cin>>element;
 arr = new int[element];
	while(true)
	{
		cout<<"1)enqueue\n2)dequeue\nchoose: ";
		int n;
		cin>>n;
		if(n==1) enqueue();
		else dequeue();
		
	}
	return 0;
}
