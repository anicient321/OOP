#include "StudentOffice.h"
#include "Course.h"
#include "UniversityConstants.h"

void StudentOffice::moveStudent(Student& student, const std::string& new_program) {
    student.study_program = new_program;
}

bool StudentOffice::enroll_student(Student& student, const Course& course) {
    int total = student.enrolled_count * 5;
    if (total + 5 <= UniversityConstants::MAX_ECTS_PER_YEAR) {
        student += course;
        return true;
    }
    return false;
}

void StudentOffice::process_exam_results(Student& student, const std::string& course_code) {
    for (size_t i = 0; i < student.enrolled_count; ++i) {
        if (student.enrolled_courses[i].get_code() == course_code) {
            Course* temp = new Course[student.completed_count + 1];
            for (size_t j = 0; j < student.completed_count; ++j) {
                temp[j] = student.completed_courses[j];
            }
            temp[student.completed_count] = student.enrolled_courses[i];
            delete[] student.completed_courses;
            student.completed_courses = temp;
            student.completed_count++;
            
            Course* temp2 = new Course[student.enrolled_count - 1];
            size_t k = 0;
            for (size_t j = 0; j < student.enrolled_count; ++j) {
                if (j != i) {
                    temp2[k++] = student.enrolled_courses[j];
                }
            }
            delete[] student.enrolled_courses;
            student.enrolled_courses = temp2;
            student.enrolled_count--;
            break;
        }
    }
}

void StudentOffice::update_student_years(std::vector<Student>& students) {
    for (size_t i = 0; i < students.size(); ++i) {
        ++students[i];
        delete[] students[i].completed_courses;
        students[i].completed_courses = nullptr;
        students[i].completed_count = 0;
    }
}
