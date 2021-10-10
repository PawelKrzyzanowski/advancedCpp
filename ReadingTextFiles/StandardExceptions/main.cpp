#include <iostream>

using namespace std;

class aClass{
    public:
        aClass(){
            char * chArray = new char[99999999999]; //Exception: bad allocation error terminates the program
            delete chArray;
        }
};

int main()
{
    try{
        aClass instance;
    }
    catch(bad_alloc &e){    //catch the exception with REFERENCE !
        //bad_alloc is a class with method what
        cout<<"Standard Class Exception: "<<e.what()<<endl;
    }
    return 0;
}
