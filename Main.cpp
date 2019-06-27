#include<iostream>
#include<iomanip>
#include "Student.h"
#include "FileOperations.h"
using namespace std;
void optionsDisp();
void titleDisp();
int main(){
    int choice;
    bool entry=true;
    titleDisp();
    while(entry){
        cout<<endl;
        optionsDisp();
        cout<<"\nEnter your choice  ";
        cin>>choice;
        cout<<endl;
        switch(choice){
            case 1:{
                        Student s;
                        s.getData();
                        writeToFile(s);
                        break;
                    }
            case 2:{
                        long reg;
                        Node *root = NULL;
                        root = ReadFromFile(root);
                        cout<<"Enter the register number of the student\n";
                        cin>>reg;
                        deleteForDel(root,reg);
                        writeTree(root);
                        cout<<endl;
                        break;
                    }
            case 3:{
            	        long reg;
            	        Node *root=NULL;
            	        root=ReadFromFile(root);
            	        cout<<"Enter the register number of the student:\n";
            	        cin>>reg;
            	        correction(root,reg);
            	        writeTree(root);
				        break;
			       }
			case 4:{
				    	 Node *root=NULL;
            	        root=ReadFromFile(root);
                       updation(root);
                       writeTreeGPA(root);
				        break;
					}
			case 5:{
				   	Node *root=NULL;
				   	root=ReadFromFile(root);
				   	
				   	if(root==NULL)
				   	{
				   	cout<<"No details found";
				   	break;
				    }
				   	else
				   	{
				   	cout<<"\nStored details until Assessment:";
                    cout<<endl<<setw(15)<<left<<"Reg No"<<setw(20)<<left<<"Name"<<setw(10)<<left;
                    for(int i=0;i<root->s.subNum;i++)
                        cout<<root->s.subject[i].subName<<setw(10)<<left;
                    cout<<endl;
                    inorder(root);
                    cout<<endl;
				   	break;
				    }
				    }
			case 6:{
				   	Node *root=NULL;
				   	root=dispReadFromFile(root);
				   	if(root==NULL)
				   	{
				   	cout<<"No details found";
				   	break;
				    }
				    else
				    {
				   	cout<<"\nFinal results:\n";
				   	cout<<endl<<setw(15)<<left<<"Reg No"<<setw(20)<<left<<"Name"<<setw(10)<<left;
                    for(int i=0;i<root->s.subNum;i++)
                        cout<<root->s.subject[i].subName<<setw(10)<<left;
                    cout<<"CGPA";
                    cout<<endl;
				   	inorder1(root);
				   	cout<<endl;
				   	break;
				    }
				   }
            case 7:{
                        Node *root = NULL;
                        root = ReadFromFile(root);
                        if(root==NULL)
				   	    {
				   	     cout<<"No details found";
				   	     break;
				        }
				        else
				        {
                        RA_display(root);
                        break;
                        }
                    }
            case 8:{
                        Node *root = NULL;
                        root = ReadFromFile(root);
                        subjectReset();
                        root = writeNewRoot(root);
                       // cout<<root->s.gpa<<endl;
                        writeTreeGPA(root);
                        break;
                    }
            case 9: entry = false;
                    break;
            default: cout<<"Invalid choice\n";
        }
    }
}

void titleDisp(){
    for(int i=0;i<60;i++)
        cout<<" ";
    cout<<"STUDENT RECORD MANAGEMENT SYSTEM\n";
     for(int i=0;i<60;i++)
        cout<<" ";
    cout<<"--------------------------------\n\n\n";
}

void optionsDisp(){
    cout<<endl;
    for(int i=0;i<23;i++)
        cout<<"* ";
      cout<<endl;
      cout<<"*  1.Add a student record                   *\n";
      cout<<"*  2.Delete a student record                *\n";
      cout<<"*  3.Edit a student record                  *\n";
      cout<<"*  4.Update the marks                       *\n";
      cout<<"*  5.Display all records                    *\n";
      cout<<"*  6.Display the Results                    *\n";
      cout<<"*  7.Display the list of Reappear Students  *\n";
      cout<<"*  8.Reset the format for next semester     *\n";
      cout<<"*  9.Exit the application                   *\n";
    for(int i=0;i<23;i++)
        cout<<"* ";
}
