#include<iostream>
#include<vector>
using namespace std;

int main(void){
/*How to declare vector and use of size,resize,push_back*/
    vector<int> v(6); //Same as vector<int> v(v,0);
    cout<<"size: "<<v.size()<<endl;
    v.resize(8,1);
    cout<<"size: "<<v.size()<<endl;
    v.resize(11,2);
    v.push_back(3); //Push_back always increase the size by 1 and add element to that index
    for(int i=0; i<11; i++) cout<<v[i]<<endl;
    cout<<"size: "<<v.size()<<endl;
    
    return 0;
}
