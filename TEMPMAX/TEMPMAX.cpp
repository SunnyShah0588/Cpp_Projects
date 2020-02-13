#include <iostream>
#define SIZE 3
using namespace std;

template<class T>
class MATRIX{

     T A[SIZE][SIZE];
 public:
         void acceptData();
         void displayData();
         void addition(MATRIX <T>,MATRIX <T>);
         void subtraction(MATRIX <T>,MATRIX <T>);
         void multiplication(MATRIX <T>,MATRIX <T>);

  };

  template<class T>
  void MATRIX <T>::acceptData(){

       int i,j;
       cout<<"\n\n\tENTER THE MATRIX\n";
       for(i=0;i<SIZE;i++){
        for(j=0;j<SIZE;j++){
            cin>>A[i][j];
        }
       }

  }

  template<class T>
  void MATRIX <T>::displayData(){

     int i,j;
        cout<<"\n\n\tTHE MATRIX IS \n";
           for(i=0;i<SIZE;i++){
                cout<<"\n\n";
                for(j=0;j<SIZE;j++){
                   cout<<"\t"<<A[i][j];
        }
       }

  }

  template<class T>
  void MATRIX <T>::addition(MATRIX <T> a,MATRIX <T> b)
  {
      int i,j;
                 for(i=0;i<SIZE;i++){
                for(j=0;j<SIZE;j++){
                   A[i][j]=a.A[i][j]+b.A[i][j];
        }
       }

  }

    template<class T>
  void MATRIX <T>::subtraction(MATRIX <T> a,MATRIX <T> b)
  {
           int i,j;
                 for(i=0;i<SIZE;i++){
                for(j=0;j<SIZE;j++){
                    A[i][j]=a.A[i][j]-b.A[i][j];
        }
       }

  }

    template<class T>
  void MATRIX <T>::multiplication(MATRIX <T> a,MATRIX <T> b)
  {
        int i,j,k;
                         for(i=0;i<SIZE;i++){
                for(j=0;j<SIZE;j++){
                    A[i][j]=0;
        }
       }

                 for(i=0;i<SIZE;i++){
                for(j=0;j<SIZE;j++){
                        for(k=0;k<SIZE;k++){
                                A[i][j]=A[i][j]+(a.A[i][k]*b.A[k][j]);

                        }
                    }
                  }

  }

  int main(){

      int ch,choice;
      MATRIX <int> Imat1,Imat2,Imat3;
      MATRIX <float> Fmat1,Fmat2,Fmat3;
      char answerI,answerF,mainmenu;

      do{

        cout<<"\n\n\t MAIN MENU";
        cout<<"\n\t 1. USE INTEGERS";
        cout<<"\n\t 2. USE FLOAT";
        cout<<"\n\t 3. EXIT";
        cout<<"\n\t ENTER YOUR CHOICE\t";
        cin>>choice;

        switch(choice){

     case 1:
               cout<<"\t\nMATRIX OPERATION USING INTEGER\n";
               Imat1.acceptData();
               Imat1.displayData();
               Imat2.acceptData();
               Imat2.displayData();

               do{

                cout<<"\n\tMATRIX INTEGER OPERATION MENU\n";
                cout<<"\n\t1. ADDITION";
                cout<<"\n\t2. SUBTRACTION";
                cout<<"\n\t3. MULTIPLICATION";
                cout<<"\n\t4. EXIT";
                cout<<"\n\tENTER YOUR CHOICE\t";
                cin>>ch;

                switch(ch){

              case 1:
                      Imat3.addition(Imat1,Imat2);
                      Imat3.displayData();
                      break;
                 case 2:
                      Imat3.subtraction(Imat1,Imat2);
                      Imat3.displayData();
                      break;
                 case 3:
                      Imat3.multiplication(Imat1,Imat2);
                      Imat3.displayData();
                      break;
                 case 4:
                       break;

                }
                cout<<"\n\tPERFORM MORE OPERATION ?\t";
                cin>>answerI;
               }while(answerI=='y'||answerI=='Y');
        break;

    case 2:

                cout<<"\n\tMATRIX OPERATION USING FLOAT\n";
               Fmat1.acceptData();
               Fmat1.displayData();
               Fmat2.acceptData();
               Fmat2.displayData();

               do{

                cout<<"\n\tMATRIX FLOAT OPERATION MENU\n";
                cout<<"\n\t1. ADDITION";
                cout<<"\n\t2. SUBTRACTION";
                cout<<"\n\t3. MULTIPLICATION";
                cout<<"\n\tENTER YOUR CHOICE\t";
                cin>>ch;

                switch(ch){

              case 1:
                      Fmat3.addition(Fmat1,Fmat2);
                      Fmat3.displayData();
                      break;
                 case 2:
                      Fmat3.subtraction(Fmat1,Fmat2);
                      Fmat3.displayData();
                      break;
                 case 3:
                      Fmat3.multiplication(Fmat1,Fmat2);
                      Fmat3.displayData();
                      break;

                }


                cout<<"\nPERFORM MORE OPERATION ?\t";
                cin>>answerF;
               }while(answerF=='y'||answerF=='Y');
        break;

    case 3:
                    break;

        }


         cout<<"GO TO MAIN MENU\t";
         cin>>mainmenu;
      }while(mainmenu=='y'||mainmenu=='Y');
      return 0;

  }
