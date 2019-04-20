#include <bits/stdc++.h>
using namespace std;
int t=0,height;
void findMin(int *arr,int l,int r)
{
	int p=1;
  while(p)
  {
  	p=0;
  	for (int i=r;i>=l;i--)
  	{
  		if(arr[i]<height) 
  		{
  			arr[i]++;
  			p=1;
  		}
  		else if(arr[i]==height && i!=l && i!=r)
  		{
  			if (p) t++;
  			else 
  			{
  				r = i-1;
  				continue;
  			}
  			p=0;
  			findMin(arr,i+1,r);
  			r = i-1;
  		}
  		if(p && i==l) t++;
  	}
  }
}

int main(void)
{
	int length;
	while(cin>>height>>length && height && length)
	{
		int arr[length];
		for(int i=0;i<length;i++) cin>>arr[i];
		findMin(arr,0,length-1);
		cout<<t<<endl;
		t=0;
	}
}

/*
 write a function that can increase the number
  of arrays element thats are low from height. 
  and if we can change any value get reach to 
  left thent count ++;
  
  we also divided our array when we get any element
  that is equal to high between left and right
  (exclusivly). 
 
*/

