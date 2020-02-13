#include <iostream>
#include <math.h>

using namespace std;

class COMPLEX{

    float real,img;

public:
        COMPLEX(){

          real=0;
          img=0;

        }
  COMPLEX(float x,float y){

      real=x;
      img=y;
  }

  COMPLEX operator+(COMPLEX c){

    COMPLEX temp;
    temp.real=real+c.real;
    temp.img=img+c.img;
    return temp;
  }
    COMPLEX operator-(COMPLEX c){

    COMPLEX temp;
    temp.real=real-c.real;
    temp.img=img-c.img;
    return temp;
  }

    COMPLEX operator*(COMPLEX c){

    COMPLEX temp;
    temp.real=(real*c.real)-(img*c.img);
    temp.img=(img*c.real+real*c.img);
    return temp;
  }
    COMPLEX operator/(COMPLEX c){

    COMPLEX temp;
    temp.real=(((real*c.real)+(img*c.img))/(pow(c.real,2)+pow(c.img,2)));
    temp.img=(((img*c.real)-(real*c.img))/(pow(c.real,2)+pow(c.img,2)));
    return temp;
  }

  void display(){

    cout<<"\n\t"<<real<<"+"<<img<<"i";
  }

};

int main(){
    int ch;
    char ans;
    COMPLEX c1,c2,c3;
    c1=COMPLEX(4,5);
    c2=COMPLEX(2,8);
     c3=c1+c2;


 case 1:
         c3=c1+c2;
         c3.display();

          case 2:

         c3=c1-c2;
         c3.display();
          case 3:
         c3=c1*c2;
         c3.display();
          case 4:
         c3=c1/c2;
         c3.display();
}
