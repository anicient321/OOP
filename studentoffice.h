#ifndef STUDENTOFFICE_H
#define STUDENTOFFICE_H

#include "Student.h"
#include <vector>

class StudentOffice {
public:
    void moveStudent(Student& student, const std::string& new_program);
    bool enroll_student(Student& student, const Course& course);
    void process_exam_results(Student& student, const std::string& course_code);
    void update_student_years(std::vector<Student>& students);
};

#endif
