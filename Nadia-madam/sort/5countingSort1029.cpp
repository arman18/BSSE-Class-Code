#include<iostream>
using namespace std;

int main (void)
{
	int n;
	cin>>n;
	int arr[100000]={0},maxNumber=0;
	for (int i=0;i<n;i++) 
	{
		int input;
		cin>>input;
		if(input>=0 && input<100000)
		{
			if (maxNumber<input) maxNumber=input;
			arr[input]+=1;
		}
	}
	for (int i=0;i<=maxNumber;i++)
	{
		
   		for(int j=0;j<arr[i];j++) cout<<i<<" ";
	}
	cout<<endl;
	
}

