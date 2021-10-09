#include <iostream>

// LIST OF STANDARD C++ EXCEPTIONS:
// https://www.tutorialspoint.com/cplusplus/cpp_exceptions_handling

using namespace std;

void aFunction(){
    bool isError1 = false;
    bool isError2 = false;

    char * anArray = new char[99999999999999]; //new can throw bad_alloc

    if(isError1)
        throw bad_alloc();  //child class first
    cout<<"The program continues!"<<endl;
    if(isError2)
        throw exception();  //parent class next
}

int main()
{
    try{
        aFunction();
    }
    catch(bad_alloc &e){
        cout<<"First catch child class exceptions like the bad_alloc: "<<e.what()<<endl;
    }
    catch(exception &e){
        cout<<"Then parent polimorfism classes like the exception: "<<e.what()<<endl;
    }

    return 0;
}
