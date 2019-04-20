#include<iostream>
using namespace std;

int totalWay(int *coin,int index,int *freOfCoin,int value,int presentCoin)
{

    if(index<0 || value<0) return 0;
    if(value==0) return 1;
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
