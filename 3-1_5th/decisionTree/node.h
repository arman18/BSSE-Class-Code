#ifndef NODE_H
#define NODE_H
#include <bits/stdc++.h>
#include "array.h"
using namespace std;
class Node{
public:
    string attName;
    bool isLeaf = false;
    string decision;
    map<string,Node*> chields;
    Node(){};


void configureChield(Array arr){
    if(arr.GetUniqueResponses().size()==1){
            //cout<<"uqique"<<endl;
        isLeaf = true;
        decision = arr.GetMajorResponse();
        return;
    }
    int index = nextAtt(arr);
    if(index==-1){
        //cout<<"index"<<endl;
        isLeaf = true;
        decision = arr.GetMajorResponse();
        return ;
    }
    //cout<<"working"<<endl;
    vector < string > uniqueValues = arr.GetAttributeUniqueValues(index);
    //cout<<uniqueValues.size()<<endl;
    for(auto &it:uniqueValues){
        chields[it] = new Node();
        chields[it]->configureChield(Array(arr.compress(index,it),arr.nextResponseIdx(index)));
        attName = arr.GetAttributes()[index];
    }
    return ;

}

int nextAtt(Array &arr){
    double H = arr.responseEntropy();
    double I = arr.attributeEntropy(0);
    double gain = 0;
    int index;
    for(int i=0;i<arr.SizeX();i++){
        if(i==arr.getResponseIdx()) continue;
        I = arr.attributeEntropy(i);
        if(gain<H-I){
            index = i;
            gain = H-I;
        }
    }
    return gain? index : -1;
}
};
#endif // NODE_H
