#include<iostream>
#include<string>
using namespace std;

class Teacher{
    
  private :
  double salary;

  public :
  //properties
    string name;
    string dept;
    string subject;

//   Teacher(){//non parameterized 
//         dept = "Computer Science";
//     }   
  Teacher(string name, string dept, string subject,double salary){// parameterized 
        this->name = name;
        this->dept = dept;
        this->subject = subject;
        this->salary = salary;
    }
    
    //copy constructor
    Teacher(Teacher &orgObj){//pass by reference
        cout<<"I am custom copy constructor"<<endl;
        this->name = orgObj.name;
        this->dept = orgObj.dept;
        this->subject = orgObj.subject;
        this->salary = orgObj.salary;
    }
  

    //methods || member functions
    void changeDept(string newDept) {
        dept = newDept;
    }

    void getInfo(){
        cout<<"Name : "<<name<<endl;
        cout<<"Subject : "<<subject<<endl;
    }
};

class Account{
private:
    double balance;
    string password;
public:
    string accountId;
    string userName;

    
};

int main() {

    Teacher t1("sahil", "CS", "C++", 29000);
    Teacher t2(t1);
    //t1.getInfo();
    t2.getInfo();
    
    return 0;
}