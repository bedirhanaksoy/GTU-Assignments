#include "student.h"                                    // includes student.h and course.h
#include "course.h"
#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

 
namespace PA4                                                       // namespace PA4
{
Student::Student() : name(""), ID(0), CourseList(nullptr)           // Default constructor
{

}

Student::Student(string student_name, int Student_ID) : name(student_name), ID(Student_ID), CourseList(nullptr),numCourses(0)   // Constructor with name and ID 
{

}


Student::~Student()                     //Destructor
{
    delete[] CourseList;
}

string Student::getStudentName()        // returns student name
{
    return name;
}

int Student::getID()                    // returns ID
{
    return ID;
}

void Student::addCourse(Course* course)                                                     // adds new course to student object that he enrolled
{
    Course** newCourseList = new Course*[numCourses + 1];                                   // creates new course** with 1 size bigger
    for (int i = 0; i < numCourses; i++)
    {
        newCourseList[i] = CourseList[i];                                                   // assigns old one to new one
    }
    newCourseList[numCourses] = course;                                                     // assign the address of the new Course object
    delete[] CourseList;                                                                    // deletes old course array
    CourseList = newCourseList;                                                             // assigns new one
    numCourses++;                                                                           // increments total num of courses
}


Course** Student::getCourses()                                                              // returns courselist course array
{
    return CourseList;
}
void Student::removeCourse(Course* course) {                                                // removes course from course array
  
    int index = -1;
    for (int i = 0; i < numCourses; i++) {                                                  // searchs the course which is going to be dropped
        if (CourseList[i] == course) {
            index = i;
            break;
        }
    }
    if (index == -1) {                                                                      // if index doesnt change, course didnt found
      
        return;
    }

    
    for (int i = index; i < numCourses-1; i++) {                                            // removes the course from the CourseList array
        CourseList[i] = CourseList[i+1];                                                    // until that index the rest of the elements slide 1 space back
    }
    CourseList[numCourses-1] = nullptr;                                                     // make null the last element
    numCourses--;                                                                           // decrement total num of courses
}  
int Student::get_num_courses()                                                              // returns total num of courses
{
    return numCourses;
}

}
