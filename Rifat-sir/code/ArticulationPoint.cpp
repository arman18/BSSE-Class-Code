#include<bits/stdc++.h>
using namespace std;
typedef vector< vector < int > > vvi;
typedef set<int> si;
int cnt = 0;
#define tr(c,i) for(typeof((c).begin()) i = (c).begin(); i!=(c).end(); i++)
int DFS(vvi &G,int *serial,int *low,int root,vector< int > &color,int parent,int numberOfNodes,si &S){
    color[root] = 0;
    serial[root] = cnt++;
    int temp = 987654,mini = 987654,node=-1,last=0,comOFroot=0;
    tr(G[root],i){
        if(*i==parent) continue;
        last = 1;
        if(color[*i]) {
            temp = DFS(G,serial,low,*i,color,root,numberOfNodes,S);
            if(parent==-1) comOFroot++;
        }
        else temp = serial[*i];
        if(temp<mini) {
            mini = temp;
        }
    }
    if(mini!=987654) {
            for(int i=0; i<numberOfNodes; i++) if(serial[i]==mini) low[root] = i;
    }
    else low[root] = 987654;
    if(parent!=-1 && serial[parent]<=low[root] && last) S.insert(parent+1);
    if(parent==-1 &&  comOFroot==1) S.erase(serial[root]+1);
    return mini;
}

int main(void){
    int numberOfNodes,numberOfEdges,node1,node2;
    cin>>numberOfNodes>>numberOfEdges;
    vvi G(numberOfNodes);
    for(int i=0; i<numberOfEdges; i++){
        cin>>node1>>node2;
        G[node1-1].push_back(node2-1);
        G[node2-1].push_back(node1-1);
    }
    int serial[numberOfNodes],low[numberOfNodes];
    vector<int> color(numberOfNodes,1);
    int root =0;
    si S;
    DFS(G,serial,low,root,color,-1,numberOfNodes,S);
    //for(int i=0; i<numberOfNodes; i++) cout<<serial[i]+1<<" "<<low[i]+1<<endl;
    cout<<"articulation point: "<<endl;
    si::iterator it = S.begin();
    while(it!=S.end()) {
        cout<<*it<<" ";
        it++;
    }
    return 0;
}
/*
6 7
1 4
4 3
3 5
5 6
2 3
1 2
3 6
ans: 3
*/
