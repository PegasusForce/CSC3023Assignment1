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
#include <istream>
#include <stdio.h>
#include <string.h>
#include <sstream>
#include <string>
using namespace NDXKHA001;
std::ostream & operator<<(std::ostream & out, const StudentRecord & s){
        
        out<<s.name<<"|"<<s.surname<<"|"<<s.studentNumber<<"|"<<s.classRecord<<"|"<<s.token<<std::endl;
        return out;
    }
std::string* operator>> (std::string* in, StudentRecord & sr)
{
    sr = StudentRecord(in[0],in[1],in[2],in[3]);
    
    return in;
}

DataBase::~DataBase() {
    db.clear();
}
bool DataBase::check(std::string snum){
    std::list<StudentRecord>::iterator it = db.begin(), end = db.end();

    for(;it != end; ++it){
       
        if((*it).studentNumber==snum){
            std::cout << "Student: "<<snum<<" already exists! Not adding"<<std::endl;
            return false;
        }
       
    }
    return true;
}
void DataBase::add(StudentRecord sr){
   if(sr.token != -1 && check(sr.studentNumber)){ 
    db.push_back(sr);
   }
}

bool DataBase::remove(std::string snum){
   
    bool removed = false;
    std::list<StudentRecord>::iterator it = db.begin(), end = db.end();

    for(;it != end; ++it){
       // std::string temp = (*it).studentNumber;
       // std::cout<<(*it).studentNumber<<"=="<<snum;
        if((*it).studentNumber==snum){
            db.erase(it);
            removed = true;
            return removed;
        }
        
    }
    return removed;
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
    db.clear();
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
       //   std::cout<<fields[i]<<" ";
        }
        StudentRecord temp;
        fields >> temp;
        add(temp);
    }
    myfile.close();
  }

  else std::cout << "Unable to open file"; 

}

void DataBase::printData(std::string snum){
    bool found = false;
    std::list<StudentRecord>::iterator it = db.begin(), end = db.end();

    for(;it != end; ++it){
       
        if((*it).studentNumber==snum){
            std::cout<<(*it).name<<" "<<(*it).surname<<std::endl<<(*it).studentNumber<<std::endl<<"Class Record: "<<(*it).classRecord;
            found =true;
            break;
        }
       
    }
    if(!found){std::cout<<"No student with that student number";}
}

void DataBase::printAverage(std::string snum){
    bool found = false;
    float sum =0;
    float count =0;
    std::list<StudentRecord>::iterator it = db.begin(), end = db.end();

    for(;it != end; ++it){
       
        if((*it).studentNumber==snum){
            found = true;
        char * pch;
        std::string temp = (*it).classRecord.c_str();
        char *charLine = (char*)temp.c_str();
        pch = strtok(charLine, " ");
        while(pch != NULL){
            float temp;
            std::stringstream convert(pch);
            convert >> temp;
            sum += temp;
            count++;
            pch = strtok (NULL, " ");
          //std::cout<<"added "<<temp<<std::endl;
        }
            break;
        }
        
        
       
    }
    if(found){
        float result = sum/count; 
        std::cout << "Average for "<<snum<<" :"<<result<<"%";
    }else{
        std::cout<<"No student with that student number";
    }
}

void DataBase::printAll(){
     std::list<StudentRecord>::iterator it = db.begin(), end = db.end();
std::cout<<"Name\tSurname\tStudent Number\tClass Record"<<std::endl;
std::cout<<"------------------------------------------------------------"<<std::endl;
    for(;it != end; ++it){
        
        std::cout<<"------------------------------------------------------------"<<std::endl;
        std::cout<<(*it).name<<"\t"<<(*it).surname<<"\t"<<(*it).studentNumber<<"\t("<<(*it).classRecord<<")"<<std::endl;    
    }
}
void DataBase::findWinner(){
    std::list<StudentRecord>::iterator it = db.begin(), end = db.end();
    std::string winner = "Nobody!";
    float avg = 0;
    float sum =0;
    int count =0;
    for(;it != end; ++it){
        char * pch;
        std::string temp = (*it).classRecord.c_str();
        char *charLine = (char*)temp.c_str();
        pch = strtok(charLine, " ");
        while(pch != NULL){
            float temp;
            std::stringstream convert(pch);
            convert >> temp;
            sum += temp;
            count++;
            pch = strtok (NULL, " ");
          //std::cout<<"added "<<temp<<std::endl;
        }
        float result = sum/count;
        if(result>avg){
            winner = (*it).name+" "+(*it).surname;
            avg = result;
        }
    }
    std::cout<<"The winner is: "<<winner<<" with an average of "<<avg<<"%"<<std::endl;
}