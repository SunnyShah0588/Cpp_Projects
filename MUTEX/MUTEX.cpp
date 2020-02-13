#include <unistd.h>     /* Symbolic Constants */
#include <sys/types.h>  /* Primitive System Data Types */
#include <errno.h>      /* Errors */
#include <stdio.h>      /* Input/Output */
#include <stdlib.h>     /* General Utilities */
#include <pthread.h>    /* POSIX Threads */
#include <string.h>     /* String handling */
//#include <semaphore.h>/* Semaphore */
#include<iostream>

//MUTEX = MUTAL EXCLUSION

using namespace std;
pthread_mutex_t mutex;
int counter=0;
void *mytask(void * ptr)
{
	int th_counter;
	th_counter = *((int*)ptr);
pthread_mutex_lock(&mutex);// request ownership
cout<<"\n Thread "<<th_counter<<" waiting in critical section";
//Start critical section
cout<<"\n Thread "<<th_counter<<" in critical region";
cout<<"\n counter value="<<counter;
cout<<"\n Thread "<<th_counter<<" is incrementing the counter";
counter++;
cout<<"\n counter value ="<< counter;
cout<<"\n Thread "<<th_counter<<" is leaving the critical section\n";
// end of critical section
pthread_mutex_unlock(&mutex);//Release ownership
return NULL;
}

int main()
{
int thread[3];
pthread_t t1;
pthread_t t2;
pthread_t t3;

thread[0]=1;
thread[1]=2;
thread[2]=3;
/*
if(pthread_mutex_init(&mutex,NULL)!=0)// Mutex initialization
{
cout<<"\n Mutex init failed \n";
return 1;
}
*/
pthread_mutex_init(&mutex,NULL); //(*mutex,attr ) successful return 0 otherwise error
pthread_create(&t1,NULL,&mytask,(void*)&thread[0]);
pthread_create(&t2,NULL,&mytask,(void*)&thread[1]);
pthread_create(&t3,NULL,&mytask,(void*)&thread[2]);
pthread_join(t1,NULL);
pthread_join(t2,NULL);
pthread_join(t3,NULL);
pthread_mutex_destroy(&mutex);
return 0;

}
