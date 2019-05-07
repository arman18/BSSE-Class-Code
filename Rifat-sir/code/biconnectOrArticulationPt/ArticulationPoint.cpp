#include<bits/stdc++.h>
using namespace std;
typedef vector< vector < int > > vvi;
typedef set<int> si;
int cnt = 0;
#define tr(c,i) for(typeof((c).begin()) i = (c).begin(); i!=(c).end(); i++)
int DFS(vvi &G,int *discoverTime,int *lowestReachableDiscoveryNum,int currentNode,vector< int > &color,int parent,int numberOfNodes,si &S){
    color[currentNode] = 0;
    discoverTime[currentNode] = cnt++; //now we need only lowest reachable discovery number for this node
    int temp = 987654,mini = 987654,node=-1,componentOfActualcurrentNode=0;
    tr(G[currentNode],i){ //traverse all its child in oder to get this node's lowest reachable discovery number
        if(*i==parent) continue;
        if(color[*i]) { //if this is a white vertex
            temp = DFS(G,discoverTime,lowestReachableDiscoveryNum,*i,color,currentNode,numberOfNodes,S);
            if(parent==-1) componentOfActualcurrentNode++; //means it is actual root that will execute immediately after call from main
        }
        else temp = discoverTime[*i];
        if(temp<mini) {
            mini = temp; //saves the minimum discover number that is given by all its child
                        //the logic behind is that parents minimum reach depends on its child
        }
    }
    if(mini!=987654) {
            for(int i=0; i<numberOfNodes; i++) if(discoverTime[i]==mini) lowestReachableDiscoveryNum[currentNode] = i; //may be it will be discoverTime of i
    }
    else lowestReachableDiscoveryNum[currentNode] = 987654;
    if(parent!=-1 && discoverTime[parent]<=lowestReachableDiscoveryNum[currentNode]) S.insert(parent+1);
    if(parent==-1 &&  componentOfActualcurrentNode==1) S.erase(discoverTime[currentNode]+1);
    return mini;
}

int main(void){
    int numberOfNodes,numberOfEdges,node1,node2;
    cin>>numberOfNodes>>numberOfEdges;
    vvi G(numberOfNodes);
    for(int i=0; i<numberOfEdges; i++){
        cin>>node1>>node2;
        G[node1-1].push_back(node2-1);
        G[node2-1].push_back(node1-1); //making undirected
    }
    int discoverTime[numberOfNodes],lowestReachableDiscoveryNum[numberOfNodes];
    vector<int> color(numberOfNodes,1);
    int currentNode =0;
    si S;
    DFS(G,discoverTime,lowestReachableDiscoveryNum,currentNode,color,-1,numberOfNodes,S);
    //for(int i=0; i<numberOfNodes; i++) cout<<discoverTime[i]+1<<" "<<lowestReachableDiscoveryNum[i]+1<<endl;
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
