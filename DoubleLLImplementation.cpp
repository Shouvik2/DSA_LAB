#include<iostream>
using namespace std;
class Node{ // Doubly Linked List node
public:
    int val;
    Node* next;
    Node* prev;//extra for DLL
    Node(int val){
        this->val=val;
        this->next=NULL;
        this->prev=NULL;// extra for DLL
    }
};
class DLL{ //User defined data structure
public:
    Node* head;
    Node* tail;
    int size;
    DLL(){
        head=tail=NULL;
        size=0;
    }
    void insertAtHead(int val){
        Node* temp=new Node(val);
        if(size==0) head=tail=temp;
        else{
            temp->next=head;
            head->prev=temp;//extra
            head=temp;
        }
        size++;
    }
    void insertAtTail(int val){
        Node* temp=new Node(val);
        if(size==0) head=tail=temp;
        else{
            tail->next=temp;
            temp->prev=tail;
            tail=temp;
        }
        size++;
    }
    void insertAtIdx(int idx,int val){
        if(idx<0 || idx>size) cout<<"Invalid Index"<<endl;
        else if(idx==0) insertAtHead(val);
        else if(idx==size) insertAtTail(val);
        else{
            Node* t=new Node(val);
            Node* temp=head;
            for(int i=1;i<=idx-1;i++){
                temp=temp->next;
            }
            t->next=temp->next;
            temp->next=t;
            t->prev=temp;
            t->next->prev=t;
            size++;
        }
    }
    void deleteAtHead(){
        if(size==0){
            cout<<"List is empty";
            return;
        }
        head=head->next;
        if(head!=NULL) head->prev=NULL;//extra
        if(head==NULL) tail=NULL;//extra
        size--;
    }
    void deleteAtTail(){
        if(size==0){
            cout<<"List is empty";
            return;
        }
        else if(size==1){ //extra
            deleteAtHead();
            return;
        }
        //extra
        Node* temp=tail->prev;
        temp->next=NULL;
        tail=temp;
        size--;
    }
    void deleteAtIdx(int idx){
        if(size==0){
            cout<<"List is empty";
            return;
        }
        else if(idx<0 || idx>=size){
            cout<<"Invalid index";
            return;
        }
        else if(idx==0) return deleteAtHead();
        else if(idx==size-1) return deleteAtTail();
        else{
            Node* temp=head;
            for(int i=1;i<=idx-1;i++){
                temp=temp->next;
            }
            temp->next=temp->next->next;
            temp->next->prev=temp; //extra
            size--;
        }
    }
    int getAtIdx(int idx){
        if(idx<0 || idx>size){
            cout<<"Invalid Index";
            return -1;
        }
        else if(idx==0) return head->val;
        else if(idx==size-1) return tail->val;
        else{
            if(idx<size/2){
                Node* temp=head;
                for(int i=1;i<=idx;i++){
                    temp=temp->next;
                }
                return temp->val;
            }
            else{
                Node* temp=tail;
                for(int i=1;i<size-idx;i++){
                    temp=temp->prev;
                }
                return temp->val;
            }
        }
    }
    void display(){
        Node* temp=head;
        while(temp!=NULL){
            cout<<temp->val<<"<->";
            temp=temp->next;
        }
        cout<<endl;
    }
};
int main(){
    DLL ll;
    int choice,data,idx;
    cout<<"1# Insert at head"<<endl;
    cout<<"2# Insert at tail"<<endl;
    cout<<"3# Insert at idx"<<endl;
    cout<<"4# Get at idx"<<endl;
    cout<<"5# Delete at head"<<endl;
    cout<<"6# Delete at tail"<<endl;
    cout<<"7# Delete at idx"<<endl;
    cout<<"8# Display the Linkedlist"<<endl;
    cout<<"9# EXIT"<<endl;
    do{
        cout<<"Enter your choice: ";
        cin>>choice;
        switch (choice){
            case 1:cout<<"ENTER YOUR DATA: "<<endl;
                cin>>data;
                ll.insertAtHead(data);
                break;
            case 2:cout<<"ENTER YOUR DATA: "<<endl;
                cin>>data;
                ll.insertAtTail(data);
                break;
            case 3:
                cout<<"ENTER YOUR DATA: ";
                cin>>data;
                cout<<"ENTER YOUR INDEX: ";
                cin>>idx;
                ll.insertAtIdx(idx,data);
                break;
            case 4:
                cout<<"ENTER YOUR INDEX: ";
                cin>>idx;
                cout<<ll.getAtIdx(idx)<<endl;
                break;
            case 5:
                ll.deleteAtHead();
                break;
            case 6:
                ll.deleteAtTail();
                break;
            case 7:cout<<"ENTER YOUR INDEX"<<endl;
                cin>>idx;
                ll.deleteAtIdx(idx);
                break;
            case 8:
                ll.display();
                break;
            case 9:exit(0);
                break;
            default:
                cout<<"INVALID"<<endl;
                break;
        }   
    }while(choice!=10);
}