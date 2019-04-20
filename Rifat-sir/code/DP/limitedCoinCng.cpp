
#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
 
int k;
int n;
int a[100];
int c[100];
int dp[100][1008];
 
 
long long  explore(int i, int sum)
{  
    long long ans;
    int mod;
    ans = 0;
 
    mod = 1e8 + 7;
   
    if(sum == k) {
        return 1;
    }
 
    if(i == n) {
        return 0;
    }
 
    if(dp[i][sum] != -1) {
        return dp[i][sum];
    }
   
    for (int j = 0; j <= c[i] and (j * a[i]) + sum <= k; j++) {
        ans += explore(i+1, sum + j * a[i]);
        ans = ans % mod;
    }
 
 
    return dp[i][sum] = ans;
 
}
 
int main()
{
 
    int t;
    int mod;
 
    mod = 1e8 + 7;
    scanf("%d", &t);   
 
    for (int cs = 1; cs <= t; cs++) {
        scanf("%d", &n);
        scanf("%d", &k);
 
 
        for (int i = 0; i < n; i++) {
            scanf("%d", a + i);
        }
 
        for (int i = 0; i < n; i++) {
            scanf("%d", c + i);
        }
 
        memset(dp, -1, sizeof dp);
 
        printf("Case %d: %lld\n", cs, explore(0, 0));
 
    }
 
}


/* //bset way:value==0 return 1 and fron n-1;
 
#include<iostream>
using namespace std;

int totalWay(int *coin,int index,int *freOfCoin,int value,int presentCoin)
{

    if(index<0 || value<0) return 0;
    if(value==0)
 return 1;
    int a=0,b=0;
    if(presentCoin>0 && coin[index]<=value) a= totalWay(coin,index,freOfCoin,value-coin[index],presentCoin-1);

    if(index>0) b = totalWay(coin,index-1,freOfCoin,value,freOfCoin[coin[index-1]]);
        
    return a+b;
}

int main(void)
{
    int t;
    cin>>t;
    for(int i=1; i<=t; i++)
    {
        int coin[51],freOfCoin[101],n,k;
        cin>>n>>k;
        for(int j=0; j<n; j++) cin>>coin[j];
        for(int j=0; j<n; j++) cin>>freOfCoin[coin[j]];
        cout<<"Case "<<i<<": "<<totalWay(coin,n-1,freOfCoin,k,freOfCoin[coin[n-1]])<<endl;
    }
}


/*#include<iostream>
using namespace std;

int totalWay(int *coin,int index,int *freOfCoin,int n,int value,int presentCoin)
{

    if(index>=n || value<0) return 0;
    if(presentCoin>0 && coin[index]==value )
 return 1;

    int a=0,b=0;
    if(presentCoin>0)
 if(coin[index]<value) a= totalWay(coin,index,freOfCoin,n,value-coin[index],presentCoin-1);

    if(index<n-1) b = totalWay(coin,index+1,freOfCoin,n,value,freOfCoin[coin[index+1]]);
        
    return a+b;
}

int main(void)
{
    int t;
    cin>>t;
    for(int i=1; i<=t; i++)
    {
        int coin[51],freOfCoin[101],n,k;
        cin>>n>>k;
        for(int j=0; j<n; j++) cin>>coin[j];
        for(int j=0; j<n; j++) cin>>freOfCoin[coin[j]];
        cout<<"Case "<<i<<": "<<totalWay(coin,0,freOfCoin,n,k,freOfCoin[coin[0]])<<endl;
    }
}

*/
