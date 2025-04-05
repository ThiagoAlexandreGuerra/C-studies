#ifndef STUDENTS_H
#define STUDENTS_H

#include <iostream>
using namespace std;

class Student {
private:
    float *Grades;
    int ArreyGradesLenth;
    int Capacity=0;
    string name;  // Alterado para string em vez de char
    int id;
    float* CreatGradeArrey(int Length);
    void ClearTerminal();

public:
    void setStudent(std::string name, int id);  // Alterado para string
    void setScores();
    void ReadingStudentsScores();
    void propertiesOfVectorSudentsGrades();
};

#endif
