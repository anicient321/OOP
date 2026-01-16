#ifndef COURSE_H
#define COURSE_H

#include <string>
#include <iostream>

class Course {
private:
    std::string name;
    std::string code;
    int ects;

public:
    Course();
    Course(const std::string& name, const std::string& code, int ects);
    
    friend std::ostream& operator<<(std::ostream& os, const Course& c);
    friend std::istream& operator>>(std::istream& is, Course& c);
    
    std::string get_code() const { return code; }
};

#endif
