/* 
 * File:   StudentRecord.cpp
 * Author: khagendra
 * 
 * Created on 08 March 2014, 2:08 PM
 */

#include "StudentRecord.h"



//Destructor
StudentRecord::~StudentRecord() {
    
}

//Copy Assignment Operator
    StudentRecord& StudentRecord::operator=(const StudentRecord & rhs)
    {
        if(this != &rhs)
        {
            name = rhs.name;
            surname = rhs.surname;
            studentNumber = rhs.studentNumber;
            classRecord = rhs.classRecord;
            token = rhs.token;
           
        }
        
    }
    //Move Assignment Operator
    StudentRecord& StudentRecord::operator=(StudentRecord && rhs){
        if(this != &rhs){
            name = move(rhs.name);
            surname = move(rhs.surname);
            studentNumber = move(rhs.studentNumber);
            classRecord = move(rhs.studentNumber);
            token = rhs.token;
        }
    }
    //Standard constructor
    StudentRecord::StudentRecord(std::string n, std::string sname, std::string snum, std::string cr){
        name = n;
        surname = sname;
        studentNumber = snum;
        classRecord = cr; 
        token = 0;
    }

