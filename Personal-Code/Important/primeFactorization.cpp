#include<bits/stdc++.h>
using namespace std;
queue<int> factor;
map<int,int> power;

void factorization(int n)
{
	int i,m=sqrt(n);
	for(i=2;i<=m;i++)
	{
		if(n%i==0) 
		{
			if(power[i]==0) factor.push(i);
			power[i]++;
			factorization(n/i);
			break;
		}
	}
	if(i>m) 
	{
		if(power[n]==0)
		{
			power[n]++;
			factor.push(n);
		}
		power[n]++;
	}
}

int main(void)
{
	int n;
	while(cin>>n)
	{
		factorization(n);
		while(!factor.empty())
		{
			cout<<factor.front()<<" ";
			if(power[factor.front()]>1) cout<<"("<<power[factor.front()]<<")"<<" ";
			power[factor.front()]=0;
			factor.pop();
		}
		cout<<endl;
	}
}
