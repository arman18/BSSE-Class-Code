/*
Examples :

Input : str = "geeksforgeeks 12 23 practice"
Output : 12 13

Input : str = "1: Prakhar Agrawal, 2: Manish Kumar Rai, 3: Rishabh Gupta"
Output : 1 2 3

Input : str = "Ankit sleeps at 4 am."
Output : 4
*/
#include<iostream>
using namespace std;
void extractIntegerWords(string str) 
{ 
    istringstream iss(str);     
   
    string temp; 
    int found; 
    while (iss>>temp) //same as while(!iss.eof())
    { 
        if (stringstream(temp) >> found) //reading return true or false!!
        cout << found << " "; 
        temp = ""; //To save from space at the end of string 
    } 
} 
  
int main() 
{ 
    string str = "1: 2 3 4 prakhar"; 
    extractIntegerWords(str); 
    return 0; 
} 
