#include<bits/stdc++.h>
using namespace std;

void addRound(unsigned char **state,unsigned char **key)
{
    for(int i=0; i<4; i++)
        for(int j=0; j<4; j++)
    {
        state[i][j] = state[i][j]^key[i][j];
    }
}

int main(void)
{
    ifstream ifile;
    ifile.open("data.txt");
    if(!ifile) return 0;
    unsigned char **state = new unsigned char *[4];
    for(int i=0; i<4; i++) state[i] = new unsigned char[4];
    int n;
    for(int i=0; i<4; i++)
        for(int j=0; j<4; j++)
    {
        ifile>>hex>>n;
        state[i][j] = n;

    }
    ifile.close();
    unsigned char **key = new unsigned char *[4];
    for(int i=0; i<4; i++) key[i] = new unsigned char[4];
    ifile.open("key.txt");
    for(int i=0; i<4; i++)
        for(int j=0; j<4; j++)
    {
        ifile>>hex>>n;
        key[i][j] = n;

    }
    addRound(state,key);
    for(int i=0; i<4; i++)
        for(int j=0; j<4; j++)
    {
        cout<<hex<<int(state[i][j])<<" ";
        if(j==3) cout<<endl;
    }
}
