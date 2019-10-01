#include<bits/stdc++.h>
using namespace std;
int n = 6,mx = 6; //same as n;
struct mystruct
{
    int currentNode;
    mystruct *parent,*next;
    int *arr; //same as n
    bool lf;
    mystruct *point; //n+1
} ;
mystruct *root,*firstLeaf;

mystruct* createNode()
{
    mystruct *m=new mystruct();
    m->currentNode = 0;
    m->parent = NULL;
    m->next = NULL;
    m->lf = true;
    m->arr = new int[n];
    m->point =  new mystruct[n+1];
    return m;
}
mystruct *findLeaf(mystruct *tempRt,int number)
{

    while(tempRt->lf==false)
    {
        int i;
        for(i=0; i<tempRt->currentNode; i++) if(number<tempRt->arr[i]) break;
        tempRt = tempRt->point[i];
    }
    return tempRt;

}

void insertValueAndPoint(mystruct *parent,int value,mystruct *right)
{
    int i=parent->currentNode-1;
    for(;i>=0; i--)
    {
        if(parent->arr[i]<=value) break;
        else
        {
            parent->arr[i+1] = parent->arr[i];
            parent->point[i+2] = parent->point[i+1];
        }
    }
    parent->arr[i+1] = value;
    parent->point[i+2] = right;
    parent->currentNode++;
}

void insertMiddle(mystruct *parent,int value,mystruct *left,mystruct *right)
{
    if(parent==NULL)
    {
        parent = createNode();
        parent->arr[0] = value;
        parent->point[0] = left;
        parent->point[1] = right;
        parent->currentNode++;
        parent->lf = false;
        root = parent;
        left->parent = parent;
        right->parent = parent;
        return;
    }
    right->parent = parent;
    insertValueAndPoint(parent,value,right);
    if(parent->currentNode==mx)
    {
        mystruct *splitNode = createNode();
        splitNode->lf = false;
        int j=0;
        for(int i=parent->currentNode-(n-1)/2;i<mx; i++)
        {
            splitNode->arr[j] = parent->arr[i];
            if(j==0)
            {
                splitNode->point[0] = parent->point[i];
                splitNode->point[0]->parent = splitNode;
            }
            splitNode->point[j+1] = parent->point[i+1];
            splitNode->point[j+1]->parent = splitNode;
            j++;
        }
        parent->currentNode-=(n-1)/2+1;
        splitNode->currentNode = (n-1)/2;
        insertMiddle(parent->parent,parent->arr[parent->currentNode],parent,splitNode);
    }

}

void insertLeaf(int number)
{
    mystruct *leaf = findLeaf(root,number);

    leaf->arr[leaf->currentNode] = number;
    leaf->currentNode++;
    sort(leaf->arr,leaf->arr+leaf->currentNode);

    if(leaf->currentNode==mx)
    {
        mystruct *splitNode = createNode();
        int j=0;
        for(int i=leaf->currentNode-n/2;i<mx; i++)
        {
            splitNode->arr[j] = leaf->arr[i];
            j++;
        }
        leaf->currentNode-=n/2;
        splitNode->currentNode = n/2;
        splitNode->next = leaf->next;
        leaf->next = splitNode;
        insertMiddle(leaf->parent,splitNode->arr[0],leaf,splitNode);
    }
}

int main(void)
{
    root = createNode();
    firstLeaf = root;
    mystruct *fst = firstLeaf;
    int totalNumber,tempNum;
//    cout<<"total Number: ";
//    cin>>totalNumber;
//    for(int i=0; i<totalNumber; i++)
//    {
//        cin>>tempNum;
//        insertLeaf(tempNum);
//    }
    while(true)
    {
        cout<<"Number: ";
        cin>>tempNum;
        insertLeaf(tempNum);
        cout<<"root node contains: ";
    for(int i=0; i<root->currentNode; i++)
        {
            cout<<root->arr[i]<<" ";
        }
    cout<<"\nleaf node contains:\n";
    while(firstLeaf!=NULL)
    {
        for(int i=0; i<firstLeaf->currentNode; i++)
        {
            cout<<firstLeaf->arr[i]<<" ";
        }
        cout<<endl;
        firstLeaf = firstLeaf->next;
    }
    firstLeaf = fst;
    }


}
//26
//35 1 8 15 25 3 11 18 5 10 9 6 2 4 16 17 26 27 28 29 30 31 32 33 34 36
