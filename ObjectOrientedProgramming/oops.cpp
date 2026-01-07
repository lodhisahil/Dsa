#include<iostream>
#include<string>
using namespace std;

// class Teacher{
    
//   private :
//   double salary;

//   public :
//   //properties
//     string name;
//     string dept;
//     string subject;

// //   Teacher(){//non parameterized 
// //         dept = "Computer Science";
// //     }   
//   Teacher(string name, string dept, string subject,double salary){// parameterized 
//         this->name = name;
//         this->dept = dept;
//         this->subject = subject;
//         this->salary = salary;
//     }
    
//     //copy constructor
//     Teacher(Teacher &orgObj){//pass by reference
//         cout<<"I am custom copy constructor"<<endl;
//         this->name = orgObj.name;
//         this->dept = orgObj.dept;
//         this->subject = orgObj.subject;
//         this->salary = orgObj.salary;
//     }
  

//     //methods || member functions
//     void changeDept(string newDept) {
//         dept = newDept;
//     }

//     void getInfo(){
//         cout<<"Name : "<<name<<endl;
//         cout<<"Subject : "<<subject<<endl;
//     }
// };



// class Account{
// private:
//     double balance;
//     string password;
// public:
//     string accountId;
//     string userName;

    
// };

// class Student{
// public :
//     string name;
//     double* cgpaPtr;
    
    
//     Student(string name, double cgpa){
//         this->name = name;
//         cgpaPtr = new double;
//         *cgpaPtr = cgpa;
//     }
//     // Student(Student &obj){
//     //     this->name = obj.name;
//     //     cgpaPtr = new double;
//     //     *cgpaPtr = *obj.cgpaPtr;
//     // }

//     //destructor
//     ~Student(){
//         cout<<"Hi i delete everything"<<endl;
//         delete cgpaPtr;
//     }

//     void getInfo(){
//         cout<<"name : "<< name <<endl;
//         cout<<"cgpa : "<< *cgpaPtr <<endl;
//     }

// };

// int main() {

//     // Teacher t1("sahil", "CS", "C++", 29000);
//     // Teacher t2(t1);
//     // //t1.getInfo();
//     // t2.getInfo();

//     Student s1("Sahil Lodhi", 8.9);
//     s1.getInfo();

//     // s1.getInfo();
//     // *(s2.cgpaPtr) = 9.2;
//     // s1.getInfo();

//     // s2.name = "Shraddha Lodhi";
//     // s2.getInfo();
//     return 0;
// }

// class Person{
// public : 
//     string name;
//     int age;  
    
//     // Person(string name, int age){
//     //     this->name = name;
//     //     this->age = age;
//     // }
//     // Person(){
//     //     cout<<"Parent constructor"<<endl;
//     // }
//     // ~Person(){
//     //     cout<<"Parent destructor"<<endl;
//     // }
// };


class Student {
    public :
    string name;
    int rollno;

    // Student(string name, int age, int rollno) : Person(name, age) {
    //     this->rollno = rollno;
    // }
    // ~Student(){
    //     cout<<"Child destructor"<<endl;
    // }

    // void getInfo(){
    //     cout<<"name : "<<name<<endl;
    //     cout<<"age : "<<age<<endl;
    //     cout<<"rollno : "<<rollno<<endl;
    // }
};

class Teacher {
    public:
    string subject;
    double salary;
};

class TA : public Student, public Teacher{
    public :
};


class GradStudent{
    public:
   string researchArea;
};


int main(){
    TA t1;
    t1.name = "tony";
    t1.subject = "Physics";

    cout<<t1.name<<endl;
    cout<<t1.subject<<endl;
    return 0;
}