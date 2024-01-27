#include <iostream>
using namespace std;
int linearSearch(int arr[],int n, int x){
    for (int i = 0; i < n; i++){
        if(arr[i] == x) return i;
    }
    return -1;
}
int main(){
    int n;
    cout<<"Enter the no. digits: ";
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"The array is: "<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    int target;
    cout<<"Enter target: ";
    cin>>target;
    cout<<"index is: "<<linearSearch(arr,n,target);
}