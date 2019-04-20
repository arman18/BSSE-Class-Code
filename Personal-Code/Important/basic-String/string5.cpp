#include<iostream> 
#include<string> // for string class 
/*
1) copy(“char array”, len, pos)
This function copies the substring in
 target character array mentioned in 
 its arguments. It takes 3 arguments,
 target char array, length to be copied
 and starting position in string to 
 start copying
 2) swap()
 
*/
using namespace std; 
int main() 
{ 
    string str1 = "geeksforgeeks is for geeks"; 
  
    string str2 = "geeksforgeeks rocks"; 
  
    char ch[80]; 
  
    str1.copy(ch,13,0); 
  
    cout << "The new copied character array is : "; 
    cout << ch << endl << endl; //geeksforgeeksU
  
    cout << "The 1st string before swapping is : "; 
    cout << str1 << endl; //geeksforgeeks is for geeks
    cout << "The 2nd string before swapping is : "; 
    cout << str2 << endl; //geeksforgeeks rocks
  
    str1.swap(str2); 
  
    cout << "The 1st string after swapping is : "; 
    cout << str1 << endl; //geeksforgeeks rocks
    cout << "The 2nd string after swapping is : "; 
    cout << str2 << endl; //geeksforgeeks is for geeks
  
    return 0; 
  
} 
