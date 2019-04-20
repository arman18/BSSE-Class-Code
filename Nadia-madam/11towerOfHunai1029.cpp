#include<iostream>

using namespace std ;

void mechanism(int n , char fulStack , char newStack , char emptyStack)
{
    if(n==1)
    {
        cout << n << "st Disk : " << fulStack << " To " << newStack << endl ;
        return ;
    }

    mechanism(n-1 , fulStack, emptyStack , newStack) ;

    cout << n << "th Disk : "<< fulStack << " To " << newStack << endl ;

    mechanism(n-1 , emptyStack , newStack , fulStack) ;
}

int main(void)
{
    int n;
    cin>>n;
    cout<<"1st tower: X\nmiddle tower: Y\ndestination tower: Z\n     mechanism    "<<endl;
    mechanism(n , 'X' , 'Z' , 'Y') ;

    return 0 ;
    
}


