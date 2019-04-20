#include <iostream>
#include <algorithm>

using namespace std;

int main(void)
{
	int n;
	cin>>n;
	int arr[n],left=0,right=n-1;
	for (int i=0;i<n;i++) cin>>arr[i];
	int value;
	cin>>value;
	sort(arr,arr+n);
	while(left<=right)
	{
		int mid=(left+right)/2;
		if(arr[mid]==value) 
		{
			cout<<"Yes "<<value<<" exist"<<endl;
			return 0;
		}
		else if(arr[mid]<value) left=mid+1;
		else right=mid-1; 
	}
	cout<<value<<" doesn't exist"<<endl;
	return 0;
}
