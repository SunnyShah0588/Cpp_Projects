#include<iostream>
#include<sys/stat.h>
#include<dirent.h>
#include<time.h>
#include<sys/types.h>
using namespace std;

int main()
{

	char fname[20];
	char dname[20];
	struct stat buff;
	struct dirent *d;
	DIR *p;
	int ch;
	char ch1;

	do
	{
		cout<<"1)File system information\n";
		cout<<"2)Directory information\n";
		cout<<"Enter your choice :";
		cin>>ch;
		switch(ch)
		{
		case 1:
			cout<<"Enter file name :";
			cin>>fname;
			stat(fname,&buff);
			cout<<"Inode number is :"<<buff.st_ino<<endl;
			cout<<"Device ID :"<<buff.st_dev<<endl;
			cout<<"Mode :"<<buff.st_mode<<endl;
      		cout<<"Access time:"<<ctime(&buff.st_atime)<<endl;
			cout<<"Modify time :"<<ctime(&buff.st_mtime)<<endl;	//data modification
			cout<<"Change time :"<<ctime(&buff.st_ctime)<<endl;	//status change*/
			break;
		case 2:
			cout<<"Enter directory name :";
			cin>>dname;
			p=opendir(dname);
                		while(d =readdir(p))
                		{
				cout<<"Directory Name :"<<d->d_name<<" ";
                      		 	cout<< "(Inode :"<<d->d_ino<<")"<<endl;

                		}
                		closedir(p);
                		break;

                }
                cout<<"Continue? :";
                cin>>ch1;
         }while(ch1=='y');
   return 0;
}
