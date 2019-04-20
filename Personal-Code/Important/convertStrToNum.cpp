#include <bits/stdc++.h> 
using namespace std; 
  
/*
there are three different way
Method 1 : Using istringstream class or sscanf()
Method 2 : String conversion using stoi() or atoi()
Method 3 : Using boost(is a library name) lexical cast() 

*/ 

void method3()
{
	 
   string str = "5"; 
   string str1 = "6.5"; 
  
   float f_value = boost::lexical_cast<float>(str1); 
  
   int i_value = boost::lexical_cast<int>(str); 
  
   cout << "The float value after casting is : "; 
   cout << f_value <<endl; //6.5
   cout << "The int value after casting is : "; 
   cout << i_value <<endl; //5
  
   return 0; 
}
