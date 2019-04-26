#include<bits/stdc++.h>
using namespace std;
typedef vector< string > vs;
typedef map< string, vs > mvs;
typedef pair<int,string> is;
typedef vector< is > vis;
#define tr(c,i) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
int cnt = 0;
void traverseByDFS(mvs &M,vis &finishTime,map<string,int> &color,string root){
    color[root] = 1;
    cnt++;
    tr(M[root],i){
        if(!color[*i]) traverseByDFS(M,finishTime,color,*i);
    }
    cnt++;
    finishTime.push_back(is(cnt,root));
}

int main(void){
    int numberOfNodes,numberOfEdges;
    string root;
    cin>>numberOfNodes>>numberOfEdges;
    mvs M;
    string s1,s2;
    for(int i=0; i<numberOfEdges; i++){
        cin>>s1>>s2;
        if(s2=="0") s2 = "\0";
        M[s1].push_back(s2);
    }
    vis finishTime;
    map<string,int> color;
    tr(M,i){
        if(!color[i->first])traverseByDFS(M,finishTime,color,i->first);
    }

    sort(finishTime.rbegin(),finishTime.rend());
    tr(finishTime,i) if(i->second!="\0") cout<<i->second<<endl;
    return 0;

}
/*
9 10
shirt tie
tie jacket
shirt belt
belt jacket
undershorts pants
pants belt
undershorts shoes
pant shoes
soks shoes
watch 0
*/
