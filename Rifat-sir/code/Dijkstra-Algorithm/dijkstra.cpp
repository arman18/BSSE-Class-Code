#include<bits/stdc++.h>
using namespace std;

void dijkstr(double **arr, int *previousNode, double *finalValue,bool *checkNode,int sourceNode,int numberOfNode){

    for(int i=0; i<numberOfNode; i++){
        if(arr[sourceNode][i]!=-1){
            int tempInt = 0;
            if(finalValue[sourceNode]>0) tempInt = finalValue[sourceNode];
            if(finalValue[i]<0) {
                finalValue[i] = tempInt + arr[sourceNode][i];
                previousNode[i] = sourceNode;
            }
            else if(tempInt + arr[sourceNode][i] < finalValue[i]){
                finalValue[i] = tempInt + arr[sourceNode][i];
                previousNode[i] = sourceNode;
            }
        }
    }
    checkNode[sourceNode] = false;
    int minValue = -1;
    for(int i=0; i<numberOfNode; i++){
        if(finalValue[i]>=0 && checkNode[i]){
            if(minValue==-1){
                minValue = finalValue[i];
                sourceNode = i;
            }
            else if(minValue>finalValue[i]){
                minValue = finalValue[i];
                sourceNode = i;
            }
        }
    }
    for(int i=0; i<numberOfNode; i++) cout<<finalValue[i]<<" ";
    //cout<<"src: "<<sourceNode<<endl;
    if(minValue==-1) return;
    else dijkstr(arr,previousNode,finalValue,checkNode,sourceNode,numberOfNode);
}

int main(void){


    int numberOfNode;
    cin>>numberOfNode;
    bool checkNode[numberOfNode];
    double **arr = new double*[numberOfNode];
    double finalValue[numberOfNode];
    for(int i=0; i<numberOfNode; i++) {
        arr[i] = new double[numberOfNode];
        checkNode[i] = true;
        finalValue[i] = -1;
    }
    for(int i=0; i<numberOfNode; i++)
        for(int j=0; j<numberOfNode; j++) arr[i][j] = -1;

    int previousNode[numberOfNode],numberOfedge,node1,node2,value;

    cin>>numberOfedge;
    for(int i=0; i<numberOfedge; i++){
        cin>>node1>>node2>>value;
        arr[node1-1][node2-1] = value;
    }

    int sourceNode;
    cin>>sourceNode;
    sourceNode--;
    finalValue[sourceNode] =0;  //modified herre
    dijkstr(arr,previousNode,finalValue,checkNode,sourceNode,numberOfNode);
    int node,temp;
    cout<<"which node you want to go: ";
    while(cin>>node){
        node--;
        temp = node;
        if(finalValue[node]==-1){
            cout<<"impossible to reach"<<endl;
            cout<<"which node you want to go: ";
            continue;
        }
        cout<<"path: ";
        while(previousNode[node]!=sourceNode)
        {
            cout<<previousNode[node]+1<<" ";
            node = previousNode[node];
        }
        cout<<sourceNode+1<<"cost: "<<finalValue[temp]<<endl;
        cout<<"which node you want to go: ";
    }
    return 0;
}


/*
input:
node:           6
edge:           10
n1 n2 weight:
            1 2 50
            1 3 45
            1 4 10
            2 3 10
            2 4 15
            3 5 30
            4 5 15
            5 2 20
            5 3 35
            6 5 3
sourceNode:      1
ans: -1 45 45 10 25 -1
*/
