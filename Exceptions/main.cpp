#include <iostream>

using namespace std;

void aFunction(){
    bool isError = true;
    if(isError)
        throw 8;
}

void bFunction(){
    bool isError = true;
    if(isError)
        throw 8;
}

void cFunction(){
    bool isError = true;
    if(isError)
        throw "Something went wrong c.";
}

void dFunction(){
    bool isError1 = true;
    bool isError2 = true;
    if(isError1)
        throw "Something went wrong d1.";
        cout<<"I am not executing d1."<<endl; //The functions stops after first error throw
    if(isError2)
        throw string("Something else went wrong d2.");
}

void eFunction(){
    bool isError1 = false;
    bool isError2 = true;
    if(isError1)
        throw "Something went wrong e1.";
    cout<<"I am executing e1."<<endl;
    if(isError2)
        throw string("Something else went wrong e2.");  //constructs object of String class
    cout<<"I am not executing e2."<<endl;
}

void nestingFunction(){
    eFunction();
}

int main(){
    //aFunction(); //The error is not cached, the compiler outs error and terminates the program
    try{
        bFunction(); //Try to catch the error
    }
    catch(int e){
        cout<<"Error No: "<<e<<endl;
    }
    cout<<"I am still running 1."<<endl; //The error has been catched so the program can continue.

    try{
        cFunction();
    }
    catch(int e){
        cout<<"Error No: "<<e<<endl; //With just the one catch for int argument, compiler terminates at String error threw
    }
    catch(char const * e){
        cout<<"Error Msg: "<<e<<endl;   //The char chain is catched with POINTER !
    }
        cout<<"I am still running 2."<<endl; //The error has been catched witch proper argument type, the program continues!

    try{
        dFunction();
    }
    catch(char const * e){
        cout<<"Error Msg: "<<e<<endl;
    }
    cout<<"I am still running 3."<<endl;

    try{
        eFunction();
    }
    catch(char const * e){
        cout<<"Error Msg: "<<e<<endl;
    }
    catch(string &e){
        cout<<"Error String: "<<e<<endl;    //String object is catched with REFERENCE !
    }
    cout<<"I am still running 4."<<endl;
    cout<<"Trying nested function:"<<endl;
    try{
        nestingFunction();
    }
    catch(char const * e){
        cout<<"Error Msg: "<<e<<endl;
    }
    catch(string &e){
        cout<<"Error String: "<<e<<endl;    //String object is catched with REFERENCE !
    }
    cout<<"I am still running 5."<<endl;
}
