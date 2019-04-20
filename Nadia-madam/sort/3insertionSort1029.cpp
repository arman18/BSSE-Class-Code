#include <iostream>

using namespace std;

int main(void)
{
	int n;
	cin>>n;
	int arr[n];

	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
		int item=arr[i],j;
		j=i-1;
		while(j>=0 && (arr[j]>item))
		{
			arr[j+1]=arr[j];
			j--; 
		}
		arr[j+1]=item;
	}
	for (int i=0;i<n;i++) cout<<arr[i]<<" ";
	cout<<endl;
}
