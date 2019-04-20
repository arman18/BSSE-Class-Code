#include <iostream>
using namespace std;
int fun(int left,int right,int *arr)
{
	if(left>=right) return 0;
	int index=left;
	for(int i=left;i<=right;i++)
	{
		if(arr[i]<arr[right]) 
		{
			swap(arr[index],arr[i]);
			index++;
		}
	}
	swap(arr[index],arr[right]);
	fun(left,index-1,arr);
	fun(index+1,right,arr);
}

int main (void)
{
	int n;
	cin>>n;
	int arr[n];
	for (int i=0;i<n;i++) cin>>arr[i];
	fun(0,n-1,arr);
	for (int i=0;i<n;i++) cout<<arr[i]<<" ";
	cout<<endl;
}
