#include<bits/stdc++.h>
using namespace std;
int factorial(int n){
    if(n==1 || n==0) return 1;
    int recAns = n*factorial(n-1);
    return recAns ;
}
int main (){
    int n;
    cout<<"Enter a number : ";
    cin>>n;
    int fact = factorial (n);
    cout<<fact;
}