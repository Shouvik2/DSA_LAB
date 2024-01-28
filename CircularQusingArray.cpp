#include<iostream>
#include<vector>
using namespace std;
class Queue{
public:
    int f;
    int b;
    int s;
    vector<int> arr;
    Queue(int val){
        f=0;
        b=0;
        s=0;
        vector<int> v(val);
        arr=v;
    }
    void push(int val){
        if(b==arr.size()){
            cout<<"Queue is FULL!"<<endl;
            return;
        }
        arr[b]=val;
        b++;
        s++;
    }
    void pop(){
        if(s==0){ // f-b -> size
            cout<<"Queue is empty!"<<endl;
            return;
        }
        f++;
        s--;
    }
    int front(){
        if(s==0){
            cout<<"Queue is empty!"<<endl;
            return -1;
        }
        return arr[f];
    }
    int back(){
        if(s==0){
            cout<<"Queue is empty!"<<endl;
            return -1;
        }
        return arr[b-1];
    }
    int size(){
        return s;
    }
    bool empty(){
        if(s==0) return true;
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
    int n;
    cout<<"Enter the size of Queue: "<<endl;
    cin>>n;
    Queue q(n);
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