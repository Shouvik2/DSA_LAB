#include<iostream>
#include<vector>
using namespace std;
void merge(vector<int>& a,vector<int>& b,vector<int>& res){
    int i=0;//a
    int j=0;//b
    int k=0;//res
    while(i<a.size() && j<b.size()){
        if(a[i]<=b[j]) res[k++];
        else res[k++]=b[j++];
    }
    if(i==a.size()){ // a is at end
        while(j<b.size()){
            res[k++]=b[j++];
        }
    }
    if(j==b.size()){ // b is at end
        while(i<a.size()){
            res[k++]=a[i++];
        }
    }
}
void mergeSort(vector<int>& v){
    int n=v.size();
    if(n==1) return;
    int n1=n/2,n2=n-n/2;
    vector<int> a(n1),b(n2);
    for(int i=0;i<n1;i++){ // copy pasting
        a[i]=v[i];
    }
    for(int i=0;i<n2;i++){ // copy pasting
        b[i]=v[i+n1];
    }
    mergeSort(a);
    mergeSort(b);
    merge(a,b,v);
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
    mergeSort(v);
    cout<<"Modified Array is: "<<endl;
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
}