#include<iostream> 
#include<string> // for string class 
/*
 1)capacity()
 This function returns the capacity allocated
 to the string, which can be equal to or more
 than the size of the string. Additional space
 is allocated so that when the new characters 
 are added to the string, the operations can 
 be done efficiently
 2) resize() 
 
 This function changes the size of string,
 the size can be increased or decreased.
 
 3)shrink_to_fit()
This function decreases the capacity of the 
string and makes it equal to its size. This 
operation is useful to save additional memory
 if we are sure that no further addition of 
 characters have to be made.
*/
using namespace std; 
int main() 
{ 
    string str = "geeksforgeeks is for geeks"; 
  
    cout << "The initial string is : "; 
    cout << str << endl; 
  
    str.resize(13); 
  
    cout << "The string after resize operation is : "; 
    cout << str << endl; 
  
    cout << "The capacity of string is : "; 
    cout << str.capacity() << endl; 
  
    // Decreasing the capacity of string 
    // using shrink_to_fit() 
    str.shrink_to_fit(); 
  
    cout << "The new capacity after shrinking is : "; 
    cout << str.capacity() << endl; 
  
    return 0; 
  
} 
