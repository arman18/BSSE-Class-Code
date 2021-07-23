#include <iostream>
#include <memory>
using namespace std;

void func(){ // memory leaks
    int *a = new int(5);
    cout<<a<<" "<<*a<<endl;

}

void func2(){ // manual delete, but leaks memory is face exception before delete
    int *a = new int(5);
    cout<<a<<" "<<*a<<endl;
    delete a;

}
void func3(){ // by smart pointer
    int *a = new int(5);
    cout<<a<<" "<<*a<<endl;
    std::unique_ptr<int> album(a); // album is parent of a

}
void funcLocal(){
    int a = 5;
    cout<<a<<" "<<&a<<endl;

}

int main(int /*argc*/, char *argv[])
{
    ///*
    // checking pointer

    int *a,*b;
    func3();
    int ab;
    cin>>hex>>ab;
    cout<<"input: "<<hex<<ab<<endl;
    a = (int *)ab;
    cout<<*a<<endl;
    //*/
//    int *a,*b;
//    //b = func();
//    funcLocal();
//    int ab;
//    cin>>hex>>ab;
//    cout<<"input: "<<hex<<ab<<endl;
//    a = (int *)ab;
//    cout<<*a<<endl;
    return 0;
}
