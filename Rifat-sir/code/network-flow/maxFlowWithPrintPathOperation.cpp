#include<bits/stdc++.h>
using namespace std;
struct node{
    string vertex;
    double capacity;
};
struct Pair{
    string vertex1,vertex2;
    double capacity;
};
typedef vector < node > vn;
typedef map<string,vn > msvn;
#define tr(c,i) for(typeof((c).begin()) i =(c).begin(); i!=(c).end(); i++)
double total = 0;
double flow(string source,string destination, msvn &Graph,double maxFlow,vector < Pair > &path){
    if(source==destination) {
        total += maxFlow;
        return maxFlow;
    }
    if(Graph[source].empty()) return 0;
    tr(Graph[source],i){
        double temp;
        node nd = *i;
        temp = maxFlow;
        if(temp>nd.capacity) temp = nd.capacity;
        temp = flow(nd.vertex,destination,Graph,temp,path);
        if(temp){ //check if we actually come back from sink or not
            nd.capacity -= temp;
            if(nd.capacity) *i = nd;
            else Graph[source].erase(i);
            Pair p;
            p.capacity = nd.capacity;
            p.vertex1 = source;
            p.vertex2 = nd.vertex;
            path.insert(path.begin(),p);
            return temp;

        }
    }
    return 0;
}

int main(void){
    int numberOfNodes,numberOfEdges;
    string node1,node2;
    double capacity;
    cin>>numberOfNodes>>numberOfEdges;
    msvn Graph;
    for(int i=0; i<numberOfEdges; i++){
        cin>>node1>>node2>>capacity;
        node nd;
        nd.vertex = node2;
        nd.capacity = capacity;
        Graph[node1].push_back(nd);
    }
    string source = "S",destination = "T";
    while(true){
        vector < Pair > path;
        if(!flow(source,destination,Graph,987654321,path)) break;
        //print that path after operation
        tr(path,i){
            cout<<" ("<<i->vertex1<<" "<<i->vertex2<<" "<<i->capacity<<")";
        }
        cout<<endl;
    }
    cout<<total<<endl;
    return 0;
}
/*
4 5
S A 10
A T 5
A B 3
B T 15
S B 7
ANS: 15

*/

