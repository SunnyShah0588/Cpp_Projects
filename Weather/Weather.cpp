#include <iostream>
using namespace std;

class weather{

	int day_of_month;
	float high_temp,low_temp;
	float amt_snowfall,amt_rainfall;

public:
	    weather();
	    void Display();
	    void Insert_Data(int);
	    void Avg_Data(weather *t);

};

weather::weather()
{
	day_of_month=99;
	high_temp=999;
	low_temp=-999;
	amt_snowfall=0;
	amt_rainfall=0;
}

void weather::Display()
{
	cout<<"\t"<<day_of_month;
	cout<<"\t"<<high_temp;
	cout<<"\t\t"<<low_temp;
	cout<<"\t\t"<<amt_rainfall;
	cout<<"\t\t"<<amt_snowfall;
	//return;
}

void weather ::Insert_Data(int d)
{
	day_of_month=d;

	cout<<"\n\t ENTER  HIGH TEMPERATURE : ";
	cin>>high_temp;

	cout<<"\n\t ENTER LOW TEMPERATURE : ";
	cin>>low_temp;

	cout<<"\n\t ENTER THE AMOUNT OF RAINFALL";
	cin>>amt_rainfall;

	cout<<"\n\t ENTER THE AMOUNT OF SNOWFALL";
	cin>>amt_snowfall;
	//return;


}

void weather ::Avg_Data(weather t[31])
{
    int count=0;
	float total_htemp,total_ltemp,total_snowfall,total_rainfall;
	float avg_htemp,avg_ltemp,avg_snowfall,avg_rainfall;
	total_htemp=total_ltemp=total_snowfall=total_rainfall=0;


	for(int i=1;i<=31;i++)
	{
		if(t[i].day_of_month==99.0)
			continue;
		else
		{
			total_htemp+=t[i].high_temp;
			total_ltemp+=t[i].low_temp;
			total_snowfall+=t[i].amt_snowfall;
			total_rainfall+=t[i].amt_rainfall;
			count++;
		}
	}
	avg_htemp=total_htemp/count;
	avg_ltemp=total_ltemp/count;
	avg_snowfall=total_snowfall/count;
	avg_rainfall=total_rainfall/count;

	cout<<"\nAVERAGE HIGH TEMPERATURE IS :"<<avg_htemp;

	cout<<"\nAVERAGE LOW TEMPERATURE IS : "<<avg_ltemp;

	cout<<"\nAVERAGE SNOWFALL IS : "<<avg_snowfall;

	cout<<"\nAVERAGE RAINFALL IS : "<<avg_rainfall;

}



int main() {

	weather Data[12][31],temp[31],obj;
	int choice,i;
	char answer;
	int day,month;

	cout<<"\n\t\t*+*+*+*+*+*+*WEATHER REPORT*+*+*+*+*+*+*+*";

	do{
		cout<<"\n\n\t\t*****MENU*****";
		cout<<"\n\t\t 1. ENTER DATA";
		cout<<"\n\t\t 2. DISPLAY DATA";
		cout<<"\n\t\t 3. EXIT";

		cout<<"\n\tENTER YOUR CHOICE";
		cin>>choice;

		switch(choice)
		{

		case 1 :
		            cout<<"ENTER THE MONTH :";
		            cin>>month;
		            cout<<"ENTER THE DAY FROM  1 TO 31 : ";
		            cin>>day;

		            Data[month][day].Insert_Data(day);

		            		break;
		case 2 :
		          cout<<"ENTER THE MONTH OF WHICH YOU WANT TO SEE REPORT";
		          cin>>month;

		   cout<<"----------------------------------------------------------------------------------------";
		   cout<<"\n                         REPORT OF THE MONTH                       ";
		   cout<<"\n---------------------------------------------------------------------------------------";
		   cout<<"\n\tDAY\tHIGH_TEMP\tLOW_TEMP\tAMOUNT_RAINFALL\tAMOUNT_SNOWFALL";
		   cout<<"\n---------------------------------------------------------------------------------------";

		   for(i=1;i<=31;i++)
		   {
			   cout<<"\n"<<i;
			   Data[month][i].Display();
		   }

		   for(i=1;i<=31;i++)
		   {
			   temp[i]=Data[month][i];
		   }
		   obj.Avg_Data(temp);
				   break;

				   case 3: break;
		}
		cout<<"\n\t\tDO YOU WISH TO CONTINUE IF YES PRESS Y on YOUR KEYBOARD";
		cin>>answer;

	}while(answer=='y');


	return 0;
}
