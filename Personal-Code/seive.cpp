#include<bits/stdc++.h>
using namespace std;
bool markedAsPrime[109999999];
/*
dinamic করলে 
bool *arr =new bool[3,000,000,000]
পর্যন্ত করা যায়।
তবে 
int *arr =new int[7,000,000,00]
int arr[8,000,000,00]
পর্যন্ত করতে দেয়।
*/
int total=0;
void seive(int n,int m)//এখানে n  একটি মৌলিক সংখ্যা
{
		if(n>m) return;
		total++;
		for(int j=n*n;j<109999999;j+=2*n) markedAsPrime[j] = 1;
		for(int i=n+2;i<=m;i+=2)
	{
		if(!markedAsPrime[i]) 
		{
			seive(i,m);
			break;
		}
	}
}

bool check(int n)
{
	if(n%2==0) return markedAsPrime[n];
	else return! markedAsPrime[n];
}

int main(void)
{
 markedAsPrime[2]=1;
 markedAsPrime[1]=1;
 int n;
 seive(3,sqrt(109999999));
 cout<<total<<endl;
 while(cin>>n)
 {
 	 if(check(n)) cout<<n<<" is prime"<<endl;
 	 else cout<<n<<" is not prime"<<endl;
 }
}
