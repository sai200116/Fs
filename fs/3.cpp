#include<iostream>
#include<fstream>
#include<string>
using namespace std;
fstream fd;
class match
{
    public :
        int read(string str[],int choice)
        {
            int n=0;
            string key;
            switch(choice)
            {
                case 1 : fd.open("list1.txt",ios::in);break;
                case 2 : fd.open("list2.txt",ios::in);break;
            }
            while(fd.eof()==0)
            {
                fd>>key;
                str[n++]=key;
            }
            fd.close();
            sorting(str,n);
            return n;
        }
        void sorting(string s[],int n)
        {
            int i,j;
            string temp;
            for(i=0;i<n;i++)
            {
                for(j=0;j<n-1;j++)
                {
                    if(s[j].compare(s[j+1])>0)
                    {
                        temp=s[j];
                        s[j]=s[j+1];
                        s[j+1]=temp;
                    }
                }
            }
        }
        void match_list()
        {
            int n1,n2,i=0,j=0,k=0;
            string a[10],b[10],c[10],item1,item2;
            n1=read(a,1);
            n2=read(b,2);
            item1=a[i++];
            item2=b[j++];
            while(i<n1||j<n2)
            {
                if(item1.compare(item2)<0)
                {
                    item1=a[i++];
                }
                else if(item1.compare(item2)==0)
                {
                    c[k++]=item1;
                    item1=a[i++];
                    item2=b[j++];
                }
                else
                {
                    item2=b[j++];
                }
            }
            fd.open("List3.txt",ios::out);
            cout<<"the Match List Names Are..:\n";
            for(i=0;i<k;i++)
            {
                fd<<c[i];
                cout<<c[i]<<endl;
            }
            fd.close();
        }
};
int main()
{
    match m;
    m.match_list();
    return 0;
}
