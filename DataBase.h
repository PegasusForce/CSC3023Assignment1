/* 
 * File:   DataBase.h
 * Author: khagendra
 *
 * Created on 08 March 2014, 2:21 PM
 */

#ifndef DATABASE_H
#define	DATABASE_H
#include <list>
#include "StudentRecord.h"
namespace NDXKHA001{
    class DataBase {
public:
    
    DataBase(std::string n):fileName(n){};
    virtual ~DataBase();
    
  
    void add(NDXKHA001::StudentRecord sr);
    bool remove(std::string snum);
    bool check(std::string snum);//check if a student already exists in the database
    void read(); //read database file into list
    void write();//write list into file
    void printData(std::string snum);//print a students data
    void printAverage(std::string snum);//print a students average
    void printAll();
    void findWinner();
    
    private:
     std::list<NDXKHA001::StudentRecord> db;
     std::string fileName;
};
}
#endif	/* DATABASE_H */

