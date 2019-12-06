
#include<bits/stdc++.h>
#include<iostream>
using namespace std;

void shiftRow(unsigned char **state,int startinRow)
{
    if(startinRow==4) return;
    unsigned char ch[3];
    for(int i=0;i<startinRow; i++) ch[i] = state[startinRow][i];
    for(int i=0; i<4; i++)
    {
        int clm = (i+startinRow)%4;
        if(clm>=i) state[startinRow][i] = state[startinRow][clm];
        else state[startinRow][i] = ch[clm];
    }
    shiftRow(state,++startinRow);
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
    shiftRow(state,1);

    for(int i=0; i<4; i++)
        for(int j=0; j<4; j++)
    {
        cout<<hex<<int(state[i][j])<<" ";
        if(j==3) cout<<endl;
    }

}
