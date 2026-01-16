#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <iostream>

class Course;
class StudentOffice;

class Student {
private:
    int id;
    std::string name;
    std::string study_program;
    int year;
    static int total_students;
    Course* enrolled_courses;
    size_t enrolled_count;
    Course* completed_courses;
    size_t completed_count;

public:
    Student(int id, const std::string& name, const std::string& study_program, int year);
    Student(const Student& other);
    Student(Student&& other);
    Student& operator=(const Student& other);
    Student& operator=(Student&& other);
    ~Student();

    static int get_total_students();
    
    friend std::ostream& operator<<(std::ostream& os, const Student& s);
    friend std::istream& operator>>(std::istream& is, Student& s);
    
    Student& operator+=(const Course& course);
    Student& operator++();
    Student operator++(int);
    
    friend class StudentOffice;
};

#endif
