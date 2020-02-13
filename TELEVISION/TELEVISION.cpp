#include<iostream>
using namespace std;
class television
{
int model_no,screen_size,price;
public:
friend void operator >> (istream & scan, television &t1);
friend void operator << (ostream & print, television &t);
};
void operator >> (istream & scan, television &t1)
{
try
{
cout<<"\nENTER THE MODEL NUMBER : ";
cin>>t1.model_no;
cout<<"\nENTER THE SCREEN SIZE : ";
cin>>t1.screen_size;
cout<<"\nENTER THE PRICE : ";
cin>>t1.price;
if(t1.model_no >9999)
throw(0);
if(t1.screen_size<12 || t1.screen_size>70)
throw(1);
if(t1.price<0 || t1.price>5000)
throw(2);
}
catch(int i)
{
if (i==0)
cout<<"MODEL NUMBER IS INVALID.";
if (i==1)
cout<<"SCREEN SIZE IS INVALID.";
if (i==2)
cout<<"PRICE IS INVALID.";
t1.model_no=t1.screen_size=t1.price=0;
}
}
void operator << (ostream & print, television &t)
{
cout<<"\nMODEL NUMBER : "<<t.model_no<<"\tSCREEN SIZE :"<<t.screen_size<<"inches\tPRICE : $"<<t.price;
}
int main()
{
television t[100];
int c,i=0,n;
cout<<"\nENTER THE NUMBER OF TELEVISION : ";
cin>>n;
while(1)
{
cout<<"\nMENU\n1.ADD DATA.\n2.DISPLAYDATA.\n3.EXIT.\nENTER YOUR CHOICE : ";
cin>>c;
switch(c)
{
case 1:for(i=0;i<n;i++)
cin>>t[i];
break;
case 2:for(i=0;i<n;i++)
cout<<t[i];
break;
case 3: return 0;
}
}
return 0;
}
