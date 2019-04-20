#include<iostream> 
#include<string> // for string class 
/*
1) begin()
This function returns an iterator
to beginning of the string.
2) end()
This function returns an iterator 
to end of the string.
3) rbegin() 
This function returns a reverse 
iterator pointing at the end of string.
4) rend()
This function returns a reverse iterator
pointing at beginning of string
*/
using namespace std; 
int main() 
{ 
    string str = "geeksforgeeks"; 
  
    string::iterator it; 
  
    string::reverse_iterator it1; 
  
    cout << "The string using forward iterators is : "; 
    for (it=str.begin(); it!=str.end(); it++) 
    cout << *it; //output = geeksforgeeks
    cout << endl; 
  
    cout << "The reverse string using reverse iterators is : "; 
    for (it1=str.rbegin(); it1!=str.rend(); it1++) 
    cout << *it1; //output = skeegrofskeeg
    cout << endl; 
  
    return 0; 
  
} 
