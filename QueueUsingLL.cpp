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
class Queue{ //User defined data structure
public:
    Node* head;
    Node* tail;
    int size;
    Queue(){
        head=tail=NULL;
        size=0;
    }
    void push(int val){ // InsertAtTail
        Node* temp=new Node(val);
        if(size==0) head=tail=temp;
        else{
            tail->next=temp;
            tail=temp;
        }
        size++;
    }
    void pop(){
        if(size==0){
            cout<<"Queue is Empty"<<endl;
            return;
        }
        Node* temp=head;// extra
        head=head->next;
        size--;
        delete(temp);// wastage nhi ho rahi
    }
    int front(){
        if(size==0){
            cout<<"Queue is Empty"<<endl;
            return -1;
        }
        return head->val;
    }
    int back(){
        if(size==0){
            cout<<"Queue is Empty"<<endl;
            return -1;
        }
        return tail->val;
    }
    void display(){
        Node* temp=head;
        while(temp!=NULL){
            cout<<temp->val<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }
    bool empty(){
        if(size==0) return true;
        else return false;
    }
};
int main(){
    Queue q;
    int choice,val;
    cout<<"1#push"<<endl;
    cout<<"2#pop"<<endl;
    cout<<"3#display the queue"<<endl;
    cout<<"4#size of queue"<<endl;
    cout<<"5#front element of queue"<<endl;
    cout<<"5#rear element of queue"<<endl;
    do{
        cout<<"Enter your choice: "<<endl;
        cin>>choice;
        switch (choice){
            case 1:cout<<"ENTER YOUR VALUE: "<<endl;
                cin>>val;
                q.push(val);
                break;
            case 2:
                q.pop();
                break;
            case 3:
                q.display();
                break;
            case 4:
                cout<<q.size<<endl;
                break;
            case 5:
                cout<<q.front()<<endl;
                break;
            case 6:
                cout<<q.back()<<endl;
                break;
            case 7:exit(0);
                break;
            default:
                cout<<"INVALID"<<endl;
                break;
        }   
    }while(choice!=8);
}