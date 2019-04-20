#include<bits/stdc++.h>
using namespace std;
int main(void)
{
	int nGrandPrix,nPilots,c=0;
	while(cin>>nGrandPrix>>nPilots && (nGrandPrix || nPilots))
	{
	struct mystruct
{
	float totalPt=0;
	int posArr[100]={0};
};
	
		mystruct pilot[100];
		int order;
		while(nGrandPrix--)
		{
			for(int i=0;i<nPilots;i++)
			{
				cin>>order;
				pilot[i].posArr[order-1]++;
				
			}
		}
		int scoringStm,nPilotRecPt;
		cin>>scoringStm;
		while(scoringStm--)
		{
			cin>>nPilotRecPt;
			int point,max=0;
			
			
			for(int i=0;i<nPilotRecPt;i++)
			{
				
				cin>>point;
				for (int j=0;j<nPilots;j++)
				{
					pilot[j].totalPt+=pilot[j].posArr[i]*point;
					if(i==nPilotRecPt-1 && (max<pilot[j].totalPt)) max=pilot[j].totalPt;
				}
			}
			for (int i=0;i<nPilots;i++)
			{
				if (pilot[i].totalPt==max)
				{
					if (c!=0) cout<<" ";
					cout<<i+1;
					c++;
				}
				pilot[i].totalPt=0;
			}
			cout<<endl;
			c=0;
		}
	}
}


/* think a pilol as a struct.
     store all information (like position every 
     competition,total points he earns, etc. ) of a pilot 
     into it.
   then calculate who is the first!!
 */
