#ifndef STUDENT_H                                               // checks wether student.h is defined or not
#define STUDENT_H                                               // define student.h

#include <string>                                               
#include <iostream>

using namespace std;                                            // using namespace std to use std types
//class Course;

namespace PA4                                                   // namespace PA4
{
    class Course;                                               // forward declaration for Course class

    class Student                                               // Student class
    {
        public:
        Student();                                              // Default constructor
        Student(string student_name, int Student_ID);           // Constructor with given name and id
        ~Student();                                             // Destructor 
        int getID();                                            // returns students id
        string getStudentName();                                // returns students name
        void addCourse(Course* course);                         // enrolls student to given course
        void removeCourse(Course* course);                      // drops student from given course
        int get_num_courses();                                  // returns total num of courses that student enrolled
        Course** getCourses();                                  // returns list of courses that student enrolled


        private:
        string name;                                            // students name
        int ID;                                                 // students id
        Course** CourseList;                                    // courses list that student enrolled
        int numCourses;                                         // total number of courses that user enrolled
    };
}
#endif                                                          // endif statement for ifndef
