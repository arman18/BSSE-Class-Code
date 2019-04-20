#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int gcde(int n1,int n2)
{
	int temp;
	while(n1%n2)
	{
		temp = n2;
		n2 = n1%n2;
		n1 = temp;
	}
	return n2;
}
int ncr(int n,int r)
{
	queue<int> q;
	if(r>=n/2) r=n-r;
	int i,value,temp,gcd;
	for(i=n-r+1;i<=n;i++) q.push(i);
	for(i=2;i<=r;i++)
	{
		temp = i;
		while(temp!=1)
		{
			value = q.front();
			q.pop();
			gcd = gcde(value,temp);
		  value = value/gcd;
		  temp = temp/gcd;
			if(value!=1) q.push(value);
		}
		
	}
	value = 1;
	while(!q.empty())
	{
		value*= q.front();
		q.pop();
	}
	return value;
}
int main(void)
{
	int n,r;
	while(true)
	{
		cin>>n>>r;
		cout<<ncr(n,r)<<endl;
	}
}
