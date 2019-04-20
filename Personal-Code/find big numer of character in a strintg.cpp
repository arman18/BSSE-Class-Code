/* firest of all we have to sort our string .... then we have to count the frequency of each character and we also have to find the big frequency */

#include <bits/stdc++.h>

using namespace std;

void srt(string &s) // *s amon hoi nah..!!
{
	int n;
	n=s.length()-1;
	for (int i=0;i<n;i++)
	{
		for (int j=0;j<n-i;j++)
		{
			if (s[j]>s[j+1]) swap (s[j],s[j+1]);
		}
	
	}
	
}

int find_big(string &s)
{
	int cnt=1,big=1;
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

int main (void)
{
	string s;
	
	cin>>s;
	
	srt(s);
	
	int big;
	
	big=find_big(s);
	
	cout<<big<<endl;
	
	return 0;
}
