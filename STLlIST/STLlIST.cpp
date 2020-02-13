#include<iostream>
#include<list>
#include<stdlib.h>

using namespace std;

void display(list <int> list1){

    list <int> ::iterator l;
    int flag=0;
    flag=list1.empty();
    if (flag==0){

        for(l=list1.begin();l!=list1.end();l++)
            cout<<"  "<<*l;

    }else{
            cout<<"LIST IS EMPTY....";
    }
}

int main(){

    int choice,flg;
    int entery,entery2;
    list <int> list1;
    list <int> list2;
    list <int>::iterator l;
    int n,m;
    char y;

      //ENTERING ELEMENTS IN LIST 1

    cout<<"\n ENTER THE NUMBER OF ELEMENTS YOU WISH TO ENTER IN LIST 1\n\t";
    cin>>n;


                for(int i=0;i<n;i++){
                    cout<<"\n\tENTER THE LIST 1 ELEMENTS\n\t";
                    cin>>entery;
                    list1.push_back(entery);
                }

       //ENTERING THE ELEMENTS IN LIST 2

                   cout<<"\n\t ENTER THE NUMBER OF ELEMENTS IN LIST 2\n\t";
                   cin>>m;

                   for(int i=0;i<m;i++){
                    cout<<"ENTER THE ELEMENTS OF LIST 2\n\t";
                    cin>>entery2;
                    list2.push_back(entery2);
                   }


    do{

        cout<<"\n\t*********MENU***********";
        cout<<"\n\t1. DISPLAY LIST";
        cout<<"\n\t2. SORT LIST";
        cout<<"\n\t3. REVERSE LIST";
        cout<<"\n\t4. MERGE LIST";
        cout<<"\n\t5. SEARCH LIST";
        cout<<"\n\t6. EXIT";
        cout<<"\n\t ENTER YOUR CHOICE FROM 1 TO 6\t";
        cin>>choice;

        switch(choice){

        case 1:
        cout<<"\tELEMENTS OF LIST 1 ARE\n\t ";
                display(list1);
            cout<<"\n\tELEMENTS OF LIST 2 ARE\n\t ";

                display(list2);
                break;

        case 2:
                   list1.sort();
                   list2.sort();
                   display(list1);
                   display(list2);
                   break;
        case 3:
                   list1.reverse();
                   list2.reverse();
                   display(list1);
                   display(list2);
                   break;
        case 4:

                   list2.sort();
                   list1.merge(list2);
                   display(list1);
                   break;
        case 5:
                   int element;
                   cout<<"\n\t ENTER THE ELEMENTS YOU WANT TO SEARCH\n\t";
                   cin>>element;
                   for(l=list1.begin();l!=list1.end();l++){

                        if(*l==element){flg=1;} }

                    if (flg==1){
                        cout<<"ELEMENT YOU ENTERED IS PRESENT";
                    }else{
                                cout<<"ELEMENT NOT PRESENT";}

                   break;
        case 6:
                 break;
        default:
                  cout<<"\n\t\tOOPS ENTERED WRONG CHOICE";
        }

      cout<<"\n\t DO YOU WISH TO CONTINUE IF YES PRESS Y: ";
      cin>>y;


    }while(y=='y'||y=='Y');

}
