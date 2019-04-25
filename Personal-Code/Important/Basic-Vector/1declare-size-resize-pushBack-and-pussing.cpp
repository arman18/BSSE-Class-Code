#include<iostream>
#include<vector>
using namespace std;

void printElement(vector<int>& v){
    int siz = v.size();
    for(int i=0; i<siz; i++) cout<<v[i]<<endl;
}

int main(void){
/*How to declare vector and use of size,resize,push_back*/
    vector<int> v(6); //Same as vector<int> v(v,0);
    cout<<"size: "<<v.size()<<endl;
    v.resize(8,1);
    cout<<"size: "<<v.size()<<endl;
    v.resize(11,2);
    v.push_back(3); //Push_back always increase the size by 1 and add element to that index
    printElement(v);
    cout<<"size: "<<v.size()<<endl;

    return 0;
}
