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
char str2[]="FILENAME";
char str3[]="pwd";
char *arg1[]={str1,str2,(char*)0};
char *arg2[]={str3,(char*)0};
int val1 = posix_spawn(&pid1,"/bin/mkdir",NULL,NULL,arg1,NULL);
int val2 = posix_spawn(&pid2,"/bin/pwd",NULL,NULL,arg2,NULL);
/*
cout<<"\n\n\t Process ID : "<<pid1 <<" Status " <<val1;
cout<<"\n\n\t Process ID : "<<pid2 <<" Status  " <<val2;
*/
int c =sysconf(_SC_NPROCESSORS_ONLN);    //returns the number of processors which are currently online
cout<<" \n Number of Cores ONLINE ARE : "<<c<<"\n";


cpu_set_t cpu1,cpu2;   //data structure represents a set of CPUs

// macros are provided to operate on the CPU set set

CPU_ZERO(&cpu1);  //Clears set, so that it contains no CPUs.
CPU_ZERO(&cpu2);
CPU_SET(0,&cpu1);  // Add CPU cpu to set.
CPU_SET(1,&cpu2);

/* A thread's CPU affinity mask determines the set of CPUs on which it
       is eligible to run.  On a multiprocessor system, setting the CPU
       affinity mask can be used to obtain performance benefits.*/

 /*       sched_setaffinity() sets the CPU affinity mask of the thread whose ID
       is pid to the value specified by mask.  If pid is zero, then the
       calling thread is used.  The argument cpusetsize is the length (in
       bytes) of the data pointed to by mask.  Normally this argument would
       be specified as sizeof(cpu_set_t).

       If the thread specified by pid is not currently running on one of the
       CPUs specified in mask, then that thread is migrated to one of the
       CPUs specified in mask.*/

int c1 = sched_setaffinity(pid1, sizeof(cpu_set_t),&cpu1);
int c2 = sched_setaffinity(pid2, sizeof(cpu_set_t),&cpu2);
if(c1==0)
{cout<<"Process 1 with id: "<<pid1<<" is running on core 0 and its Status is : "<<val1<<"\n ";
}

if(c2==0)
{cout<<"Process 2 with id: "<<pid2<<" is running on core 1 and its Status is : "<<val2<<"\n";
}
return 0;
}
