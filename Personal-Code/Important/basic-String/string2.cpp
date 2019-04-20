#include<iostream> 
#include<string> // for string class 
/*
1)getline()
2)push_back()
3)pop-back()
*/
using namespace std; 
int main() 
{ 
    string str; 
  
    getline(cin,str); //arman
  
    cout << "The initial string is : "; 
    cout << str << endl; 
  
    str.push_back('s'); //armans
  
    cout << "The string after push_back operation is : "; 
    cout << str << endl; 
  
    str.pop_back(); //arman
  
    cout << "The string after pop_back operation is : "; 
    cout << str << endl; 
  
    return 0; 
  
} 
