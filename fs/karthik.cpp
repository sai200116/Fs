#include<iostream>
#include<fstream>
using namespace std;
int main()
{
    fstream fd;
    fd.open("file.txt",ios::in);
    int i=1;
    char reg[11],name[16],ph[11];
    while(!fd.eof())
    {
        fd.get(reg,11);
        fd.get(name,16);
        fd.get(ph,11);
        cout<<"Student"<<i++<<endl;
        cout<<"Reg"<<reg<<endl;
        cout<<"Name"<<name<<endl;
        cout<<"Phone"<<ph<<endl;
    }
    fd.close();
    return 0;
}
