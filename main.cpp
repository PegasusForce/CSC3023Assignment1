/* 
 * File:   main.cpp
 * Author: Khagendra Naidoo
 * Assignment 1 - Part 1
 * 
 * Created on 08 March 2014, 1:17 PM
 */

#include <iostream>
void clear(void);

using namespace std;

/*
 * Main program
 */
int main() {
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
            cout << "You chose: add student";
        break;    
        case 2:
            cout << "You chose: delete given student";
        break;
        case 3:
            cout << "You chose: read database";
        break;
        case 4:
            cout << "You chose: save database";
            break;
        case 5:
            cout << "You chose: display given student data";
            break;
        case 6:
            cout << "You chose: grade student";
            break;
        case 7:
            cout << "You chose: display all student data";
            break;
        case 8:
            cout << "You chose: find winning student";
            break;
    }
    cout<< endl;
    }
    
    
    
    return 0;
}

void clear(void) { std::cout << std::string(100,'\n'); }

