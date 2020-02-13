#include<iostream>
#include<spawn.h>
#include<sys/wait.h>
#include<sched.h>
#include<unistd.h>
using namespace std;
int main()
{
int pid1, pid2;
char str1[]="mkdir";
char str2[]="C";
char str3[]="pwd";
char *arg1[]={str1,str2,(char*)0};
char *arg2[]={str3,(char*)0};
int val1 = posix_spawn(&pid1,"/bin/mkdir",NULL,NULL,arg1,NULL);
int val2 = posix_spawn(&pid2,"/bin/pwd",NULL,NULL,arg2,NULL);
/*
cout<<"\n\n\t Process ID : "<<pid1 <<" Status " <<val1;
cout<<"\n\n\t Process ID : "<<pid2 <<" Status  " <<val2;
*/
int c =sysconf(_SC_NPROCESSORS_CONF);
cout<<" \n Number of Cores: "<<c<<"\n";
cpu_set_t cpu1,cpu2;
CPU_ZERO(&cpu1);
CPU_ZERO(&cpu2);
CPU_SET(0,&cpu1);
CPU_SET(1,&cpu2);

int c1 = sched_setaffinity(pid1, sizeof(cpu_set_t),&cpu1);
int c2 = sched_setaffinity(pid2, sizeof(cpu_set_t),&cpu2);
if(c1==0)
{cout<<"Process 1 with id: "<<pid1<<"is running on core 0 and its Status is : "<<val1<<"\n ";
}

if(c2==0)
{cout<<"Process 2 with id: "<<pid2<<"is running on core 1 and its Status is : "<<val2<<"\n";
}
return 0;
}
