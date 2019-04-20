#include <bits/stdc++.h>

using namespace std;

void upcase (string &s)
{

for (int i=0;i<s.length();i++) if (s[i]>='a' && s[i]<='z') s[i]=s[i] & 95;
	
}

void lowcase(string &s)
{
	for (int i=0;i<s.length();i++) if (s[i]>='A' && s[i]<='Z') s[i]=s[i] | 32;

}

int main (void)

{
	string s;
	cout<<"enter a string: ";
	getline(cin,s);

	cout<<"what do u want to do?\n1) all upper case.\n2) all lower case.\n";
	int n;
	cin>>n;
	
	
	if (n==1) upcase(s);
	else lowcase(s);
	cout<<"result is: "<<s<<endl;
	return 0;
}
