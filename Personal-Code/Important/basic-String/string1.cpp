#include <bits/stdc++.h> 
using namespace std; 
/*
we can get length of string 
by size() as well as length() 
but length() is preferred for strings.
We can concat a string to another string
by += or by append(), 
but += is slightly slower than append()
because each time + is called
a new string (creation of new buffer)
is made which is returned that is a bit
overhead in case of many append operation. 
*/  
int main() 
{ 
 
    string str1("first string"); //str1 = first string
  
    string str2(str1); //str2 = first string
  
    string str3(5, '#'); //str3 = #####
  
    string str4(str1, 6, 6); //str4 = string
  
    string str5(str2.begin(), str2.begin() + 5); //str5 = first
  
    cout << str1 << endl; 
    cout << str2 << endl; 
    cout << str3 << endl; 
    cout << str4 << endl; 
    cout << str5 << endl; 
  
    string str6 = str4; //str6 = string
  
    str4.clear(); //str4 = \0
  
    int len = str6.length(); // len = 6 , Same as "len = str6.size();" 
  
    cout << "Length of string is : " << len << endl; 
  
    char ch = str6.at(2); //  ch = r , Same as "ch = str6[2];" 
  
  
    cout << "third character of string is : " << ch << endl; 
  
    char ch_f = str6.front();  // Same as "ch_f = str6[0];" 
    char ch_b = str6.back();    // "ch_b = str6[str6.length() - 1];" 
                              
    cout << "First char is : " << ch_f << ", Last char is : "
         << ch_b << endl; 
  
    // c_str returns null terminated char array version of string 
    const char* charstr = str6.c_str(); 
    printf("%s\n", charstr); 
  
    str6.append(" extension"); //  same as str6 += " extension"
     
  
    // another version of appends, which appends part of other 
    // string 
    str4.append(str6, 0, 6);  // at 0th position 6 character 
  
    cout << str6 << endl; 
    cout << str4 << endl; 
  
    //  find returns index where pattern is found. 
    //  If pattern is not there it returns predefined 
    //  constant npos whose value is -1 
  
    if (str6.find(str4) != string::npos) 
        cout << "str4 found in str6 at " << str6.find(str4) 
             << " pos" << endl; 
    else
        cout << "str4 not found in str6" << endl; 
  
    //  substr(a, b) function returns a substring of b length 
    //  starting from index a 
    cout << str6.substr(7, 3) << endl; 
  
    //  if second argument is not passed, string till end is 
    // taken as substring 
    cout << str6.substr(7) << endl; 
  
    //  erase(a, b) deletes b character at index a 
    str6.erase(7, 4); 
    cout << str6 << endl; 
  
    //  iterator version of erase 
    str6.erase(str6.begin() + 5, str6.end() - 3); 
    cout << str6 << endl; 
  
    str6 = "This is a examples"; 
  
    //  replace(a, b, str)  replaces b character from a index by str 
    str6.replace(2, 7, "ese are test"); 
  
    cout << str6 << endl; 
  
    return 0; 
} 
