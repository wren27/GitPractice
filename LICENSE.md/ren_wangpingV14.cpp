// Name: Ren_wangping ID:A20368149 Section: CS105
//This program is written to store info about athleles from 2016 Summer Qlympics
//Users may search info like names,ages,country info,venue or ad revenue through this program
//or also learn about all the info at once
#include <iostream>
#include <string>
#include <fstream>
using namespace std;
int MAXATHLETES = 50;
int MAXCOUNTRIES = 20;
int MAXFUNCTIONCALLS = 100;
void menu(char letter,string countryName[],string lastnames[],string firstnames[],int ages[],double ad_revenues[],char venues[],string sports[],int number_of_athletes_each_country[],int letterCounters[]);
void listall(string array1[],string array2[],int array3[],double array4[],char array5[],string array6[]);
bool athleteReport(string lastname1,string array1[],string array2[],int array3[],double array4[],char array5[],string array6[]);
bool countryReport(string countryName2,string array0[],string array1[],string array2[],int array3[],double array4[],char array5[],string array6[],int array7[]);
bool venueReport(char character,string array1[],string array2[],char array3[]);
bool adRevenueReport(string lastname,string lastnames[],string firstnames[],double ad_revenues[]);
void finalStats(int letterCounters[]);
void sortList(string lastnames[]);
int main ()
{
	string firstnames[MAXATHLETES];
    string lastnames[MAXATHLETES];
    int ages[MAXATHLETES];
    int i=0;
	int number_of_athletes_each_country[MAXCOUNTRIES];
    int numCountries = 0;
	int counter=0,counter1=0;
	int letterCounters[8]={0,0,0,0,0,0,0,0};//This array is for finalStats function.
    double ad_revenues[MAXATHLETES];
    char venues[MAXATHLETES];
	char letter1;
	char letter2;
    string sports[MAXATHLETES];
	string countryName[MAXCOUNTRIES];
	ifstream inputFile;
	inputFile.open("socs105.txt");
	inputFile >> countryName[counter];
	while (countryName[counter]!="END_OF_FILE")
	{

	inputFile >> number_of_athletes_each_country[counter];
	for (i=0;i<number_of_athletes_each_country[counter];i++)//i is used as a loop control varaible, counter1 is used to count the total athletes so that info from file could be put into arrays in sequence.
	{
	inputFile >> lastnames[counter1];
	inputFile >> firstnames[counter1];
	inputFile >> ages[counter1];
	inputFile >> ad_revenues[counter1];
	inputFile >> venues[counter1];
	getline(inputFile, sports[counter1]);
	counter1++;
	}
	counter++;
	inputFile >> countryName[counter];


	}

	inputFile.close();
	cout << "Enter M to get main menu" << endl;
	cout << "Enter Q to see how many times you have entered for each letter in main menu" << endl;
	cout << "Please enter a character: ";
	cin >> letter1;
	cout << endl;
	switch (letter1)
	{
		case'M':
		case'm':
		cout << "Enter L or l to list all information of all athletes" << endl;
		cout << "Enter A or a to find information for specific athlete" << endl;
		cout << "Enter C or c to find information about atheles in each country" << endl;
		cout << "Enter R or r to have information on athletes ad revenue" << endl;
		cout << "Enter V or v to have information on venues" << endl;
		cout << "Enter Q or q to go back" << endl;
		cout << "Enter O or o to have all athletes' lastnames sorted alphabetically" << endl;
		cout << "Please enter a character: ";

		cin >> letter2;
		menu( letter2,countryName,lastnames,firstnames,ages,ad_revenues,venues,sports,number_of_athletes_each_country,letterCounters);
		break;
		case'q':
		case'Q':
		finalStats(letterCounters);
		break;
		default:
		letterCounters[7]++;//This is counting bad inputs for finalStats function.
		cout << "Input error, please try again." << endl;
	}
		return (0);

    }
	//This is main menu function, offerring different options from different functions so that users might choose the one that they are looking for.
	void menu (char letter,string countryName[],string lastnames[],string firstnames[],int ages[],double ad_revenues[],char venues[],string sports[],int number_of_athletes_each_country[],int letterCounters[])
	{
		string lastname,countryName1,lastname1;
		char venueName;
		switch (letter)
		{

			case'l':
			case'L':
			letterCounters[0]++;
			listall(lastnames,firstnames,ages,ad_revenues,venues,sports);
			break;
			case'a':
		    case'A':
			letterCounters[1]++;
		    cout << "Enter the athlete's lastname that you want to search for: ";
		    cin >> lastname;
		    cout << endl;
		    athleteReport(lastname,lastnames,firstnames,ages,ad_revenues,venues,sports);
			break;
			case'c':
		    case'C':
			letterCounters[2]++;
		    cout << "Enter the name of the country that you want to search for or enter 'ALL' to see all the information: ";
		    cin >> countryName1;
		    cout << endl;
		    countryReport(countryName1,countryName,lastnames,firstnames,ages,ad_revenues,venues,sports,number_of_athletes_each_country);
		    break;
			case 'r':
			case 'R':
			letterCounters[3]++;
			cout << "Enter the athlete's lastname that you want to search for: ";
			cin >> lastname1;
			adRevenueReport(lastname1,lastnames,firstnames,ad_revenues);
			break;
			case'v':
			case'V':
			letterCounters[4]++;
			cout << "Please enter a character for the venue you want to search or enter 'a' to see all the info: ";
			cin >> venueName;
			cout << endl;
		    venueReport(venueName,lastnames,firstnames,venues);
			break;
			case'q':
			case'Q':
			letterCounters[5]++;
			main();
			break;
			case'o':
			case'O':
			sortList(lastnames);
			letterCounters[6]++;
			break;
			default:
			cout << "Input error, please try again." << endl;
		}
	}
	//This function is written to list all the info about all athletes who paticipate the Qlympics
	void listall(string array1[],string array2[],int array3[],double array4[],char array5[],string array6[])
	{
		int i;
		int listsize=19;
		for (i=0;i<listsize;i++)
		{
			cout << array1[i] << " ";
			cout << array2[i] << " ";
			cout << array3[i] << " ";
			cout << array4[i] << " ";
			cout << array5[i] << " ";
			cout << array6[i] << endl;
		}
	}
	//This function is written to give all info for specific athlete that the users are looking for.
	bool athleteReport(string lastname1,string array1[],string array2[],int array3[],double array4[],char array5[],string array6[])
	{
	    int i=0;
		int counter = 19;// Number of total athletes


		while (i<counter)
		{

		if (lastname1 == array1[i])
		{

			cout << array1[i] << " ";
			cout << array2[i] << " ";
			cout << array3[i] << " ";
			cout << array4[i] << " ";
			cout << array5[i] << " ";
			cout << array6[i] << endl;
			return true;
		}
		else
			i++;
		}
		cout << "No athlete found." << endl;
		return false;

		}
		//This function is written to offer athletes info for a specific country or all of them.
		bool countryReport(string countryName2,string array0[],string array1[],string array2[],int array3[],double array4[],char array5[],string array6[],int array7[])
	{

		int i=0,k,j,counter = 0,sum1=0;
		double averageValue,sum=0;
		int countriesNum = 4; //Number of countries
        if (countryName2!= "ALL")
		{

			while (i<countriesNum)
		{

		if (countryName2 == array0[i])
		{
			for (j=0;j < array7[i];j++)
		    {
			sum = sum + array4[sum1];
			cout << array1[sum1] << " ";
			cout << array2[sum1] << " ";
			cout << array3[sum1] << " ";
			cout << array4[sum1] << " ";
			cout << array5[sum1] << " ";
			cout << array6[sum1] << endl;
			sum1++;
			}
			averageValue = sum / array7[i];
		    cout << "The sum of the total ad revenue is: " << sum << endl;
		    cout << "The average value of ad revenue for the country you entered is: " << averageValue;
		    return true;


		}
		else
		{
			sum1=sum1+array7[i];//The sum1 is used to output info from arrays in sequence ao that it won't be assigned 0 like j does.
		    i++;
		}
		}
		if (i=4)//This time no countries fits.
			cout << "No country found." << endl;
			return false;
		}
		else if (countryName2 == "ALL")
		{
			while (i<countriesNum)
			{
			cout << array0[i] << endl;
			sum = 0;
			for (k=0;k<array7[i];k++)
		{

			sum = sum + array4[counter];

			cout << array1[counter] << " ";
			cout << array2[counter] << " ";
			cout << array3[counter] << " ";
			cout << array4[counter] << " ";
			cout << array5[counter] << " ";
			cout << array6[counter] << endl;
			counter++;
		}
		averageValue = sum / array7[i];//How to show double type
		cout << "The sum of the total ad revenue is: " << sum << endl;
		cout << "The average value of ad revenue for the country you entered is: " << averageValue << endl;
		i++;

		}
		return true;
		}
		}
		//This function is written to offer athletes info for different venues.
	    bool venueReport(char character,string array1[],string array2[],char array3[])
		{
			int i = 0;
			if (character == 'a')
			{
			cout << "q" << endl;
			while (i < 19) //Number of total athletes
			{
				if (array3[i] == 'q')
				{
					cout << array1[2] << " " << array2[2] << " " << "individual sport" << endl;
						cout << array1[3] << " " << array2[3] << " " << "team sport" << endl;
						cout << array1[4] << " " << array2[4] << " " << "board sport" << endl;
						cout << array1[6] << " " << array2[6] << " " << "individual sport" << endl;
						cout << array1[8] << " " << array2[8] << " " << "team sport" << endl;
						cout << array1[12] << " " << array2[12] << " " << "individual sport" << endl;
						cout << array1[13] << " " << array2[13] << " " << "board sport" << endl;
	                    cout << array1[15] << " " << array2[15] << " " << "board sport" << endl;
				        i=19;
				}
				else i++;
			}
			cout << "p" << endl;
			i=0;
			while (i < 19)
			{
				if (array3[i] == 'p')
				{
					cout << array1[i] << " " << array2[i] << endl;
					i++;
				}
				else i++;
			}
			cout << "w" << endl;
			i=0;
			while (i < 19)
			{
				if (array3[i] == 'w')
				{
					cout << array1[i] << " " << array2[i] << endl;
					i++;
				}
				else i++;
			}
			cout << "h" << endl;
			i=0;
			while (i < 19)
			{
				if (array3[i] == 'h')
				{
					cout << array1[i] << " " << array2[i] << endl;
					i++;
				}
				else i++;
			}
			cout << "k" << endl;
			i=0;
			while (i < 19)
			{
				if (array3[i] == 'k')
				{
					cout << array1[i] << " " << array2[i] << endl;
					i++;
				}
				else i++;
			}
	         return true;
			}
		    else if (character !='a')
			{
				while (i < 19)
			{
			if (character == array3[i])
			{
				switch(character)
				{
					case'q':
					    cout << array1[2] << " " << array2[2] << " " << "individual sport" << endl;
						cout << array1[3] << " " << array2[3] << " " << "team sport" << endl;
						cout << array1[4] << " " << array2[4] << " " << "board sport" << endl;
						cout << array1[6] << " " << array2[6] << " " << "individual sport" << endl;
						cout << array1[8] << " " << array2[8] << " " << "team sport" << endl;
						cout << array1[12] << " " << array2[12] << " " << "individual sport" << endl;
						cout << array1[13] << " " << array2[13] << " " << "board sport" << endl;
	                    cout << array1[15] << " " << array2[15] << " " << "board sport" << endl;
				        i=19;
					break;
					default:
				    {
						cout << array1[i] << " " << array2[i] << endl;
				        i++;//Both place should have loop control varaible
					}
				}
			}
			else
				i++;//Both place should have loop control varaible
			}
			if (i<19)
			{
			return true;
			}
			else
				cout << "No venue found." << endl;
			return false;

			}
			}
			//This program is written to offer ad revenue info for different athletes.
			bool adRevenueReport(string lastname,string lastnames[],string firstnames[],double ad_revenues[])
			{
				int i = 0;
				if (lastname!="all")
				{
				while (i < 19)//number of total athletes.
				{
				if (lastname == lastnames[i])
				{
					cout << lastnames[i] << " " << ad_revenues[i] << endl;
					return true;
				}
				else i++;
				}
				cout << "No athlete found." << endl;
				return false;
				}
				else if (lastname == "all")
				{
					while (i < 19)
					{
						cout << lastnames[i] << " " << firstnames[i] << " " << ad_revenues[i] << endl;
						i++;
					}
					return true;
				}
			}
			//This function is used is count the times that the users entered for each letter in main menu.
			void finalStats(int letterCounters[])
			{
				cout << "The number of L's is" << " " << letterCounters[0] << endl;
				cout << "The number of A's is" << " " << letterCounters[1] << endl;
				cout << "The number of C's is" << " " << letterCounters[2] << endl;
				cout << "The number of R's is" << " " << letterCounters[3] << endl;
				cout << "The number of V's is" << " " << letterCounters[4] << endl;
				cout << "The number of Q's is" << " " << letterCounters[5] << endl;
				cout << "The number of Q's is" << " " << letterCounters[6] << endl;
				cout << "The number of Q's is" << " " << letterCounters[7] << endl;
			}
			void sortList(string array1[])
			{
				int i;
				for (i=0;i < 19;i++)
				{
				if (array1[i][0]=='A')
					cout << array1[i] << " ";
				}
				for (i=0;i < 19;i++)
				{
				if (array1[i][0]=='C')
					cout << array1[i] << " ";
				}
				for (i=0;i < 19;i++)
				{
				if (array1[i][0]=='D')
					cout << array1[i] << " ";
				}
				for (i=0;i < 19;i++)
				{
				if (array1[i][0]=='F')
					cout << array1[i] << " ";
				}
				for (i=0;i < 19;i++)
				{
				if (array1[i][0]=='G')
					cout << array1[i] << " ";
				}
				for (i=0;i < 19;i++)
				{
				if (array1[i][0]=='H')
					cout << array1[i] << " ";
				}
				for (i=0;i < 19;i++)
				{
				if (array1[i][0]=='J')
					cout << array1[i] << " ";
				}
				for (i=0;i < 19;i++)
				{
				if (array1[i][0]=='K')
					cout << array1[i] << " ";
				}
				for (i=0;i < 19;i++)
				{
				if (array1[i][0]=='L')
					cout << array1[i] << " ";
				}
				for (i=0;i < 19;i++)
				{
				if (array1[i][0]=='M')
					cout << array1[i] << " ";
				}
				for (i=0;i < 19;i++)
				{
				if (array1[i][0]=='O')
					cout << array1[i] << " ";
				}
				for (i=0;i < 19;i++)
				{
				if (array1[i][0]=='P')
					cout << array1[i] << " ";
				}
				for (i=0;i < 19;i++)
				{
				if (array1[i][0]=='S')
					cout << array1[i] << " ";
				}
			}






