#include<bits/stdc++.h>
using namespace std;
struct edges{
    double cost;
    int fromNode;
    int toNode;
};
bool sortByCost(const edges &p1,const edges&p2){
return p1.cost < p2.cost;
}

int root(int *arr,int node){
    while(arr[node]!=node) node = arr[node];
    return node;
}

bool unio(int *arr,int node1,int node2){
    if(root(arr,node1)!=root(arr,node2)){
        arr[root(arr,node2)] = node1;
        return true;
    }
    return false;
}
int main(void){
    int numberOfNodes,numberOfEdges,node1,node2;
    double weight;
    cin>>numberOfNodes>>numberOfEdges;
    vector<edges> V(numberOfEdges);
    for(int i=0; i<numberOfEdges; i++){
        cin>>node1>>node2>>weight;
        edges e;
        e.cost = weight;
        e.fromNode = node1;
        e.toNode = node2;
        V[i] = e;
    }
    sort(V.begin(),V.end(),sortByCost);
    int arr[numberOfNodes];
    for(int i=0; i<numberOfNodes; i++) arr[i] = i;
    for(int i=0; i<numberOfEdges; i++) {
        if(unio(arr,V[i].fromNode-1,V[i].toNode-1))

           cout<<V[i].fromNode<<" "<<V[i].toNode<<" "<<V[i].cost<<endl;
    }
    return 0;
}
