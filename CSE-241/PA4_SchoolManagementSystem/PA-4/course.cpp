#include "course.h"                                                         // include course.h and student.h
#include "student.h"
#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;
namespace PA4
{



Course::Course() : name(""), code(""), StudentList(nullptr), numStudents(0)                                                                     // Default constructor
{

}


Course::Course(string Course_Name, string Course_Code) : name(Course_Name), code(Course_Code), StudentList(nullptr), numStudents(0)             // Constructor with name and code info
{

}


Course::~Course()
{
    delete[] StudentList;                                               // Destructor
}


string Course::getCourseName()                                          // returns course name
{
    return name;
}

void Course::setCourseName(string Course_Name)                          // sets course name
{
    name = Course_Name;
}

string Course::getCode()                                                // returns course code
{
    return code;
}

void Course::setCode(string Course_Code)                                // sets course code
{
    code = Course_Code;
}

Student** Course::getStudents()                                         // returns list of students in this course
{
    return StudentList;
}

void Course::addStudent(Student* student)                               // adds student to this course
{
    Student** newStudentList = new Student*[numStudents + 1];           // creates new student list with one size bigger
    for (int i = 0; i < numStudents; i++)
    {
        newStudentList[i] = StudentList[i];                             // assign every element to new list
    }   
    newStudentList[numStudents] = student;                              // last element assign
    delete[] StudentList;                                               // delete the old one
    StudentList = newStudentList;                                       // assign student list to new list
    numStudents++;                                                      // increment total num of student 

}
int Course::get_num_students(){                                         // returns total num of students
    return numStudents;
}
void Course::removeStudent(Student* student) {                          // drop student from this course
    int index = -1;
    for (int i = 0; i < numStudents; i++) {                             // searchs for the student which going to be dropped from course
        if (StudentList[i] == student) {
            index = i;
            break;
        }
    }

    if (index != -1) {                                                    // if it is found, every element shifth one cell left 
        
        for (int i = index; i < numStudents - 1; i++) {
            StudentList[i] = StudentList[i + 1];
        }
        StudentList[numStudents - 1] = nullptr;                           // last cell will be null
        numStudents--;                                                     // decrement the total num of students
       
    }
}
}

