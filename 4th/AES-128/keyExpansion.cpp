#include<bits/stdc++.h>
using namespace std;
unsigned char allKey[4][44];
unsigned char sBox[16][16];
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
    unsigned char temp[4];
    if(round<9) temp[0] = pow(2,round-1);
    else if(round==9) temp[0] = 27;
    else temp[0] = 54;
    for(int i=1;i<3; i++) temp[i] = 0;
    return temp;
}
unsigned char *exor(unsigned char temp1[],unsigned char temp2[])
{
    for(int i=0; i<4; i++) temp1[i] = temp1[i]^temp2[i];
    return temp1;
}
void expansion(unsigned char **key)
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

int main(void)
{

}
