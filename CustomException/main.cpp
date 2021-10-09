#include <iostream>
#include <exception>

using namespace std;

// This is my own Exception class, to define some special exceptions
// The best way is to heritage methods form C++ standard exception class
// including the what() method, to return string msg.

class MyExceptionClass: public exception
{
    public:
        //This line is copied from original exception documentation for the what() method
        //What is does here it overrides the original method with mine.
        virtual const char * what() const throw(){
            //"const throw()" means that method can't throw exception
            return "This is my exception description, e.g. badd_alloc not enough memory...";
    }
};

class aClass{
    public:
        void fail(){
            cout<<"Fail function is running and sth failed"<<endl;
            throw MyExceptionClass(); //This is construtctor heritaged form exception
    }
};

int main()
{
    aClass instance;
    try{
        instance.fail();
    }
    catch(MyExceptionClass &e){
        cout<<"Here my fail function throw my exception: "<<e.what()<<endl;
    }

    return 0;
}
