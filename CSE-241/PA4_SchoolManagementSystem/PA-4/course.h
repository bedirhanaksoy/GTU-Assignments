#ifndef COURSE_H                                                
#define COURSE_H

#include <string>
#include <iostream>

using namespace std;                                            // using namespace std to use std types
//class Student;

namespace PA4                                                   // namespace PA4
{
    class Student;                                              // forward declaration for Student class
    
    class Course                                                
    {
        public:
        Course();                                               // Default constructor
        Course(string Course_Name, string Course_Code);         // Constructor with name and course code parameters
        ~Course();                                              // Destructor
        string getCode();                                       // returns coruses code
        void setCode(string Course_Code);                       // sets courses code
        void setCourseName(string Course_Name);                 // sets courses name
        string getCourseName();                                 // returns courses name
        int get_num_students();                                 // returns total num of students in this class
        Student** getStudents();                                // returns list of students which enrolled to this class
        void addStudent(Student* student);                      // adds student
        void removeStudent(Student* student);                   // removes student

        private:
        string name;                                            // courses name
        string code;                                            // courses code
        Student** StudentList;                                  // students list which enrolled to this class
        int numStudents;                                        // total num of students in this class
    };
}
#endif