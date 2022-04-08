#include <bits/stdc++.h>
using namespace std;

// The class flights contains the record of two classes namely economy and business. Booking function is used to book the flight ticket by specifying all the necessary
// details accordingly. display_seats function will display all the seats that are available as 'A' and not available as 'NA'. Cancellation function is used to 
// cancel the tickets. display_meal function will display the rows and columns where the meal is ordered. Summary function is used to print both the flight summary
// and individual summary.

class flights
{
	int seats_eco[50][50],meal_eco[50][50], id_eco[50][50], age_eco[50][50], ticket_row_eco[50][50], ticket_column_eco[50][50], cost_passenger_eco[50][50];
	int seats_bus[50][50],meal_bus[50][50], id_bus[50][50], age_bus[50][50], ticket_row_bus[50][50], ticket_column_bus[50][50], cost_passenger_bus[50][50];
	int total_row_eco,total_col_eco,total_row_bus, total_col_bus, cost_economy, cost_business;
	char sex_eco[50][50],sex_bus[50][50];
	long contact_number_eco[50][50],contact_number_bus[50][50];
	string name_eco[50][50], ticket_class_eco[50][50],name_bus[50][50], ticket_class_bus[50][50],flight_no;
	static int booking_id;
	public:
		flights();
		void booking(string flight_number);
		void total_row_column(string flight_number);
		void cancellation();
		void display_seats();
		void display_meal();
		void summary(int booking_id);
	
};

int flights::booking_id = 0;

// Initializing all the variables to 0 value using for loop to avoid garbage values with the help of constructor.
flights::flights()
{
	cost_economy = 1000;
	cost_business = 2000;
	int i,j;
	for(i=0;i<50;i++)
	{
		for(j=0;j<50;j++)
		{
			seats_eco[i][j]=0; seats_bus[i][j]=0;
			meal_eco[i][j]=0; meal_bus[i][j]=0;
			id_eco[i][j]=0; id_eco[i][j]=0;
			cost_passenger_eco[i][j]=0; cost_passenger_bus[i][j]=0;
			ticket_row_eco[i][j]=0;  ticket_row_bus[i][j]=0;
			ticket_column_eco[i][j]=0; ticket_column_bus[i][j]=0;
			sex_eco[i][j]=' ';  sex_bus[i][j]=' ';
			age_eco[i][j]=0; 	age_bus[i][j]=0;
			contact_number_eco[i][j]=0;  contact_number_bus[i][j]=0;
		}
	}
}

// total_row_column function will read the corresponding file and specify the total rows and total columns in the economy class as well as in the business class.
void flights::total_row_column(string flight_number)
{
	fstream  file1;
	string flight_file;
	flight_file = flight_number + ".txt";
	flight_no = flight_number;
	
	file1.open(flight_file.c_str(),ios::in);
	if(!file1)
		cout<<"No such file";
	else
	{
		char c;
		int eco1,eco2,eco3,eco_row=0;
		int business1,business2,business3,business_row=0;
		while(!file1.eof())
		{
			file1 >> c;
			if(c=='{' && eco1==0)
			{ file1>>c; eco1 = c-'0'; file1>>c; file1>>c; eco2=c-'0'; file1>>c; file1>>c; eco3=c-'0';}
			else if(c=='}' && eco_row==0)
			{file1>>c;file1>>c; eco_row= c-'0'; file1>>c; eco_row=(eco_row*10)+(c-'0');}
			
			else if(c=='{' && eco1!=0 && eco2!=0 && eco3!=0)
			{ file1>>c; business1 = c-'0'; file1>>c; file1>>c; business2=c-'0'; file1>>c; file1>>c; business3=c-'0';}
			else if(c=='}' &&eco_row!=0)
			{file1>>c;file1>>c; business_row= c-'0'; file1>>c; business_row=(business_row*10)+(c-'0');}
		}
		total_row_eco = eco_row;
		total_col_eco = eco1+eco2+eco3;
		total_row_bus = business_row;
		total_col_bus = business1+business2+business3;
		
		cout<<"\nTotal rows - Economy: "<<total_row_eco <<endl;
		cout<<"Total columns - Economy: "<<total_col_eco<<endl;
		cout<<"Total rows - Business: "<<total_row_bus<<endl;
		cout<<"Total columns - Business: "<<total_col_bus<<endl;
	}
	
}

// The booking function is used to book the ticket according to the class specified. Here the user can't book tickets of different class at the same time.

void flights::booking(string flight_number)
{
	
	int number,i,k,l,row,column;
	char ch;
	string y,seat_number;
	display_seats();
	cout<<"\nHow many tickets do you want to book? :  ";
	cin>>number;
	
	booking_id++;
	//display_seats();
	
	cout<<"Enter the ticket class (Economy/Business): ";
	cin>>y;
	transform(y.begin(), y.end(), y.begin(), ::tolower); // even if the input is EcOnOmy, it will convert the string to lowercase letters.
		
	for(i=1;i<=number;i++)
	{
		if(y.compare("economy")==0)
		{
			cout<<"\nEnter the seat number of Passenger(row_column)- "<<i<<" : ";
			cin>>seat_number;
			row=0;column=0;
			
			// Loop to extract the row number
			for(k=0;seat_number[k]!='_';k++)
			{
				row=(row*10)+(seat_number[k]-'0');
			}
			// Loop to extract the column number
			for(l=k+1;seat_number[l];l++)
			{
				column=(column*10)+(seat_number[l]-65);
			}
			// This condition checks whether the seat is available or not. If the value of seats_eco[row-1][column] is 0, then the seat is available, else the seat
			// is not available. Specifying the row-1 value helps us to start from 0th index. The user enters all the necessary details. 
			// Here, the choice of asking for meal is also taken into account. If the user wish to have meal, then he can specify Y(Yes) accordingly.
			
			if(seats_eco[row-1][column]==0)
			{
				id_eco[row-1][column]=booking_id;
				seats_eco[row-1][column]=1;
				ticket_class_eco[row-1][column]="economy";
				ticket_row_eco[row-1][column]=row-1;
				ticket_column_eco[row-1][column]=column;
				cout<<"Enter the name of Passenger-"<<i<<" : ";
				cin>>name_eco[row-1][column];				
				cout<<"Enter the age of Passenger-"<<i<<" : ";
				cin>>age_eco[row-1][column];				
				cout<<"Enter the sex of Passenger(M/F)-"<<i<<" : ";
				cin>>sex_eco[row-1][column];				
				cout<<"Enter the contact number of Passenger-"<<i<<" : ";
				cin>>contact_number_eco[row-1][column];
				
				cout<<"Do you want meal(Y/N)? : ";
				cin>>ch;
				if(ch=='y' || ch=='Y')
				{
					meal_eco[row-1][column]=1;
					cost_passenger_eco[row-1][column] = cost_economy+200;
				}					
				else
				{
					meal_eco[row-1][column]=0;
					cost_passenger_eco[row-1][column] = cost_economy;
				}
			}
			else
			{
				i=i-1;
				cout<<"This seat is not available currently.\n";
			}
		}
		// Similarly, all the necessary actions are performed for the business class also.
		else
		{
			row=0,column=0;
			cout<<"\nEnter the seat number of Passenger(row_column)- "<<i<<" : ";
			cin>>seat_number;
			// Loop to extract the row number
			for(k=0;seat_number[k]!='_';k++)
			{
				row=(row*10)+(seat_number[k]-'0');
			}
			// Loop to extract the column number
			for(l=k+1;seat_number[l];l++)
				column= (column*10)+(seat_number[l]-'A');
			
			if(seats_bus[row-1][column]==0)
			{
				id_bus[row-1][column]=booking_id;
				seats_bus[row-1][column]=1;
				ticket_class_bus[row-1][column]="business";
				ticket_row_bus[row-1][column]=row-1;
				ticket_column_bus[row-1][column]=column;	
				cout<<"Enter the name of Passenger-"<<i<<" : ";
				cin>>name_bus[row-1][column];
				cout<<"Enter the age of Passenger-"<<i<<" : ";
				cin>>age_bus[row-1][column];
				cout<<"Enter the sex of Passenger(M/F)-"<<i<<" : ";
				cin>>sex_bus[row-1][column];				
				cout<<"Enter the contact number of Passenger-"<<i<<" : ";
				cin>>contact_number_bus[row-1][column];
				 
				cout<<"Do you want meal(Y/N)? : ";
				cin>>ch;
				if(ch=='y' || ch=='Y')
				{
					meal_bus[row-1][column]=1;
					cost_passenger_bus[row-1][column] = cost_business+200;
				}					
				else
				{
					meal_bus[row-1][column]=0;
					cost_passenger_bus[row-1][column] = cost_business;
				}
			}
			else
			{
				i=i-1;
				cout<<"This seat is not available currently.\n";
			}
		}
	}
	// After successful booking, now the ticket prize will increase accordingly for both the class. 
	cost_business+=200;
	cost_economy+=100;
	// Finally the summary is printed to get a better view.
	summary(booking_id);
}

// display_seats function will display all the available seats as 'A' and all non-available seats as 'NA'.
void flights::display_seats()
{
	int i,j;
	cout<<"\nTotal available seats are: \nA = Avaible		NA = Not Available\n";
	cout<<"Economy Class : \n";
	for(i=0;i<total_row_eco;i++)
	{
		for(j=0;j<total_col_eco;j++)
		{
			if(seats_eco[i][j]==0)
				cout<<"A"<<"   ";
			else
				cout<<"NA"<<"   ";
		}
		cout<<endl;	
	}
	cout<<"\nBusiness Class :  \n";
	for(i=0;i<total_row_bus;i++)
	{
		for(j=0;j<total_col_bus;j++)
		{
			if(seats_bus[i][j]==0)
				cout<<"A"<<"   ";
			else
				cout<<"NA"<<"   ";
		}
		cout<<endl;	
	}
}

// display_meal function is used to display all the rows and columns where the meal is ordered.
void flights::display_meal()
{
	int i,j;
	cout<<"Meals ordered in Economy Class are :  \n";
	for(i=0;i<total_row_eco;i++)
	{
		for(j=0;j<total_col_eco;j++)
		{
			if(meal_eco[i][j]==1)
				cout<<"Row : "<< i+1 <<"Column : "<< ((char)j+65)<<endl;
		}
	}
	cout<<"Meals ordered in Business Class are :  \n";
	for(i=0;i<total_row_bus;i++)
	{
		for(j=0;j<total_col_bus;j++)
		{
			if(meal_bus[i][j]==1)
				cout<<"Row : "<< i+1 <<"Column : "<< ((char)j+65)<<endl;
		}
	}
}

// The cancellation function prompts the user with the seat number and the ticket class. Accordingly, it will find the corresponding entry and erase all the values.

void flights::cancellation()
{
	int row=0,column=0,i,j;
	string seat_number, x;
	cout<<"\nEnter the seat number: ";
	cin>>seat_number;
	// Loop to extract the row number
	for(i=0;seat_number[i]!='_';i++)
	{
		row=(row*10)+(seat_number[i]-'0');
	}
	// Loop to extract the column number
	for(j=i+1;seat_number[j];j++)
		column= (column*10)+(seat_number[j]-65);
		
	cout<<"\nEnter the ticket class : ";
	cin>>x;
	transform(x.begin(), x.end(), x.begin(), ::tolower);
	
	
	if(x.compare("economy")==0)
	{
		cout<<name_eco[row-1][column]<<" is deleted."<<endl;
		cout<<(cost_passenger_eco[row-1][column] - 200 )<<" will be debited. "<<endl;
		name_eco[row-1][column]="";
		age_eco[row-1][column]=0;
		contact_number_eco[row-1][column]=0;
		meal_eco[row-1][column]=0;
		sex_eco[row-1][column]=' ';
		ticket_column_eco[row-1][column]=0;
		ticket_row_eco[row-1][column]=0;
		cost_passenger_eco[row-1][column]=0;
		ticket_class_eco[row-1][column]="";
		//cout<<name_eco[row-1][column]<<' '<<age_eco[row-1][column]<<' '<<contact_number_eco[row-1][column]<<' '<<meal_eco[row-1][column]<<' '<<sex_eco[row-1][column]<<' '<<ticket_column_eco[row-1][column]<<' '<<ticket_row_eco[row-1][column]<<' '<<cost_passenger_eco[row-1][column]<<' ';
	}
	else if(x.compare("business")==0)
	{	
		cout<<name_bus[row-1][column]<<" is deleted."<<endl;
		cout<<cost_passenger_bus[row-1][column] - 200 <<" will be debited. "<<endl;
		name_bus[row-1][column]="";
		age_bus[row-1][column]=0;
		contact_number_bus[row-1][column]=0;
		meal_bus[row-1][column]=0;
		sex_bus[row-1][column]=' ';
		ticket_column_bus[row-1][column]=0;
		ticket_row_bus[row-1][column]=0;
		cost_passenger_bus[row-1][column]=0;
		ticket_class_bus[row-1][column]="";
	}
}

// The summary function is used to print both the flight summary and the individual summary. If the user enters the booking ID, then the corresponding entries are displayed.
void flights::summary(int booking_id)
{
	int i,j,x;
	cout<<"\nEnter  1. Flight summary   2. Individual summary\n";
	cin>>x;
	if(x==1)
	{
		cout<<"\n   FLIGHT SUMMARY\n";
		cout<<"ECONOMY CLASS : \n";
		for(i=0;i<total_row_eco;i++)
		{
			for(j=0;j<total_col_eco;j++)
			{
				if(seats_eco[i][j]==0)
					cout<<"A   ";
				else
					cout<<"NA  ";
			}
			cout<<endl;
		}
		cout<<"\nBUSINESS CLASS : \n";
		for(i=0;i<total_row_bus;i++)
		{
			for(j=0;j<total_col_bus;j++)
			{
				if(seats_bus[i][j]==0)
					cout<<"A   ";
				else
					cout<<"NA  ";
			}
			cout<<endl;
		}
	}
	else
	{
		cout<<"\n\n   INDIVIDUAL SUMMARY\n";
		int flag=0;
		// The below for loop is used to check all the entries that match the booking ID in the economy class.
		for(i=0;i<total_row_eco;i++)
		{
			for(j=0;j<total_col_eco;j++)
			{
				if(id_eco[i][j]==booking_id)
				{
					cout<<"\n\nFlight Number : "<<flight_no<<endl;
					cout<<"Booking ID : "<<id_eco[i][j]<<endl;
					cout<<"Passenger Name : "<<name_eco[i][j]<<endl;
					cout<<"Age : "<<age_eco[i][j]<<endl;
					cout<<"Sex : "<<sex_eco[i][j]<<endl;
					cout<<"Contact Number : "<<contact_number_eco[i][j]<<endl;
					cout<<"Row : "<<(ticket_row_eco[i][j]+1)<<endl;
					cout<<"Column : "<<(char)(ticket_column_eco[i][j]+65)<<endl;
					cout<<"Ticket Fare : "<<cost_passenger_eco[i][j]<<endl;
					cout<<"Meal preference : "; (meal_eco[i][j]==0)?cout<<"No":cout<<"Yes"<<endl;
					flag=1;
				}
			}
		}
		// The below for loop is used to check all the entries that match the booking ID in the business class.
		if(flag==0)
		{
			for(i=0;i<total_row_bus;i++)
			{
				for(j=0;j<total_col_bus;j++)
				{
					if(id_bus[i][j]==booking_id)
					{
						cout<<"\n\nFlight Number : "<<flight_no<<endl;
						cout<<"Booking ID : "<<id_bus[i][j]<<endl;
						cout<<"Passenger Name : "<<name_bus[i][j]<<endl;
						cout<<"Age : "<<age_bus[i][j]<<endl;
						cout<<"Sex : "<<sex_bus[i][j]<<endl;
						cout<<"Contact Number : "<<contact_number_bus[i][j]<<endl;
						cout<<"Row : "<<ticket_row_bus[i][j]<<endl;
						cout<<"Column : "<<(ticket_column_bus[i][j]+'A')<<endl;
						cout<<"Ticket Fare : "<<cost_passenger_bus[i][j]<<endl;
						cout<<"Meal preference : "; (meal_bus[i][j]==0)?cout<<"No":cout<<"Yes"<<endl;
						flag=1;
					}
				}
			}
		}
		if(flag==0)
			cout<<"\nEnter a valid  Booking ID. ";
	}
}

// In the main function, array of objects are created for the class 'flights'. Here, i have created array of size 5 which can be extended accordingly.
// Using the map function, the flight number will be stored as keys and the values(which starts from 1,2,..) are used to access the array.
// Using the do-while loop, all the functions depending upon the choices entered by the user is called. They can enter n or N when the user wants to 
// come out of the loop.
  
int main()
{
	flights number_of_flights[5];
	int i,choice,num=1,x;
	char j;
	string flight_number;
	map<string,int>m;
	cout<<"								FLIGHT TICKET BOOKING SYSTEM\n\n";
	cout<<"The user can enter the flight number and can start booking the tickets. If the user wants to cancel the ticket, the same can be achieved here. They can also visualize the seats that are available and the seats that are not available. After successful booking of tickets, the summary will also be printed...\n\n";
	cout<<"								HAPPY JOURNEY!!!\n";
	do
	{
		cout<<"\nEnter the Flight number: ";
		cin>>flight_number;
		
		if(m[flight_number]==0)
		{
			m[flight_number]=num;
			num++;
		}
		cout<<"Flight Number : "<< flight_number<<' ';
		
		number_of_flights[m[flight_number]-1].total_row_column(flight_number);
		
		cout<<"\nEnter   1. Ticket Booking   2. Ticket Cancellation   3. Display available seats   4. Display meal orders   5. Summary \n";
		cin>>choice;
		switch(choice)
		{
			case 1: number_of_flights[m[flight_number]-1].booking(flight_number); break;
			case 2: number_of_flights[m[flight_number]-1].cancellation(); break;
			case 3: number_of_flights[m[flight_number]-1].display_seats(); break;
			case 4: number_of_flights[m[flight_number]-1].display_meal(); break;
			case 5: cout<<"Enter Booking ID : "; cin>>x; number_of_flights[m[flight_number]-1].summary(x); break;
			default: cout<<"Enter a valid choice!!!";
		}
		
		cout<<"\nDo you want to continue(y/n) ? ";
		cin>>j;
			
	}while(j=='y' || j=='Y');
	return 0;
}
