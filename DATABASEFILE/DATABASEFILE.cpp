#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

class Database
{
    string name;
    string dateOfBirth;
    string bloodGroup;
    float height,weight;
    string address;
    string telNo;
    int insurancePolicyNo;
    int drivingLicenseNo;
public:
    Database(){};

    void acceptData();
    void displayData();

    ~Database(){};
};

void Database :: acceptData()
{

    string name;
    ofstream out;
    out.open("F:\PROJECTS\cppprog\database.txt",ios::out);

    int n;
    cout << "\nHow many record do you want to enter ? " << endl;
    cin >> n;

    int i=1;
    while(i<=n)
    {
        cout << "\n\n\nEnter record of " << i << " person : " << endl;

        cout << endl << " Enter name : ";
        cin >> name;

        cout << endl << " date of birth : ";
        cin >> dateOfBirth;

        cout << endl << " height : ";
        cin >> height;

        cout << endl << " weight : ";
        cin >> weight;

        cout << endl << " blood group : ";
        cin >> bloodGroup;

        cout << endl << " address : ";
        cin >> address;

        cout << endl << " phone no : ";
        cin >> telNo;

        cout << endl << " driving license no : ";
        cin >> drivingLicenseNo;

        cout << endl << " insurance policy no : ";
        cin >> insurancePolicyNo;

        out << endl;
        out << setw(10) << name ;
        out << setw(10) << dateOfBirth ;
        out << setw(10) << height ;
        out << setw(10) << weight ;
        out << setw(10) << bloodGroup ;
        out << setw(10) << address ;
        out << setw(10) << telNo ;
        out << setw(10) << drivingLicenseNo ;
        out << setw(10) << insurancePolicyNo ;

        i++;
    }
    out.close();

}

void Database :: displayData()
{

    ifstream in;
    in.open("F:\PROJECTS\cppprog\database.txt",ios::in);

    cout << setw(10) << "n";
    cout << setw(10) << "dob";
    cout << setw(10) << "h";
    cout << setw(10) << "w";
    cout << setw(10) << "bg";
    cout << setw(10) << "a";
    cout << setw(10) << "pn";
    cout << setw(10) << "dln";
    cout << setw(10) << "ipn" << endl ;

    while(!in.eof()){

        char person[100];

        in.getline(person,100);
        cout << person << endl ;

    }
    in.close();
}
int main()
{
    int ch;
    Database data;

    do{
        cout << "\n\n1. Accept data" << endl ;
        cout << "2. Display data" << endl ;
        cout << "3. Exit" << endl ;
        cout << "----> " ;
        cin >> ch;


        switch(ch)
        {
        case 1:
            data.acceptData();
            break;
        case 2:
            data.displayData();
        case 3:
            break;
        default:
            cout << "Invalid choice....!!!!!" << endl ;
        }
    }while(ch!=3);

    return 0;
}
