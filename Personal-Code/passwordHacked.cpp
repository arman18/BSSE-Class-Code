#include <bits/stdc++.h>
using namespace std;
char ch[3];

struct mystruct
{
	char ch;
	int pos=0;
	
};
int main(void)
{
	ch[0] = 'A';
ch[1] ='B';
ch[2] = 'C';
mystruct arr[3];
arr[0].ch= ch[0];
arr[1].ch= ch[0];
arr[2].ch= ch[0];
//string s= arr[0].ch+arr[1].ch+ arr[2].ch;
int n;
cin>>n;
while(n--)
{
  	cout<<arr[2].ch<<arr[1].ch<< arr[0].ch<<endl;
  
  for(int i=0;i<3;i++)
  {
  	arr[i].pos = (arr[i].pos +1)%3;
  	arr[i].ch = ch[arr[i].pos];
  	if (arr[i].pos) break;
  }
  

}


}
