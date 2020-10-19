#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;
fstream fd;
class student
{
    public:
        char Register_Number[12],Name[15],Phone_Number[12],buffer[100];
        void padding(char str[],int n)
        {
            int i;
            for(i=0;i<n-1;i++)
            {
                if(str[i]=='\0')
                {
                    str[i]=' ';
                    str[i+1]='\0';
                }
            }
            strcat(buffer,str);
            return;
        }
        void pack()
        {
            int len;
            strcpy(buffer,"");
            len=sizeof(Register_Number);
            cout<<"Enter Register Number..:\n";
            cin>>Register_Number;
            padding(Register_Number,len);
            len=sizeof(Name);
            cout<<"Enter Name..:\n";
            cin>>Name;
            padding(Name,len);
            len=sizeof(Phone_Number);
            cout<<"Enter Phone Number..:\n";
            cin>>Phone_Number;
            padding(Phone_Number,len);
            fd.open("student.txt",ios::out|ios::app);
            fd<<buffer;
            fd.close();
        }
        void unpack()
        {
            fd.open("student.txt",ios::in);
            while(fd>>Register_Number&&fd>>Name&&fd>>Phone_Number)
            {
                cout<<"Register_Number : "<<Register_Number<<endl;
                cout<<"Name : "<<Name<<endl;
                cout<<"Phone_Number : "<<Phone_Number<<endl;
            }
            fd.close();
        }
};
int main()
{
    int choice;
    student s;
    do
    {
        cout<<"1 : insert\n";
        cout<<"2 : display\n";
        cout<<"3 : exit\n";
        cout<<"Enter your choice..:\n";
        cin>>choice;
        switch(choice)
        {
            case 1 : s.pack();break;
            case 2 : s.unpack();break;
            case 3 : cout<<"exit\n";
        }
    }while(choice>0&&choice<3);
    return 0;
}
