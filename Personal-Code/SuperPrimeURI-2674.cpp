#include<iostream>
#include<math.h>
using namespace std;
bool isPrime(int n)
{
	  int i,m=sqrt(n);
	  for (i=2;i<=m;i++)
		{
			if(n%i==0) break;
		}
		 return i>m;
		
}
int main(void)
{
	int x,i,m;
	
	while(cin>>x)
	{
		if(x==1) 
		{
			cout<<"Nada"<<endl;
			continue;
		}
		if(isPrime(x))
		{
			while(x)
			{
				int rest=x%10;
				if((rest!=2) && (rest%2==0 || rest==1 || rest==9))
				{
					cout<<"Primo"<<endl;
					break;
				}
				x/=10;
			}
			if(x==0) cout<<"Super"<<endl;
		}
		else cout<<"Nada"<<endl;
		
	}
}
