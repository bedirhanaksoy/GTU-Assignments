#ifndef SCHOOLMANAGERSYSTEM_H
#define SCHOOLMANAGERSYSTEM_H

#include <string>
#include <iostream>

using namespace std;                                                // using namespace std for using std types

namespace PA4                                                       // namespace PA4
{
    class Student;                                                  // forward decleration for student and course classes
    class Course;

    class SchoolManagerSystem
    {
        public:
        SchoolManagerSystem();                                      // Default constructor
        ~SchoolManagerSystem();                                     // Destructor
        void select_course();                                       // select course sub menu
        void select_student();                                      // select student sub menu
        void main_menu();                                           // main menu
        void student_menu();                                        // student sub menu 
        void course_menu();                                         // course sub menu
        void add_student_to_a_course(Student* student);             // adds student to a course
        void remove_student_from_a_course(Student* student);        // drops student from a course
        void delete_student(Student* student);                      // deletes a student from system
        void delete_course(Course* Course);                         // deletes a course from system
        void add_student();                                         // adds student to system
        void add_course();                                          // adds course to system
        int get_number_of_students();                               // returns total num of students
        int get_number_of_courses();                                // returns total num of courses
        void list_all_students();                                   // lists all students
        void list_all_courses();                                    // lists all courses

        private:
        Course** List_of_All_Courses;                               // list of all courses
        Student** List_of_All_Students;                             // list of all students
        int number_of_courses;                                      // total num of courses
        int number_of_students;                                     // total num of students
    };
}
#endif