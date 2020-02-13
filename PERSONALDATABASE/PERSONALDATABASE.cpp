#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

class PersonalInfo
{
private:
    string name;
    string dateOfBirth;
    string bloodGroup;
    float height,weight;
    string address;
    string telNo;
    friend class Database;
};

class Database
{
    int insurancePolicyNo;
    int drivingLicenseNo;
    PersonalInfo person;
public:
    static int dataCount;
    Database(){}
    Database(Database &data){

        this->person.name = data.person.name;
        this->person.dateOfBirth = data.person.dateOfBirth;
        this->person.height = data.person.height;
        this->person.weight = data.person.weight;
        this->person.bloodGroup = data.person.bloodGroup;
        this->person.address = data.person.address;
        this->person.telNo = data.person.telNo;
        this->drivingLicenseNo = data.drivingLicenseNo;
        this->insurancePolicyNo = data.insurancePolicyNo;

    }

    static void initCount(){ dataCount++;};
    void acceptData();
    void displayData();

    ~Database(){};
};

int Database :: dataCount;

void Database :: acceptData()
{
    cout << endl << " Enter name : ";
    cin >> this->person.name;

    cout << endl << " date of birth : ";
    cin >> this->person.dateOfBirth;

    cout << endl << " height : ";
    cin >> this->person.height;

    cout << endl << " weight : ";
    cin >> this->person.weight;

    cout << endl << " blood group : ";
    cin >> this->person.bloodGroup;

    cout << endl << " address : ";
    cin >> this->person.address;

    cout << endl << " phone no : ";
    cin >> this->person.telNo;

    cout << endl << " driving license no : ";
    cin >> this->drivingLicenseNo;

    cout << endl << " insurance policy no : ";
    cin >> this->insurancePolicyNo;
}

void Database :: displayData()
{
    cout << setw(10) << this->person.name;
    cout << setw(10) << this->person.dateOfBirth;
    cout << setw(10) << this->person.height;
    cout << setw(10) << this->person.weight;
    cout << setw(10) << this->person.bloodGroup;
    cout << setw(10) << this->person.address;
    cout << setw(10) << this->person.telNo;
    cout << setw(10) << this->drivingLicenseNo;
    cout << setw(10) << this->insurancePolicyNo;
}


int main()
{
    int ch;
    Database * data;
    Database * copyData;

    do{
        cout << "\n\n1. Accept data" << endl ;
        cout << "2. Display original data" << endl ;
        cout << "3. Display copied data" << endl ;
        cout << "4. Exit" << endl ;
        cout << "----> " ;
        cin >> ch;


        switch(ch)
        {
        case 1:
            int n;
            cout << "\nHow many record do you want to enter ? " << endl;
            cin >> n;
            data = new Database[n];
            copyData = new Database[n];

            for(int i=1 ; i<=n ; i++){
                cout << "\n\n\nEnter record of " << i << " person : " << endl;
                data[i-1].acceptData();
                data[i-1].initCount();

                copyData[i-1] = data[i-1];
            }
            break;
        case 2:
            cout << endl << "\n\n name (n)\n date of birth (dob)\n height (h)\n weight (w)\n blood group(bg)\n address(a)\n phone no(pn)\n driving license no(dln)\n insurance policy no (ipn) " << endl << endl;
            cout << setw(10) << "n";
            cout << setw(10) << "dob";
            cout << setw(10) << "h";
            cout << setw(10) << "w";
            cout << setw(10) << "bg";
            cout << setw(10) << "a";
            cout << setw(10) << "pn";
            cout << setw(10) << "dln";
            cout << setw(10) << "ipn" << endl ;
            for(int i=1 ; i<=n ; i++){
                data[i-1].displayData();
                cout << endl;
            }

            cout <<  endl << "Data Count : " << data->dataCount << endl;
            break;
        case 3:
            cout << endl << "\n\n name (n)\n date of birth (dob)\n height (h)\n weight (w)\n blood group(bg)\n address(a)\n phone no(pn)\n driving license no(dln)\n insurance policy no (ipn) " << endl << endl;
            cout << setw(10) << "n";
            cout << setw(10) << "dob";
            cout << setw(10) << "h";
            cout << setw(10) << "w";
            cout << setw(10) << "bg";
            cout << setw(10) << "a";
            cout << setw(10) << "pn";
            cout << setw(10) << "dln";
            cout << setw(10) << "ipn" << endl ;
            for(int i=1 ; i<=n ; i++){
                copyData[i-1].displayData();
                cout << endl;
            }

            cout <<  endl << "Data Count : " << copyData->dataCount << endl;
            break;
        case 4:
            break;
        default:
            cout << "Invalid choice....!!!!!" << endl ;
        }
    }while(ch!=4);

    delete(data);
    return 0;
}
