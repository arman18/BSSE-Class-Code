#include<iostream>
#include<algorithm>
using namespace std;

void printFCFS(int arr[],int total)
{
    cout<<"FCFS ";
    for(int i=0; i<total; i++) cout<<arr[i]<<" ";
    cout<<endl;

}

void printSSTF(int arr[],int total,int initial)
{
    sort(arr,arr+total);
    int minDist = abs(arr[0]-initial),index=0;
    for(int i=1; i<total; i++)
    {
        if(minDist>=abs(initial-arr[i]))
        {
            minDist = abs(initial-arr[i]);
            index = i;
        }

    }
    cout<<"SSTF ";
    int next = index+1,prev = index-1;
    int nextval,preVal;
    while(index>=0 && index<total)
    {
        cout<<arr[index]<<" ";
        if(prev<0) preVal=98765;
        else preVal = arr[prev];
        if(next>=total) nextval = 98765;
        else nextval = arr[next];
        if(abs(arr[index]-preVal)>=abs(arr[index]-nextval))
        {
            index = next;
            next++;
        }
        else
        {
            index = prev;
            prev--;
        }
    }
    cout<<endl;
}

int indexForInitial(int arr[],int total,int initial)
{
    int index = 0;
    if(arr[total-1]<initial) return total-1;
    if(arr[0]>initial) return 0;
    for(int i=0; i<total-1; i++)
    {
        if(initial>=arr[i] && initial<=arr[i+1])
        {
                if(initial==arr[i]) index=i;
                else index = i+1;
                break;
        }

    }
    return index;
}

void printSCAN(int arr[],int total,int initial)
{
    cout<<"SCAN ";
    sort(arr,arr+total);
    int index = indexForInitial(arr,total,initial);

    for(int i=index; i<total; i++) cout<<arr[i]<<" ";
    for(int i=index-1; i>=0; i--) cout<<arr[i]<<" ";
    cout<<endl;
}


void printCSCAN(int arr[],int total,int initial)
{
    cout<<"CSCAN ";
    sort(arr,arr+total);
    int index = indexForInitial(arr,total,initial);
    for(int i=index; i<total; i++) cout<<arr[i]<<" ";
    for(int i=0; i<index; i++) cout<<arr[i]<<" ";
    cout<<endl;
}

void printLOOK(int arr[],int total,int initial)
{
    cout<<"LOOK ";
    sort(arr,arr+total);
    int index = indexForInitial(arr,total,initial);

    for(int i=index; i<total; i++) cout<<arr[i]<<" ";
    for(int i=index-1; i>=0; i--) cout<<arr[i]<<" ";
    cout<<endl;
}

int main(void)
{
    int total;
    cout<<"total number: ";
    cin>>total;
    cout<<"current position of arm: ";
    int pos;
    cin>>pos;
    int arr[total],Max,Min;
    cout<<"all number: ";
    cin>>arr[0];
    Min = arr[0];
    Max = arr[0];
    for(int i=1; i<total; i++)
    {
        cin>>arr[i];
        if(Max<arr[i]) Max = arr[i];
        if(Min>arr[i]) Min = arr[i];
    }
    printFCFS(arr,total);
    printSSTF(arr,total,pos);
    printSCAN(arr,total,pos);
    printCSCAN(arr,total,pos);
    printLOOK(arr,total,pos);
    return 0;
}
