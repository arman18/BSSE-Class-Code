#ifndef NODE_H
#define NODE_H
#include <bits/stdc++.h>
using namespace std;

class Node{
public:
    Node *parent;
    Node *leftChild;
    Node *rightChild;
    int *value;
    int k;
    int compareIndex;
public:

    Node(int k,int arr[]){
        this->k = k;
        compareIndex = 0;
        value = new int[k];
        parent = NULL;
        leftChild = NULL;
        rightChild = NULL;
        for(int i=0;i<k;i++) {
            value[i] = arr[i];
            //cout<<value[i]<<endl;
        }
    }
    bool isLeftChild(Node *node){ // weather node is able to left child or not
        return value[compareIndex]>node->value[compareIndex];
    }
    bool setChild(Node *node){
        if(isLeftChild(node)){
            leftChild = node;
            //cout<<"left"<<endl;
        }

        else {
            rightChild = node;
            //cout<<"right"<<endl;
        }
        node->setParent(this);
    }
    void setParent(Node *parent){
        this->parent = parent;
        compareIndex = (parent->compareIndex+1)%k;
        //cout<<compareIndex<<" "<<k;
    }
    bool match(Node *node){
        for(int i=0;i<k;i++){
            if(value[i]!=node->value[i]) return false;
        }
        return true;
    }


};
#endif // NODE_H
