/* 
 * File:   StudentRecord.cpp
 * Author: khagendra
 * 
 * Created on 08 March 2014, 2:08 PM
 */

#include "StudentRecord.h"
using namespace NDXKHA001;


//Destructor
StudentRecord::~StudentRecord() {
    if(token!=-1)
    tokenlib::release_token(token);
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
            if(token != -1){tokenlib::release_token(token);}
            token = tokenlib::acquire_token();
           
        }
        
    }
    //Move Assignment Operator
    StudentRecord& StudentRecord::operator=(StudentRecord && rhs){
        if(this != &rhs){
            name = std::move(rhs.name);
            surname = std::move(rhs.surname);
            studentNumber = std::move(rhs.studentNumber);
            classRecord = std::move(rhs.studentNumber);
            token = rhs.token;
            rhs.token = -1;
        }
    }
    //Standard constructor
    StudentRecord::StudentRecord(std::string n, std::string sname, std::string snum, std::string cr){
        name = n;
        surname = sname;
        studentNumber = snum;
        classRecord = cr; 
        token = tokenlib::acquire_token();
    }

