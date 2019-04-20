

#include <bits/stdc++.h>

using namespace std;

int main (void)
{
	int H1,H2,m1,m2,H3,m3;
	
	cin>>H1>>m1>>H2>>m2;
	
	while ( H1!=0 || H2!=0 || m2!=0 || m1!=0)
	
	{
	
		m3 = m2 - m1;
		
		if (m3 < 0) 
		{
			m3+=60;
			H2--;
		}
	
		H3 = H2 - H1;
	
		if (H3 < 0) H3 += 24;
	
		cout << (H3*60) + m3 <<endl;
	
		cin>>H1>>m1>>H2>>m2;
	
	}
}


