#include<bits/stdc++.h> 
using namespace std;
int main(){
    int n;
    cout<<"enter size of array: ";
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"Array is: "<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    for(int i=0;i<=n-1;i++){
        int j=i;
        while(j>=1 && arr[j]<arr[j-1]){ 
            int temp=arr[j]; 
            arr[j]=arr[j-1];
            arr[j-1]=temp;
            j--; 
        }
    }   
    cout<<"Modified Array is: "<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}