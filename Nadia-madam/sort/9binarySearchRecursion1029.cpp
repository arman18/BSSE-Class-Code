#include <bits/stdc++.h>
using namespace std;
int search(int *arr,int low,int high,int c)
{
    if (low >high) return 0;
	int mid =(low+high)/2;
	
	
	if (arr[mid]==c) 
	{
		cout<<"yes "<<c<<" exist"<<endl;
		return 1;
	}
	
	else if(c>arr[mid] ) search(arr,mid+1,high,c);
	else if(c<arr[mid+low]) search (arr,low,mid-1,c);
	 
}

int main (void)

{
	int n;
	cin>>n;
	int arr[n];
	for (int i=0;i<n;i++) cin >>arr[i];
	sort(arr,arr+n);
	int c;
	while(cin>>c) 
	{
	int p=search(arr,0,n-1,c);
	if (p==0) cout<<"No "<<c<<" doesn't exist"<<endl;;
	}
}
