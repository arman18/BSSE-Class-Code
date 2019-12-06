#include<bits/stdc++.h>
using namespace std;

#define SHR(x, n)    (x >> n)
#define ROTR(x, n)   ((x >> n) ^ (x << (64 - n)))
#define CH(x, y, z)  ((x & y) ^ (~x & z))
#define MAJ(x, y, z) ((x & y) ^ (x & z) ^ (y & z))
#define sum512_zero(x) (ROTR(x, 28) ^ ROTR(x, 34) ^ ROTR(x, 39))
#define sum512_one(x) (ROTR(x, 14) ^ ROTR(x, 18) ^ ROTR(x, 41))
#define sigma512_zero(x) (ROTR(x,  1) ^ ROTR(x,  8) ^ SHR(x,  7))
#define sigma512_one(x) (ROTR(x, 19) ^ ROTR(x, 61) ^ SHR(x,  6))

uint64_t key[80],HASH[8];

void initializeHASH()
{
    ifstream ifile;
    ifile.open("initialHASH.txt");
    if(!ifile)
    {
        cout<<"unable to open initialHASH.txt";
        exit(0);
    }
    for(int i=0;i<8;i++) ifile>>hex>>HASH[i];
    ifile.close();
}

void initializeKey()
{
    ifstream ifile;
    ifile.open("SHAkey.txt");
    if(!ifile)
    {
        cout<<"unable to open SHAkey.txt"<<endl;
        exit(1);
    }
    for(int i=0;i<80; i++) ifile>>hex>>key[i];
    ifile.close();
}
void printHASH()
{
    cout<<hex<<(uint64_t)HASH[0]<<(uint64_t)HASH[1]
            <<(uint64_t)HASH[2]<<(uint64_t)HASH[3]
            <<(uint64_t)HASH[4]<<(uint64_t)HASH[5]
            <<(uint64_t)HASH[6]<<(uint64_t)HASH[7]<<endl;
}
int main(void)
{

    unsigned char M[128];
    ifstream ifile;
    ifile.open("data.txt");
    if(!ifile)
    {
        cout<<"unable to open data.txt"<<endl;
        exit(0);
    }
    initializeKey();
    initializeHASH();
    uint64_t W[80],t1,t2,a,b,c,d,e,f,g,h;
    char tempCH;
    int i=0,flag=0,flag2=1;
    uint64_t numberOfChar = 0;
    while(true)
    {
        for(i=0;i<128;i++)
        {
            if(ifile.get(tempCH)) M[i] = (int)tempCH;
            else break;
        }

        numberOfChar+=i;
        if(i<112)
        {
            if(i==0 && numberOfChar==0) exit(0);
            if(flag2) M[i] = 1;
            else M[i] = 0;
            M[i] = M[i]<<7;
            for(i=i+1;i<128;i++) M[i] = 0;
            uint64_t totalBins = numberOfChar*8;
            for(i=127;i>119;i--)
            {
                M[i] = totalBins | M[i];
                totalBins = totalBins>>8;
            }
            flag=1;
        }
        else if(i<128)
        {
            M[i] = 1;
            M[i] = M[i]<<7;
            for(i=i+1;i<128;i++) M[i] = 0;
            flag2 = 0;
        }
    //--------------for given M----------
        i = 0;
        for(int j=0;j<16;j++)
        {
            W[j] = M[i];
            int temp = i;
            for(i=i+1;i<temp+8;i++) W[j] = W[j]<<8 | M[i];
        }
        for(int j=16;j<80;j++) W[j] = (sigma512_one(W[j-2])+W[j-7]+sigma512_zero(W[j-15])+W[j-16]);

        a = HASH[0];   e = HASH[4];
        b = HASH[1];   f = HASH[5];
        c = HASH[2];   g = HASH[6];
        d = HASH[3];   h = HASH[7];

        for(i=0;i<80;i++)
        {
            t1 = (h + CH(e,f,g) + sum512_one(e) + W[i] + key[i]);
            t2 = (sum512_zero(a) + MAJ(a,b,c));
            h = g;   g = f;
            f = e;   e = (d+ t1);
            d = c;   c = b;
            b = a;   a = (t1+ t2);
        }

       HASH[0] = (a+HASH[0]);
       HASH[1] = (b+HASH[1]);
       HASH[2] = (c+HASH[2]);
       HASH[3] = (d+HASH[3]);
       HASH[4] = (e+HASH[4]);
       HASH[5] = (f+HASH[5]);
       HASH[6] = (g+HASH[6]);
       HASH[7] = (h+HASH[7]);

       if(flag) break;
    }
        printHASH();
//---------------complete------------

}
