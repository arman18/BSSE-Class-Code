#include <iostream>

using namespace std;

int *prepend (int *arr,int &csize,int &size)
{
	int value;
	cout<<"Give value: ";
	cin>>value;
	csize+=1;
	
	if(csize > size) 
	{
		
		int *brr;
		
		brr = new int[size*2];
		size=size*2;
		for (int i=csize-1; i>0; i--) brr[i] = arr[i-1];
		
		delete [] arr;
		
		brr[0] = value; 
		
		return brr;
	}
	
	for (int i=csize-1; i>0; i--) arr[i] = arr[i-1];
	
	arr[0] = value;
		
	
}

int *printArr (int *arr,int csize,int size)

{
	cout<<"Total arr size is: "<<size<<endl;
	for (int i=0;i<csize;i++) cout<<arr[i]<<" ";
	cout<<endl;
}

int *shrink (int *arr,int &csize ,int &size)
{
	int *brr =new int[size/2];
	
	size =size/2;
	
	
	if (csize>size) csize =size;
	
	for(int i=0;i<csize;i++) brr[i] =arr[i];
	
	delete [] arr;
	
	return brr;
}

int main (void)
{
	cout<<"give five integer: ";
	int csize=5,*arr,size=5;
	arr = new int[5];
	for (int i=0; i<5; i++) cin>>arr[i];
	int choice;
	cout<<"your choice:\n\n1)Prepend and enlarge\n2)shrink\n3)Print\n";
	
	while(cin>>choice && choice)
	{
		switch (choice)
		{
			case 1: arr =prepend(arr,csize,size);
			break;
			case 2: arr =shrink(arr,csize,size);
			break;
			case 3: printArr(arr,csize,size);
			break;
		}
		cout<<"your choice:\n\n1)Prepend and enlarge\n2)shrink\n3)Print\n";	
		
		
	}
	
}
