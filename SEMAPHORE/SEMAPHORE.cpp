#include <unistd.h>     /* Symbolic Constants */
#include <sys/types.h>  /* Primitive System Data Types */
#include <errno.h>      /* Errors */
#include <stdio.h>      /* Input/Output */
#include <stdlib.h>     /* General Utilities */
#include <pthread.h>    /* POSIX Threads */
#include <string.h>     /* String handling */
#include <semaphore.h>  /* Semaphore */
#include<iostream>
using namespace std;
sem_t var;
int counter=0;           //shared variable
void *mytask(void * ptr)
{
	int th_counter;
	th_counter = *((int*)ptr);
cout<<"\n Thread "<<th_counter<<" waiting in critical section";
sem_wait(&var);            // start of Critical section
cout<<"\n Thread "<<th_counter<<" in critical region";
cout<<"\n counter value="<<counter;
cout<<"\n Thread "<<th_counter<<" is incrementing the counter";
counter++;
cout<<"\n counter value ="<< counter;
cout<<"\n Thread "<<th_counter<<" is leaving the critical section\n";

                  //End of critical section

sem_post(&var);  //function increments the value of semaphore and wake up a blocked process
pthread_exit(0);

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

sem_init(&var,0,1);  //used for initialization of semaphore value (&var=semaphore object to initialize,
                    //  pshared = if semaphore is local to process then its value must be 0,
                   //value=initial value set to semaphore
pthread_create(&t1,NULL,&mytask,(void*)&thread[0]);
pthread_create(&t2,NULL,&mytask,(void*)&thread[1]);
pthread_create(&t3,NULL,&mytask,(void*)&thread[2]);
pthread_join(t1,NULL);
pthread_join(t2,NULL);
pthread_join(t3,NULL);
sem_destroy(&var);
return 0;

}
