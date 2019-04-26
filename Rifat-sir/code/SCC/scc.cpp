#include<bits/stdc++.h>
using namespace std;
typedef vector< int > vi;
typedef vector< vi > vvi;
typedef pair<int,int> ii;
typedef vector< ii > vii;
#define tr(c,i) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
int cnt = 0;
void traverseByDFS(vvi &G,vii &finishTime,vi &color,int root){
    color[root] = 1;
    cnt++;
    tr(G[root],i){
        if(!color[*i]) traverseByDFS(G,finishTime,color,*i);
    }
    cnt++;
    finishTime.push_back(ii(cnt,root));
}
void DFS(vvi &RG,vi &mark,int root){
    mark[root] = 1;
    tr(RG[root],i){
        if(!mark[*i]) DFS(RG,mark,*i);
    }
}
int main(void){
    int numberOfNodes,numberOfEdges,node1,node2;
    cin>>numberOfNodes>>numberOfEdges;
    vvi G(numberOfNodes);
    vvi RG(numberOfNodes);
    for(int i=0; i<numberOfEdges; i++){
        cin>>node1>>node2;
        node1--;
        node2--;
        G[node1].push_back(node2);
        RG[node2].push_back(node1);
    }
    int root = 0;
    vii finishTime;
    vi color(numberOfNodes,0);
    traverseByDFS(G,finishTime,color,root);
    cnt = 0;
    sort(finishTime.rbegin(),finishTime.rend());
    vi mark(numberOfNodes,0);
    tr(finishTime,i) {
        if(!mark[i->second]) {
            cnt++;
            DFS(RG,mark,i->second);
        }
    }
    cout<<"SCC: "<<cnt<<endl;
    return 0;

}
