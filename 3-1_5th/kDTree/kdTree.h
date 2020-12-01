#ifndef KDTREE_H
#define KDTREE_H
#include <bits/stdc++.h>
#include "node.h"
using namespace std;
class KDtree{
private:
    Node *root;
    int k;
public:
    KDtree(int k){
        this->k=k;
        root = NULL;
        //cout<<"kd tree"<<endl;
    }
    void add(Node *node){
        if(root ==NULL) {
            root = node;
            return;
        }
        Node *index = root;
        Node *leaf;
        while(index != NULL){
            leaf = index;
            index = index->isLeftChild(node) ? index->leftChild : index->rightChild;
        }
        leaf->setChild(node);
    }
    void Search(Node *searchNode){
        Node *index = root;
        if(root != NULL ) {
            cout<<"Root-->";

        }
        while(index != NULL){
            for(int i=0;i<k;i++){
                cout<<index->value[i]<<" ";
            }
            cout<<endl;
            if(index->match(searchNode)) {
                cout<<"(Found)"<<endl<<endl;
                return;
            }
            else {

                if(index->isLeftChild(searchNode)) cout<<"left-->";
                else cout<<"right-->";
                index = index->isLeftChild(searchNode) ? index->leftChild : index->rightChild;
            }
        }
        cout<<"(Not Found)"<<endl<<endl;
    }
};

#endif //KDTREE_H
