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
    
   //static bool initialize();
    void add(NDXKHA001::StudentRecord sr);
    bool remove(std::string snum);
    bool check(std::string snum);
    void read();
    void write();
    void printData(std::string snum);
    void printAverage(std::string snum);
    void printAll();
    void findWinner();
    
    private:
     std::list<NDXKHA001::StudentRecord> db;
     std::string fileName;
};
}
#endif	/* DATABASE_H */

