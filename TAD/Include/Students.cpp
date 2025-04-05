#include <iostream>
#include <conio.h>
#include "Students.h"
#include <cstdlib> 

using namespace std;

void Student::ClearTerminal(){
    system("CLS");
}

void Student::setStudent(string nameS, int IdS){

    name=nameS;
    id=IdS;
}

float* Student::CreatGradeArrey(int Length){

    float* StudentGrades= new float[Length];
    return StudentGrades;
}

void Student::setScores(){

    int Length;
    float score;
    string position[] = {"first", "second", "third", "fourth", "fifth", "sixth"};

    cout<<"wirite the amount of scores the Student have: "<<endl;
    cin>>Length;
    cout<<"Wirite the student scores below or press 11 for exist to anytime: "<<endl;

    ArreyGradesLenth=Length;
    Grades = CreatGradeArrey(Length);

    for(int i=0; i<Length ; i++){

        cout<<position[i]<<" note: ";
        cin>>score;
        if(score==11){
            break;
        }else{
            Capacity++;
            Grades[i]=score;
            cout<<endl;
        }

    }

}

void Student::ReadingStudentsScores(){

    float sum=0;

    string position[]={"first", "second" , "third" , "fourth" , "fifth" , "sixth"};
    
    ClearTerminal();
     
    cout<<name<<endl;
    cout<<id<<endl;
    cout<<"---------------------------------------------------------------------"<<endl;

    for(int i=0; i<Capacity; i++){

        cout<<"---------------------"<<endl;
        cout<<"|"<<position[i] <<"        | "<<Grades[i]<<" |"<<endl;
        cout<<"---------------------"<<endl;
        sum+=Grades[i];
    }

    cout<<"Average: "<<(sum/(static_cast<float>(Capacity)))<<endl;
} 

void Student::propertiesOfVectorSudentsGrades(){

    float percent = ((static_cast<float>(Capacity) / ArreyGradesLenth) * 100);
    cout<<"properties Of Vector Sudents Grades_______________________________:"<<endl;
    cout<<endl;
    cout<<"Length_______________________________: "<<ArreyGradesLenth<<endl;
    cout<<"Capacity_____________________________: "<<percent<<"%"<<endl;

}