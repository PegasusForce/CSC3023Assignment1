/* 
 * File:   main.cpp
 * Author: Khagendra Naidoo
 * Assignment 1 - Part 1
 * 
 * Created on 08 March 2014, 1:17 PM
 */

#include <iostream>
#include <fstream>
#include "StudentRecord.h"
#include "cmdline_parser.h"
#include "DataBase.h"

void clear(void);//clear the output terminal
void stringToUpper(std::string&);//convert string to uppercase

using namespace std;
using namespace NDXKHA001;

/*
 * Main program
 */
int main(int argc, char* argv[]) {
    {
   //Use cmd_parser to get the filename from the terminal argument
	cmdline_parser parser;

	if(!parser.process_cmdline(argc, argv))
	{
		std::cerr << "Couldn't process command line arguments" << std::endl;
		return 1;
	}

	if(parser.should_print_help())
		{ parser.print_help(std::cout);	}

	string file_name = parser.get_filename();
	cout << "Using file located at "+ file_name << endl;
	cout << "-----------------------------------------------------" << endl;
         DataBase db = DataBase(file_name);
	
    //Start menu loop
    cout<< "Welcome to the Mage's College of Winterhold student database\n------------------------------------------------------------\n";

    int choice;
    bool exit = false;
    while(!exit){
            cout<< "Please choose an option:\n\n1. Add Student\n2. Delete given student\n3. Read Database\n4. Save Database\n5. Display given student data\n6. Grade Student\n7. Display all student data\n8. Find winning student\n\n0. Exit\n\nEnter choice: ";
    cin >>  choice;
     clear();
    switch(choice){
        case 0:
          exit = true;
          cout << "Wizards rule!";
        break;
        case 1://Add student
                {
                    string name;
                    string surname;
                    string snum;
                    string cr;
                    cout<<"Enter the student's first name: ";
                    cin>> name;
                    cout<<"Enter the student's second name: ";
                    cin>> surname;
                    cout<<"Enter the student's student number: ";
                    cin>>snum;
                    stringToUpper(snum);
                    cout<<"Enter the students class record (e.g. 100 89 75 36 ): ";
                    cin.ignore();
                    getline(cin, cr);
                    
                    db.add(StudentRecord(name, surname, snum, cr));
      
                       }
        break;    
        case 2:
        {//Remove a student from the database
            cout<<"Enter the student number of the student you would like to delete: ";
            std::string snum;
            
            cin>>snum;
            stringToUpper(snum);
           if(db.remove(snum)){
               cout<<"Success!"<<endl;
           }else{
               cout<<"Fail!"<<endl;
           }
            
        
        }
        break;
        case 3://Read the database file into the programs virtual database
            db.read();
        break;
        case 4:{//Write the virtual database to the database file; overwrites the file
            db.write();
        }
            break;
        case 5://Print out a specific student's details
        {   cout<<"Enter student's student number: ";
         string choice;
         
        cin>>choice;
        stringToUpper(choice);
        db.printData(choice);}
            break;
        case 6://Calculate a students average mark
        {
            cout << "Enter the student number for the student you'd like to see the average: ";
            string snum;
       
            cin>> snum;
            stringToUpper(snum);
            db.printAverage(snum);
        }
            break;
        case 7://Print all records
        {
            db.printAll();
        }
            break;
        case 8://Find the winning student
            
        {
            db.findWinner();
        }
            break;
    }
    cout<< endl;
    }
    
    

}
StudentRecord::print_counts(std::cout, "StudentRecord");
tokenlib::final_token_check();
    return 0;
}
void clear(void) { std::cout << std::string(100,'\n'); }

void stringToUpper(string &s)
{
   for(unsigned int l = 0; l < s.length(); l++)
  {
    s[l] = toupper(s[l]);
  }
}
