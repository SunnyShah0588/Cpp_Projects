#include<iostream>
#include<iomanip>
#include<string>

using namespace std;

/* CREATED A PERSON CLASS */
class PERSON{

   private:
             string name;
             string dob;
             string bloodGroup;
             int hight,weight;
             string insuranceNo;
             string address;
             float telephone;

   public:
            void accept();
            void display();
            friend class DATABASE;


};// END OF PERSON CLASS

  // START OF THE DATABASE CLASS DECLARED FRIEND OF THE PERSON
class DATABASE{

     PERSON info;

   public:

          static int dataCount;
          DATABASE(){}
        DATABASE(DATABASE &data){

           this->info.name=data.info.name;
           this->info.dob=data.info.dob;
           this->info.bloodGroup=data.info.bloodGroup;
           this->info.hight=data.info.hight;
           this->info.weight=data.info.weight;
           this->info.insuranceNo=data.info.insuranceNo;
           this->info.address=data.info.address;
           this->info.telephone=data.info.telephone;

        }

        static void itsCount(){
          dataCount++;
           }

           void accept();
           void display();
           ~DATABASE(){};
};
// DATABASE CLASS ENDS HERE

int DATABASE:: dataCount;
// ACCEPT FUNCTION
void DATABASE::accept(){

    cout<<"\n ENTER THE NAME\t";
    cin>>this->info.name;

    cout<<"\n ENTER THE DATE OF BIRTH (DD\MM\YYYY)\t";
    cin>>this->info.dob;

    cout<<"\n ENTER THE BLOOD GROUP (X+)\t";
    cin>>this->info.bloodGroup;

    cout<<"\n ENTER THE HIGHT IN INCHES\t";
    cin>>this->info.hight;

    cout<<"\n ENTER THE WEIGHT IN KGs\t";
    cin>>this->info.weight;

    cout<<"\n ENTER THE INSURANCE POLICY NUMBER \t";
    cin>>this->info.insuranceNo;

    cout<<"\n ENTER THE CONTACT ADDRESS\t";
    cin>>this->info.address;

    cout<<"\n ENTER THE TELEPHONE NUMBER\t";
    cin>>this->info.telephone;


}//ACCEPT FUNCTON ENDS


//DISPLAY FUNCTION
void DATABASE::display(){

                              cout<<setw(10)<<this->info.name;
                              cout<<setw(8)<<this->info.dob;
                              cout<<setw(4)<<this->info.bloodGroup;
                              cout<<setw(4)<<this->info.hight;
                              cout<<setw(4)<<this->info.weight;
                              cout<<setw(10)<<this->info.insuranceNo;
                              cout<<setw(10)<<this->info.address;
                              cout<<setw(10)<<this->info.telephone;

}//DISPLAY FUNCTION ENDS HERE

//INT MAIN IS HERE
int main(){

                   int choice;
                   DATABASE *data;
                   DATABASE *copyData;

                   do{
                            cout << "\n\t1. Accept data" << endl ;
                            cout << "\n\t2. Display original data" << endl ;
                            cout << "\n\t3. Display copied data" << endl ;
                            cout << "\n\t4. Exit" << endl ;
                            cout << "\n-------(CHOICE FROM 1 to 4) -----> " ;
                cin >> choice;


                switch(choice)
                {
                    case 1:
                             int n;
                            cout<<"HOW MANY RECORDS DO YOU WISH TO ENTER IN DATABASE\t";
                            cin>>n;

                            data = new DATABASE[n];
                            copyData =new DATABASE[n];

                            for(int i=1;i<=n;i++){

                                cout << "\n\n\n\tENTER THE RECORDS OF  " << i << " person : " << endl;
                                data[i-1].accept();
                                data[i-1].itsCount();
                                copyData[i-1]=data[i-1];

                            }
                            break;

                       case 2:    cout <<"\n\n name\t date of birth\tblood group\t height\t weight\tinsurance policy no\t address\t phone no";

                                   for(int i=1;i<=n;i++){
                                    data[i-1].display();
                                   }

                                   cout <<"Data Count : " << data->dataCount << endl;
                            break;

                       case 3:    cout <<"\n\n name\t date of birth\tblood group\t height\t weight\tinsurance policy no\t address\t phone no";

                                   for(int i=1;i<=n;i++){
                                    copyData[i-1].display();
                                   }

                                   cout <<"Data Count : " << data->dataCount << endl;
                            break;

                        case 4:   break;

                        default: cout<<"OOPS WRONG CHOICE....SORRY......ENTER CORRECT CHOICE";

                }

}  while(choice!=4);

  delete(data);
return 0;
}
