#include <bits/stdc++.h>

using namespace std;

void st(string &s)
{
	for(int i=0;i<s.length()-1;i++)
	{
		for(int j=0;j<s.length()-1-i;j++)
			if(s[j]>s[j+1]) swap(s[j],s[j+1]);
	}
}

int find_big(string &s)
{
	int big=1,cnt=1;
	for (int i=0;i<s.length();i++)
	{
		
		if (s[i]==s[i+1]) cnt++;
		
		else 
		{
			if (big<cnt) big=cnt;
			cnt=1;
		}
		
	}
	return big;

}

void small(string &s)
{
	for (int i=0;i<s.length();i++) s[i]=s[i] | 32;
	
}


int main (void)

{
	char ch,chh;
	string s,h;
	int t;
	cin>>t;
	getline (cin,h);
	while (t--)
	{
		getline(cin,s);
		
		small(s);
		
		for (int i=0;i<s.length();i++)
		{
			if (s[i]<'a' || s[i]>'z')
			{
				s.erase(i,1);
				i--;
			}
		}
		
		st(s);
		int n,cnt=1;
		n=find_big(s);
		
		for (int i=0;i<s.length();i++)
		{
			if (s[i]==s[i+1]) cnt++;
			else
			{
				if (cnt==n) cout<<s[i];
				cnt=1;
			}
		}
		
		cout<<endl;
		
	}
	
	
	return 0;
}
