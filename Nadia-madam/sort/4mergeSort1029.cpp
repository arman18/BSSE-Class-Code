#include <iostream>
using namespace std;
void devide(int left,int right,int *arr)
{
	int length=(right-left+1);
	if(length==1) return;
	int nl=length/2,nr=length-nl;
	int leftArr[nl],rightArr[nr];
	for(int i=0;i<nl;i++) leftArr[i]=arr[left+i];

	for(int i=0;i<nr;i++) rightArr[i]=arr[left+i+nl];	


	devide(0,nl-1,leftArr);
	devide(0,nr-1,rightArr);
	int i=0,j=0,pos=left;
	while(i<nl && j<nr)
	{
		if(leftArr[i]<=rightArr[j])
		{
			arr[pos]=leftArr[i];
			i++;
			pos++;
		}
		else
		{
			arr[pos]=rightArr[j];
			j++;
			pos++;
		}
	}
	while(i<nl)
	{
		arr[pos]=leftArr[i];
		i++;
		pos++;
	}
	while(j<nr)
	{
		arr[pos]=rightArr[j];
		j++;
		pos++;
	}
}

int main (void)
{
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++) cin>>arr[i];
	devide(0,n-1,arr);
	for(int i=0;i<n;i++) cout<<arr[i]<<" ";
	cout<<endl;
}
