#include<iostream>

#include<fstream>

#include<string>

using namespace std;

fstream fd;

class match

{

	public :

			 int read(string a[],int c)

			 {

				int n=0;

				switch(c)

				{

					case 1 :fd.open("text1.txt",ios::in);break;

					case 2 :fd.open("text2.txt",ios::in);break;

				}

				while(fd.eof()==0)

				{

					 fd>>a[n++];

				}

				fd.close();

				sort(a,n);

				return n;

			}

			void sort(string d[],int n)

			{

				int i,j;

				string temp;

				for(i=0;i<n;i++)

				{

					for(j=0;j<n-1;j++)

					{

						if(d[j].compare(d[j+1])>0)

						{

							temp=d[j];

							d[j]=d[j+1];

							d[j+1]=temp;

						}

					}

				}

			}

			void match1()

			{

				string a[10],b[10];

				string c[10];

				int k=0,i=0,j=0,n1,n2;

				n1=read(a,1);

				n2=read(b,2);

				string item1,item2;

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

				i=0;

				cout<<"The Match List Names Are :"<<endl;

				fd.open("match.txt",ios::out|ios::app);

				while(i<k)

				{

					fd<<c[i]<<endl;

					cout<<c[i++]<<endl;

				}

				fd.close();

			}

};

int main()

{

	match m;

	m.match1();

	return 0;

}
