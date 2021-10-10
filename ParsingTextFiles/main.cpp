#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    fstream iFile; //it's an instance
    string iFileName = "idata.txt";

    iFile.open(iFileName, ios::in);

    if( !iFile.is_open() ){
        cout<<"Can not open file "<<iFileName;
        return 1;
    }

    while( iFile ){
        string text;
        int population;
        getline(iFile, text, ':');
        iFile>>population;
        //iFile.get(); //gets endline C++98
        iFile>>ws; //gets white space endline in C++ 11
        if( !iFile ) //to avoid lat line print
            break;

        cout<<text<<"....."<<population<<endl;
    }
    iFile.close();

    return 0;
}
