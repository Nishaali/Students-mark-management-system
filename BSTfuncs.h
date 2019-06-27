#include "Student.h"
#include<cstring>
#include<iomanip>
struct Node{
    Student s;
    Node *left, *right;
};

Node* insertForDel(Node *&node, Student ss) {
    if (node == NULL){
        node = new Node;
        	int cred=0,points;
	float sum=0,gp;
	for(int i=0;i<ss.subNum;i++)
	{
		cred=cred+ss.subject[i].credit;
    }
    for(int i=0;i<ss.subNum;i++)
    {
    	if(ss.subject[i].marks>=90)
            points=10;
    	else if(ss.subject[i].marks>=80)
            points=9;
    	else if(ss.subject[i].marks>=70)
            points=8;
    	else if(ss.subject[i].marks>=60)
            points=7;
    	else if(ss.subject[i].marks>=50)
            points=6;
    	else
            points=0;
    	sum=sum+(ss.subject[i].credit*points);
    }
	gp=sum/cred;
    ss.gpa=gp;
	
        node->s = ss;
        node->left = node->right = NULL;
    }
    if (ss.reg < node->s.reg)
        node->left  = insertForDel(node->left,ss);
    else if (ss.reg > node->s.reg)
        node->right = insertForDel(node->right,ss);
    return node;
}

Node* findmin (Node* t){
    if(t->left == NULL)
        return t;
    else{
        t = findmin(t->left);
        return t;
    }
}

Node* deleteForDel(Node *&node, long regno){
    Node *temp = NULL;
    if(node==NULL)
        cout<<"No such record of student\n";
    else{
        if(regno < node->s.reg)
            node->left = deleteForDel(node->left, regno);
        else if (regno > node->s.reg)
            node->right = deleteForDel(node->right, regno);
        else{
            temp = node;
            if(node->left && node->right){
                temp = findmin(node->right);
                node->s = temp->s;
                node->right = deleteForDel(node->right,node->s.reg);
            }
            else if(node->left == NULL && node->right)
                node = node->right;
            else if(node->right == NULL&& node->left)
                node = node->left;
            else
                node = NULL;
            delete(temp);
        }
    }
    return node;
}

struct Node* search( Node *&t, long regno){
    if (t == NULL || t->s.reg == regno)
       return t;
    if (t->s.reg < regno)
       return search(t->right,regno);
    return search(t->left, regno);
}

void correction(Node *newt,long regno){
	int c;

	struct Node *t;
	t=search(newt,regno);
	if(t==NULL){
        cout<<"No such record of a student\n";
        return;
	}
	string newname;
	long newreg;

	cout<<"Enter the correction to be done:1.Name 2.Reg no 3.Marks\n";
	cin>>c;
	switch(c)
	{
		case 1:
			{
				cout<<"Enter the new name\n";
				cin>>newname;
				t->s.name=newname;
				break;
			}
			case 2:
				{
					cout<<"Enter the new register number:\n";
					cin>>newreg;
					t->s.reg=newreg;
					break;
				}
			case 3:
				{
					int m;
					float newm;
					cout<<setw(6)<<left<<"Number"<<"  "<<setw(13)<<left<<"Subject Name"<<endl;
					for(int i=0;i<t->s.subNum;i++)
                        cout<<setw(6)<<left<<i+1<<"  "<<setw(13)<<left<<t->s.subject[i].subName<<endl;
					cout<<"Enter the subject number in which mark is to changed:\t";
					cin>>m;
					cout<<"Enter the new mark of desired subject";
					cin>>newm;
					t->s.subject[m-1].marks=newm;
							int cred=0,points;
	float sum=0,gp;
	for(int i=0;i<t->s.subNum;i++)
	{
		cred=cred+t->s.subject[i].credit;
    }
    for(int i=0;i<t->s.subNum;i++)
    {
    	if(t->s.subject[i].marks>=90)
            points=10;
    	else if(t->s.subject[i].marks>=80)
            points=9;
    	else if(t->s.subject[i].marks>=70)
            points=8;
    	else if(t->s.subject[i].marks>=60)
            points=7;
    	else if(t->s.subject[i].marks>=50)
            points=6;
    	else
            points=0;
    	sum=sum+(t->s.subject[i].credit*points);
    }
	gp=sum/cred;
    t->s.gpa=gp;
	
					break;
				}
			}
}

void inorder(Node *t){
    if(t==NULL)
        return;
    inorder(t->left);
    cout<<setw(15)<<left<<t->s.reg<<setw(20)<<left<<t->s.name<<setw(10)<<left;
    for(int i=0;i<t->s.subNum;i++)
        cout<<t->s.subject[i].marks<<setw(10)<<left;
    cout<<endl;
    inorder(t->right);
}

void updation(Node *&t){
	 if(t==NULL)
        return;
    updation(t->left);

    float newm;
    cout<<"Reg: "<<t->s.reg<<"\nName: "<<t->s.name<<endl;
    for(int i=0;i<t->s.subNum;i++)
    {
        cout<<"Enter the new mark of "<<t->s.subject[i].subName<<" ";
        cin>>newm;
        t->s.subject[i].marks=t->s.subject[i].marks+newm;
    }
	int cred=0,points;
	float sum=0,gp;
	for(int i=0;i<t->s.subNum;i++)
	{
		cred=cred+t->s.subject[i].credit;
    }
    for(int i=0;i<t->s.subNum;i++)
    {
    	if(t->s.subject[i].marks>=90)
            points=10;
    	else if(t->s.subject[i].marks>=80)
            points=9;
    	else if(t->s.subject[i].marks>=70)
            points=8;
    	else if(t->s.subject[i].marks>=60)
            points=7;
    	else if(t->s.subject[i].marks>=50)
            points=6;
    	else
            points=0;
    	sum=sum+(t->s.subject[i].credit*points);
    }
	gp=sum/cred;
    t->s.gpa=gp;
	updation(t->right);
}

void inorder1(Node *t){
       if(t==NULL)
        return;
    inorder1(t->left);

    cout<<setw(15)<<left<<t->s.reg<<setw(20)<<left<<t->s.name<<setw(10)<<left;
    for(int i=0;i<t->s.subNum;i++)
        cout<<t->s.subject[i].marks<<setw(10)<<left;
    cout<<t->s.gpa;
    cout<<endl;

    inorder1(t->right);
}
void in_RA_display(Node *t,int index,int &cnt){
    if(t==NULL)
        return;
    in_RA_display(t->left,index,cnt);
    if(t->s.subject[index].marks<=50){
        cnt++;
        cout<<setw(15)<<left<<t->s.reg<<" "<<setw(6)<<left<<t->s.subject[index].marks<<endl;
    }
    in_RA_display(t->right,index,cnt);
}
void RA_display(Node *t){
    int cnt;
    for(int i=0;i<t->s.subNum;i++){
        cnt=0;
        cout<<"Subject: "<<t->s.subject[i].subName<<endl;
        cout<<setw(15)<<"Register Number"<<" "<<setw(6)<<left<<"Marks"<<endl;
        in_RA_display(t,i,cnt);
        if(cnt==0)
            cout<<"No Reappear Students in "<<t->s.subject[i].subName<<endl;
    }
}
