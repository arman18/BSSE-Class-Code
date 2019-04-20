#include <bits/stdc++.h>
using namespace std;

int main(void)
{
	string s,word;
while(getline(cin,s) && s!="*")
{
  istringstream iss(s);
  iss>>word;
  char ch=word[0];
  ch =ch | 32;
  int p=0;
	while(iss>>word)
	{
		char temp =word[0];
		temp= temp | 32;
		if (temp!=ch) 
		{
			cout<<"N"<<endl;
			p=1;
			break;
		}
	}
	if (p) continue;
	cout<<"Y"<<endl;
}

}
/*
  Tautograms are a special case of
alliteration, which is the occurrence of the same letter at the
beginning of adjacent word

   0
   1
  10
  11
 100
 101
 110
 111
1000
1001
1010
1011
1100
1101
    noticeable that one digit active (1)
    after first n (number of stanio man) number
    and remain active after n mumber then 
    deactive again
*/

