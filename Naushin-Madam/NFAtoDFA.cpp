#include<bits/stdc++.h>
using namespace std;
int main(void)
{
	struct mystruct
	{
		int n;
		string s[2];
	};
	queue<string> q1,q2;
	map<string,mystruct> mp;
	string str,str0,str1,temp,strch;
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>str>>str0>>str1;
		q1.push(str);
		q2.push(str0);
		q2.push(str1);
		mp[str].n=1;
		mp[str].s[0] = str0;
		mp[str].s[1] = str1;
	}
	while(true)
	{
		if(q2.front()=="\0")
		{
			while(q1.front()!="\0")
	   {
		    str = q1.front();
		    cout<<str<<" "<<mp[str].s[0]<<" "<<mp[str].s[1]<<endl;
		    q1.pop();
   	}
			break;
		}
		str=q2.front();
		q2.pop();
		if(mp[str].n==0)
		{
			q1.push(str);
			
			for(int i=0;i<2;i++)
			{
				
				for(int j=0;j<str.length();j++)
				{
					strch = str[j];
					if(mp[strch].n)
					{
						
						temp=mp[strch].s[i];
						for(int k=0;k<temp.length();k++)
						{
							if(mp[str].s[i].find(temp[k])==std::string::npos)
							mp[str].s[i] += temp[k];
						}
					}
				}
				q2.push(mp[str].s[i]);
				
			}
				mp[str].n=1;
			
		}
		
	}
	
	
}
