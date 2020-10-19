#include<iostream>
#include<fstream>
using namespace std;
fstream fd;
class student
{
public:

    string Registration_num,Name,Phone,buffer;
    void pack()
    {
        buffer="";
        cout<<"Enter Registration no"<<endl;
        cin>>Registration_num;
        cout<<"Enter name:"<<endl;
        cin>>Name;
        cout<<"Enter Phone number"<<endl;
        cin>>Phone;
        buffer+=Registration_num+'|'+Name+'|'+Phone+'|'+'#';
        fd.open("student.txt",ios::out|ios::app);
        fd<<buffer;
        fd.close();
    }
    void unpack()
    {
        fd.open("student.txt",ios::in);
        cout<<"Details are"<<endl;
        while(getline(fd,Registration_num,'|')&&getline(fd,Name,'|')&&getline(fd,Phone,'|'))
        {
            cout<<"Registration number"<<Registration_num<<endl;
            cout<<"Name"<<Name<<endl;
            cout<<"Phone"<<Phone<<endl;

        }
        fd.close();
    }

};
int main()
{
    student s;
    int ch,n,i;
    cout<<"Enter no of Students";
    cin>>n;
    for(i=0;i<n;i++)
    {
        do
            {
                cout<<"Enter an option"<<endl;
                cout<<"1) Insert"<<endl<<"2) Display"<<endl<<"3) exit"<<endl;
                cin>>ch;
                switch(ch)
                {
                    case 1: s.pack();
                            break;
                    case 2: s.unpack();
                            break;
                    case 3: exit(0);
                            break;

                }


            }while(ch>0&&ch<4);
    }
}
