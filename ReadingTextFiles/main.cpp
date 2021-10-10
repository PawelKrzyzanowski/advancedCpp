#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    string iname = "file.txt";
    string oname = "ofile.txt";

    ifstream iFile;
    ofstream oFile;
    iFile.open(iname);
    oFile.open(oname);
    if(iFile.is_open()){
        string line;
        while(iFile){
            getline(iFile, line);
            cout<<line<<endl;
            if(oFile.is_open()){
                oFile<<line<<endl;
            }
            else{
                cout<<"The oFile coudn't be opened.";
                break;
            }
        }
        iFile.close();
    }
    if(oFile.is_open())
        oFile.close();

    return 0;
}
