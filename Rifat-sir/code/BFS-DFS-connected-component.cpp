#include<bits/stdc++.h>
using namespace std;
queue<int> q;
stack<int> st;
void BFS(int *check,int node,int **arr)
{
	
	int root = q.front();
	q.pop();
	for(int i=root+1;i<node;i++)
	{
		if(arr[root][i] && check[i])
		{
		  q.push(i);
		  check[i]=0;
		}
	}
	
	for(int i=root-1;i>=0;i--)
	{
		if(arr[i][root] && check[i])
		{
			
			q.push(i);
			check[i]=0;
		}
	}
	
}
void DFS(int* check,int node,int **arr)
{
	int root = st.top();
	for(int i=root+1;i<node;i++)
	{
		if(arr[root][i] && check[i])
		{
			st.push(i);
			check[i]=0;
		  DFS(check,node,arr); //////
		  return;
		}
	}
	
	for(int i=root-1;i>=0;i--)
	{
		if(arr[i][root] && check[i])
		{
			st.push(i);
			check[i]=0;
		  DFS(check,node,arr); ///////
		  return;
		}
	}
}
void component(int *arr)
{
	
}
int main(void)
{
	int node,edge,n1,n2;
	cout<<"node: ";
	cin>>node;
	cout<<"edge: ";
	cin>>edge;
	int **arr=new int*[node];
	
	for(int i=0;i<node;i++) arr[i]=new int[node];
	for(int i=0;i<node;i++)
	{
		for(int j=0;j<node;j++) arr[i][j] = 0;
	}
	for(int i=0;i<edge;i++)
	{
		cin>>n1>>n2;
		if(n1>n2) swap(n1,n2);
		arr[n1-1][n2-1] =1;
	}
	
	
	while(true)
	{
		int check[node],choose;
		for(int i=0;i<node;i++) check[i]=1;
		cout<<"1)BFS\n2)DFS\n3)component\n4)exit\nchoose: ";
		cin>>choose;
		if(choose==1)
		{
			cout<<"From whice node u wnat to traverse\ninput should be >0 && <="<<node<<": ";
			int root;
			cin>>root;
			root--;
			if(root>=0 && root<node)
			{
			  q.push(root);
			  check[root]=0;
			 }
			while(!q.empty())
			{
			  cout<<q.front()+1<<" ";
			  BFS(check,node,arr); ////////////
			 	
			 }
			 cout<<endl;
		}
		else if(choose==2)
		{
			cout<<"From whice node u wnat to traverse\ninput should be >0 && <="<<node<<": ";
			int root;
			cin>>root;
			root--;
			if(root>=0 && root<node)
			{
				st.push(root);
				check[root]=0;
			}
			while(!st.empty())
			{
				DFS(check,node,arr);   ///////////
				cout<<st.top()+1<<" ";
				st.pop();
			}
			cout<<endl;
		}
		else if(choose==3)
		{
			int count=0;
			for(int i=0;i<node;i++)
			{
				if(check[i])
				{
					count++;
					cout<<"component "<<count<<": ";
					st.push(i);
					check[i]=0;
					while(!st.empty())
					{
						DFS(check,node,arr); ////////////
						cout<<st.top()+1<<" ";
						st.pop();
					}
					cout<<endl;
				}
			}
			cout<<"total component: "<<count<<endl;
		}
		else return 0;
	}
}
