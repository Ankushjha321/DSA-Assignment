#include<iostream>
#include<fstream>
using namespace std;

int main(){
    ofstream fout;
    string line;
    fout.open("Vasu.txt");
    while(fout){
        cout<<"Enter a string";
        getline(cin, line);

        if(line=="-1"){
            break;
        }

        fout<<line<<endl;
    }

    fout.close();

    ifstream fin;
    fin.open("Vasu.txt");
    fin.seekg(4);

    while(fin){
        getline(fin,line);
       cout<<line<<endl;
       }
    fin.close();
    return 0;
}