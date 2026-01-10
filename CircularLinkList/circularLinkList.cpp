#include<iostream>
using namespace std;


class Node{
public:
     int data;
     Node* next;

     Node(int val){
        data = val;
        next = NULL;
     }
};

class CircularList{
    Node* head;
    Node* tail;

public: 
     CircularList(){
        head = tail = NULL ;
     }

     void insertAtHead(int val){
        Node* newNode = new Node(val);
        if(head == NULL){
            head = tail = newNode;
            tail->next = head;
        }
        else{
            newNode->next = head;
            head = newNode;
            tail->next = head;
        }
     }

     void insertAtTail(int val){
        Node* newNode = new Node(val);
        if(head == NULL){
            head = tail = newNode;
            tail->next = head;
        } else {
            tail->next = newNode;
            tail = newNode;
            tail->next = head;
        }
     }

     void deleteAtHead(){
        if(head == NULL){
            cout<<"List is empty"<<endl;
            return;
        } else if(head == tail){
            delete head;
            head = tail = NULL ;
        } else {
            Node* temp = head;
            head = head->next;
            tail->next = head;
            temp->next = NULL;
            delete temp;
        }
     }
     void deleteAtTail(){
        if(head == NULL){
            cout<<"List is empty"<<endl;
            return;
        } else if(head == tail){
            delete head;
            head = tail = NULL ;
        } else {
            Node* temp = tail;
            Node* prev = head;
            while(prev->next != tail){
                prev = prev->next;
            }
            tail = prev;
            tail->next = head;
            temp->next = NULL;
            delete temp;
        }
     }

     void printCLL(){
         if(head == NULL) return;

         cout<<head->data<<"->";
         Node* temp = head->next;
         while(temp != head){
            cout<<temp->data<<"->";
            temp = temp->next;
            }
        cout<<temp->data<<endl;
     }
};

int main(){
    CircularList cll;

    cll.insertAtTail(1);
    cll.insertAtTail(2);
    cll.insertAtTail(3);
    // cll.deleteAtHead();
    // cll.deleteAtHead();
    cll.printCLL();
    cll.deleteAtTail();
    cll.printCLL();
    cll.deleteAtTail();
    cll.printCLL();
    cll.deleteAtTail();
    cll.printCLL();


    return 0;
}