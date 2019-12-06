#include<bits/stdc++.h>
using namespace std;

char productByTwo(unsigned char ch)
{
        if(int(ch>>7)) return (ch<<1)^(27);
        return ch<<1;
}
char product(int n,unsigned char ch)
{
    if(n==1) return ch;
    if(n==2) return productByTwo(ch);
    return productByTwo(ch)^ch;
}
void mixCLM(int constArr[][4],unsigned char **state)
{

    for(int i=0; i<4; i++)
    {
        unsigned char tempArr[4];
        for(int k=0; k<4; k++)
        {
            tempArr[k] = state[k][i];
            state[k][i] = 0;
        }

        for(int j=0; j<4; j++) for(int k = 0; k<4; k++) state[j][i]^=product(constArr[j][k],tempArr[k]);
    }
}

int main(void)
{
    unsigned char ch = product(2,110);
    cout<<int(ch)<<endl;

    int constArr[4][4] = {2,3,1,1,1,2,3,1,1,1,2,3,3,1,1,2},n;
    unsigned char **state   = new unsigned char *[4];
    for(int i=0;i<4; i++) state[i] = new unsigned char[4];
    ifstream ifile;
    ifile.open("data.txt");
    if(!ifile) return 0;
    for(int i=0; i<4; i++)
    {
        for(int j=0; j<4; j++)
        {
            ifile>>hex>>n;
            state[i][j] = n;
        }
    }
    mixCLM(constArr,state);
    for(int i=0; i<4; i++)
    {
        for(int j=0; j<4; j++) cout<<hex<<int(state[i][j])<<" ";
        cout<<endl;
    }
}



