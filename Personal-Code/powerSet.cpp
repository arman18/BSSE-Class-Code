#include<iostream>
#include<string>
#include<queue>
using namespace std;
 queue<string> q;

void powerSet(string s)
{
	string st,temp;
	char ch;
	int pos;
  do
	{
		st=q.front();
		cout<<"{"<<st<<"} ";
		q.pop();
		ch=st[st.length()-1];
		pos=s.find(ch);
		
		for(int i=pos+1;i<s.size();i++) 
		{
			temp=st;
			if(st!="\0") temp+=",";
			temp+=s[i];
			q.push(temp);
		}
		
	} 	while(!q.empty());
	cout<<endl;
}

int main(void)
{
	string s;
 while(cin>>s)
 {
 	 string ss;
 	 ss+=s[0];
 	 q.push("\0");
 	 //cout<<q.front()<<endl;
 	 powerSet(s);
 	 
 }
 
}
