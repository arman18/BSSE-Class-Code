#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;

#define tr(c,i) for(typeof((c).begin()) i = (c).begin(); i!=(c).end(); i++)

bool sortBySecond(const ii &p1,const ii&p2){
    return p1.second > p2.second;
    
    //sort will give me p1 and p2 and will ask me weather i want
    //to place p2 before p1 or not
    //here i given that permission if p2.second is less than p1.second
}
int main(void){
    vector<ii> vec;
    vec.push_back(ii(100,50));
    vec.push_back(ii(132,5));
    vec.push_back(ii(80,95));
    sort(vec.begin(),vec.end(),sortBySecond);
    tr(vec,ij) {
        cout<<ij->first<<" "<<ij->second<<endl;
        }
    return 0;
}
