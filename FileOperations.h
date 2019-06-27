#include "Student.h"
#include<fstream>
#include<iostream>
#include "BSTfuncs.h"
using namespace std;

void writeToFile(Student stud){
    ofstream output;
    output.open("StudentDetails.txt",fstream::app);
    output<<stud.reg<<" "<<stud.name<<" ";
    for(int i=0; i<stud.subNum;i++){
        output<<stud.subject[i].marks<<" ";
    }
    output<<stud.gpa<<" ";
    output<<endl;
}

Node*  ReadFromFile(Node *&node){
    ifstream input;
    Student st;
    st.readSubjects();
    input.open("StudentDetails.txt");
    long r;
    while(input>>r){
        st.reg = r;
        input>>st.name;
        for(int i=0;i<st.subNum;i++){
            input>>st.subject[i].marks;
        }
        input>>st.gpa;
        node = insertForDel(node, st);
    }
    return node;
}

void in_writeTree(Node *t, ofstream &outfile){
    if(t==NULL)
        return;
    in_writeTree(t->left,outfile);
    outfile<<t->s.reg<<" "<<t->s.name<<" ";
    for(int i=0;i<t->s.subNum;i++)
        outfile<<t->s.subject[i].marks<<" ";
    outfile<<t->s.gpa;
    outfile<<endl;
    in_writeTree(t->right, outfile);
}

void writeTree(Node *t){
    ofstream outfile;
    outfile.open("StudentDetails.txt");
    in_writeTree(t,outfile);
    outfile.close();
}

void in_writeTreeGPA(Node *t, ofstream &outfile){
    if(t==NULL)
        return;
    in_writeTreeGPA(t->left,outfile);
    outfile<<t->s.reg<<" "<<t->s.name<<" ";
    for(int i=0;i<t->s.subNum;i++)
        outfile<<t->s.subject[i].marks<<" ";
    outfile<<t->s.gpa;
    outfile<<endl;
    in_writeTreeGPA(t->right, outfile);
}

void writeTreeGPA(Node *t){
    ofstream outfile;
    outfile.open("StudentDetails.txt");
    in_writeTreeGPA(t,outfile);
    outfile.close();
}

Node*  dispReadFromFile(Node *&node){
    ifstream input;
    Student st;
    st.readSubjects();
    input.open("StudentDetails.txt");
    long r;
    while(input>>r){
        st.reg = r;
        input>>st.name;
        for(int i=0;i<st.subNum;i++){
            input>>st.subject[i].marks;
        }
        input>>st.gpa;
        node = insertForDel(node, st);
    }
    return node;
}

void subjectReset(){
    ofstream output;
    output.open("SubjectDetails.txt");
    int n,c;
    string str;
    cout<<"Enter the num of subjects\n";
    cin>>n;
    output<<n<<endl;
    for(int i=0; i<n;i++){
        cout<<"Enter the subject and credit\n";
        cin>>str>>c;
        output<<str<<" "<<c<<endl;
    }
    output.close();
}

void in_writeNewRoot(Node *&t){
    if(t==NULL)
        return;
    in_writeNewRoot(t->left);
    t->s.readSubjects();
    t->s.gpa=0;
    for(int i=0;i<t->s.subNum;i++)
        t->s.subject[i].marks=0;
    in_writeNewRoot(t->right);
}

Node* writeNewRoot(Node *&t){
    in_writeNewRoot(t);
    //cout<<t->s.gpa<<endl;
    return t;
}

