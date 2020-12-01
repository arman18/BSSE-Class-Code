#ifndef DEC_TREEID3_H
#define DEC_TREEID3_H
#include <bits/stdc++.h>
#include "node.h"
#include "array.h"
using namespace std;
class DecTree{
public:
Node *root = NULL;
bool isNumeric;
DecTree(Array arr,bool isNumeric){
    this->isNumeric = isNumeric;
    root  = new Node();
    root->configureChield(arr);
}
void print(){
    cout<<endl;
    if (root!=NULL) printRecursively(root,0);
    cout<<endl;
    cout<<endl;
}


vector <string> testDecision(Array arr){
    vector <string> result;
    if(root==NULL) return result;
    for(int index=1;index<arr.SizeY();index++){
        map < string, string > row = arr.getRow(index);
        string ans = isNumeric? SearchByNumeric(row,root):SearchByAlpha(row,root);
        //cout<<" ans: "<<ans<<" response: "<<arr.getResponse(index)<<endl;
        if(ans==arr.getResponse(index))
            result.push_back("true");
        else result.push_back("false");
    }
    return result;
}
private:
string SearchByAlpha(map < string, string > &row,Node *tempRoot){
    string result;
    if(tempRoot->isLeaf) return tempRoot->decision;
    string value = row[tempRoot->attName];
    if(value.empty()) return "null";
    for(auto &child:tempRoot->chields)
        if((child.first)==value) return SearchByAlpha(row,child.second);
    return "null";
}
string SearchByNumeric(map < string, string > &row,Node *tempRoot){
    string result;
    if(tempRoot->isLeaf) return tempRoot->decision;
    //cout<<"---------------------------------------------------";
    double value;
    istringstream iss1(row[tempRoot->attName]);
    iss1>>value;
    //cout<<"value: "<<value;
    Node *selected= NULL;
    double valueDiff = 45645643;
    double seleccc;
    for(auto &child:tempRoot->chields){
        istringstream iss2(child.first);
        double childValue;
        iss2>>childValue;
        if(valueDiff>abs(childValue-value)){
            selected = child.second;
            valueDiff = abs(childValue-value);
            seleccc = childValue;
        }

    }
    //cout<<" selected: "<<seleccc;
    if(selected!=NULL) return SearchByNumeric(row,selected);

    return "null";
}

    void printRecursively(Node *startNode,long space){
        if(startNode->isLeaf) cout<<startNode->decision;
        else{
            space+=startNode->attName.length();
            int cont = 0;
            for (auto &child:startNode->chields){
                if(cont==0){
                    cout<<startNode->attName<<"--("<<child.first<<")->";
                    printRecursively(child.second,space+child.first.length()+6);
                    cont++;
                    continue;
                }
                cout<<endl;
                for(int i=0;i<space;i++) cout<<" ";
                cout<<"--("<<child.first<<")->";
                printRecursively(child.second,space+child.first.length()+6);
            }
        }
    }
};

#endif // DEC_TREEID3_H
