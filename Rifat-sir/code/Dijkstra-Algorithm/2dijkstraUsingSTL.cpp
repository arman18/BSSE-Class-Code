#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
typedef vector< double > vd;
//typedef vector< vi > vvi;
typedef pair< double,int > di;
typedef vector< vector<di> > GRAPH;
typedef priority_queue< di,vector< di >, greater< di > > Q;
//#define sz(a) int((a).size())
//#define pb push_back
//#define all(c) (c).begin(),(c).end()
#define tr(c,i) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define present(c,x) ((c).find(x) != (c).end())
#define cpresent(c,x) (find(all(c),x) != (c).end())

void dijkstra(GRAPH &graph,vd &distance,int *previousNode,int srcNode,Q &que){
    di top;
    double costOfNode,costOfAdjascentNode;
    int node,adjascentNode;
    while(!que.empty()){
        top = que.top();
        que.pop();
        node = top.second;
        costOfNode = top.first;
        tr(graph[node],i){
            adjascentNode = i->second;
            costOfAdjascentNode = i->first;
            if(distance[adjascentNode-1]>(costOfNode + costOfAdjascentNode)){
                distance[adjascentNode-1] = costOfNode + costOfAdjascentNode;
                previousNode[adjascentNode] = node;
                que.push(di(distance[adjascentNode-1],adjascentNode));
            }
        }
    }
}

void printPath(int *previousNode,int node,int sourceNode){
    if(sourceNode==node) {
        cout<<sourceNode;
        return;
    }
    printPath(previousNode,previousNode[node],sourceNode);
    cout<<" "<<node;
    return;
}

int main(void){
    int numberOfNode,numberOfEdges,node1,node2,srcNode;
    cout<<"numberOfNode numberOfEdges:"<<endl;
    cin>>numberOfNode>>numberOfEdges;
    cout<<"node1 node2 cost:"<<endl;
    double cost;
    GRAPH graph(numberOfNode+1);
    for(int i=0; i<numberOfEdges; i++){
        cin>>node1>>node2>>cost;
        graph[node1].push_back(di(cost,node2));
    }
    while(true){
        cout<<"give source node: "<<endl;
        cin>>srcNode;

        Q que;
        que.push(di(0,srcNode));
        int previousNode[numberOfNode+1];
        vd distance(numberOfNode,987654321);
        distance[srcNode-1] = 0;
        dijkstra(graph,distance,previousNode,srcNode,que);
        while(true){
            cout<<"1) print path\n2) another source"<<endl;
            int n;
            cin>>n;
            if(n==1) {
                cout<<"destination node: ";
                cin>>n;
                if(distance[n-1]==987654321){
                    cout<<"Not possible to reach"<<endl;
                    continue;
                }
                printPath(previousNode,n,srcNode);
                cout<<"\nminimum cost: "<<distance[n-1]<<endl;
            }
            else if(n) break;
        }
    }
    return 0;
}

