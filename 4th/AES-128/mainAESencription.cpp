#include<bits/stdc++.h>
using namespace std;
unsigned char allKey[4][44];
unsigned char sBox[16][16];
unsigned char invSBox[16][16];
unsigned char key[4][4];
int forwardArr[4][4] = {2,3,1,1,1,2,3,1,1,1,2,3,3,1,1,2};
int backwordArr[4][4] = {14,11,13,9,9,14,11,13,13,9,14,11,11,13,9,14};
void printState(unsigned char **state)
{
        for(int i=0; i<4;i++)
        for(int j=0; j<4; j++) cout<<state[j][i];
        cout<<endl;
}

void initializeKey()
{
    ifstream ifile;
    int n;
    char ch;
    ifile.open("key.txt");
    if(!ifile)
    {
        cout<<"unable to open key.txt:";
        exit(1);
    }
    for(int i=0; i<4; i++)
        for(int j=0; j<4; j++)
    {
        ifile.get(ch);
        key[j][i] = ch;
    }
    ifile.close();
}
void initSBox()
{
    int n;
    ifstream ifile;
    ifile.open("s-box.txt");
    if(!ifile)
    {
        cout<<"unable to open s-box.txt:";
        exit(0);
    }
    for(int i=0; i<16; i++)
        for(int j=0; j<16; j++)
    {
        ifile>>hex>>n;
        sBox[i][j] = n;
    }
    ifile.close();
}
void initInvSBox()
{
    int n;
    ifstream ifile;
    ifile.open("invS-box.txt");
    if(!ifile)
    {
        cout<<"unable to open invSBox.txt"<<endl;
        exit(0);
    }
    for(int i=0;i<16;i++)
        for(int j=0; j<16; j++)
        {
            ifile>>hex>>n;
            invSBox[i][j] = n;
        }
        ifile.close();
}
unsigned char *SubWord(unsigned char temp[])
{
    unsigned char ch,tempCH;
    for(int i=0; i<4; i++)
        {
            ch = temp[i];
            tempCH = ch<<4;
            temp[i] = sBox[int(ch>>4)][int(tempCH>>4)];
        }
    return temp;
}
unsigned char *RotWord(unsigned char temp[])
{
    unsigned char ch = temp[0];
    for(int i=0;i<3; i++) temp[i] = temp[i+1];
    temp[3] = ch;
    return temp;
}
unsigned char *Rcon(int round)
{
    unsigned char *temp = new unsigned char[4];
    if(round<9) temp[0] = pow(2,round-1);
    else if(round==9) temp[0] = 27;
    else temp[0] = 54;
    for(int i=1;i<4; i++) temp[i] = 0;
    return temp;
}
unsigned char *exor(unsigned char temp1[],unsigned char temp2[])
{
    for(int i=0; i<4; i++) temp1[i] = temp1[i]^temp2[i];
    return temp1;
}
void expansionKey()
{
    for(int word=0;word<4;word++)
        for(int byte=0;byte<4; byte++) allKey[byte][word] = key[byte][word];

    unsigned char *temp= new unsigned char[4];
    for(int word=4; word<44;word++)
    {
        for(int byte=0;byte<4; byte++) temp[byte] = allKey[byte][word-1];
        if(word%4==0) temp = exor(SubWord (RotWord (temp)),Rcon(word/4));
        for(int byte=0; byte<4; byte++) allKey[byte][word] = temp[byte]^allKey[byte][word-4];

    }
}
void addRound(unsigned char **state,int round)
{
    for(int i=0; i<4; i++)
        for(int j=0; j<4; j++)
    {
        state[j][i] = state[j][i]^allKey[(round*4)+j][i];
    }
}
void substitute(unsigned char **state)
{
    unsigned char ch,tempCH;
    for(int i=0; i<4; i++)
        for(int j=0; j<4; j++)
        {
            ch = state[i][j];
            tempCH = ch<<4;
            state[i][j] = sBox[int(ch>>4)][int(tempCH>>4)];
        }
}

void invSubstitute(unsigned char **state)
{
    unsigned char ch,tempCh;
    for(int i=0; i<4; i++)
        for(int j=0; j<4;j++)
    {
        ch = state[i][j];
        tempCh = ch<<4;
        state[i][j] = invSBox[int(ch>>4)][int(tempCh>>4)];
    }
}
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

void invShiftRows(unsigned char **state,int startinRow)
{
    if(startinRow==4) return;
    unsigned char ch[3];
    for(int i=0;i<startinRow; i++) ch[i] = state[startinRow][3-i];
    for(int i=0; i<4; i++)
    {
        int clm = (i+startinRow)%4;
        if(clm>=i) state[startinRow][3-i] = state[startinRow][3-clm];
        else state[startinRow][3-i] = ch[clm];
    }
    invShiftRows(state,++startinRow);
}
char productByTwo(unsigned char ch)
{
        if(int(ch>>7)) return (ch<<1)^(27);
        return ch<<1;
}
unsigned char productByPowerTwoNumber(int n,unsigned char ch)
{
    if(n==1) return ch;
    if(n==2) return productByTwo(ch);
    else return productByPowerTwoNumber(2,productByPowerTwoNumber(n/2,ch));
}
unsigned char product(int n,unsigned char ch)
{
    unsigned char tempCh = 0;
    int power;
    do
    {
        power = log2(n);
        tempCh^=productByPowerTwoNumber(pow(2,power),ch);
        n = n%(int)(pow(2,power));
    }while(n!=0);
    return tempCh;
}

void mixCLM(unsigned char **state,int forward)
{

    for(int i=0; i<4; i++)
    {
        unsigned char tempArr[4];
        for(int k=0; k<4; k++)
        {
            tempArr[k] = state[k][i];
            state[k][i] = 0;
        }
        if(forward) for(int j=0; j<4; j++) for(int k = 0; k<4; k++) state[j][i]^=product(forwardArr[j][k],tempArr[k]);
        else for(int j=0; j<4; j++) for(int k = 0; k<4; k++) state[j][i]^=product(backwordArr[j][k],tempArr[k]);
    }
}

int main(void)
{
    initSBox();
    initializeKey();
    initInvSBox();
    expansionKey();
    ifstream ifile;
    ifile.open("data.txt");
    if(!ifile) return 0;
    unsigned char **state = new unsigned char *[4];
    for(int i=0; i<4; i++) state[i] = new unsigned char[4];
    char ch;

    while(ifile.get(ch))
    {
        int word=0;
        int byte=1;
        state[0][0] = ch;
        for(; word<4;word++)
        {
            for(; byte<4;)
            {
                if(ifile.get(ch)) state[byte][word] = ch;
                else break;
                byte=(byte+1)%4;
                if(byte==0) break;
            }
            if(ifile.eof()) break;
        }
        for(;word<4;word++)
            for(;byte<4;)
                {
                    state[byte][word] = 0;
                    byte=(byte+1)%4;
                    if(byte==0) break;
                }

        addRound(state,0);
        for(int i=1; i<11; i++)
        {
            substitute(state);
            shiftRow(state,1);
            if(i<10) mixCLM(state,1);
            addRound(state,i);
        }

        addRound(state,10);
        for(int i=9;i>=0;i--)
        {
            invShiftRows(state,1);
            invSubstitute(state);
            addRound(state,i);
            if(i>0) mixCLM(state,0);
        }
        printState(state);
    }
}
