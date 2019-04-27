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
    tr(Graph[source],i){
        double temp;
        node nd = *i;
        temp = maxFlow;
        if(temp>nd.capacity) temp = nd.capacity;
        if(nd.capacity) temp = flow(nd.vertex,destination,Graph,temp,path);
        else temp = 0;
        if(temp){
            nd.capacity -= temp;
            *i = nd;
            //Pair p;
            //p.capacity = nd.capacity;
            //p.vertex1 = source;
            //p.vertex2 = nd.vertex;
            //path.insert(path.begin(),p);
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
        //tr(path,i){
          //  cout<<" ("<<i->vertex1<<" "<<i->vertex2<<" "<<i->capacity<<")";
        //}
        //cout<<endl;
    }
    cout<<"After max flow remaining capacity will be:"<<endl;
    tr(Graph,i){
        tr(i->second,j){
            cout<<i->first<<" "<<j->vertex<<" "<<j->capacity<<endl;
        }
    }
    cout<<total<<endl;
    return 0;
}


