#include<iostream>
using namespace std;
 
void countSort(int arr[], int n, int divisor)
{  
	int tempArr[n], i, digit[10] = {0};
 
	for (i = 0; i < n; i++) //count total number of same digit
		digit[(arr[i] / divisor) % 10]++;
 
	for (i = 1; i < 10; i++)  //cumulative
		digit[i] += digit[i-1];
 
	for (i = n - 1; i >= 0; i--) // put main arr to tempArr base on cumulative 
	{
		tempArr[digit[(arr[i] / divisor) % 10] - 1] = arr[i];
		digit[(arr[i] / divisor) % 10]--;
	}
 
	for (i = 0; i < n; i++) //paste temparr to main arr
		arr[i] = tempArr[i];
}
 

int main()
{
	int n, i,maximum=0;
	cin>>n;
 
	int arr[n];
	for(i = 0; i < n; i++)
	{
		cin>>arr[i];
		if (maximum<arr[i]) maximum=arr[i];
	}

	for (int divisor = 1; maximum/divisor > 0; divisor *= 10) countSort(arr, n, divisor);
		
	for (i = 0; i < n; i++) cout<<arr[i]<<" ";
	cout<<endl;
	return 0;
}
