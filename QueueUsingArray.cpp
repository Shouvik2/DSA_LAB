#include<iostream>
using namespace std;
#define MAX 10
class Queue{
public:
    int f;
    int b;
    int arr[MAX];
    Queue(){
        f=0;
        b=0;
    }
    void push(int val){
        if(b==MAX-1){
            cout<<"Queue is FULL!"<<endl;
            return;
        }
        arr[b]=val;
        b++;
    }
    void pop(){
        if(f-b==0){ // f-b -> size
            cout<<"Queue is empty!"<<endl;
            return;
        }
        f++;
    }
    int front(){
        if(f-b==0){
            cout<<"Queue is empty!"<<endl;
            return -1;
        }
        return arr[f];
    }
    int back(){
        if(f-b==0){
            cout<<"Queue is empty!"<<endl;
            return -1;
        }
        return arr[b-1];
    }
    int size(){
        return b-f;
    }
    bool empty(){
        if(f-b==0) return true;
        else return false;
    }
    void display(){
        for(int i=f;i<b;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
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
                cout<<q.size()<<endl;
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