#include<iostream>
#include<fstream>
using namespace std;
void insert_table()
{
    int n;
    printf("Enter Number Of Keys..:\n");
    scanf("%d",&n);
    int hashtable[n];
    int i,j,address,key,flag=0;
    for(i=0;i<n;i++)
    {
        hashtable[i]=-1;
    }
    for(i=1;i<=n;i++)
    {
        printf("Enter Key..:\n");
        scanf("%d",&key);
        address=key%n;
        flag=0;
        for(j=address;j<n;j++)
        {
            if(hashtable[j]==-1)
            {
                flag=1;
                hashtable[j]=key;
                break;
            }
        }
        if(flag==0)
        {
            for(j=0;j<address;j++)
            {
                if(hashtable[j]==-1)
                {
                    flag=1;
                    hashtable[j]=key;
                    break;
                }
            }
        }
    }
    printf("THE HASHTABLE IS\n");
    printf("Address\t\tKeyValue\n");
    fstream fd;
    fd.open("hash.txt",ios::out);
    fd<<"Address\t\tKeyValue\n";
    for(i=0;i<n;i++)
    {
        printf("%d\t\t%d\n",i,hashtable[i]);
        fd<<i<<"\t\t"<<hashtable[i]<<"\n";
    }
    fd.close();
    return;
}
int main()
{
    insert_table();
    return 0;
}
