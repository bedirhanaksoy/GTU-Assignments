#include "SchoolManagerSystem.h"            // includes all header files
#include "student.h"
#include "course.h"
#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;
namespace PA4
{

    SchoolManagerSystem::SchoolManagerSystem():number_of_courses(0), number_of_students(0), List_of_All_Students(nullptr), List_of_All_Courses(nullptr)
    {
                                                            // default constructor
    }

    void SchoolManagerSystem::main_menu(){                  // main menu 
        int input;
        while (true)
        {
            cout<<"0 exit"<<endl;
            cout<<"1 student"<<endl;
            cout<<"2 course"<<endl;
            cout<<"3 list_all_students"<<endl;
            cout<<"4 list_all_courses"<<endl;
            cin>>input;
            
            switch (input)
            {
                case 0: 
                    return;                                 // returns main and terminates program in main
                case 1: 
                    student_menu();                         // student sub menu
                    break;
                case 2: 
                    course_menu();                          // course sub menu
                    break;
                case 3:
                    list_all_students();                    // lists all students in system
                    break;
                case 4:     
                    list_all_courses();                     // lists all courses in system
                    break;
                default:
                    break;  

            }
        }
    }
    void SchoolManagerSystem::student_menu(){               // student sub menu
        int input;  
        while (true)
        {
            cout << "Student Menu:" << endl;
            cout << "0 up" << endl;
            cout << "1 add_student" << endl;
            cout << "2 select_student" << endl;
            cin >> input;

            switch (input)
            {
                case 0:
                    return;
                case 1:
                    add_student();                          // adds new student to system
                    break;
                case 2:
                    select_student();                       // select student sub menu
                    break;
                default:
                    break;
            }
        }
    }
    void SchoolManagerSystem::course_menu(){            // course sub menu
        int input;
        while (true)
        {
            cout << "0 up" << endl;
            cout << "1 add_course" << endl;
            cout << "2 select_course" << endl;
            cin >> input;

            switch (input)
            {
                case 0:
                    return;
                case 1:
                    add_course();                       // adds new course to system
                    break;
                case 2:
                    select_course();                    // select course sub menu 
                    break;
                default:
                    break;
            }
        }
    }
    void SchoolManagerSystem::list_all_courses()        // lists all courses in system
    {

        if (number_of_courses == 0)
        {                                               // if there isnt any courses returns
            return;
        }

        for (int i = 0; i < number_of_courses; i++)                         // prints all courses and their codes 
        {
            cout << i + 1 << ": ";
            cout << List_of_All_Courses[i]->getCode();
            cout <<" "<<List_of_All_Courses[i]->getCourseName() << endl;
        }
    }

    void SchoolManagerSystem::list_all_students() {                         // lists all students in system
        for (int i = 0; i < number_of_students; i++) {
            cout<<i+1<<": ";
            cout<<List_of_All_Students[i]->getStudentName()<<endl;
        }
    }
    int SchoolManagerSystem::get_number_of_courses()                        // returns total num of courses
    {
        return number_of_courses;
    }

    int SchoolManagerSystem::get_number_of_students()                       // returns total num of students
    {
        return number_of_students;
    }

    void SchoolManagerSystem::add_student()                                 // adds new student to system
    {   

        string input;
        cin.ignore();                                                       // ignore any char in buffer
        getline(cin, input);                                                // read the input line from user

        
        string name = "";
        int id = 0;
        for (char c : input) {                                              // for loop runs until input searching ends
            if (isdigit(c)) {                                               // if char is integer, its students number
                id = stoi(input.substr(input.find(c)));                     // assigns id of student
                break;
            }
            name += c;                                                      // assings name char by char every turn
        }
        
        Student* new_student = new Student(name, id);                       // Create a new Student object with the provided information

        
        Student** temp = new Student*[number_of_students + 1];              // make new list of students
        for (int i = 0; i < number_of_students; i++)
        {
            temp[i] = List_of_All_Students[i];                              // assigns all the names to new one
        }
        temp[number_of_students] = new_student;                             // assigns the new student to last element of list
        number_of_students++;                                               // increase the total num of students
        delete[] List_of_All_Students;                                      // delete the old list
        List_of_All_Students = temp;                                        // assign the new one
    }
    void SchoolManagerSystem::add_course() {                                // adds new course
        string all_input;
        int flag=0;
        cin.ignore();                                                       // ignore the chars in buffer
        getline(cin, all_input);                                            // read the input line from user

        
        string course_code = "";                                            // initialize code and name empty
        string course_name = "";
        bool foundSpace = false;    
        for (char c : all_input) {                                          // the first word before whitespace will be code and for loop runs until all_input ends
            if (c == ' '&&flag==0) {                                        // flag for consider only the first wihtespace 
                foundSpace = true;
                flag=1;
                continue;
            }
            if (!foundSpace) {                                              // if whitespace still doesnt found, this char is course codes char
                course_code += c;
            } else {
                course_name += c;                                           // else it is course names char
            }
        }
        Course* newCourse = new Course(course_name,course_code);             // create a new Course object

                                                                
        if (number_of_courses > 0) {                                        // if there is some other courses
                                                                            // create a new temporary array with size+1
            Course** temp = new Course*[number_of_courses + 1];

            
            for (int i = 0; i < number_of_courses; i++) {                   // copy the existing array elements to the temporary array
                temp[i] = List_of_All_Courses[i];
            }

            
            temp[number_of_courses] = newCourse;                            // add the new course object to the end of the temporary array

            
            delete[] List_of_All_Courses;                                   // delete the old List_of_All_Courses array

            
            List_of_All_Courses = temp;                                     // update the List_of_All_Courses pointer to the temporary array
        }
        else {                                                              // if the List_of_All_Courses array is empty, allocate memory for the first course
            
            List_of_All_Courses = new Course*[1];                                                  
            List_of_All_Courses[0] = newCourse;
        }

       
        number_of_courses++;                                                // increment the number_of_courses variable

    }

    void SchoolManagerSystem::select_student()                              // select student sub menu
    {
        int student_ID,input;
        string stdinput;
        cin.ignore();                                                       //ignore the chars in buffer
        getline(cin, stdinput);                                             // read the input line from user           

        
        string student_name = "";
        for (char c : stdinput) {                                           // loop runs until the stdinput search ends
            if (isdigit(c)) {
                student_ID = stoi(stdinput.substr(stdinput.find(c)));       // if the current char is an integer, it assigns it to id
                break;
            }
            student_name += c;                                              // else assigns to students name
        }

        while(true)
        {
            cout<<"0 up"<<endl;
            cout<<"1 delete_student"<<endl;
            cout<<"2 add_selected_student_to_a_course"<<endl;
            cout<<"3 drop_selected_student_from_a_course"<<endl;
            cin>>input;

            switch(input)
            {
                case 0:     
                    return;
                case 1:
                    for(int i=0;i<number_of_students;i++){
                        if(List_of_All_Students[i]->getID() == student_ID) // finds the relevant student object to delete
                        {
                            delete_student(List_of_All_Students[i]);       // deletes the entered student
                            return;
                        }
                    }         
                    break;
                case 2:
                    for(int i=0;i<number_of_students;i++){
                        if(List_of_All_Students[i]->getStudentName() == student_name && List_of_All_Students[i]->getID() == student_ID) // finds the entered student
                        {
                            add_student_to_a_course(List_of_All_Students[i]);                                                           // adds student to a course will be listed
                        }   
                    }
                    break;
                case 3: 
                    for(int i=0;i<number_of_students;i++){
                        if(List_of_All_Students[i]->getStudentName() == student_name && List_of_All_Students[i]->getID() == student_ID) // finds the entered student
                        {
                            remove_student_from_a_course(List_of_All_Students[i]);                                                      // drops student from a course
                        }
                    }
                    break;
                default:
                    break;
            }
        }
    }
    void SchoolManagerSystem::add_student_to_a_course(Student* student) {                       // adds student to given course
        for (int i = 0; i < number_of_courses; i++) {                                           // check if student is already enrolled in the course
            bool enrolled = false;
            for (int j = 0; j < List_of_All_Courses[i]->get_num_students(); j++) {
                if (List_of_All_Courses[i]->getStudents()[j]->getID() == student->getID()) {    // compares the name and id with courses
                    enrolled = true;
                    break;
                }
            }
            if (!enrolled) {
                cout << i+1 << ". " <<  List_of_All_Courses[i]->getCode() <<" "<<List_of_All_Courses[i]->getCourseName() << endl; // if student didnt enrolled prints to stdout 
            }
        }

        int course_choice;
        while (true) {
            cin >> course_choice;                                                           // user selects one choice 

            if (course_choice == 0) {
                return;
            } else if (course_choice >= 1 && course_choice <= number_of_courses) {          // if choice is valid 
                Course* selected_course = List_of_All_Courses[course_choice-1];             // course pointer that points the choosen course
                bool enrolled = false;
                for (int j = 0; j < selected_course->get_num_students(); j++) {
                    if (selected_course->getStudents()[j]->getID() == student->getID()) {   // checks wether student is enrolled to this course
                        enrolled = true;
                        break;
                    }
                }
                if (!enrolled) {                                                            // if student didnt enrolled
                    selected_course->addStudent(student);                                   // adds student to this course
                    student->addCourse(selected_course);                                    // adds course to course list of student object
                } 
                return;
            }
            else return; 
        }
    }

    void SchoolManagerSystem::remove_student_from_a_course(Student* student) {                              // drops student from a course
        Course** courseList = student->getCourses();                                                        // creates a new list of courses
        int numCourses = student->get_num_courses();                                                        
        for (int i = 0; i < numCourses; i++) {
            cout << i+1 << ". " <<courseList[i]->getCode() <<" "<<courseList[i]->getCourseName() <<endl;    // lists courses
        }

        int course_choice;
        while (true) {
            cin >> course_choice;                                                               // user selects a course to remove

            if (course_choice == 0) {
                return;
            } 
            else {
                Course* selected_course = courseList[course_choice-1];                          // course pointer to point selected course
                selected_course->removeStudent(student);                                        // remove student from selected course
                student->removeCourse(selected_course);                                         // remove course from course list of student object
                return;
            }
        }
    }

    void SchoolManagerSystem::select_course()                                       // select course sub menu
    {
        Course* selected_course;
        string entry;
        int input;
        int flag=0;
        cin.ignore();                                                               // ignore chars in buffer
        getline(cin, entry);                                                        // read the input line from user                           

        
        string code = "";
        string course_name = "";                                                    // initialize code and course name empty 
        bool foundSpace = false;
        for (char c : entry) {                                                      // loop runs until entry ends
            if (c == ' ' && flag==0) {                                              // checks for flag and whitespace, flag for check whitespace for only once
                foundSpace = true;
                flag = 1;
                continue;
            }
            if (!foundSpace) {                                                      // if space still doesnt fount it means that char is belong to code
                code += c;
            } else {
                course_name += c;                                                   // else it belongs to course name
            }
        }

        while(true)
        {
            cout<<"0 up"<<endl;
            cout<<"1 delete_course"<<endl;
            cout<<"2 list_students_registered_to_the_selected_course"<<endl;
            cin>>input;
            for(int i=0;i<number_of_courses;i++){
                        if(List_of_All_Courses[i]->getCourseName() == course_name && List_of_All_Courses[i]->getCode() == code)
                        {  
                            selected_course = List_of_All_Courses[i];                   // search for entered course
                        }
                    }

            switch(input)
            {
                case 0:
                    return;
                case 1:
                    for(int i=0;i<number_of_courses;i++){
                        if(List_of_All_Courses[i]->getCourseName() == course_name && List_of_All_Courses[i]->getCode() == code) // search for entered course
                        {
                            delete_course(List_of_All_Courses[i]);                  // if it exists, deletes that course
                            selected_course = List_of_All_Courses[i];               
                            return;
                        }
                    }
                    break;

                case 2:
                    for(int i=0;i<selected_course->get_num_students();i++){
                        cout<<selected_course->getStudents()[i]->getStudentName()<<" "<<selected_course->getStudents()[i]->getID()<<endl; // lists the students which enrolled that class
                    }
                    break;
                default:
                    break;
            }
        }
    }
    void SchoolManagerSystem::delete_course(Course* course) {                   // deletes course from system
        for (int i = 0; i < number_of_courses; i++) {
            if (List_of_All_Courses[i] == course) {                             // searchs for given course
                delete List_of_All_Courses[i];                                  // deletes that course
                for (int j = i; j < number_of_courses-1; j++) {
                    List_of_All_Courses[j] = List_of_All_Courses[j+1];          // slide every course object one element left
                }
                List_of_All_Courses[number_of_courses-1] = nullptr;             // last element will be null
                number_of_courses--;                                            // decrease total num of courses
                break;
            }
        }

        
        for (int i = 0; i < number_of_students; i++) {                          // remove course from every student object's CourseList
            Course** courses = List_of_All_Students[i]->getCourses();           // creates new course** pointer to find the selected course 
            int num_courses = List_of_All_Students[i]->get_num_courses();
            for (int j = 0; j < num_courses; j++) {
                if (courses[j] == course) {                                     // searchs for selected course in course list
                    List_of_All_Students[i]->removeCourse(course);              // removes course from each student objects
                    break;
                }
            }
        }
    }

    void SchoolManagerSystem::delete_student(Student* student){                 // deletes student from system
        for (int i = 0; i < number_of_students; i++) {
            if (List_of_All_Students[i] == student) {                           // searchs for given student
                delete List_of_All_Students[i];                                 // deletes this element from list
                for (int j = i; j < number_of_students-1; j++) {                // slide one element left every element of list of all students
                    List_of_All_Students[j] = List_of_All_Students[j+1];
                }
                List_of_All_Students[number_of_students-1] = nullptr;           // last element will be null
                number_of_students--;                                           // decrease the total num of students
                break;
            }
        }

        
        for (int i = 0; i < number_of_courses; i++) {                           // remove student from every student object's studentlist
            Student** students = List_of_All_Courses[i]->getStudents();         // student** pointer for searching the students
            int num_students = List_of_All_Courses[i]->get_num_students();
            for (int j = 0; j < num_students; j++) {
                if (students[j] == student) {                                   // if the given student found in list of students
                    List_of_All_Courses[i]->removeStudent(student);             // removes the student from each courses
                    break;
                }
            }
        }
    }

    SchoolManagerSystem::~SchoolManagerSystem(){                                // destructor for schoolmanagersystem
        delete[] List_of_All_Courses;                                           // delete course list
        delete[] List_of_All_Students;                                          // delete student list
    }

}