#include "node.h"
#include "kdTree.h"
int main(void)
{
    int k;

    cout<<"k: "; cin>>k;
    KDtree *tree = new KDtree(k);
    cout<<"1) Add"<<endl;
    cout<<"2) Search"<<endl;
    cout<<"choose: ";
    int choose; cin>>choose;
    while(choose==1 || choose==2){
    switch(choose){
        case 1:{
            int numberOfNodes;
            cout<<"number of Nodes: ";cin>>numberOfNodes;
            for(int i=0;i<numberOfNodes;i++){
                int values[k];
                cout<<"node "<<i+1<<endl;
                cout<<"enter ( "<<k<<" values):"<<endl;
                for(int j=0;j<k;j++) cin>>values[j];
                tree->add(new Node(k,values));
            }
            break;
        }
        case 2:{
            cout<<"enter ( "<<k<<" values):"<<endl;
            int values[k];
            for(int j=0;j<k;j++) cin>>values[j];
            tree->Search(new Node(k,values));
        }
    }
    cout<<"1) Add"<<endl;
    cout<<"2) Search"<<endl;
    cout<<"choose: ";
    cin>>choose;
    }

    return 0;
}
