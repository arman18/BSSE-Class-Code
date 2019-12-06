#include<bits/stdc++.h>
using namespace std;
int main(void)
{
    ifstream ifile;
    ifile.open("data.txt");
    if(!ifile) cout<<"err"<<endl;

    char ch;
    int count = 0;

    while(ifile.get(ch))
    {
        cout<<ch;
    }



    return 0;
}
