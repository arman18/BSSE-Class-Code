#include <bits/stdc++.h> 
using namespace std; 
  
/*
there are three different way
Method 1 : Using ostringstream class or sscanf()
Method 2 : Using to_string() 
Method 3 : Using boost(is a library name) lexical cast() 

*/ 

int method1()
{
	int num = 2016; 
  
    ostringstream str1; 
  
    str1 << num; 
  
    string geek = str1.str(); 
  
    cout << "The newly formed string from number is : "; 
    cout << geek << endl; //2016
  
    return 0; 
}
//নিচেরগুলো কাজ করে না
int method2()
{
    int i_val = 20; 
  
    float f_val = 30.50; 
  
    string stri = to_string(i_val); 
  
    string strf = to_string(f_val); 
  
    cout << "The integer in string is : "; 
    cout << stri << endl; //20
    cout << "The float in string is : "; 
    cout << strf << endl; //30.500000
  
    return 0;
}

int method3()
{
   float f_val = 10.5; 
  
   int i_val = 17; 
     
   string strf = boost::lexical_cast<string>(f_val);  
     
   string stri = boost::lexical_cast<string>(i_val);  
     
   cout << "The float value in string is : "; 
   cout << strf << endl; //10.5
   cout << "The int value in string is : "; 
   cout << stri << endl; //17
     
   return 0;
}
