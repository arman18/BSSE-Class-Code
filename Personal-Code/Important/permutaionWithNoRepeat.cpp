#include<bits/stdc++.h>
using namespace std;

int main(void)
{
 int n,pos=2;
 cin>>n;
 char arr[3];
 arr[0]='A';
 arr[1]='B';
 arr[2]='C';
 while(n--)
 {
 	 cout<<arr[0]<<arr[1]<<arr[2]<<endl;
 	 pos=(pos+1)%3;
 	 if(pos==2) pos=(pos+1)%3;
 	 swap(arr[pos],arr[2]);
 }
}

/*
আমরা সর্বদা বামের সংখ্যাটিকে toggle করাব।toggle করার ফলে 
যে corresponding সংখ্যাটি repeat হবে তাকে swap করে নিব।
*/
