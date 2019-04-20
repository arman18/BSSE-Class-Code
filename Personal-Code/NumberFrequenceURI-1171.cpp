#include<iostream>
using namespace std;

int main (void)
{
  int n,maximum=0,arr[80000],input;
  cin>>n;
  while(n--)
  {
  	 cin>>input;
  	 arr[input]++;
  	 if(maximum<input) maximum=input;
  }
  for(int i=0;i<=maximum;i++)
  {
  	if(arr[i]) cout<<i<<" aparece "<<arr[i]<<" vez(es)"<<endl;
  }
  
	return 0;
}
