#include<bits/stdc++.h>
#include<map>
using namespace std;
map<char,int> mp;

int decimal(string num,string base)
{
	int total=0,bs,len = num.length(),pw=0;
	if(base=="hex") bs = 16;
	else if (base=="oct") bs = 8;
	else if(base=="bin") bs = 2;
	else if(base=="dec") bs = 10;
	for (int i= len-1;i>=0;i--) total += mp[num[i]]*pow(bs,pw++);
	return total;
}

string convert(string num,string from,string to)
{
	int devisor,dec,remain;
	if(to=="hex") devisor = 16;
	else if(to=="bin") devisor = 2;
	else if(to=="dec") devisor = 10;
	else if(to=="oct") devisor = 8;
	to.erase();
	dec = decimal(num,from);
	while(dec)
	{
		remain = dec % devisor;
		for ( auto &i : mp)
		{
			if(i.second==remain)
			{
				to.insert(0,1,i.first);
				break;
			}
		}
		dec = dec / devisor;

	}
	return to;
}
int main(void)
{
mp['0'] = 0; mp['1'] = 1; mp['2'] = 2;
mp['3'] = 3; mp['4'] = 4; mp['5'] = 5;
mp['6'] = 6; mp['7'] = 7; mp['8'] = 8;
mp['9'] = 9; mp['a'] = 10; mp['b'] = 11;
mp['c'] = 12; mp['d'] = 13; mp['e'] = 14;
mp['f'] = 15;

	string num,base;
	
	int t;
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		cout<<"Case "<<i<<':'<<endl;
		cin>>num>>base;
		if(base=="dec")
		{
			cout<<convert(num,"dec","hex")<<" hex"<<endl;
			cout<<convert(num,"dec","bin")<<" bin"<<endl;
		}
		else if(base=="bin")
		{
			cout<<decimal(num,"bin")<<" dec"<<endl;
			cout<<convert(num,"bin","hex")<<" hex"<<endl;
		}
		else if(base=="hex")
		{
			cout<<decimal(num,"hex")<<" dec"<<endl;
			cout<<convert(num,"hex","bin")<<" bin"<<endl;
		}
		cout<<endl;
	}
}
