/* 
 * File:   StudentRecord.h
 * Author: khagendra
 *
 * Created on 08 March 2014, 2:08 PM
 */

#ifndef STUDENTRECORD_H
#define	STUDENTRECORD_H
#include <string>

class StudentRecord {
public:
    //Default constructor
    StudentRecord();
    //Copy Constructor
    StudentRecord(const StudentRecord& orig);
    //Destructor
    virtual ~StudentRecord();
    //Move Constructor
    StudentRecord(StudentRecord && rhs);
    //Copy Assignment Operator
    StudentRecord& operator=(const StudentRecord& rhs);
    
    std::string name;
    std::string surname;
    std::string studentNumber;
    std::string classRecord;
    int token;
private:

};

#endif	/* STUDENTRECORD_H */

