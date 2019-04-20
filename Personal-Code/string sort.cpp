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




int main (void)
{
	string s;
	cout<<"give a string: ";
	
	getline(cin,s);
	
	srt(s);
	
	cout<<"after sorting: "<<s<<endl;	
	
}
