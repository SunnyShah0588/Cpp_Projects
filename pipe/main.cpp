#include<iostream>
#include<sys/types.h>
#include<unistd.h>
#include <stdio.h>
#include <stdlib.h>

using namespace std;
int main()
{
	int fdis[2],child_pid,a,b;
	char str[200],buff[200],rev[200];
	//pipe(fdis);
	child_pid=fork();
	if(child_pid==-1)
	{
		cout<<"\nChild Process Failed";
	}
	else
	{ 	if(child_pid==0)
		{
			close(fdis[0]);
			cout<<"\nEnter the String : ";
			cin>>str;
			write(fdis[1],str,sizeof(str));
			//a=1;
			return 0;
		}
		else
		{
			close(fdis[1]);
			read(fdis[0],buff,sizeof(buff));

			for(int i=0;buff[i]!='\0';i++)
			{
				b=i;
			}

			for(int i=b,j=0;i>=0;i--,j++)
			{
				rev[j]=buff[i];
			}

			cout<<"\nReversed String is : "<<rev<<"\n";
		}
	}
	return 0;
}

