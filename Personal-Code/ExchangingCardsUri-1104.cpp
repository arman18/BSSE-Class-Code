#include <bits/stdc++.h>
using namespace std;
bool binarySearch(int* arr,int l,int r,int value)
{
	int mid=(l+r)/2;
	if (l>r) return true;
	else if (arr[mid]==value) return false;
	else if (arr[mid]<value) return binarySearch(arr,mid+1,r,value);
 else return binarySearch(arr,l,mid-1,value);
}
int main(void)
{
	int m,n;
	while(cin>>m>>n && m && n)
	{
		int arr1[m],arr2[n],p=1,q=1,r=0;
		cin>>arr1[0];
		for (int i=1;i<m;i++)
		{
			cin>>arr1[p];
			if(arr1[p]!=arr1[p-1]) p++;
			
		}
		cin>>arr2[0];
		for(int i=1;i<n;i++)
		{
			cin>>arr2[q];
			if(arr2[q]!=arr2[q-1]) q++;
		}
		int mini=min(p,q);
		if(p==mini)
		for (int i=0;i<p;i++)
		{
			if (binarySearch(arr2,0,q-1,arr1[i])) r++;
		}
		else
		{
			for (int i=0;i<q;i++) 
			{
				if (binarySearch(arr1,0,p-1,arr2[i])) r++;
			}
		}
		
		cout <<r<<endl;
	 
	}
	
}
/* 
 input: 
        10 9
  1 1 2 3 5 7 8 8 9 15
  2 2 2 3 4 6 10 11 11
process:
  take as (its highly nessesary!!because of identifying minimum)
      arr1= 1 2 3 5 7 8 9 15
      arr2= 2 3 4 6 10 11
  Tnen select arr2 (because length of arr2 is minimum)
  and count those element that are not common with arr1;
  that are :
             4 6 10 11
output: 4
   (minimum 4 card the two people can exchange without repeating same card)

*/
