#include <iostream>
using namespace std;
int main(void)
{
	int n,a=0,b=1;
	cin>>n;
	if (n==1) cout<<0<<endl;
	else if (n==2) cout<<1<<endl;
	else
	{
		int s;
		for (int i=0;i<n-2;i++)
		{
			s=a+b;
			a=b;
			b=s;
		}
		cout<<"ans: "s<<endl;
	}
}
