#include <bits/stdc++.h>
using namespace std;
int main(void)
{
	int s,e,temp;
	while(cin>>s>>e &&(s || e))
	{
		int total = e-s+1,length=0;
		temp=s;
		int arr[10] ={0};
		while(e)
		{
		 length++;
		 e=e/10;
		}
		
		int toggle,tgleRest,quotient,pos,index,rest,sEnd,p,tempRest;
		for(int i=0;i<length;i++)
		{
			//int i=0;
			p=pow(10,i);
			sEnd= s%p;
			toggle = (total +sEnd)/p;
			tgleRest = (total+ sEnd)%p;
			if(tgleRest)  toggle +=1;
			else tgleRest=p;//jehuto toggle unchanged 
//so akhane vagses 0 hobe nah think yourself
//very importent!!
			quotient = toggle/10;
			rest = toggle%10;
			tempRest=rest;
			index = temp%10;
			temp=temp/10;
			for(int j= index;j<index+10;j++)
			{
			
if ( j==index) 
		   {
		   	if(temp==0 && index==0 ) 
		   	{
		   		if(quotient>0)
		   		{
		   			arr[j%10]+=(quotient-1)*p;
		   			if(rest==1) arr[j%10]+=tgleRest;
		   			else if(rest>1) arr[j%10]+=p;
		   			
		   		}
		   		rest--;
		   		continue; 
		   		
		   	}
		   			   	
		  if (quotient) 
		   	{
		   		arr[j%10]+=p-sEnd+p*(quotient-1);
		   		if(rest==1)
		   		{
		   			arr[j%10]+=tgleRest;
		   			rest--;
		   		}
		     else if(rest>1)
		   		{
		   			arr[j%10]+=p;
		   			rest--;
		   		}
		   	}
		  else if(rest)
		   	{
		   		if(rest==1)
		   		{
		   			arr[j%10]+=total;
		   			rest--;
		   			continue;
		   		}
		   		arr[j%10]+=p-sEnd;
		   		rest--;
		   	}

		   }
else
		   {
		   	if(rest>0 ) 
		   	{
		   		if(rest==1) arr[j%10]+=tgleRest;
		   		
		   		else arr[j%10]+= p;
		   	
		   		rest--;
		   		
		   	}
		   	else if(tempRest==0 && j==(index+9))
		   	{
		   		arr[j%10]+=tgleRest;
		   		if(quotient) arr[j%10]+=(quotient-1)*p;
		   		continue;
		   	}
		   	arr[j%10]+=p*quotient; 
		   	
		   }
			}
		}
		for(int i=0;i<=9;i++)
		{
			cout<<arr[i];
			if(i==9) cout<<endl;
			else cout<<" ";
		}
	}
}


