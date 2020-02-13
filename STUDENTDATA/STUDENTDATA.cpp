#include <iostream>
#include <iomanip>

using namespace std;

class STUDENT{

  protected:
             string name;
             string uniRoll;
             string subject;
             unsigned int subCode;
  public:
             void setName(string name){
                 this->name=name;
             }

             void setUniRoll(string uniRoll){
                this->uniRoll=uniRoll;
             }

             void setSubject(string subject){
                this->subject=subject;
             }

             void setSubCode(unsigned int subCode){
                 this->subCode=subCode;
             }

             string getName(){
              return this->name;
             }
             string getUniRoll(){
              return this->uniRoll;
             }
             string getSubject(){
              return this->subject;
             }
             unsigned int getSubCode(){
              return this->subCode;
             }
};

class INTERNALASS : public virtual STUDENT{
  protected:
              unsigned int internalMarks;
  public:
              void setInternalMarks(unsigned int internalMarks){
                   this->internalMarks=internalMarks;
              }
              unsigned int getInternalMarks(){
                return this->internalMarks;
              }

};

class EXTERNALASS : public virtual STUDENT{
  protected:
              unsigned int externalMarks;
  public:
              void setExternalMarks(unsigned int externalMarks){
                   this->externalMarks=externalMarks;
              }
              unsigned int getExternalMarks(){
                return this->externalMarks;
              }

};

class FINALRESULT : public EXTERNALASS ,public INTERNALASS{
private:
          unsigned int totalMarks;
public:
           unsigned int getTotalMarks();
           void acceptData();
           void displayData();
 };

 unsigned int FINALRESULT::getTotalMarks(){
   totalMarks=getInternalMarks()+getExternalMarks();
   return this->totalMarks;
    }
void FINALRESULT::acceptData(){

       cout<<"\n\tENTER THE NAME OF STUDENT\t";
       cin>>name;
       cout<<"\n\tENTER THE UNIVERSITY ROLL NO. OF STUDENT\t";
       cin>>uniRoll;
       cout<<"\n\tENTER THE SUBJECT NAME\t";
       cin>>subject;
       cout<<"\n\tENTER THE SUBJECT CODE\t";
       cin>>subCode;
       cout<<"\n\tENTER STUDENT INTERNAL MARKS\t";
       cin>>internalMarks;
       cout<<"\n\tENTER STUDENT EXTERNAL MARKS\t";
       cin>>externalMarks;
}

void FINALRESULT::displayData(){

   cout<<setw(10)<<getName();
   cout<<setw(10)<<getUniRoll();
   cout<<setw(10)<<getSubject();
   cout<<setw(6)<<getSubCode();
   cout<<setw(3)<<getInternalMarks();
   cout<<setw(3)<<getExternalMarks();
   cout<<setw(4)<<getTotalMarks();
}

int main (){

      FINALRESULT s [100];
      int choice,record,flag;
      string rollNo;

            cout<<"ENTER THE NUMBER OF RECORD YOU WANT TO ENTER";
            cin>>record;

      do{

          cout<<"\r*********MENU************\n";
          cout<<"\n\t1. ENTER THE RECORD\n";
          cout<<"\n\t2. LIST A TABLE\n";
          cout<<"\n\t3. INSERT A NEW RECORD\n";
          cout<<"\n\t4. DELETE OLD RECORD\n";
          cout<<"\n\t5. EDIT A RECORD\n";
          cout<<"\n\t6. SEARCH THE RECORD\n";
          cout<<"\n\t7. EXIT\n";
          cout<<"\n\tENTER THE CHOICE(FROM 1 to 7)\t";
          cin>>choice;

          switch(choice){

      case 1:


            for(int i=0;i<record;i++){
                cout<<"RECORD NO. :"<<i+1;
                s[i].acceptData();
            }
            break;
      case 2:   cout<<"\n";
                cout<<setw(10)<<"NAME";
                cout<<setw(10)<<"\tUNIVERSITY ROLL";
                cout<<setw(10)<<"\tSUBJECT";
                cout<<setw(10)<<"\tSUBJECT CODE";
                cout<<setw(10)<<"\tINTERNAL MARKS";
                cout<<setw(10)<<"\tEXTERNAL MARKS";
                cout<<setw(10)<<"\tTOTAL MARKS";
                for(int i=0;i<record;i++){
                    s[i].displayData();
                }
                break;
      case 3:
             record++;
             s[record-1].acceptData();
          break;
      case 4:
             if (record>0){
                cout<<"ENTER THE ROLL NO";
                cin>>rollNo;
               if (rollNo!=s[record-1].getUniRoll()){
                flag=0;
                       for(int i=0;i<record;i++){
                        if (rollNo==s[i].getUniRoll()){
                            flag=1;
                        }
                        if (flag==1){
                            s[i].setName(s[i+1].getName());
                            s[i].setUniRoll(s[i+1].getUniRoll());
                            s[i].setSubject(s[i+1].getSubject());
                            s[i].setSubCode(s[i+1].getSubCode());
                            s[i].setInternalMarks(s[i+1].getInternalMarks());
                            s[i].setExternalMarks(s[i+1].getExternalMarks());
                        }
                       }
               } else
               {
                   flag=1;
               }

             }
             if(flag==1){
                record--;
             }else{
             cout<<"NO ENTERY TO DELETE.....";
             }
          break;
      case 5: int i;
              cout<<"ENTER THE ROLL NO.";
              cin>>rollNo;

              for(i=0;i<record;i++){
                if(rollNo==s[i].getUniRoll()){
                    flag=1;
                    break;
                }
                flag=0;
              }
              if(flag==1){
                s[i].acceptData();
            }else{
            cout<<"\nDATA NOT FOUND";
            }
          break;
      case 6:  cout<<"ENTER THE ROLL NO.";
               cin>>rollNo;

               for(int i=0;i<record;i++){
                if(rollNo==s[i].getUniRoll()){
                    flag=1;
                    break;
                        }
                        flag=0;
               }
               if(flag==1){
                     cout<<"\n";
                cout<<setw(10)<<"NAME";
                cout<<setw(10)<<"\tUNIVERSITY ROLL";
                cout<<setw(10)<<"\tSUBJECT";
                cout<<setw(10)<<"\tSUBJECT CODE";
                cout<<setw(10)<<"\tINTERNAL MARKS";
                cout<<setw(10)<<"\tEXTERNAL MARKS";
                cout<<setw(10)<<"\tTOTAL MARKS";
               s[i].displayData();
                               }else
                               cout<<"DATA NOT FOUND";
          break;
      case 7:
          break;
      default:
               cout<<"\n\tINVALID CHOICE....!";
          }

          }while(choice!=7);
      return 0;
}
