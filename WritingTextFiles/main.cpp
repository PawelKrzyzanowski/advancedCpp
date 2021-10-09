#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    //included fstream class gives me two ways to write chars to a file
    string fileName = "file.txt";
    ofstream aFile1; //1 method
    fstream aFile2; //2 method
    //1 method usage
    aFile1.open(fileName);
    if(aFile1.is_open()){
        aFile1 << "The first line of text, then numbers: " << endl;
        aFile1 << 123 << endl;
        aFile1 << 321 << endl;
        aFile1.close();
    }
    else{
        cout<<"The "<<fileName<<" has not opened."<<endl;
    }
    aFile2.open(fileName, ios::out);
    if(aFile2.is_open()){
        aFile2 << "Second opening overwrites whole the file text!: " << endl;
        aFile2 << 456 << endl;
        aFile2.close();
    }
    else{
        cout<<"The "<<fileName<<" has not opened at 2nd time."<<endl;
    }
    return 0;
}
