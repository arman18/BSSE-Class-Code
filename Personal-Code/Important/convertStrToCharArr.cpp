#include <bits/stdc++.h> 
using namespace std; 
  
/*
Method 1 : Using c_str() function && strcpy()
The c_str() function is used to return
a pointer to an array that contains a
null terminated sequence of character
representing the current value of the string
syntax:
	const char* c_str() const ;
	
Method 2 : Using to_string() 
Method 3 : Using boost(is a library name) lexical cast() 

*/ 
int main() 
{ 
    // assigning value to string s 
    string s = "geeksforgeeks"; 
  
    int n = s.length();  
      
    // declaring character array 
    char char_array[n+1];  
      
    // copying the contents of the  
    // string to char array 
    strcpy(char_array, s.c_str());  
      
    for (int i=0; i<n; i++) 
      cout << char_array[i]; //geeksforgeeks
  
    return 0; 
}

//Another approach:

int main() 
{ 
// assigning value to string p 
char p[]="geeksforgeeks"; 
string s; 
int i; 
for(i=0;i<sizeof(p);i++) 
{ 
s[i]=p[i]; 
cout<<s[i]; 
} 
return 0; 
} 
