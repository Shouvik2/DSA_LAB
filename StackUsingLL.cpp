// Stack Using LL
#include<iostream>
using namespace std;
class Node{ // Linked List node
public:
    int val;
    Node* next;
    Node(int val){
        this->val=val;
        this->next=NULL;
    }
};
class Stack{ // user defined data structure
public:
    Node* head;
    int size;
    Stack(){
        head=NULL;
        size=0;
    }
    void push(int val){
        Node* temp=new Node(val);
        temp->next=head;
        head=temp;
        size++;
    }
    void pop(){
        if(head==NULL){
            cout<<"Stack is empty!"<<endl;
            return;
        }
        head=head->next;
        size--;
    }
    int top(){
        if(head==NULL){
            cout<<"Stack is empty!"<<endl;
            return -1;
        }
        return head->val;
    }
    void print(Node* temp){
        if(temp==NULL) return;
        print(temp->next);
        cout<<temp->val<<" ";
    }
    void display(){
        Node* temp=head;
        print(temp);
        cout<<endl;
    }
};
int main(){
    Stack st;
    int choice,val;
    cout<<"1#push"<<endl;
    cout<<"2#pop"<<endl;
    cout<<"3#display the stack"<<endl;
    cout<<"4#size of stack"<<endl;
    cout<<"5#top element of stack"<<endl;
    do{
        cout<<"Enter your choice: "<<endl;
        cin>>choice;
        switch (choice){
            case 1:cout<<"ENTER YOUR VALUE: "<<endl;
                cin>>val;
                st.push(val);
                break;
            case 2:
                st.pop();
                break;
            case 3:
                st.display();
                break;
            case 4:
                cout<<st.size<<endl;
                break;
            case 5:
                cout<<st.top()<<endl;
                break;
            case 6:exit(0);
                break;
            default:
                cout<<"INVALID"<<endl;
                break;
        }   
    }while(choice!=7);
}