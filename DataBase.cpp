/* 
 * File:   DataBase.cpp
 * Author: khagendra
 * 
 * Created on 08 March 2014, 2:21 PM
 */

#include "DataBase.h"
#include "StudentRecord.h"
#include <list>
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string.h>
#include <string>
using namespace NDXKHA001;
std::ostream & operator<<(std::ostream & out, const StudentRecord & s){
        
        out<<s.name<<"|"<<s.surname<<"|"<<s.studentNumber<<"|"<<s.classRecord<<"|"<<s.token<<std::endl;
        
    }

DataBase::~DataBase() {
    db.clear();
}
void DataBase::add(StudentRecord sr){
    db.push_back(sr);
  
}

bool DataBase::remove(std::string snum){
   
    bool removed = false;
    std::list<StudentRecord>::iterator it = db.begin(), end = db.end();

    for(;it != end; ++it){
       
        if((*it).studentNumber==snum){
            db.erase(it);
            removed = true;
        }
        return removed;
    }
    
}

void DataBase::write(){
  std::ofstream myfile;
        myfile.open (fileName);
     std::list<StudentRecord>::iterator it = db.begin(), end = db.end();

    for(;it != end; ++it){
        
       myfile<<*it;
        }
            
    
        myfile.close();
}

void DataBase::read(){
    std::string fields[5];
    std::string line;
  std::ifstream myfile (fileName);
  if (myfile.is_open())
  {
    while ( getline (myfile,line) )
    {
        char * pch;
        char *charLine = (char*)line.c_str();
        pch = strtok(charLine, "|");
        for(int i=0;i<5;i++){
            fields[i] = pch;
            pch = strtok (NULL, "|");
            std::cout<<fields[i]<<" ";
        }
        StudentRecord temp;
       // fields >> temp;
    }
    myfile.close();
  }

  else std::cout << "Unable to open file"; 

}
