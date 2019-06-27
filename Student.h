#ifndef STUDENT_H
#define STUDENT_H
#include "Subject.h"
#include<fstream>
#define MAX 10
using namespace std;

class Student
{
    public:
        Student(){
            gpa = 0.00;
        }
        Student(long r, string n){

        }
        int subNum;
        long reg;
        string name;
        float gpa;
        Subject subject[MAX];

        void getData(){
            cout<<"Enter the register number and the name of the student\n";
            cin>>reg>>name;
            readSubjects();
            cout<<"Enter the marks\n";
            for(int i=0;i<subNum;i++){
                cout<<subject[i].subName<<" : ";
                cin>>subject[i].marks;
            }
               
                cout<<endl;
            }
        
        void readSubjects(){
            ifstream input;
            string str;
            input.open("SubjectDetails.txt");
            input>>subNum;
            for(int i=0;i<subNum;i++){
                input>>subject[i].subName;
                input>>subject[i].credit;
            }
            input.close();
        }
};

#endif // STUDENT_H
