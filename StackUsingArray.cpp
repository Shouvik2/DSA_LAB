// Stack using Array
#include<iostream>
using namespace std;
#define MAX 5
class Stack{ // user defined data structure
public:
    int arr[MAX];
    int idx;
    Stack(){
        idx=-1;
    }
    void push(int val){
        if(idx==MAX-1){
            cout<<"Stack is Full"<<endl;
            return;
        }
        idx++;
        arr[idx]=val;
    }
    void pop(){
        if(idx==-1){
            cout<<"Stack is empty!"<<endl;
            return;
        }
        idx--;
    }
    int top(){
        if(idx==-1){
            cout<<"Stack is empty!"<<endl;
            return -1;
        }
        return arr[idx];
    }
    int size(){
        return idx+1;
    }
    void display(){
        for(int i=0;i<=idx;i++){
            cout<<arr[i]<<" ";
        }
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
                cout<<st.size()<<endl;
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