#include<iostream>
#include<pthread.h>
#include<stdlib.h>
using namespace std;
int a[3][3]={1},b[3][3]={1},c[3][3]={0};
int i,j,k;
void insert()
{
cout<<"\n INSERT MATRIX 1\n";
for(i=0;i<3;i++)
{
for(j=0;j<3;j++)
{
cin>>a[i][j];
}
}
cout<<"\n INSERT MATRIX 2\n";
for(i=0;i<3;i++)
{
for(j=0;j<3;j++)
{
cin>>b[i][j];
}
}
}
void * calc(void *val)
{
int from = *((int*)val);
int to=from+1;
cout<<"\n I am Thread"<<from<<"\n";
for(i=from;i<3;i++)
{
for(j=0;j<3;j++)
{
c[i][j]=0;
for(k=0;k<3;k++)
{
c[i][j]+=a[i][k]*b[k][j];
}}
}
return NULL;
}
void display()
{
cout<<"\n MATRIX 1 is:\n";
for(i=0;i<3;i++)
{
for(j=0;j<3;j++)
{
cout<<a[i][j]<<"\t";
}
cout<<"\n";
}
cout<<"\n MATRIX 2 is :\n";
for(i=0;i<3;i++)
{
for(j=0;j<3;j++)
{
cout<<b[i][j]<<"\t";
}
cout<<"\n";
}
cout<<"\n Resultant MATRIX is :\n";
for(i=0;i<3;i++)
{
for(j=0;j<3;j++)
{
cout<<c[i][j]<<"\t";
}
cout<<"\n";
}
}
int main()
{
pthread_t t0,t1,t2;
int val0=0,val1=1,val2=2;
int rval0,rval1,rval2;
insert();
rval0=pthread_create(&t0,NULL,calc,(void*)&val0);
rval1=pthread_create(&t1,NULL,calc,(void*)&val1);
rval2=pthread_create(&t2,NULL,calc,(void*)&val2);
pthread_join(t0,NULL);
pthread_join(t1,NULL);pthread_join(t2,NULL);
display();
return 0;
}
