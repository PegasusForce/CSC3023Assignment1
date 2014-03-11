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
void clear(void);

using namespace std;
using namespace NDXKHA001;

/*
 * Main program
 */
int main(int argc, char* argv[]) {
    

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
	cout << "-----------------------------------------" << endl;

	//ifstream file(file_name.c_str());
    
    cout<< "Welcome to the Mage's College of Winterhold student database\n------------------------------------------------------------\n";

    int choice;
    bool exit = false;
    while(!exit){
            cout<< "Please choose an option:\n\n1. Add Student\n2. Delete given student\n3. Read Database\n4. Save Database\n5. Display given student data\n6. Grade Student\n7. Display all student data\n8. Find winning student\n\n0. Exit"<<endl;
    cin >>  choice;
     clear();
    switch(choice){
        case 0:
          exit = true;
          cout << "Wizards rule!";
        break;
        case 1:
 //           cout << "You chose: add student"<<endl;
                {
                StudentRecord ghoragdush("Ghoragdush","the Goblinsmasher","GHO003","37 45 49");
                StudentRecord jothridar("Jo'Thri-Dar","the Thief","JOT004","34 87 68");
//                StudentRecord::print_counts(std::cout, "StudentRecord");
//                tokenlib::check_tokens();
                       }
        break;    
        case 2:
            cout << "You chose: delete given student"<<endl;
        break;
        case 3:
            cout << "You chose: read database"<<endl;
        break;
        case 4:{
            cout << "You chose: save database"<<endl;
            ofstream myfile;
        myfile.open (file_name);
        myfile << "Writing this to a file.\n";
        myfile.close();
        }
            break;
        case 5:
            cout << "You chose: display given student data"<<endl;
            break;
        case 6:
            cout << "You chose: grade student"<<endl;
            break;
        case 7:
            cout << "You chose: display all student data"<<endl;
            break;
        case 8:
            cout << "You chose: find winning student"<<endl;
            break;
    }
    cout<< endl;
    }
    
    
StudentRecord::print_counts(std::cout, "StudentRecord");
tokenlib::final_token_check();
    return 0;
}

void clear(void) { std::cout << std::string(100,'\n'); }

