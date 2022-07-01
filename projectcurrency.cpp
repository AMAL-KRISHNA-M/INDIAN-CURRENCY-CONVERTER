//including the necessary header files
#include<iostream>

#include<fstream>

#include<string>

#include<sstream>

#include<vector>

#include<iomanip>

#include<stdlib.h>

using namespace std;


vector<string> readRecordFromFile(string filename);

vector<string> readRecordFromFile1(string filename);

int menu();


//function to read from file and convert indian rupee to foreign currency
vector<string> readRecordFromFile(string filename){
    vector<string> record;

    ifstream file;
    file.open(filename);

    bool foundrecord=false;

    string fieldone;
    string fieldtwo;
    string fieldthree;
    string tempString;
    float cal, cal1, cal2;

    system("cls");

    //cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
    cout<<setw(50)<<"Type the appropriate Currency Name for performing the conversion in the required currency"<<endl;
    cout<<setw(55)<<"-> Type US Dollar for USD"<<endl;
    cout<<setw(51)<<"-> Type Euro for Euro"<<endl;
    cout<<setw(59)<<"-> Type British Pound for GBP"<<endl;
    cout<<setw(63)<<"-> Type Australian Dollar for AUD"<<endl;
    cout<<setw(61)<<"-> Type Canadian Dollar for CAD"<<endl;
    cout<<setw(62)<<"-> Type Singapore Dollar for SGD"<<endl;
    cout<<setw(57)<<"-> Type Swiss Franc for SFr"<<endl;
    cout<<setw(62)<<"-> Type Malaysian Ringgit for RM"<<endl;
    cout<<setw(58)<<"-> Type Japanese Yen for JPY"<<endl;
    cout<<setw(67)<<"-> Type Chinese Yuan Renminbi for CNY"<<endl<<endl;
    getline(cin, tempString);
    cout<<"Enter the amount to convert to "<<tempString<<" : ";
    cin>>cal;

    while (getline(file,fieldone,',') && !foundrecord) 
    {
        getline(file, fieldtwo, ',');
        cal1 = atof(fieldtwo.c_str());
        getline(file, fieldthree, '\n');
        if (fieldone == tempString){
            foundrecord = true;
            record.push_back(fieldone);
            record.push_back(fieldtwo);
            record.push_back(fieldthree);

        }
    }
    
    cout<<"\n";
    cout<<"\n";
    cout<<"One Indian Rupee is "<<cal1<<" "<<record[0]<<endl<<endl;
    cal2 = cal*cal1; 
    cout<<cal<<" Indian Rupee is "<<cal2<<" "<<record[0];
    cout<<"\n";
    cout<<"\n";
    system("pause");
    menu();
    return record;
}


//function to read from file to convert foreign currency to indian rupees
vector<string> readRecordFromFile1(string filename){
    vector<string> record;

    ifstream file;
    file.open(filename);

    bool foundrecord=false;

    string fieldone;
    string fieldtwo;
    string fieldthree;
    string tempString;
    float cal, cal1, cal2;

    system("cls");

    cout<<setw(50)<<"Type the appropriate Currency Name for performing the conversion in the required currency"<<endl;
    cout<<setw(55)<<"-> Type US Dollar for USD to Indian Rupee"<<endl;
    cout<<setw(51)<<"-> Type Euro for Euro to Indian Rupee"<<endl;
    cout<<setw(59)<<"-> Type British Pound for GBP to Indian Rupee"<<endl;
    cout<<setw(63)<<"-> Type Australian Dollar for AUD to Indian Rupee"<<endl;
    cout<<setw(61)<<"-> Type Canadian Dollar for CAD to Indian Rupee"<<endl;
    cout<<setw(62)<<"-> Type Singapore Dollar for SGD to Indian Rupee"<<endl;
    cout<<setw(57)<<"-> Type Swiss Franc for SFr to Indian Rupee"<<endl;
    cout<<setw(62)<<"-> Type Malaysian Ringgit for RM to Indian Rupee"<<endl;
    cout<<setw(58)<<"-> Type Japanese Yen for JPY to Indian Rupee"<<endl;
    cout<<setw(67)<<"-> Type Chinese Yuan Renminbi for CNY to Indian Rupee"<<endl<<endl;
    getline(cin, tempString);
    cout<<"Enter the amount to convert "<<tempString<<" to "<<"Indian Rupee"<<" : ";
    cin>>cal;


    while (getline(file,fieldone,',') && !foundrecord) 
    {
        getline(file, fieldtwo, ',');
        getline(file, fieldthree, '\n');
        cal1 = atof(fieldthree.c_str());
        if (fieldone == tempString){
            foundrecord = true;
            record.push_back(fieldone);
            record.push_back(fieldtwo);
            record.push_back(fieldthree);

        }
    }

    cout<<"\n";
    cout<<"\n";
    cout<<"One "<<record[0]<<" is "<<record[2]<<" "<<"Indian Rupee"<<endl<<endl;
    cal2 = cal*cal1; 
    cout<<cal<<" "<<record[0]<<" is "<<cal2<<" "<<"Indian Rupee";
    cout<<"\n";
    cout<<"\n";
    system("pause");
    menu();
    return record;
}


//function to show the value of 1 Rupee in foreign currency and vice versa
int show1rupee(){

    vector<string> record;

    ifstream file;
    file.open("currency.csv");
    string fieldone;
    string fieldtwo;
    string fieldthree;
    string tempString;
    int i;
    cout<<endl<<endl;

    system("cls");
    
    cout<<setw(80)<<"****************************************"<<endl;
    cout<<setw(80)<<"*                                      *"<<endl;
    cout<<setw(80)<<"*   INDIAN RUPEE EXCHANGE RATES DATA   *"<<endl;
    cout<<setw(80)<<"*                                      *"<<endl;
    cout<<setw(80)<<"****************************************"<<endl;
    cout<<endl<<endl;
    bool foundrecord=false;
    getline(file,fieldone,',');
    getline(file, fieldtwo, ',');
    getline(file, fieldthree, '\n');

    for(i=0; i<10; i++){
        getline(file,fieldone,',');
        getline(file, fieldtwo, ',');
        getline(file, fieldthree, '\n');
        cout<<"-> "<<"One "<<fieldone<<" is "<<fieldthree<<" Indian Rupee"<<" & "<<"One Indian Rupee is "<<fieldtwo<<" "<<fieldone<<endl<<endl;
    }
    cout<<endl<<endl<<endl<<endl;
    system("pause");
    menu();
    return 0;
}


//function to use switch case for making a menu driven interface
int menu(){
    
    int option;
    cout<<endl;
    cout<<endl;

    system("cls");

    cout<<setw(100)<<"\033[3;42;30m********************************************\033[0m"<<endl;
    cout<<setw(100)<<"\033[3;42;30m*                                          *\033[0m"<<endl;
    cout<<setw(100)<<"\033[3;42;30m*   Welcome to Indian Currency Converter   *\033[0m"<<endl;
    cout<<setw(100)<<"\033[3;42;30m*                                          *\033[0m"<<endl;
    cout<<setw(100)<<"\033[3;42;30m********************************************\033[0m"<<endl;
    cout<<endl;
    cout<<endl;
    cout<<setw(50)<<"\x1B[31m1. Enter 1 to convert INDIAN RUPEE TO FOREIGN CURRENCY:- ";
    cout<<endl;
    cout<<setw(55)<<"-> a) US Dollar"<<endl;
    cout<<setw(50)<<"-> b) Euro"<<endl;
    cout<<setw(59)<<"-> c) British Pound"<<endl;
    cout<<setw(63)<<"-> d) Australian Dollar"<<endl;
    cout<<setw(61)<<"-> e) Canadian Dollar"<<endl;
    cout<<setw(62)<<"-> f) Singapore Dollar"<<endl;
    cout<<setw(57)<<"-> g) Swiss Franc"<<endl;
    cout<<setw(63)<<"-> h) Malaysian Ringgit"<<endl;
    cout<<setw(58)<<"-> i) Japanese Yen"<<endl;
    cout<<setw(68)<<"-> j) Chinese Yuan Renminbi "<<endl<<endl;
    cout<<setw(50)<<"\x1B[32m2. Enter 2 to show the INDIAN RUPEE EXCHANGE RATES DATA:- "<<endl<<endl;
    cout<<setw(50)<<"\x1B[33m3. Enter 3 to convert FOREIGN CURRENCY TO INDIAN RUPEE:- "<<endl;
    cout<<setw(55)<<"-> a) US Dollar to Indian Rupee"<<endl;
    cout<<setw(50)<<"-> b) Euro to Indian Rupee"<<endl;
    cout<<setw(59)<<"-> c) British Pound to Indian Rupee"<<endl;
    cout<<setw(63)<<"-> d) Australian Dollar to Indian Rupee"<<endl;
    cout<<setw(61)<<"-> e) Canadian Dollar to Indian Rupee"<<endl;
    cout<<setw(62)<<"-> f) Singapore Dollar to Indian Rupee"<<endl;
    cout<<setw(57)<<"-> g) Swiss Franc to Indian Rupee"<<endl;
    cout<<setw(63)<<"-> h) Malaysian Ringgit to Indian Rupee"<<endl;
    cout<<setw(58)<<"-> i) Japanese Yen to Indian Rupee"<<endl;
    cout<<setw(67)<<"-> j) Chinese Yuan Renminbi to Indian Rupee"<<endl<<endl;
    cout<<setw(30)<<"\x1B[35m4. Enter 4 to EXIT FROM THE PROGRAM.\033[0m "<<endl<<endl;
    cout<<"\n";
    cin>>option;
    switch(option)
    {
    case 1:
        //this contains function to read from file and convert indian rupee to foreign currency
        fflush(stdin);
        readRecordFromFile("currency.csv");
        break;
    
    case 2:
        //this case contains function to show the value of 1 Rupee in foreign currency and vice versa 
        show1rupee();
        break;

    case 3:
        //this case contains function to read from file and convert foreign currency to indian rupee
        fflush(stdin);
        readRecordFromFile1("currency.csv");
        break;
    case 4:
        //this case is used to exit from the program
        exit(1);
    }
    
    return 0;
}


//main program
int main(){

    //calling the menu function
    menu();
    
    return 0;
}