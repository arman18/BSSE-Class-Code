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
		
		int toggle,tgleRest,quotient,pos,index,rest,sEnd,p;
		for(int i=0;i<length;i++)
		{
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
			index = temp%10;
			temp=temp/10;
			for(int j= index;j<index+10;j++)
			{
			
if ( j==index) 
		   {
		   	if(temp==0 && index==0 ) 
		   	{
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
		   	if(rest ) 
		   	{
		   		if(rest==1)
		   		{
		   			arr[j%10]+=tgleRest;
		   			rest--;
		   		}
		   		else
		   		{
		   		 arr[j%10]+= p;
		   		 rest--;	
		   		}
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



/*#include <bits/stdc++.h>
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
		int toggle,tgleRest,quotient,pos,index,rest,sEnd,p;
		for(int i=0;i<length;i++)
		{
			p=pow(10,i);
			sEnd= s%p;
			toggle = (total +sEnd)/p;
			tgleRest = (total+ sEnd)%p;
			//if(tgleRest ) 
			toggle +=1;
			quotient = toggle/10;
			rest = toggle%10;
			index = temp%10;
			temp=temp/10;
			for(int j= index;j<index+10;j++)
			{
			
				if ( j==index) 
		   {
		   	if(temp==0 && index==0 ) 
		   	{
		   		rest--;
		   		continue;
		   	}
		   	if(rest) 
		   	{
		   		if(rest==1)
		   		{
		   			if (i==0) tgleRest=1;
		   			if(tgleRest==0) tgleRest=10;
		   			arr[j%10]+=tgleRest-sEnd;
		   			rest--;
		   			
		   		}
		   		else if (quotient)
		   		{ 
		   		 arr[j%10]+= p;
		   	  	rest--;
		   			
		   		}
		   	}
		   	
		   	if (quotient) arr[j%10]+=p-sEnd+p*(quotient-1);
		   	else if(rest)
		   	{
		   		arr[j%10]+=p-sEnd;
		   		rest--;
		   		continue;
		   	}

		   }
		   else
		   {
		   	if(rest) 
		   	{
		   		if(rest==1)
		   		{
		   			if (i==0) tgleRest=1;
		   			arr[j%10]+=tgleRest;
		   			rest--;
		   		}
		   		else 
		   		{
		   		 arr[j%10]+= p;
		   		 rest--;	
		   		}
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



কোন একটি কলামে সংখ্যাগুলি কতবার toggle করছে তা depend করে 
  (মোট সংখ্যা + তার শুরু কত থেকে)/ঐ কলামের স্হানীয় মান|
  
  তো মোট toggle জানার পর প্রতিটা digit কতবার toggle
  করেছে সেটা বের করে নেব।
  
  then প্রথম ও শেষটাকে manually set করব আর বাকি গুগুলো
  আমরা জানি প্রত্তেকে তার স্হানীয়মান সংখ্যকবার position দখল 
  করে থাকে...*/
