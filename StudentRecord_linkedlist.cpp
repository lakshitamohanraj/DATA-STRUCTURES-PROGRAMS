#include <iostream>

using namespace std;

/*student a node 
insert at position or before student id
delete at position or delete at id
display all
search student using id*/
struct Student{
      string name;
      long int rollno;
      string courses;
      double total_marks;
      struct Student* next;
};
struct Student * getNewNode(string name, long int regno,string courses,double totalmark){
         struct Student *newnode=new Student();
         newnode->name=name;
         newnode->rollno=regno;
         newnode->courses=courses;
         newnode->total_marks=totalmark;
         newnode->next=NULL;
         
         return newnode;
}
struct Student* insert(struct Student* head,string name,long int regno,string courses,double totalmark){
    struct Student *newnode=getNewNode(name,regno,courses,totalmark);
     if(!newnode) cout<<"fatal_error: heap out of space"<<endl;
    else if(head==NULL || head->rollno > regno){
        
        newnode->next=head;
        head=newnode;
        return head;
    }
    else if(head!=NULL){
        struct Student* temp=head;
        while(temp->next!=NULL && regno > temp->next->rollno)
            temp=temp->next;
        newnode->next=temp->next;
        temp->next=newnode; 
        return head;
        
        }

}

struct Student* deleteAtId(struct Student* head, int id){//id=rolllno
    if(head==NULL) {cout<<"Empty Records"<<endl; exit(0);}
    else if(head!=NULL){
        struct Student* temp=head;
        while(temp!=NULL){
            if(temp->next->rollno==id){
                break;
            }
            temp=temp->next;
        }
        struct Student*temp1=temp->next;
        temp->next=temp1->next;
        delete temp1;
        cout<<"The Student with Register number: "<<id<<" is Successfully deleted from Record"<<endl;
        return head;
    }
}
void search(struct Student* head,int id){
    int c=0;
     if(head==NULL) {cout<<"Empty Records"<<endl; return; }
     else if(head!=NULL){
        struct Student* temp=head;
        while(temp!=NULL){
            if(temp->rollno==id) {cout<<"Student Found: \n INFO:"<<endl;
            cout<<"========================================================="<<endl;
            cout<<"Register Number: "<<temp->rollno<<endl;
            cout<<"Name: "<<temp->name<<endl;
            cout<<"Courses: "<<temp->courses<<endl;
            cout<<"Total Marks :"<<temp->total_marks<<endl;
            cout<<"========================================================="<<endl;
            c++;
            }
            temp=temp->next;
        }
     }
     if(c==0) cout<<"----------Student Not Found!----------"<<endl;
    return ;
     
}
void showData(struct Student* head){
       if(head==NULL) cout<<"Empty Records"<<endl;
       else if(head!=NULL){
        Student* temp=head;
        while(temp!=NULL){
            cout<<"========================================================="<<endl;
            cout<<"Register Number: "<<temp->rollno<<endl;
            cout<<"Name: "<<temp->name<<endl;
            cout<<"Courses: "<<temp->courses<<endl;
            cout<<"Total Marks :"<<temp->total_marks<<endl;
            cout<<"========================================================="<<endl;

            temp=temp->next;
        }
       }
}
int main(){
    struct Student * head=NULL;
    cout<<"--------------------STUDENT RECORD LIST------------"<<endl;
    cout<<"Enter the number of trials"<<endl;
    int query;
    cin>>query;
    int n;
    string name,course;
    int regno;
    double totalmark;
    for(int i=0;i<query;i++){
        cout<<"AVAILABLE OPTIONS: "<<endl;
        cout<<"1.INSERTION()\n 2.DELETION()\n 3.SEARCH()\n 4.VIEWING()\n";
        cout<<"Enter the option to perform:\n";
        cin>>n;
        switch (n)
        {
        case 1:
             cout<<"Enter the details of Student: "<<endl;
             cout<<"Enter the Name of the Student: ";
             cin>>name;
             cout<<"Enter the Registration Number of the Student: ";
             cin>>regno;
             cout<<"Enter the courses enrolled by the Student:(separated by comma) :";
             cin>>course;
             cout<<"Enter the total marks of the student :";
             cin>>totalmark;
             head=insert(head,name,regno,course,totalmark);
             cout<<"Successfully The Record inserted :"<<endl;
            break;
        case 2:
           cout<<"Enter the Register number of the Student  to be Deleted from the Record: ";
           cin>>regno;
           head=deleteAtId(head,regno);
         break;
         case 3:
           cout<<"Enter the Register number of the student to be searched in the Record :";
           cin>>regno;
           search(head,regno);
           break;
        case 4:  
          cout<<"-------------------THE STUDENT RECORD INFO------------------"<<endl;
          showData(head);
        default:
        cout<<"Invalid option:!!!"<<endl;
            break;
        }
        
    }
    
    return 0;
    
}