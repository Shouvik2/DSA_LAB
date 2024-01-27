#include<iostream>
#include<vector>
using namespace std;
int binarySearch(vector<int>&nums, int target){
    int lo=0;
    int hi=nums.size()-1;
    while(lo<=hi){
        int mid=lo+(hi-lo)/2;
        if(nums[mid]==target) return mid;
        else if(nums[mid]>target) hi=mid-1;
        else lo=mid+1;
    }
    return -1;
}
int main(){
    int n;
    cout<<"enter size of array: ";
    cin>>n;
    vector<int> v;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        v.push_back(x);
    }
    cout<<"Array is: "<<endl;
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
    int target;
    cout<<"Enter target: ";
    cin>>target;
    cout<<"index is: "<<binarySearch(v,target);
}