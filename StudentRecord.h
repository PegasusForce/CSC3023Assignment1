/* 
 * File:   StudentRecord.h
 * Author: khagendra
 *
 * Created on 08 March 2014, 2:08 PM
 */

#ifndef STUDENTRECORD_H
#define	STUDENTRECORD_H
#include <string>
#include <iostream>
#include <utility>
#include "counter.h"
#include "tokenlib/tokenlib.h"
namespace NDXKHA001{
class StudentRecord: public sjp::counter<StudentRecord>{
    public:
    //Default constructor
    StudentRecord(): name("Ulfric"), surname("Stormcloak"), studentNumber("STRULF001"), classRecord("100 100 100 100"), token(tokenlib::acquire_token()){};
    //Standard constructor
    StudentRecord(std::string n, std::string sname, std::string snum, std::string cr);
    //Copy Constructor
    StudentRecord(const StudentRecord& orig): name(orig.name), surname(orig.surname), studentNumber(orig.studentNumber), classRecord(orig.classRecord), token(tokenlib::acquire_token()){};
    //Destructor
    virtual ~StudentRecord();
    //Move Constructor
    StudentRecord(StudentRecord && rhs): name(std::move(rhs.name)), surname(std::move(rhs.surname)), studentNumber(std::move(rhs.studentNumber)), classRecord(std::move(rhs.classRecord)), token(rhs.token){rhs.token = -1;};
    //Copy Assignment Operator
    StudentRecord& operator=(const StudentRecord & rhs);
    //Move Assignment Operator
    StudentRecord& operator=(StudentRecord && rhs);
    // output stream operator
    friend std::ostream & operator<<(std::ostream & out, const StudentRecord & s);
    
    

    std::string name;
    std::string surname;
    std::string studentNumber;
    std::string classRecord;
    int token;
    private:
};
}
#endif	/* STUDENTRECORD_H */

