#include<bits/stdc++.h>
using namespace std;
unsigned char sBox[16][16];
void initSBox()
{
    int n;
    ifstream ifile;
    ifile.open("s-box.txt");
    if(!ifile)
    {
        cout<<"unable to open s-box.txt:";
        exit(1);
    }
    for(int i=0; i<16; i++)
        for(int j=0; j<16; j++)
    {
        ifile>>hex>>n;
        sBox[i][j] = n;
    }
    ifile.close();
}
void substitute(unsigned char **state)
{
    unsigned char ch,tempCH;
    initSBox();
    for(int i=0; i<4; i++)
        for(int j=0; j<4; j++)
        {
            ch = state[i][j];
            tempCH = ch<<4;
            state[i][j] = sBox[int(ch>>4)][int(tempCH>>4)];
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
    substitute(state);
    for(int i=0; i<4; i++)
        for(int j=0; j<4; j++)
    {
        cout<<hex<<int(state[i][j])<<" ";
        if(j==3) cout<<endl;
    }
}
