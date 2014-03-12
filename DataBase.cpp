/* 
 * File:   DataBase.cpp
 * Author: khagendra
 * 
 * Created on 08 March 2014, 2:21 PM
 */

#include "DataBase.h"
#include "StudentRecord.h"
#include <list>
using namespace NDXKHA001;

DataBase::~DataBase() {
}
void DataBase::add(StudentRecord sr){
    db.push_back(sr);
  //  std::cout<<"things left: "<< db.size()<<std::endl;
}

bool DataBase::remove(std::string snum){
   
    bool removed = false;
    std::list<StudentRecord>::iterator it = db.begin(), end = db.end();
    std::cout<< db.size()<<std::endl;
    for(;it != end; ++it){
       // std::cout<<(*it).studentNumber<<std::endl;
        if((*it).studentNumber==snum){
            db.erase(it);
            removed = true;
        }
        return removed;
    }
    
}
